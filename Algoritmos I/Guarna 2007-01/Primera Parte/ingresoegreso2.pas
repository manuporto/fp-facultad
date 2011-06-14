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
        nombre: String;
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
END;

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
	                clrscr;
                        writeln;
			Writeln ('Ingrese el ID de ejemplar que desea ingresar');
                        Writeln;
			Readln  (ID);

			While (POSICION_EJEMPLAR (ID,EJEMPLAR,LONG_VECTOR)<>-1) do
				Begin
                                        clrscr;
					writeln;
					writeln;
		 			writeln ('El ID ingresado ya esta asignado a otro ejemplar');
		 			writeln;
		 			writeln ('Engrese nuevamente el ID');
		 			readln (id);	
				end;
		
			ejemplar[long_vector+1].id_ejemplar:=id;
		        clrscr;
                        writeln;
			Writeln ('Ingrese el ID de Título');
                        Writeln;
			readln  (id);
		
			while (POSICION_ID_TITULO (ID, TITULO)=-1) do
				begin
                                        clrscr;
					writeln;
		 			writeln;
		 			writeln ('El ID ingresado no existe');
		 			writeln;
		 			writeln ('Engrese nuevamente el ID');
		 		end;

		 	ejemplar[long_vector+1].id_titulo:=id;

                        clrscr;
                        writeln;
			Writeln ('Ingrese el pasillo en el que desea ubicar el ejemplar');
			writeln;
                        readln (pasillo);
                        clrscr;
                        Writeln;
			Writeln ('Ingrese el estante en el que desea ubicar el ejemplar');
			Writeln;
                        readln (estante);
		
			while (not pasillo_estante_valido (pasillo,estante,titulo[posicion_id_titulo (id, titulo)].id_genero,genero)) do
					
					begin
                                                clrscr;
		 				writeln;
		 				writeln ('La ubicación no es válida');
		 				writeln;
		 				writeln ('Ingrese nuevamente el pasilloe n el que desea ubicar el ejemplar');
		 				Writeln;
                                                readln  (pasillo);
		 				writeln;
		 				Writeln ('Ingrese el estante en el que desea ubicar el ejemplar');
					        writeln;
                                                readln  (estante);
					        writeln;
		 			end;

		 	ejemplar[long_vector+1].pasillo:=pasillo;
		 	ejemplar[long_vector+1].estante:=estante;
		 	ejemplar[long_vector+1].estado:=true;
		 
		 	long_vector:=long_vector+1;
		 
		 	Writeln ('El ejemplar ha sido ingresado');
		
		END;
	
	 PROCEDURE EGRESO (var Ejemplar:tv_ejemplar; long_vector:integer);
   		var
   			id:integer;

			begin
				clrscr;
                                writeln;
				Writeln ('Ingrese el ID de ejemplar que desea egresar');
				Writeln;
                                readln (id);

				while (posicion_ejemplar  (id,ejemplar,long_vector)=-1)do
					
					begin   clrscr;
		 				writeln;
		 				writeln ('El ejemplar no existe');
		 				writeln;
		 				writeln ('Engrese nuevamente el ID del ejemplar');
		 				writeln;
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

	while a<>3 do
		
		begin
			writeln;
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

      Writeln('Para volver al men£ INGRESOS/EGRESOS oprima cualquier tecla');
     	readln(a);
		end;


	END;

PROCEDURE INICIALIZAR_GENERO (var V_GENERO : tv_genero);

	Begin
	
		with v_genero[1] do
			begin
				id_genero				:= 1;
				nombre					:='Novela';
				pasillo_inicial	:= 1;
				estante_inicial	:= 1;
				pasillo_final		:= 2;
				estante_final		:= 10
			end;
		
		with v_genero[2] do
			begin
				id_genero				:= 2;
				nombre					:='Ensayo';
				pasillo_inicial	:= 2;
				estante_inicial	:= 11;
				pasillo_final		:= 4;
				estante_final		:= 2
			end;

		with v_genero[3] do
			begin
				id_genero				:= 3;
				nombre					:='Ciencia';
				pasillo_inicial	:= 4;
				estante_inicial	:= 3;
				pasillo_final		:= 6;
				estante_final		:= 9
			end;
			

		with v_genero[4] do
			begin
				id_genero				:= 4;
				nombre					:='Humanidades';
				pasillo_inicial	:= 6;
				estante_inicial	:= 10;
				pasillo_final		:= 7;
				estante_final		:= 13
			end;


		with v_genero[5] do
			begin
				id_genero				:= 5;
				nombre					:='Infantil';
				pasillo_inicial	:= 7;
				estante_inicial	:= 14;
				pasillo_final		:= 8;
				estante_final		:= 8
			end;


		with v_genero[6] do
			begin
				id_genero				:= 6;
				nombre					:='Diccionarios';
				pasillo_inicial	:= 8;
				estante_inicial	:= 9;
				pasillo_final		:= 9;
				estante_final		:= 11
			end;


		with v_genero[7] do
			begin
				id_genero				:= 7;
				nombre					:='Otros';
				pasillo_inicial	:= 9;
				estante_inicial	:= 12;
				pasillo_final		:= 10;
				estante_final		:= 15
			end;
	
	End;

PROCEDURE INICIALIZAR_TITULO (var V_TITULO : tv_titulo);

	Begin
	
		with v_titulo[1] do
			begin
				id_titulo				:= 1;
				nombre					:='La';
				id_genero				:= 2;
			end;
		
		with v_titulo[2] do
			begin
				id_titulo				:= 2;
				nombre					:='Lala';
				id_genero				:= 3;
			end;
	
		with v_titulo[3] do
			begin
				id_titulo				:= 3;
				nombre					:='Lalala';
				id_genero				:= 4;
			end;
	
		with v_titulo[4] do
			begin
				id_titulo				:= 4;
				nombre					:='Lalalala';
				id_genero				:= 5;
		 end;
	
		with v_titulo[5] do
			begin
				id_titulo				:= 5;
				nombre					:='Lalalalala';
				id_genero				:= 6;
			end;
	End;


	var
  	v_ejemplar: Tv_ejemplar;
  	v_titulo: Tv_titulo;
  	v_genero: Tv_genero;
  	largo_vector: integer;

	BEGIN

		inicializar_genero (v_genero);
   	Inicializar_titulo (v_titulo);
   	largo_vector:=1;
    
    Menu_ingreso_egreso (v_ejemplar, v_titulo, v_genero, largo_vector)
	
END.
		

