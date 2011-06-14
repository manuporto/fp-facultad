typedef enum {PARCIAL,FINAL,TP} tTipoExamen;

typedef struct {
	double lista[30];
	}tNotas;

typedef struct {
	char alumno[28];
	short tiempo;
	tTipoExamen tipo;
	union {
		char entera;
		double decimal;
	}nota;
	char totalpuntos;
	tNotas puntajes;
}tExamen;

int main (int a, char **b){
	tExamen tp1,final1,final2;
	printf ("tExamen mide %d\nEl resultado es %d\n",sizeof(tExamen),(long)(&(final1.nota.entera))-(long)(&final1));
	return 0;
}