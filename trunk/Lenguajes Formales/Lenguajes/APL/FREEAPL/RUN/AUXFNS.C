/////////////////////////////////////////////////////////////////
//  AUXFNS.C Prototype file for APLWin DLL auxiliary functions
//  Copyright 1995 Tauno Ylinen.
/////////////////////////////////////////////////////////////////

#include <windows.h>
#include <ctype.h>
#include <math.h>
#include "apl.h"
#include "auxfns.h"

int FAR PASCAL LibMain(HANDLE h, WORD ds, WORD heapsz, LPSTR cmd)
{
	if(heapsz>0)
		UnlockData(0);
	return 1;
}

int FAR PASCAL WEP(int param)
{
	return 1;
}

struct item * FAR PASCAL _export ATOF(INT fn, int n, struct item **iptr)
{
    int run=0, exrun=0, k;
    INT i, j, count=0, start=0, end=0;
    char buf[128];
    struct item *p, *r, *(FAR *f)(int, int, INT);

    /* check of arguments */
    if(n!=1) goto error;
	p=((struct nlist *)iptr[0])->itemp;
	if(p==NULL) goto error;
	if(p->type!=CH) goto error;
	if(p->rank!=1) goto error;

	/* count elements */
	for(i=0;i<p->size;i++){
		exrun=run;
		run=!isspace((*((char*)p->datap+i)));
		if(run>exrun) count++;
	}


    /* call of extern function (newdat) */
	f=fn;
    r=(f)((int)DA,(int)1,(INT)count);


	/* scan input data */

	for(i=0;i<r->size;i++){
		run=exrun=0;
		for(j=0;start+j<p->size;j++){
			exrun=run;
			run=!isspace(k=(*((char*)p->datap+start+j)));
			buf[j]=k;
			if(run<exrun) {end=j; break;}
		}
		buf[j]='\0';
		*(r->datap+i)=atof(buf);
		start+=end;
	}

    /* returns pointer to result */
    return r;

    /* error return: pointer to dummy object */
    error:
    r=(f)((int)DU, (int)0, (INT)0);
    return r;
}


struct item * FAR PASCAL _export SUMMA(INT fn, int n, struct item **iptr)
{
    int i;
    struct item *p, *q, *r, *(FAR *f)(int, int, INT);

    /* check of arguments */
    if(n!=2) goto error;
	p=((struct nlist *)iptr[0])->itemp;
	q=((struct nlist *)iptr[1])->itemp;
	if(p==NULL||q==NULL) goto error;
	if(p->type!=DA||q->type!=DA) goto error;
	if(p->rank!=q->rank) goto error;
	if(p->size!=q->size) goto error;

    /* call of extern function (newdat) */
	f=fn;
    r=(f)((int)p->type,(int)p->rank,(INT)p->size);

    /* copying dimensions */
	for(i=0;i<r->rank;i++)
		r->dim[i]=p->dim[i];

    /* itemwise addition of arguments */
	for(i=0;i<r->size;i++)
		*(r->datap+i)=(*(p->datap+i))+(*(q->datap+i));

    /* returns pointer to result */
    return r;

    /* error return: pointer to dummy object */
    error:
    r=(f)((int)DU, (int)0, (INT)0);
    return r;
}


