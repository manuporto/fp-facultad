// parser.h

//PRE:	Parser no creado. El carácter separador es distinto del escape.
int parserCrear(TDA_Parser* tda,char* arch_par,char* arch_conf,char* arch_log);
/*POST:	Devuelve 1 si pudo crear el parser, y escribe en el log "parserCrear: 
 Parser creado exitosamente". No lee ninguna línea. Devuelve 0 en otro caso, y 
 escribe en el log "parserCrear: Error <descripción del error>". */

//PRE: Parser creado.
int parserDestruir(TDA_Parser* tda);
/*POST:	Devuelve 1 si pudo destruir el parser, y escribe en el log 
 "parserDestruir: Parser destruido". Devuelve 0 en otro caso, y escribe en el
  log "parserDestruir: Error <descripción del error>".*/
  
//PRE: Parser creado.
int parserSiguiente(TDA_Parser* tda);
/*POST:	Devuelve 1 si pudo obtener la siguiente línea, y escribe en el log 
 "parserSiguiente: Linea leida exitosamente". Devuelve 0 en otro caso (Fin de 
 archivo), y escribe en el log "parserSiguiente: Error <descripción del 
 error>".*/

//PRE:	Parser creado, se leyó al menos una línea.
int parserCantCampos(TDA_Parser* tda);
/*POST:	Devuelve la cantidad de campos de la línea (Los campos vacíos se 
 cuentan) , y escribe en el log "parserCantCampos: Cantidad de campos de la
  linea = <cantidad de campos>".*/
  
/*PRE:	Parser creado. La función parserSiguiente se ejecuto previamente sin
 error. El campo N existe en la línea actual.*/  
int parserCampo(TDA_Parser* tda, int n, char* valor);
/*POST:	Devuelve 1 si pudo obtener el valor del campo, y escribe en el log
 "parserCampo: Campo <n> obtenido exitosamente = "<valor>"".*/
 
 

