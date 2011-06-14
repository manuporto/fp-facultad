	PROGRAM COMPILAR ;
	
	Type

Tr_Ejemplar = record
	Id_Ejemplar: Integer;
	Id_Titulo: Integer;
	Pasillo: byte;
	Estante: byte;
	Etado: Boolean
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
var
largo_vector: integer;

	
	Function posicion_ejemplar  (id:integer;v_ejemplar:Tv_ejemplar; largo_vector:integer):integer;
	var 
		encontrado:boolean;
		i:byte;
		
		begin
			posicion_ejemplar:=-1;	
	
	While( not encontrado or (i<largo_vector)) do
		begin
			If v_ejemplar[i].id_ejemplar=id then
				begin
					posicion_ejemplar:=i;
					encontrado:=true;
				end;
			i:=i+1;
		end;
                end;
		
	
	Function posicion_id_titulo (id:integer;v_titulo:Tv_titulo; largo_vector:integer):integer;
	
	var 
		encontrado:boolean;
		i,j:byte;
		
		begin
			posicion_id_titulo:=-1;
	
	While (not encontrado or (i<largo_vector)) do
		begin
			If v_titulo[i].id_titulo=id then
				begin
					posicion_id_titulo:=i;
					encontrado:=true;
				end;
			i:=i+1;
		end;
                end;

		
	
 Function pasillo_estante_valido (id_gen:integer; v_genero:Tv_genero):boolean;
 
 var 
		encontrado:boolean;
		i,j,k,pas,est:byte;
                pasillo_inicio, pasillo_fin, estante_inicio, estante_fin:byte;
		
		begin

	While not encontrado  do
		begin
			If v_genero[i].id_genero=id_gen then
				begin
					pasillo_inicio:=v_genero[i].pasillo_inicial;
					pasillo_fin:=v_genero[i].pasillo_final;
					estante_inicio:=v_genero[i].estante_inicial;
					estante_fin:=v_genero[i].estante_final;
					encontrado:=true;
					j:=i;
				end;
			i:=i+1;
		end;
			
			encontrado:=false;
			
			i:=0;
			k:=0;
		
		while (((k<=estante_fin) or ((i<=pasillo_fin)) and (not encontrado))) do
                			begin
		if (pas =(pasillo_inicio+i)) and (est=(estante_inicio+k))then
			encontrado:=true;
			K:=k+1;
			if k=15 then
				begin
					i:=i+1;
					k:=0;
			end;
			
		end;
		end;
    
		
		
 

	


PROCEDURE INGRESO (var v_Ejemplar: Tv_ejemplar; var v_TITULO: Tv_titulo;
									 var v_GENERO: Tv_genero; var largo_vecto:integer);
var 

		posicion,id:integer;
                num_pasillo,num_estante,pasillo, estante:byte;

Begin
		
		
		Writeln ('Ingrese el ID de ejemplar que desea ingresar');
		readln (id);
		
		while (posicion_ejemplar  (id,v_ejemplar,largo_vector)<>-1) do
			begin
		 			writeln;
		 			writeln;
		 			writeln ('El ID ingresado ya esta asignado a otro ejemplar');
		 			writeln;
		 			writeln ('Engrese nuevamente el ID');
		 			readln (id);	
		 	end;
				
		v_ejemplar[largo_vector+1].id_ejemplar:=id;
						
		
		Writeln ('Ingrese el ID de T¡tulo');
		readln  (id);
				
				
			 while (posicion_id_titulo (id, v_titulo,largo_vector)=-1) do
				begin
						writeln;
		 				writeln;
		 				writeln ('El ID ingresado no existe');
		 				writeln;
		 				writeln ('Engrese nuevamente el ID');
		 		end;
		 		
		 v_ejemplar[largo_vector+1].id_titulo:=id;

		Writeln ('Ingrese el pasillo en el que desea ubicar el ejemplar');
		readln (pasillo);
		
		Writeln ('Ingrese el estante en el que desea ubicar el ejemplar');
		readln (estante);
		
				while not pasillo_estante_valido ( v_titulo[posicion_id_titulo (id, v_titulo,largo_vector)].id_genero,v_genero) do
				begin
						writeln;
		 				writeln;
		 				writeln ('La ubicación no es válida');
		 				writeln;
		 				writeln ('Ingrese nuevamente el pasilloe n el que desea ubicar el ejemplar');
		 				readln  (num_pasillo);
		 				writeln;
		 				Writeln ('Ingrese el estante en el que desea ubicar el ejemplar');
					  readln  (num_estante);
					  writeln;
		 				
		 			end;
		 			
		 v_ejemplar[largo_vector+1].pasillo:=num_pasillo;
		 v_ejemplar[largo_vector+1].estante:=num_estante;
		 {v_ejemplar[largo_vector+1].estado:=true;}
		 
		 largo_vector:=largo_vector+1;				 
		 
		 Writeln ('El ejemplar ha sido ingresado');	 		
	end;
		 
		 PROCEDURE EGRESO (var v_Ejemplar:tv_ejemplar; largo_vector:integer);
                 var

                    id:integer;

		begin
		Writeln ('Ingrese el ID de ejemplar que desea egresar');
		readln (id);
		
		while (posicion_ejemplar  (id,v_ejemplar,largo_vector)=-1)do
			begin
		 			writeln;
		 			writeln;
		 			writeln ('El ejemplar no existe');
		 			writeln;
		 			writeln ('Engrese nuevamente el ID del ejemplar');
		 			readln (id);	
		 	end;
		 	
		 	{v_ejemplar[posicion_ejemplar (id,v_ejemplar,largo_vector)].estado:=false;}
	        end;
					
PROCEDURE MENU_INGRESO_EGRESO (var EJEMPLAR:Tv_ejemplar; var TITULO: Tv_titulo;
                               var GENERO: Tv_genero;var largo_vector:integer);
var 
		num_operacion:byte;
															 
Begin



writeln; 
Writeln ('MENé INGRESO/EGRESO');
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
  1 : INGRESO ( EJEMPLAR, TITULO,genero, largo_vector);

  2 : EGRESO (EJEMPLAR,largo_vector);
end;


end;

var ejemplar:Tv_ejemplar;
    titulo:Tv_titulo;
    genero: Tv_genero;

Begin
	
	menu_ingreso_egreso (ejemplar, titulo,genero, largo_vector)
end.



