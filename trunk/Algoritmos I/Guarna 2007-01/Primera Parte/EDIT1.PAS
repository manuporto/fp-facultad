PROGRAM COMPILAR ;
uses crt;

const
    MAX_PASILLOS = 10;
    MAX_ESTANTES = 15;
    MAX_EJEMPLAR = 500;
    MAX_TITULO = 500;
    MAX_AUTOR = 500;
    MAX_GENERO = 7;
    MAX_TOTAL = 500;

	
	Type

Tr_Ejemplar = record
	Id_Ejemplar: Integer;
	Id_Titulo: Integer;
	Pasillo: byte;
	Estante: byte;
	Estado: Boolean
  end;
{* Se va a encargar de definir posición del ejemplar entre otras cosas*}

Tr_Titulo = record
	Id_Titulo: Integer;
	Nombre: String;
	Id_Autor: Integer;
	Id_Genero: Integer;
	Estado: Boolean
  end;

Tr_Autor = record
	Id_Autor: Integer;
	Nombre: String;
	Estado: Boolean
  end;

{* Los registro anteriores tienen definidos un "Estado" que no es más
   que un boolean para poder dar la baja lógica*}

Tr_Genero = record
	Id_Genero: Integer;
	Pasillo_Inicial: byte;
	Pasillo_Final: byte;
	Estante_Inicial: byte;
	Estante_Final: byte
  end;
{* Además de darle un Id al genero, indíca pasillo y estante, inicial y 
final entre los
   cuales está definido este *}

{* Vectores de los registros aneriores *}


Tv_Ejemplar = array [1..50] of Tr_Ejemplar;
Tv_Titulo =array [1..50] of Tr_Titulo;
Tv_Autor = array [1..50] of Tr_Autor;
Tv_Genero = array [1..50] of Tr_Genero;


FUNCTION POSICION_EJEMPLAR (ID:integer;EJEMPLAR:Tv_ejemplar;LONG_VECTOR:BYTE):INTEGER;

VAR
   I: BYTE;
   ENCONTRADO: BOOLEAN;

BEGIN
	  i:=1;
	  posicion_ejemplar:=-1;
    encontrado:=false;

	WHILE ((NOT ENCONTRADO) and (I<=LONG_VECTOR)) DO
        begin
		IF ID=Ejemplar[i].id_ejemplar then
			begin
				posicion_ejemplar:=i;
				encontrado:=true;
			end;
	i:=i+1
        end;
end;

FUNCTION POSICION_ID_TITULO (ID:integer;TITULO:Tv_titulo):integer;
	
	var 
		encontrado:boolean;
		i,j:byte;
		
		begin
			posicion_id_titulo:=-1;
			encontrado:=false;
                        i:=1;
	
	While ((not encontrado) AND (i<=MAX_GENERO)) do
		begin
			If titulo[i].id_titulo=id then
				begin
					posicion_id_titulo:=i;
					encontrado:=true;
				end;
			i:=i+1;
		end;
     end;
  Function pasillo_estante_valido (pas, est:byte; id_gen:integer; genero:Tv_genero):boolean;
 
 var 
		encontrado:boolean;
		i,j,k:byte;
    pasillo_inicio, pasillo_fin, estante_inicio, estante_fin:byte;
		
		begin

	While (not encontrado)  do
		begin
			If genero[i].id_genero=id_gen then
				begin
					pasillo_inicio:=genero[i].pasillo_inicial;
					pasillo_fin:=genero[i].pasillo_final;
					estante_inicio:=genero[i].estante_inicial;
					estante_fin:=genero[i].estante_final;
					encontrado:=true;
					j:=i;
				end;
			i:=i+1;
		end;
			
			encontrado:=false;
			
			i:=pasillo_inicio;
			k:=estante_inicio;

		while (((k<=estante_fin) or ((i<pasillo_fin)) and (not encontrado))) do
                			begin
		if ((pas =i) and (est=k))then
			encontrado:=true;
			K:=k+1;
			if k=15 then
				begin
					i:=i+1;
					k:=1;
			end;
			
		end;
                pasillo_estante_valido:=encontrado;
		end;


PROCEDURE INGRESO (VAR EJEMPLAR: TV_EJEMPLAR; VAR TITULO:TV_TITULO; VAR GENERO: TV_GENERO; var LONG_VECTOR:INTEGER);
var
   id:Byte;
   pasillo, estante:byte;

BEGIN
	
	Writeln ('Ingrese el ID de ejemplar que desea ingresar');
	Readln  (ID);

	While (POSICION_EJEMPLAR (ID,EJEMPLAR,LONG_VECTOR)<>-1) do
		Begin
			writeln;
			writeln;
		 	writeln ('El ID ingresado ya esta asignado a otro ejemplar');
		 	writeln;
		 	writeln ('Engrese nuevamente el ID');
		 	readln (id);	
		end;
		
		ejemplar[long_vector+1].id_ejemplar:=id;
		
		Writeln ('Ingrese el ID de Título');
		readln  (id);
		
			 while (POSICION_ID_TITULO (ID, TITULO)=-1) do
				begin
						writeln;
		 				writeln;
		 				writeln ('El ID ingresado no existe');
		 				writeln;
		 				writeln ('Engrese nuevamente el ID');
		 		end;

		 ejemplar[long_vector+1].id_titulo:=id;
		
		
		Writeln ('Ingrese el pasillo en el que desea ubicar el ejemplar');
		readln (pasillo);
		Writeln ('Ingrese el estante en el que desea ubicar el ejemplar');
		readln (estante);
		
				while (not pasillo_estante_valido (pasillo,estante,
                                          titulo[posicion_id_titulo (id, titulo)].id_genero,genero)) do
				begin
						writeln;
		 				writeln;
		 				writeln ('La ubicación no es válida');
		 				writeln;
		 				writeln ('Ingrese nuevamente el pasilloe n el que desea ubicar el ejemplar');
		 				readln  (pasillo);
		 				writeln;
		 				Writeln ('Ingrese el estante en el que desea ubicar el ejemplar');
					  readln  (estante);
					  writeln;
		 				
		 			end;

		 ejemplar[long_vector+1].pasillo:=pasillo;
		 ejemplar[long_vector+1].estante:=estante;
		 ejemplar[long_vector+1].estado:=true;
		 
		 long_vector:=long_vector+1;
		 
		 Writeln ('El ejemplar ha sido ingresado');
	end;
	
	 PROCEDURE EGRESO (var Ejemplar:tv_ejemplar; long_vector:integer);
                 var

                    id:integer;

		begin
		Writeln ('Ingrese el ID de ejemplar que desea egresar');
		readln (id);

		while (posicion_ejemplar  (id,ejemplar,long_vector)=-1)do
			begin
		 			writeln;
		 			writeln;
		 			writeln ('El ejemplar no existe');
		 			writeln;
		 			writeln ('Engrese nuevamente el ID del ejemplar');
		 			readln (id);	
		 	end;
		 	
		 	ejemplar[posicion_ejemplar (id,ejemplar,long_vector)].estado:=false;
                        ejemplar[posicion_ejemplar (id,ejemplar,long_vector)].id_ejemplar:=0;
	        end;

PROCEDURE MENU_INGRESO_EGRESO (var EJEMPLAR:Tv_ejemplar; var TITULO: Tv_titulo;
                               var GENERO: Tv_genero;var long_vector:integer);
var 
		a,num_operacion:byte;

															 
Begin
a:=1;

while a=1 do
begin

writeln; 
Writeln ('MENÚ INGRESO/EGRESO');
writeln;
writeln;
writeln;
writeln ('1 -  Ingreso');
writeln;
writeln ('2 -  Egreso');
writeln;
writeln;
write ('Elija una opción: ');
readln (num_operacion);

 		Case num_operacion of
  			1 : INGRESO ( EJEMPLAR, TITULO,GENERO, Long_VECTOR);

  			2 : EGRESO (EJEMPLAR,LOng_VECTOR);
		end;

                Writeln('Para volver al men£ INGRESOS/EGRESOS oprima 1');
                readln(a);
end;


END;


var
  v_ejemplar: Tv_ejemplar;
  v_titulo: Tv_titulo;
  v_genero: Tv_genero;
  largo_vector: integer;

BEGIN
     v_ejemplar[1].id_ejemplar:=2;
     v_titulo[1].id_titulo:=4;
     v_titulo[2].id_titulo:=3;
     v_titulo[3].id_titulo:=2;
     v_titulo[4].id_titulo:=7;
     v_titulo[5].id_titulo:=1;
     v_titulo[6].id_titulo:=6;
     v_titulo[7].id_titulo:=5;
     v_titulo[3].id_genero:=2;
     v_genero[1].id_genero:=2;
     v_genero[1].pasillo_inicial:=1;
     v_genero[1].pasillo_final:=2;
     v_genero[1].estante_inicial:=8;
     v_genero[1].estante_final:=3;

     largo_vector:=1;
     Menu_ingreso_egreso (v_ejemplar, v_titulo, v_genero, largo_vector)
end.
		

