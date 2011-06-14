/* Punto 1, inciso a */

typedef struct {
        int ID_emisor;
        int ID_receptor;
        char mensaje [20];
        } telemcola;

typedef struct {
        int ID_usuario;
        char alias[20];
        int cant_recibidos;
        int cant_entregados;
        TDA_Cola entrada;
        TDA_Cola salida;
        } telemarbol;

typedef struct {
        TDA_Arbol arbol;
        }TDA_Mensajero;


/* Punto 1, inciso b */



/* Punto 2 */

int AB_RAMA_MAYOR_PESO (TDA_AB ab, int *nodos) {
    return compara_pesos (peso(ab.raiz->izq),peso(ab.raiz->der),nodos); 
    }

int peso (TDA_AB *ab) {
    
    if (ab==NULL)
       return 0;
    else
        return (1+peso(p->izq)+peso(p->der));
    }

int compara_pesos (int a,int b,int *c){
    if (a > b ) {
       *cant = a;
       return -1;
       }

    else if (a=b) {
         *cant = b;
         return 0;
         }
         
         else {
              *cant = b;
              return 1;
              }
    }
         
