/* Punto 1, inciso a */

typedef struct {
        int padron;
        t_fecha aprobacion;
        int nota;
        } telemalumnos;

typedef struct {
        int materia;
        int anio;
        TDA_AB alumnos;
        } telemmaterias;

typedef struct {
        TDA_AB materias;
        } TDA_Materias;

/* Punto 1, inciso b */

TDA_cola cargar_aprobados (TDA_Materias ab, TDA_Cola cola){

    
    telemcola elem;
    TDA_Cola colaaux;

    c_sacar (*cola,*elem);
    



/* Punto 2, inciso a */

/* Definir un TDA ABO (Árbol binario Ordenado), el cual es en su estructura IGUAL al TDA AB
(NODOS), pero tiene en su estructura un puntero a una función de comparación que recibe
dos parámetros void y retorna -1 si el primero es menor al segundo elemento, 0 si son
iguales y 1 si el segundo es menor que el primero.
Dicha función sirve para comparar los elementos del ABO. */

typedef struct TNodoABO {
        void *elem;
        struct TNodoAB *izq, *der;
        } TNodoABO;

typedef struct {
        TNodoAB *raiz, *cte;
        int tamdato;
        int (*fcomp)(void *, void *);
        } TDA_ABO;


/* Punto 2, inciso b */

/* Desarrollar la primitiva de TDA ABO “Borrar_por_rango”, que recibe por parámetro un
árbol ordenado (TDA ABO) y dos punteros a void (elem_dde y elem_hta) y elimina de la
estructura los elementos cuyas claves estén comprendidas entre elem_dde y elem_hta.
Estos elementos (elem_dde y elem_hta) pueden no estar en el ABO. Para comparar las
claves DEBE UTILIZARSE LA FUNCIÓN DE COMPARACION definida en el TDA_ABO.
Pre: Arbol creado. Definir post Para optimizar la implementación, NO se pueden usar otras
primitivas del tipo ni estructuras auxiliares y se debe recorre una sola vez el ABO*/

int Borrar_por_rango (TDA_ABO abo, void* elem_dde, void* elem_hta) {
    
    
    
