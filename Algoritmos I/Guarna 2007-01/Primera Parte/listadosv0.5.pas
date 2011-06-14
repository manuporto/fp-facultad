{Changelog

v0.5 - Agregados todos los procedimientos de ordenamiento
v0.4 - Listos los Procedimientos de listado por autores y géneros

}

{

á -  
é - ‚
í - ¡
ó - ¢
ú - £

Á - µ
É - 
Í - Ö
Ó - O
Ú - é

ñ - ¤
Ñ - ¥

¿ - ¨
¡ - ­

}


{
1.- Listado por Autor		[DONE]
2.- Listado por Género	[DONE]
3.- Listado por Título
4.- Listado individual
5.- Ordenar
}
Program Listados_TP;

uses crt;

Const
	MAX_PASILLOS	=	10;
	MAX_ESTANTES	=	15;
	MAX_EJEMPLAR	= 500;
	MAX_TITULO 		= 500;
	MAX_AUTOR			= 500;
	MAX_GENERO		=	7;
	MAX_TOTAL			=	500;
	

Type

	Tr_Ejemplar = record
		Id_Ejemplar	: Integer;
		Id_Titulo		: Integer;
		Pasillo			: byte;
		Estante			: byte;
		Estado			: Boolean
  end;
{* Se va a encargar de definir posición del ejemplar entre otras cosas*}

	Tr_Titulo = record
		Id_Titulo		: Integer;
		Nombre			: String;
		Id_Autor		: Integer;
		Id_Genero		: Integer;
		Estado			: Boolean
  end;

	Tr_Autor = record
		Id_Autor		: Integer;
		Nombre			: String;
		Estado			: Boolean
  end;

{* Los registro anteriores tienen definidos un "Estado" que no es más que un boolean para poder dar la baja lógica*}

	Tr_Genero = record
		Id_Genero				: Integer;
		Nombre					:	string [20];
		Pasillo_Inicial	: byte;
		Estante_Inicial	: byte;
		Pasillo_Final		: byte;
		Estante_Final		: byte
  end;
{* Además de darle un Id al genero, indíca pasillo y estante, inicial y final entre los cuales está definido este *}

{* Vectores de los registros aneriores *}
	Tv_Ejemplar = array [1..MAX_EJEMPLAR]	of Tr_Ejemplar;
	Tv_Titulo 	= array [1..MAX_TITULO]		of Tr_Titulo;
	Tv_Autor 		= array [1..MAX_AUTOR]		of Tr_Autor;
	Tv_Genero 	= array [1..MAX_GENERO]		of Tr_Genero;
	Tv_Listados = array [1..MAX_TOTAL]		of String;

Procedure Inicializar_autor (var v_autor : tv_autor; var largo_autor : integer);

Begin
	v_autor[1].id_autor		:=1;
	v_autor[1].nombre			:='Bla bla';
	v_autor[1].estado			:= true;

	v_autor[2].id_autor		:=2;
	v_autor[2].nombre			:='Juan Pablo';
	v_autor[2].estado			:= true;

	v_autor[3].id_autor		:=3;
	v_autor[3].nombre			:='Roberto G¢mez';
	v_autor[3].estado			:= true;

	v_autor[4].id_autor		:=4;
	v_autor[4].nombre			:='Pedro Pablo';
	v_autor[4].estado			:= true;

	v_autor[5].id_autor		:=5;
	v_autor[5].nombre			:='Pl cido Domingo';
	v_autor[5].estado			:= true;

	v_autor[6].id_autor		:=6;
	v_autor[6].nombre			:='Ra£l Gomez';
	v_autor[6].estado			:= true;

	v_autor[7].id_autor		:=7;
	v_autor[7].nombre			:='Don Torcuato';
	v_autor[7].estado			:= true;

	v_autor[8].id_autor		:=8;
	v_autor[8].nombre			:='Dado de baja';
	v_autor[8].estado			:= false;

	v_autor[9].id_autor		:=9;
	v_autor[9].nombre			:='John Hopkins';
	v_autor[9].estado			:= true;

	v_autor[10].id_autor	:=10;
	v_autor[10].nombre		:='Lula da Silva';
	v_autor[10].estado		:= true;

	v_autor[11].id_autor	:=11;
	v_autor[11].nombre		:='Peter Crouch';
	v_autor[11].estado		:= true;

	v_autor[12].id_autor	:=12;
	v_autor[12].nombre		:='Baldomero';
	v_autor[12].estado		:= true;
	 
	v_autor[13].id_autor	:=13;
	v_autor[13].nombre		:='Random Guy';
	v_autor[13].estado		:= true;

	v_autor[14].id_autor	:=14;
	v_autor[14].nombre		:='Pablo Picasso';
	v_autor[14].estado		:= true;

	v_autor[15].id_autor	:=15;
	v_autor[15].nombre		:='Ernest Hemingway';
	v_autor[15].estado		:= true;

	v_autor[16].id_autor	:=16;
	v_autor[16].nombre		:='Homero Simpson';
	v_autor[16].estado		:= true;

	v_autor[17].id_autor	:=17;
	v_autor[17].nombre		:='Dado de baja';
	v_autor[17].estado		:= false;

	v_autor[18].id_autor	:=18;
	v_autor[18].nombre		:='Dado de baja';
	v_autor[18].estado		:= false;

	v_autor[19].id_autor	:=19;
	v_autor[19].nombre		:='Ludovica Squirru';
	v_autor[19].estado		:= true;

	v_autor[20].id_autor	:=20;
	v_autor[20].nombre		:='Roger Federer';
	v_autor[20].estado		:= true;

	v_autor[21].id_autor	:=21;
	v_autor[21].nombre		:='Peter Griffin';
	v_autor[21].estado		:= true;

	v_autor[22].id_autor	:=22;
	v_autor[22].nombre		:='Alessandra Tu Sex¢loga';
	v_autor[22].estado		:= true;

	v_autor[23].id_autor	:=23;
	v_autor[23].nombre		:='Horangel';
	v_autor[23].estado		:= true;

	v_autor[24].id_autor	:=24;
	v_autor[24].nombre		:='Donatello';
	v_autor[24].estado		:= true;

	v_autor[25].id_autor	:=25;
	v_autor[25].nombre		:='Domino Harvey';
	v_autor[25].estado		:= false;

	v_autor[26].id_autor	:=26;
	v_autor[26].nombre		:='Atahualpa Yupanqui';
	v_autor[26].estado		:= true;

	largo_autor := 26
End;

Procedure Inicializar_genero (var v_genero : tv_genero);

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
		end
	
End;

{Visualización de datos: Se deberá contar con la opción de visualizar listados completos
de Géneros, Autores y Títulos, por pantalla, ordenados por número (los listados deben
ser claros y prolijos, con datos encolumnados y alineados, y deben contar con pausa por
pantalla cuando ésta se llena).
También debe contar con la visualización individual (por código) de los datos completos,
tanto para un género literario como para un título o un autor.}

Procedure Ordenar_ejemplares (var v_ejemplar : tv_ejemplar; tipo,largo_ejemplar : byte);
var 
	i,j : integer;
	aux : tr_ejemplar;
	
Begin
	
	if tipo = 1 then
		for i:=1 to (largo_ejemplar-1) do
			for j:=1 to (largo_ejemplar-i) do
				if (v_ejemplar[j].id_ejemplar > v_ejemplar[j+1].id_ejemplar) then 
					begin
						aux := v_ejemplar[j];
						v_ejemplar[j]:= v_ejemplar[j+1];
						v_ejemplar[j+1]:= aux
					end;

	if tipo = 2 then
		for i:=1 to (largo_ejemplar-1) do
			for j:=1 to (largo_ejemplar-i) do
				if (v_ejemplar[j].id_titulo > v_ejemplar[j+1].id_titulo) then
					begin
						aux := v_ejemplar[j];
						v_ejemplar[j]:= v_ejemplar[j+1];
						v_ejemplar[j+1]:= aux
					end


End;


Procedure Ordenar_autor (var v_autor : tv_autor; tipo,largo_autor : byte);
var 
	i,j : integer;
	aux : tr_autor;
	
Begin
	
	if tipo = 1 then
		for i:=1 to (largo_autor-1) do
			for j:=1 to (largo_autor-i) do
				if (v_autor[j].id_autor > v_autor[j+1].id_autor) then 
					begin
						aux := v_autor[j];
						v_autor[j]:= v_autor[j+1];
						v_autor[j+1]:= aux
					end;

	if tipo = 2 then
		for i:=1 to (largo_autor-1) do
			for j:=1 to (largo_autor-i) do
				if (v_autor[j].nombre > v_autor[j+1].nombre) then
					begin
						aux := v_autor[j];
						v_autor[j]:= v_autor[j+1];
						v_autor[j+1]:= aux
					end

End;


Procedure Ordenar_genero (var v_genero : tv_genero; tipo : byte);
var 
	i,j : integer;
	aux : tr_genero;
	
Begin
	
	if tipo = 1 then
		for i:=1 to (MAX_GENERO-1) do
			for j:=1 to (MAX_GENERO-i) do
				if (v_genero[j].id_genero > v_genero[j+1].id_genero) then 
					begin
						aux := v_genero[j];
						v_genero[j]:= v_genero[j+1];
						v_genero[j+1]:= aux
					end;
		
	if tipo = 2 then
		for i:=1 to (MAX_GENERO-1) do
			for j:=1 to (MAX_GENERO-i) do
				if (v_genero[j].nombre > v_genero[j+1].nombre) then
					begin
						aux := v_genero[j];
						v_genero[j]:= v_genero[j+1];
						v_genero[j+1]:= aux
					end

End;

Procedure Ordenar_titulo (var v_titulo : tv_titulo; tipo,largo_titulo : byte);
var 
	i,j : integer;
	aux : tr_titulo;
	
Begin
	
	if tipo = 1 then
		for i:=1 to (largo_titulo-1) do
			for j:=1 to (largo_titulo-i) do
				if (v_titulo[j].id_titulo > v_titulo[j+1].id_titulo) then 
					begin
						aux := v_titulo[j];
						v_titulo[j]:= v_titulo[j+1];
						v_titulo[j+1]:= aux
					end;
		
	if tipo = 2 then
		for i:=1 to (largo_titulo-1) do
			for j:=1 to (largo_titulo-i) do
				if (v_titulo[j].nombre > v_titulo[j+1].nombre) then
					begin
						aux := v_titulo[j];
						v_titulo[j]:= v_titulo[j+1];
						v_titulo[j+1]:= aux
					end;

	if tipo = 3 then
		for i:=1 to (largo_titulo-1) do
			for j:=1 to (largo_titulo-i) do
				if (v_titulo[j].id_autor > v_titulo[j+1].id_autor) then 
					begin
						aux := v_titulo[j];
						v_titulo[j]:= v_titulo[j+1];
						v_titulo[j+1]:= aux
					end;

	if tipo = 4 then
		for i:=1 to (largo_titulo-1) do
			for j:=1 to (largo_titulo-i) do
				if (v_titulo[j].id_genero > v_titulo[j+1].id_genero) then 
					begin
						aux := v_titulo[j];
						v_titulo[j]:= v_titulo[j+1];
						v_titulo[j+1]:= aux
					end

{En vez de los cuatro IFs se podría hacer con un CASE, pero en los CASE me parece que queda
desprolijo si se usa código de más de una línea}

End;


{Procedure Listado_titulos (var v_titulo : tv_titulo; largo_titulo : integer);
var
Begin
	ClrScr;
	for i:=1 to largo_titulo do
		v_titulo[i].	
	
	
End.}

Procedure Listado_autores (v_autor : tv_autor; largo_autor : integer);
var
	i,j : integer;
Begin
	
	Ordenar_autor (v_autor,1,largo_autor);
	j := 1;
	ClrScr;
	write ('ID       Nombre');
	for i:=1 to largo_autor do
		with v_autor[i] do
			if estado = true then {Lo lista sólo si el estado es verdadero, o sea, si existe}
				begin
					if (j mod 22) = 0 then 
						begin
							writeln;
							writeln;
							write ('Presione una tecla para continuar... ');
							readkey;
							ClrScr;
							writeln ('ID       Nombre');
							inc (j) {Este incrementar es para dejar un espacio entre el encabezado y el listado a partir de la segunda vez que se lista}
						end;
					gotoxy (1,(j mod 22) +2);
					write (id_autor:2);
					gotoxy (10,(j mod 22) +2);
					write (nombre);
					inc(j)	
				end;
	writeln;
	writeln;
	write ('Presione una tecla para volver al men£...');
	readkey;
End;


Procedure Listado_generos (v_genero : tv_genero);
var
	i : integer;
Begin
	ClrScr;
	
	write ('ID       Nombre              Inicio              Fin');
	for i:=1 to MAX_GENERO do
		with v_genero[i] do
		begin
			gotoxy (1,i+2);
			write (id_genero);
			gotoxy (10,i+2);
			write (nombre);
			gotoxy (30,i+2);
			write ('P:',pasillo_inicial:2,' E:',estante_inicial:2);
			gotoxy (50,i+2);
			write ('P:',pasillo_final:2,' E:',estante_final:2)
		end;
	writeln;
	writeln;
	write ('Presione una tecla para volver al men£...');
	readkey			
End;

Procedure Menu_listados (var v_titulo : tv_titulo; var v_autor : tv_autor; var v_genero : tv_genero; largo_titulo, largo_autor, largo_ejemplar : integer);

var
	opt:byte;

Begin
	repeat
		ClrScr;
		writeln ('Men£ Listados');
		writeln ('-------------');
		writeln;
		writeln;
		writeln ('1.- Listado de t¡tulos');
		writeln;
		writeln ('2.- Listado de autores');
		writeln;
		writeln ('3.- Listado de g‚neros');
		writeln;
		writeln ('4.- Salir del men£ listados');
		writeln;
		write ('Elija una opci¢n: ');
		{$I-}
		readln (opt);
		{$I+}	
		if IOResult <> 0 then
			begin
				writeln ('Ingrese s¢lo n£meros por favor.');
				write ('Presione una tecla para ingresar nuevamente');
				readkey;
				opt:=0 {Para que vuelva al menú}
			end;
		
		
		case opt of
{			1: listado_titulos (v_titulo);}
			2: listado_autores (v_autor,largo_autor);
			3: listado_generos (v_genero)
		end;
		
	until opt=4 {o until (opt <= 4) and (opt > 0) para que salga después de listar}

End;

{Procedure listado_individual ( );}

var
	v_genero	:	tv_genero;
	v_autor		:	tv_autor;
	v_titulo	:	tv_titulo;
	largo_titulo,largo_autor,largo_ejemplar	:	integer;

BEGIN
	Inicializar_genero (v_genero);
	Inicializar_autor (v_autor,largo_autor);
	Menu_listados (v_titulo, v_autor, v_genero, largo_titulo, largo_autor, largo_ejemplar)

END.