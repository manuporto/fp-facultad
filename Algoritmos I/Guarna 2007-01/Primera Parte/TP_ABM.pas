Program TP;

{ * * *  D E C L A R A C I O N E S  * * * }

uses CRT;


const
	MAX_PASILLOS	= 10;
	MAX_ESTANTES	= 15;
	MAX_EJEMPLAR	= 200;
	MAX_TITULO 	= 200;
	MAX_AUTOR	= 200;
	MAX_GENERO	= 7;


type

	tr_ejemplar = record
		id_ejemplar	: integer;
		id_titulo	: integer;
		pasillo		: integer;
		estante		: integer;
		estado		: boolean
  	end;

	tr_titulo = record
		id_titulo	: integer;
		nombre		: string;
		id_autor	: integer;
		id_genero	: integer;
		estado		: boolean
	end;

	tr_autor = record
		id_autor	: integer;
		nombre		: string [30];
		estado		: boolean
	end;


	tr_genero = record
		id_genero	: integer;
		nombre		: string [30];
		pasillo_inicial	: byte;
		estante_inicial	: byte;
		pasillo_final	: byte;
		estante_final	: byte
	end;

	tv_ejemplar = array [1..MAX_EJEMPLAR]	of tr_ejemplar;
	tv_titulo   = array [1..MAX_TITULO]	of tr_titulo;
	tv_autor    = array [1..MAX_AUTOR]	of tr_autor;
	tv_genero   = array [1..MAX_GENERO]	of tr_genero;


{ * * *  / D E C L A R A C I O N E S  * * * }



{ * * *  I N I C I A L I Z A C I O N E S  * * *  }


Procedure Inicializar_ejemplar(var vec : TV_ejemplar; var largo : integer);
var
	I : integer;

Begin
	i:=1;
	vec[i].id_titulo:=1;
	vec[i].estante:=9;
	vec[i].id_ejemplar:=1;
	vec[i].Pasillo:=1;
	vec[i].estado:=true;

	i:=2;
	vec[i].id_titulo:=4;
	vec[i].estante:=3;
	vec[i].id_ejemplar:=1266;
	vec[i].Pasillo:=2;
	vec[i].estado:=False;

	i:=3;
	vec[i].id_titulo:=3;
	vec[i].estante:=9;
	vec[i].id_ejemplar:=1452;
	vec[i].Pasillo:=3;
	vec[i].estado:=true;

	i:=4;
	vec[i].id_titulo:=5;
	vec[i].estante:=10;
	vec[i].id_ejemplar:=1237;
	vec[i].Pasillo:=5;
	vec[i].estado:=true;

	i:=5;
	vec[i].id_titulo:=1;
	vec[i].estante:=1;
	vec[i].id_ejemplar:=145;
	vec[i].Pasillo:=4;
	vec[i].estado:=true;

	i:=6;
	vec[i].id_titulo:=7;
	vec[i].estante:=1;
	vec[i].id_ejemplar:=1236;
	vec[i].Pasillo:=3;
	vec[i].estado:=true;

	i:=7;
	vec[i].id_titulo:=4;
	vec[i].estante:=11;
	vec[i].id_ejemplar:=7;
	vec[i].Pasillo:=10;
	vec[i].estado:=true;

	i:=8;
	vec[i].id_titulo:=3;
	vec[i].estante:=4;
	vec[i].id_ejemplar:=8;
	vec[i].Pasillo:=9;
	vec[i].estado:=true;


	i:=9;
	vec[i].id_titulo:=4;
	vec[i].estante:=5;
	vec[i].id_ejemplar:=9;
	vec[i].Pasillo:=7;
	vec[i].estado:=true;


	i:=10;
	vec[i].id_titulo:=3;
	vec[i].estante:=1;
	vec[i].id_ejemplar:=10;
	vec[i].Pasillo:=6;
	vec[i].estado:=true;


	i:=11;
	vec[i].id_titulo:=1;
	vec[i].estante:=1;
	vec[i].id_ejemplar:=11;
	vec[i].Pasillo:=7;
	vec[i].estado:=true;


	i:=12;
	vec[i].id_titulo:=8;
	vec[i].estante:=3;
	vec[i].id_ejemplar:=12;
	vec[i].Pasillo:=2;
	vec[i].estado:=true;

	i:=13;
	vec[i].id_titulo:=5;
	vec[i].estante:=9;
	vec[i].id_ejemplar:=1536;
	vec[i].Pasillo:=3;
	vec[i].estado:=true;


	largo:=i
end;


procedure Inicializar_autor (var v_autor : tv_autor; var largo_autor : integer);

Begin
	v_autor[1].id_autor	:= 1;
	v_autor[1].nombre	:= 'Bla bla';
	v_autor[1].estado	:= true;

	v_autor[2].id_autor	:= 2;
	v_autor[2].nombre	:= 'Juan Pablo';
	v_autor[2].estado	:= true;

	v_autor[3].id_autor	:= 3;
	v_autor[3].nombre	:= 'Roberto G¢mez';
	v_autor[3].estado	:= true;

	v_autor[4].id_autor	:= 4;
	v_autor[4].nombre	:= 'Pedro Pablo';
	v_autor[4].estado	:= true;

	v_autor[5].id_autor	:= 5;
	v_autor[5].nombre	:= 'Pl cido Domingo';
	v_autor[5].estado	:= true;

	v_autor[6].id_autor	:= 6;
	v_autor[6].nombre	:= 'Ra£l Gomez';
	v_autor[6].estado	:= true;

	v_autor[7].id_autor	:= 7;
	v_autor[7].nombre	:= 'Don Torcuato';
	v_autor[7].estado	:= true;

	v_autor[8].id_autor	:= 8;
	v_autor[8].nombre	:= 'Dado de baja';
	v_autor[8].estado	:= false;

	v_autor[9].id_autor	:= 9;
	v_autor[9].nombre	:= 'John Hopkins';
	v_autor[9].estado	:= true;

	v_autor[10].id_autor	:= 10;
	v_autor[10].nombre	:= 'Lula da Silva';
	v_autor[10].estado	:= true;

	v_autor[11].id_autor	:= 11;
	v_autor[11].nombre	:= 'Peter Crouch';
	v_autor[11].estado	:= true;

	v_autor[12].id_autor	:= 12;
	v_autor[12].nombre	:= 'Baldomero';
	v_autor[12].estado	:= true;
	
	v_autor[13].id_autor	:= 13;
	v_autor[13].nombre	:= 'Random Guy';
	v_autor[13].estado	:= true;

	v_autor[14].id_autor	:= 14;
	v_autor[14].nombre	:= 'Pablo Picasso';
	v_autor[14].estado	:= true;

	v_autor[15].id_autor	:= 15;
	v_autor[15].nombre	:= 'Ernest Hemingway';
	v_autor[15].estado	:= true;

	v_autor[16].id_autor	:= 16;
	v_autor[16].nombre	:= 'Homero Simpson';
	v_autor[16].estado	:= true;

	v_autor[17].id_autor	:= 17;
	v_autor[17].nombre	:= 'Dado de baja';
	v_autor[17].estado	:= false;

	v_autor[18].id_autor	:= 18;
	v_autor[18].nombre	:= 'Dado de baja';
	v_autor[18].estado	:= false;

	v_autor[19].id_autor	:= 19;
	v_autor[19].nombre	:= 'Ludovica Squirru';
	v_autor[19].estado	:= true;

	v_autor[20].id_autor	:= 20;
	v_autor[20].nombre	:= 'Roger Federer';
	v_autor[20].estado	:= true;

	v_autor[21].id_autor	:= 21;
	v_autor[21].nombre	:= 'Peter Griffin';
	v_autor[21].estado	:= true;

	v_autor[22].id_autor	:= 22;
	v_autor[22].nombre	:= 'Alessandra Tu Sex¢loga';
	v_autor[22].estado	:= true;

	v_autor[23].id_autor	:= 23;
	v_autor[23].nombre	:= 'Horangel';
	v_autor[23].estado	:= true;

	v_autor[24].id_autor	:= 24;
	v_autor[24].nombre	:= 'Donatello';
	v_autor[24].estado	:= true;

	v_autor[25].id_autor	:= 25;
	v_autor[25].nombre	:= 'Domino Harvey';
	v_autor[25].estado	:= false;

	v_autor[26].id_autor	:= 26;
	v_autor[26].nombre	:= 'Atahualpa Yupanqui';
	v_autor[26].estado	:= true;

	largo_autor := 26
End;


procedure Inicializar_genero (var v_genero : tv_genero);

Begin
	with v_genero[1] do
	begin
		id_genero		:= 1;
		nombre			:= 'Novela';
		pasillo_inicial		:= 1;
		estante_inicial		:= 1;
		pasillo_final		:= 2;
		estante_final		:= 10
	end;

	with v_genero[2] do
	begin
		id_genero		:= 2;
		nombre			:= 'Ensayo';
		pasillo_inicial		:= 2;
		estante_inicial		:= 11;
		pasillo_final		:= 4;
		estante_final		:= 2
	end;

	with v_genero[3] do
	begin
		id_genero		:= 3;
		nombre			:= 'Ciencia';
		pasillo_inicial		:= 4;
		estante_inicial		:= 3;
		pasillo_final		:= 6;
		estante_final		:= 9
	end;

	with v_genero[4] do
	begin
		id_genero		:= 4;
		nombre			:= 'Humanidades';
		pasillo_inicial		:= 6;
		estante_inicial		:= 10;
		pasillo_final		:= 7;
		estante_final		:= 13
	end;

	with v_genero[5] do
	begin
		id_genero		:= 5;
		nombre			:= 'Infantil';
		pasillo_inicial		:= 7;
		estante_inicial		:= 14;
		pasillo_final		:= 8;
		estante_final		:= 8
	end;

	with v_genero[6] do
	begin
		id_genero		:= 6;
		nombre			:= 'Diccionarios';
		pasillo_inicial		:= 8;
		estante_inicial		:= 9;
		pasillo_final		:= 9;
		estante_final		:= 11
	end;

	with v_genero[7] do
	begin
		id_genero		:= 7;
		nombre			:= 'Otros';
		pasillo_inicial		:= 9;
		estante_inicial		:= 12;
		pasillo_final		:= 10;
		estante_final		:= 15
	end

End;


procedure Inicializar_titulo (var v_titulo : tv_titulo; var largo_titulo : integer);

Begin
	
	with v_titulo[1] do
	begin
		id_titulo	:= 1;
		nombre		:= 'Tennis';
		id_Autor	:= 20;
		id_Genero	:= 7;
		estado		:= true
	end;

	with v_titulo[2] do
	begin
		id_titulo	:= 2;
		nombre		:= 'Family Guy';
		id_Autor	:= 21;
		id_Genero	:= 7;
		estado		:= true
	end;

	with v_titulo[3] do
	begin
		id_titulo	:= 3;
		nombre		:= 'Italiano-Ruso';
		id_Autor	:= 13;
		id_Genero	:= 6;
		estado		:= true
	end;

	with v_titulo[4] do
	begin
		id_titulo	:= 4;
		nombre		:= 'Las Tortugas Ninja';
		id_Autor	:= 24;
		id_Genero	:= 5;
		estado		:= true
	end;

	with v_titulo[5] do
	begin
		id_titulo	:= 5;
		nombre		:= 'To Have and Have Not';
		id_Autor	:= 15;
		id_Genero	:= 1;
		estado		:= true
	end;

	with v_titulo[6] do
	begin
		id_titulo 	:= 6;
		nombre		:= 'Ciencias Naturales y Sociales';
		id_Autor	:= 3;
		id_Genero	:= 3;
		estado		:= true
	end;

	with v_titulo[7] do
	begin
		id_titulo	:= 7;
		nombre		:= 'Caza-recompensas';
		id_Autor	:= 25;
		id_Genero	:= 7;
		estado		:= true
	end;

	with v_titulo[8] do
	begin
		id_titulo	:= 8;
		nombre		:= 'Dado de baja';
		id_Autor	:= 26;
		id_Genero	:= 7;
		estado		:= false
	end;

	largo_titulo := 8

End;


{Procedure Inicializar_ejemplar (var v_ejemplar : tv_ejemplar; var largo_ejemplar : integer);}

{ * * *  / I N I C I A L I Z A C I O N E S  * * *  }


{ * * *  O R D E N A M I E N T O S  * * * }

procedure Ordenar_autor (var v_autor : tv_autor; tipo, largo_autor : integer); {*1}

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
					v_autor[j] := v_autor[j+1];
					v_autor[j+1] := aux
				end;

	if tipo = 2 then
		for i:=1 to (largo_autor-1) do
			for j:=1 to (largo_autor-i) do
				if (v_autor[j].nombre > v_autor[j+1].nombre) then
				begin
					aux := v_autor[j];
					v_autor[j] := v_autor[j+1];
					v_autor[j+1] := aux
				end

End;
{
*1 - Tipo 1: Ordena por ID del autor. Tipo 2: Ordena por nombre de autor.
}


procedure Ordenar_titulo (var v_titulo : tv_titulo; tipo, largo_titulo : integer); {*1}

var
	i,j : integer;
	aux : tr_titulo;

Begin
	if tipo = 1 then  {*2}
		for i:=1 to (largo_titulo-1) do
			for j:=1 to (largo_titulo-i) do
				if (v_titulo[j].id_titulo > v_titulo[j+1].id_titulo) then
				begin
					aux := v_titulo[j];
					v_titulo[j] := v_titulo[j+1];
					v_titulo[j+1] := aux
				end;

	if tipo = 2 then  {*2}
		for i:=1 to (largo_titulo-1) do
			for j:=1 to (largo_titulo-i) do
				if (v_titulo[j].nombre > v_titulo[j+1].nombre) then
				begin
					aux := v_titulo[j];
					v_titulo[j] := v_titulo[j+1];
					v_titulo[j+1] := aux
				end;

	if tipo = 3 then  {*2}
		for i:=1 to (largo_titulo-1) do
			for j:=1 to (largo_titulo-i) do
				if (v_titulo[j].id_autor > v_titulo[j+1].id_autor) then
				begin
					aux := v_titulo[j];
					v_titulo[j] := v_titulo[j+1];
					v_titulo[j+1] := aux
				end;

	if tipo = 4 then  {*2}
		for i:=1 to (largo_titulo-1) do
			for j:=1 to (largo_titulo-i) do
				if (v_titulo[j].id_genero > v_titulo[j+1].id_genero) then
				begin
					aux := v_titulo[j];
					v_titulo[j] := v_titulo[j+1];
					v_titulo[j+1] := aux
				end

End;
{
*1 - Tipo 1: Ordena por el ID del título. Tipo 2: Por el nombre. Tipo 3: Por el ID del autor. Tipo 4: Por el ID de género.
*2 - En vez de los cuatro IFs se podría hacer con un CASE, pero en los CASE me parece que queda
desprolijo si se usa código de más de una línea
}


procedure Ordenar_ejemplar (var v_ejemplar : tv_ejemplar; tipo, largo_ejemplar : integer); {*1}

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
					v_ejemplar[j] := v_ejemplar[j+1];
					v_ejemplar[j+1] := aux
				end;

	if tipo = 2 then
		for i:=1 to (largo_ejemplar-1) do
			for j:=1 to (largo_ejemplar-i) do
				if (v_ejemplar[j].id_titulo > v_ejemplar[j+1].id_titulo) then
				begin
					aux := v_ejemplar[j];
					v_ejemplar[j] := v_ejemplar[j+1];
					v_ejemplar[j+1] := aux
				end

End;
{
*1 - Tipo 1: Ordena por el ID del ejemplar. Tipo 2: Ordena por el ID del titulo.
}


{ * * *  / O R D E N A M I E N T O S  * * * }


{ * * *  B Ú S Q U E D A S  * * * }

function Buscar_autor (var v_autor : tv_autor; largo_autor, id_buscada : integer) : string;

var
	encontrado	: boolean;
	i						:	integer;
	resultado		: string;

Begin
	i:=1;
	encontrado := false;
	resultado := '-1';
	while (i<=largo_autor) AND (NOT (encontrado)) do
		begin
			if id_buscada = v_autor[i].id_autor then
				if v_autor[i].estado = true then
					begin
						encontrado := true;
						resultado := v_autor[i].nombre
					end;
			inc(i)
		end;

	Buscar_autor := resultado

End;


function Buscar_genero (var v_genero : tv_genero; id_buscada : byte) : string;

var
	encontrado	: boolean;
	i						:	integer;
	resultado		: string;

Begin
	i:=1;
	encontrado := false;
	resultado := '-1'; {*1}
	while (i<=MAX_GENERO) AND (NOT (encontrado)) do
		begin
			if id_buscada = v_genero[i].id_genero then
				begin
					encontrado :=true;
					resultado := v_genero[i].nombre
				end;
			inc(i)
		end;

	Buscar_genero := resultado

End;
{
*1 - Esto no haría falta, ya que siempre se encuentra el género
}


procedure Buscar_titulo (var v_titulo : tv_titulo; var reg_titulo : tr_titulo; largo_titulo, id_buscada : integer);

var
	encontrado	: boolean;
	i						:	integer;

Begin
	i:=1;
	encontrado := false;
	reg_titulo.estado := false;
	while (i<=largo_titulo) AND (NOT (encontrado)) do
		begin
			if id_buscada = v_titulo[i].id_titulo then
				if v_titulo[i].estado = true then
					begin
						encontrado := true;
						reg_titulo := v_titulo[i]
					end;
			inc(i)
		end

End;


function BuscaGenero (var V_Genero: tv_genero; Pasillo, Estante: integer): integer;
{Ingresando el pasillo y el estante retorna el id_genero sino retorna -1}

var
   i: byte;
   Encontrado: boolean;
   PosGlobalBuscada, PosGlobalInicial, PosGlobalFinal: integer;

begin
     i := 1;
     Encontrado := False;
     PosGlobalBuscada:=(Pasillo-1)*15 + Estante;
     while not Encontrado do
           with V_Genero[i] do
           begin
                PosGlobalInicial:=(pasillo_inicial-1)*15 + estante_inicial;
                PosGlobalFinal:=(pasillo_final-1)*15 + estante_final;
                if (PosGlobalBuscada>=PosGlobalInicial) and (PosGlobalBuscada<=PosGlobalFinal)
                then begin
                     Encontrado := True;
                     BuscaGenero := i;
                     end
                else inc(i);
           end;
     if not Encontrado then BuscaGenero := -1;
end;

function BuscarPos_Ejemplar (var VecEjemplar: tv_ejemplar; LargoVector, IdEjemplar: integer): integer;
{Busca dentro del vector de ejemplares el id indicada, si lo encuentra devuelve la posicion,
sino devuelve -1}

var
   Inicio, Fin, Medio: integer;
   Terminado: boolean;

begin
     Inicio    := 1;
     Fin       := LargoVector;
     Terminado := False;
     while not Terminado do
     begin
          if (IdEjemplar > VecEjemplar[Fin].id_ejemplar) or (IdEjemplar < VecEjemplar[Inicio].id_ejemplar)
          then begin
               Terminado := True;
               BuscarPos_Ejemplar := -1;
               end
          else begin
               Medio := (Inicio+Fin) div 2;
               if IdEjemplar = VecEjemplar[Medio].id_ejemplar
               then begin
                    Terminado := True;
                    BuscarPos_Ejemplar := Medio;
                    end
               else if idEjemplar > VecEjemplar[Medio].id_ejemplar
                    then Inicio := Medio+1 {busca en la 2a mitad}
                    else Fin := Medio-1 {busca en la 1a mitad}
               end
     end
end;


{ * * *  / B Ú S Q U E D A S  * * * }


{ * * *  L I S T A D O S   C O M P L E T O S  * * * }

procedure Listado_autores (v_autor : tv_autor; largo_autor : integer);

var
	i,j : integer;

Begin

	if largo_autor = 0 then
	begin
		ClrScr;
		writeln;
		writeln ('No hay autores para listar')
	end

	else
	begin
		Ordenar_autor (v_autor,1,largo_autor);
		j := 1;
		ClrScr;
		write ('ID       Nombre'); {*2}
		for i:=1 to largo_autor do
			with v_autor[i] do
				if estado = true then {*1}
				begin
					if (j mod 22) = 0 then
						begin
							writeln;
							writeln;
							write ('Presione una tecla para continuar... ');
							readkey;
							ClrScr;
							writeln ('ID       Nombre'); {*2}
							inc (j) {*3}
						end;
					gotoxy (1,(j mod 22) +2);
					write (id_autor:2);
					gotoxy (10,(j mod 22) +2);
					write (nombre);
					inc(j)
				end;
	end;

	writeln;
	writeln;
	write ('Presione una tecla para volver al men£...');
	readkey;
End;
{
*1 - Lo lista sólo si el estado es verdadero, o sea, si existe
*2 - Encabezado
*3 - Este incrementar es para dejar un espacio entre el encabezado y el listado a partir de la segunda vez que se lista
}


procedure Listado_generos (v_genero : tv_genero);

var
	i : integer;

Begin
	ClrScr;

	write ('ID       Nombre              Inicio              Fin'); {*1}
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
{
*1 - Encabezado
}


procedure Listado_titulos (var v_titulo : tv_titulo; var v_autor : tv_autor;
var v_genero : tv_genero; largo_titulo, largo_autor : integer);

var
	j,i													: integer;
	nombre_autor, nombre_genero	: string;

Begin

	if largo_titulo = 0 then
	begin
		ClrScr;
		writeln ('No hay t¡tulos para listar');
	end

	else
	begin

		Ordenar_titulo (v_titulo,1,largo_titulo); {*1}

		j := 1;
		ClrScr;
		write ('ID       Nombre                   Autor                    Género'); {*2}
		for i:=1 to largo_titulo do
			with v_titulo[i] do
				if estado = true then {*3}
				begin
					if (j mod 22) = 0 then  {*4}
					begin
						writeln;
						writeln;
						write ('Presione una tecla para continuar... ');
						readkey;
						ClrScr;
						writeln ('ID       Nombre                  Autor                    G‚nero'); {*2}
						inc (j) {*5}
					end;

					nombre_autor := buscar_autor(v_autor,largo_autor,id_autor);
					nombre_genero := buscar_genero (v_genero,id_genero);
					if nombre_autor <> '-1' then {*6}
					begin
						gotoxy (1,(j mod 22) +2);
						write (id_titulo:2);
						gotoxy (10,(j mod 22) +2);
						write (nombre);
						gotoxy (35,(j mod 22) +2);
						write (nombre_autor);
						gotoxy (60,(j mod 22) +2);
						write (nombre_genero);
						inc(j)
					end
				end
	end;

	writeln;
	writeln;
	write ('Presione una tecla para volver al men£...');
	readkey;
End;
{
*1 - El 1 es para ordenar por ID.
*2 - El encabezado.
*3 - Lo lista sólo si el estado es verdadero, o sea, si existe
*4 - Si ya se listaron más de 22, empieza una nueva hoja
*5 - Este incrementar es para dejar un espacio entre el encabezado y el listado a partir de la segunda vez que se lista.
*6 - Esto no haría falta, ya que si el libro está, el autor debe existir
}

{ * * *  / L I S T A D O S   C O M P L E T O S  * * * }

Function Check_existencia_Titulo(var Titulos: Tv_Titulo; Codigo: Integer): Integer;
{* Chequea la existencia, en el vector de titulos, de el "codigo" ingresado
   En caso de existir regresa la posici¢n en el vector de ese titulo, sino -1*}

 var
   I:Integer;
   Existe:Boolean;

 Begin
	I:= 1;
	Existe:= False;
	While not Existe and (I <= Max_Titulo) and (Titulos[I].Id_Titulo <> 0) do
	begin
		If (Titulos[I].Id_Titulo = Codigo ) and Titulos[I].Estado then
			Existe:= True
		 Else
			I:=I +1;
	end;

	If not Existe then
		Check_existencia_Titulo:= -1
	else
		Check_existencia_Titulo:= I;
 End;


{ * * *  L I S T A D O S   I N D I V I D U A L E S * * *  }

procedure listado_individual_autor (var v_autor : tv_autor; largo_autor : integer);

var
	id_autor : integer;
        N_autor: string;
Begin
	repeat
		ClrScr;
		id_autor:=-1;
		writeln ('Consulta individual de autores');
		writeln ('------------------------------');
		writeln;
		write ('Ingrese el c¢digo del autor que quiere listar( 0 para salir): ');
		{$I-}  {*1}
		readln (id_autor);
		{$I+}  {*1}
		if IOResult<>0 then
		begin
			writeln ('Ingrese s¢lo n£meros positivos...');
			writeln;
			id_autor := -1;
		end;
                writeln;
		
		N_autor:= Buscar_autor(v_autor,largo_autor,id_autor);
		if (id_autor > 0) AND (N_autor <> '-1' )then
		begin
			if (buscar_autor (v_autor, largo_autor, id_autor)) <> '-1' then
			begin
				writeln ('ID: ',id_autor);
				writeln;
				writeln ('Nombre: ',buscar_autor (v_autor, largo_autor, id_autor));
				writeln;
				writeln;
				writeln;
				write ('Ingrese una tecla para volver al men£ ...');
			end
			else
				write ('No existe un autor con ese c¢digo...');
					
		end
		else
		begin
			if (id_autor<>-1) and (Id_autor <> 0) then write ('No existe un autor con ese c¢digo...');
		end;
		if Id_autor <> 0 then readkey;
	
	until (id_autor = 0);

End;
{
*1 - Directivas para que no salga del programa si ingresa un valor no aceptado.
}


procedure listado_individual_genero (var v_genero : tv_genero);

var
	id_genero : integer;

Begin
	repeat
		ClrScr;
		id_genero := -1;
		writeln ('Consulta individual de g‚neros');
		writeln ('------------------------------');
		writeln;
		write ('Ingrese el c¢digo del g‚nero que quiere listar (0 para salir): ');
		{$I-}  {*1}
		readln (id_genero);
		{$I+}  {*1}
		if IOResult<>0 then
		begin
			writeln ('Ingrese s¢lo n£meros positivos');
			id_genero := -1;
		end;
                writeln;
		if (id_genero > 0) AND (id_genero <= 7) then
		begin
			writeln ('ID: ',id_genero);
			writeln;
			writeln ('Nombre: ',buscar_genero (v_genero,id_genero));
			writeln;
			writeln;
			writeln;
			write ('Ingrese una tecla para volver al men£ ...');

		end
		else
		begin
			if (id_genero<> -1) and (id_genero <> 0) then write ('No existe un g‚nero con ese c¢digo...');
			write ('Presione una tecla para ingresar nuevamente');
		end;
		if (id_genero <> 0) then
		readkey;
	until (id_genero >= 0) and (id_genero <= 7);

End;
{
*1 - Directivas para que no salga del programa si ingresa un valor no aceptado.
}


procedure listado_individual_titulo (var v_titulo : tv_titulo; var v_autor : tv_autor;
var v_genero : tv_genero; largo_titulo, largo_autor : integer);

var
	pos,id_titulo	: integer;
	reg_titulo	: tr_titulo;
	autor, genero	: string;

Begin
	repeat
		ClrScr;
		id_titulo := -1;
		writeln ('Consulta individual de t¡tulos');
		writeln ('------------------------------');
		writeln;
		write ('Ingrese el c¢digo del t¡tulo que quiere listar (0 para salir): ');
		{$I-}
		readln (id_titulo);
		{$I+}
		if IOResult<>0 then
		begin
			writeln ('Ingrese s¢lo n£meros positivos');
			id_titulo := -1;
		end;
                writeln;
		pos:= ChecK_existencia_titulo(v_titulo,id_titulo);
		if (id_titulo > 0) AND (pos > 0) then
		begin
			Buscar_titulo (v_titulo, reg_titulo, largo_titulo, id_titulo); {*2}
				if (reg_titulo.estado){ AND (autor <> '-1') }then
				begin
					with reg_titulo do
					begin
						autor := Buscar_autor(v_autor,largo_autor,id_autor);
						genero := Buscar_genero(v_genero,id_genero);
						writeln ('ID: ',id_titulo);
						writeln;
						writeln ('Nombre: ',nombre);
						writeln;
						writeln ('Autor: ',autor);
						writeln;
						writeln ('G‚nero: ',genero);
						writeln;
						writeln;
						writeln;
						write ('Presione una tecla para ingresar nuevamente...')
					end
				end
				else
				begin
					writeln ('No existe un t¡tulo con ese c¢digo.');
					write ('Presione una tecla para ingresar nuevamente...');
					id_titulo:=0
				end

		end
		else
		begin
			if (id_titulo<> -1) and (id_titulo <> 0)then writeln ('No existe un t¡tulo con ese c¢digo.');
			write ('Presione una tecla para ingresar nuevamente...');
		end;
		if (id_titulo <> 0) then
		readkey;

	until (id_titulo = 0) ;

End;
{
*1 - Directivas para que no salga del programa si ingresa un valor no aceptado.
*2 - Devuelve el registro completo del ejemplar buscado.
}

{ * * *  / L I S T A D O S   I N D I V I D U A L E S * * *  }



{ * * *  V I S U A L I Z A C I O N E S * * * }

Function Toma_Color_y_Caracter(cod: byte):char;
{* Entra El codigo de color deseado y lo establece, además de devolver*}
{* un caracter relacionado con ese color *}
 var
	caracter:char;
 Begin
	Case  cod  of
		0:Begin
			textColor(16); {negro}
			caracter:='±';
		  end;
		1:Begin
			textColor(17); {azul}
			caracter:='°';
		  end;
		2:Begin
			textColor(18); {verde}
			caracter:='²';
		  end;
		3:Begin
			textColor(20); {rojo}
			caracter:='Û';
		  end;
		4:Begin
			textColor(21); {Magenta}
			caracter:='°';
		  end;
		5:Begin
			textColor(23); {Gris Claro}
			caracter:='±';
		  end;
		6:Begin
			textColor(28); {Amarillo}
			caracter:='²';
		  end;
		7:Begin
			textColor(22); {verde Claro}
			caracter:='Û';
		  end;
                8:Begin
                       textcolor(28);
                       caracter:='Û';
                  end

	end;

	Toma_Color_y_Caracter:= caracter
end;

Procedure Muestra_Mapa(P_Inic,E_Inic,P_fin,E_fin,Codigo: byte);
{* "Dibuja" los pasillos con sus estantes y con "codigo" establece
    el color a dibujar los pasillos, si es 0 inicia las estanterias
    como vacías  *}

var
	I,x:byte;
	x_final:byte;
	Car: char;
	FinGenero:boolean;
 begin
        If P_inic <> 0 then {*Caso que el genero esta establecido*}
          begin
	       x:= 4 + (P_Inic -1)*8;
	       x_final:= 4 + (P_fin -1)*8;

               FinGenero:= false;
          end
        else
           FinGenero:= true;

	Car:= Toma_Color_y_caracter(codigo);



   	While not FinGenero and (x<= x_final) do
	 Begin
		If codigo = 0 then {* caso inicia el dibujo como estanterias vacías*}
		 Begin
			gotoXY(X,E_Inic+2);
			Write('Pas',P_inic);
			P_Inic:= P_Inic + 1
		 end;

		While not Fingenero and ( E_inic <= 15)do
		 begin
                        gotoXY(x-3, E_Inic+ 3);
			Write(E_Inic,' ');

			gotoXY(x,E_Inic+3);

                        For I:= 1 to 4 do
				Write(car);
			If (x= X_final) and (E_Inic= E_Fin) then
				FinGenero:= True
			else
				E_Inic:= E_Inic +1
		 end;
		E_Inic:=1;
		x:=x +8
	 end;
 end;

{ * * *  V I S U A L I Z A C I O N  D E  G E N E R O S  * * * }

Procedure Visualiza_Generos(var VecGeneros: Tv_Genero);
{* Va a Mostrar Los Generos, en forma de plano *}
var
	inicio,fin,k,I,J: byte;
	x,y: byte;
	Carac: char;
Begin
        TextBackground(15);
        TextColor(16);
        clrscr;
	Writeln(' Distribuci¢n de G‚neros en la Biblioteca');
        writeln(' ----------------------------------------');
        Writeln;
	Muestra_Mapa(1,1,10,15,0);

	For J:= 1 to Max_Genero do
	begin
		With Vecgeneros[J] do
			Muestra_Mapa(Pasillo_inicial,estante_inicial,Pasillo_final,estante_final,J);
	end;

	Textcolor(0);  {Negro}
	gotoXY(2,20);
	Writeln(' Referencias ');

        For K:=1 to 2 do
            begin
                 If k=1 then
                    begin
                         inicio:=0;
                         fin:= Max_Genero div 2;
                         X:=2
                    end
                 else
                     begin
                          inicio:= (Max_Genero div 2) +1;
                          fin:= Max_Genero;
                          X:=25
                     end;
                 y:=21;
                 For I:= inicio to fin do
	             begin
		          Carac:= Toma_Color_y_Caracter(I);
                          y:= y +1;
		          GotoXY(x,y);
                          Write(carac,' ');
                          If I = 0 then
                             Write('Sin Genero')
                          else
		              Write(VecGeneros[I].Nombre);
		      end
            end;
        readkey;
        textcolor(15);
        textbackground(0);
 end;

{ * * *  /V I S U A L I Z A C I O N  D E  G E N E R O S  * * * }

{ * * * V I S U A L I Z A C I O N  P O R  T I T U L O S  * * * }



Procedure Toma_Titulo(var vecTitulo: Tv_Titulo; var PosTit: Integer; Var Cod_Titulo: Integer);
{* Una segunda validación del codigo de titulo ingresado *}
{* Llama a checkTitulo para saber si existe *}

 Begin

	PosTit:=-1;
	While (PosTit < 0) and (cod_titulo<>0) do
	Begin
                Cod_Titulo:=0;
		ClrScr;
		Writeln(' Visualizaci¢n De Informaci¢n por Titulo');
		writeln(' ---------------------------------------');
		writeln;
		Write('Ingrese Codigo de Titulo (0 para salir): ');
		{$I-}
		Readln(Cod_titulo);
		{$I+}
		If  IOResult = 0 then
			begin
				PosTit:= Check_existencia_Titulo(VecTitulo,Cod_Titulo);
				If (PosTit = -1) and ( Cod_Titulo > 0) then
					Begin
						Writeln('.- El codigo de Titulo ingresado NO Existe');
						readkey;
					end
			end
		else
			Cod_titulo:= -1;
	end
 end;


Procedure Toma_posicion_Ejemplar(Ejemplares: Tv_Ejemplar;largo_Ejemplar,Cod:Integer;var Posicion:Integer);
{* Busca en que posicion se encuantra ejemplares que tengan Id_Titulo igual a cod*}
{* Comienza a buscar en la "Posicion" ingresada mas 1 *}
 var
   I:integer;
   Encontrado:Boolean;
Begin
	I:=Posicion+1;
	Encontrado:= false;
	While not Encontrado and (I<= Largo_Ejemplar+1) do
	Begin
		With Ejemplares[I] do
		Begin
			If (Id_Titulo = Cod) and estado then
				Encontrado:=True
			else
				I:=I +1;
	        end;

	        If Encontrado then
		   Posicion:=I
	        else
		    Posicion:=-1;
        end
end;


Procedure Visualiza_Ejemplar(Ejemplares:Tv_Ejemplar;Fin_Ejemplar, COdTitulo:Integer;NomTitulo:String);
{* Busca y manda a mostrar los ejemplares con el codigo de titulo ingresado *}

var
   Pos:Integer;
   Y:Byte;
   car:char;
Begin


        Pos:=0;
        Toma_posicion_Ejemplar(Ejemplares,fin_Ejemplar,CodTitulo,Pos);
        If Pos > 0 then
           Begin
                textcolor(16); {* Negro *}
                textbackground(15); {* Blanco *}
                clrscr;

	        Muestra_Mapa(1,1,10,15,0);
                car:= Toma_Color_y_Caracter(8);

                gotoXY(2,22);
	        Write(Car,' ');
                Textcolor(16); {* Negro *}
	        Writeln('.- Ubicaci¢n de los ejemplares del titulo : ',NomTitulo);
	        Write('Presione cualquier tecla para continuar')
           end
        else
            Begin
                 Writeln('.- No hay Elementos con este t¡tulo en la Biblioteca');
                 Write('Presione cualquier tecla para continuar')
            end;

	While Pos > 0 do
	Begin
		With Ejemplares[Pos] do
		begin

			Muestra_Mapa(Pasillo,estante,Pasillo,Estante,8);
		end;
		Toma_posicion_Ejemplar(Ejemplares,Fin_Ejemplar,CodTitulo,Pos)
	end;
	Readkey;

 end;


Procedure Por_Titulo(var VecTit: Tv_Titulo;var vecEjem: Tv_Ejemplar;var vecAutor:Tv_Autor;
var VecGen:Tv_Genero;fin_autor,fin_titulo,fin_ejemplar: integer);
{* Establece y llama a todos los procedimientos y funciones necesarios  para
   mostrar los datos De los Titulos de la Biblioteca *}
var
   PosY:byte;
   R_Titulo: Tr_titulo;
   Codigo:integer;
   Pos,Posicion:integer;
   NGenero,NAutor:String;
Begin
	Codigo:=1;
	While Codigo> 0 do
	begin
		Toma_Titulo(vecTit,Posicion,Codigo);
		Clrscr;

		If codigo > 0 then
		Begin
			With VecTit[Posicion] do
			begin
				Ngenero:= Buscar_Genero(VecGen,Id_Genero);
				NAutor:= Buscar_Autor(VecAutor,fin_Autor,Id_Autor);


                                Writeln(' Datos del T¡tulo');
                                writeln(' ----------------');
                                writeln;
				Write('.- Id : ');
				Writeln(Codigo);
                                writeln;
				Write('.- Nombre: ');
				Writeln(Nombre);
                                writeln;
				Write('.- Autor: ');
				Writeln(NAutor);
                                writeln;
				Write('.- G‚nero: ');
				Writeln(NGenero);
                                Writeln;
			end;
			Writeln('Presione cualquier tecla para ver los ejemplares de este Titulo ');
			Readkey;
			ClrScr;
			Pos:=0;
			Toma_posicion_Ejemplar(VecEjem,Fin_Ejemplar,codigo,Pos);

                        Writeln(' Datos de Ejemplares');
                        writeln(' -------------------');

			While Pos > 0 do
			Begin

				With VecEjem[Pos] do
				begin
                                        writeln;
					Write('.- Id Ejemplar : ');
					Writeln(Id_Ejemplar);
					Write('.- Ubicaci¢n: Pasillo : ');
					Writeln(Pasillo);
					Write('              Estante : ');
					Writeln(Estante);
			    	   	Writeln('------------------------');
					Writeln;
					PosY:= WhereY;
					Writeln('Presione cualquier tecla para continuar ');
					Readkey;
					GotoXY(1,PosY);
                                        ClrEol;

				end;
				Toma_posicion_Ejemplar(VecEjem,Fin_Ejemplar,Codigo,Pos);

			end;
                        Clrscr;

			Visualiza_Ejemplar(VecEjem,fin_Ejemplar,Codigo,VecTit[Posicion].Nombre);
                        textcolor(15); {* Blanco *}
                        textbackground(0) {* Negro *}
		end
	end
end;

{ * * * /V I S U A L I Z A C I O N  P O R  T I T U L O S  * * * }


Procedure Visualizaciones(var VecTitulos: Tv_Titulo;var vecEjemplares: Tv_Ejemplar;
        var vecAutores:Tv_Autor;var VecGeneros:Tv_Genero;ultimo_autor,ultimo_titulo,ultimo_ejemplar: integer);
var
   Eleccion:Byte;

Begin

     Eleccion := 4;

     While Eleccion <> 0  do
      Begin
           Eleccion:=3;
           While (Eleccion <> 1) and (Eleccion <> 2) and (Eleccion <> 0)do
            Begin
                 Clrscr;

                 Writeln(' Visualizaciones ');
                 writeln(' --------------- ');
                 writeln;
                 writeln;
                 Writeln(' 1.- Mapa de Distribuci¢n de G‚neros');
                 Writeln;
                 Writeln(' 2.- Ubicaci¢n en La Biblioteca de un T¡tulo');
                 writeln;
                 Writeln(' 0.- Volver');
                 writeln;
                 Write(' Eliga una opci¢n :');
                 {$I-}
		 Readln(eleccion);
		 {$I+}
		 If IoResult <> 0 then
			eleccion:= 3;
            end;

            Case Eleccion of
                 1: Visualiza_Generos(VecGeneros);
                 2: Por_Titulo(vecTitulos,vecEjemplares,vecAutores,VecGeneros,ultimo_autor,ultimo_titulo,ultimo_ejemplar);
            end;

      end;

end;

{ * * * / V I S U A L I Z A C I O N E S * * * }


Function Posicion_ejemplar (ID:integer;var Ejemplar:Tv_ejemplar;Long_vector:Byte):INTEGER;

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

Function Posicion_id_titulo (ID:integer;var Titulo:Tv_titulo):integer;

var
	encontrado:boolean;
	i:byte;

BEGIN
			
	posicion_id_titulo:=-1;	
	encontrado:=false;
        i:=1;

			
	While ((not encontrado) AND (i<=MAX_TITULO)) do
		begin
			If titulo[i].id_titulo=id then

				begin	
					posicion_id_titulo:=i;
					encontrado:=true;
				end;

			i:=i+1;
		end;
				
END;


Function pasillo_estante_valido (pas, est:byte; id_gen:integer; genero:Tv_genero):boolean;
 
var 
	encontrado:boolean;
	i,j,k:byte;
    	pasillo_inicio, pasillo_fin, estante_inicio, estante_fin:byte;
    	ubicacion_inicial,ubicacion_final,ubicacion_buscada : integer;
		
BEGIN

	encontrado:=false;
	i:=1;
	
	While (not encontrado)  do
			
		begin
				
			If genero[i].id_genero=id_gen then
				
				begin
					pasillo_inicio:=genero[i].pasillo_inicial;
					pasillo_fin:=genero[i].pasillo_final;
					estante_inicio:=genero[i].estante_inicial;
					estante_fin:=genero[i].estante_final;
					encontrado:=true;
				end;

			i:=i+1;

		end;

	encontrado:=false;
	i:=pasillo_inicio;
	k:=estante_inicio;

	ubicacion_inicial:=pasillo_inicio*100 + estante_inicio;
	ubicacion_buscada:=pas*100 + est;
	ubicacion_final:=pasillo_fin*100 + estante_fin;
	
	while ((ubicacion_inicial<=ubicacion_final) and (not encontrado)) do
	begin
		if ubicacion_inicial = ubicacion_buscada then
			encontrado:=true;

		if ((ubicacion_inicial-MAX_ESTANTES) mod 100) = 0 then
		begin
				ubicacion_inicial:= ubicacion_inicial - MAX_ESTANTES;
				ubicacion_inicial:= ubicacion_inicial + 100;
		end;
		inc(ubicacion_inicial);
	end;

      pasillo_estante_valido:=encontrado;

END;


Procedure ingreso (Var Ejemplar: Tv_Ejemplar; Var Titulo:TV_Titulo; Var Genero: Tv_Genero; var Long_vector:Integer);

var
	id:integer;
   	pasillo, estante:byte;
   	idGenero:byte;
   	error : boolean;

BEGIN
	error:=true;

	while error do

		begin
		    	clrscr;
		    	error:=false;
 	           	writeln;
		    	Write ('Ingrese el ID del ejemplar a ingresar (0 para salir): ');
			{$I-}
			readln (id);
			{$I+}

			if IOResult <> 0 then
				begin   writeln;
					writeln ('Ingrese s¢lo n£meros por favor.');
                                        writeln;
                                        writeln;
					write ('Presione una tecla para ingresar nuevamente');
					readkey;
					error:=true;
				end;
		end;

	While ((ID<>0) and (POSICION_EJEMPLAR (ID,EJEMPLAR,LONG_VECTOR)<>-1)) do

		Begin
			clrscr;
			writeln;
			writeln;
			writeln ('El ID ingresado ya esta asignado a otro ejemplar');
			error:=true;
			
			while error do
				begin
					writeln;
					Write ('Ingrese nuevamente el ID: ');
	 	    			error:=false;
					{$I-}
					readln (id);
					{$I+}
					if IOResult <> 0 then
						begin
                                                        writeln;
							writeln ('Ingrese s¢lo n£meros por favor.');
                                                        writeln;
							write ('Presione una tecla para ingresar nuevamente');
							readkey;
							error:=true;
						end;
				end;
		end;
			
 	if ID<>0 then

{BeginIF} 	begin
			ejemplar[long_vector+1].id_ejemplar:=id;
			error:=true;
			while error do
				begin
					clrscr;
					writeln;
					Write ('Ingrese el ID de T¡tulo: ');
			 	    	error:=false;
					{$I-}
					readln (id);
					{$I+}
					if IOResult <> 0 then
						begin
                                                        writeln;
							writeln ('Ingrese s¢lo n£meros por favor.');
                                                        writeln;
							write ('Presione una tecla para ingresar nuevamente');
							readkey;
							error:=true;
						end;
				end;
						
			while (POSICION_ID_TITULO (ID, TITULO)=-1) do
				begin
        				clrscr;
					writeln;
					writeln;
					write ('El ID ingresado no existe');
                                        writeln;
					error:=true;
		
					while error do
						begin
							error:=false;
							writeln;
							write ('Ingrese nuevamente el ID del t¡tulo: ');
							{$I-}
							readln (id);
							{$I+}
				
							if IOResult <> 0 then
								begin
                                                                        writeln;
									writeln ('Ingrese s¢lo n£meros por favor.');
                                                                        writeln;
									write ('Presione una tecla para ingresar nuevamente');
									readkey;
									error:=true;
								end;
						end;
				end;

		 		ejemplar[long_vector+1].id_titulo:=id;

				error:=true;

			while error do

 				begin
		      			clrscr;
   			  		writeln;
	 				error:=false;
	 				write ('Ingrese el pasillo en el que desea ubicar el ejemplar: ');
	 				{$I-}
	 				readln  (pasillo);
	 				{$I+}

					if IOResult <> 0 then
						begin
                                                        writeln;
							writeln ('Ingrese s¢lo n£meros por favor.');
                                                        writeln;
							write ('Presione una tecla para ingresar nuevamente');
							readkey;
							error:=true;
						end;
	 			end;
			
			Writeln;
			error:=true;
		
	
			while error do
	
				begin

					error:=false;
					writeln;
					write ('Ingrese el estante en el que desea ubicar el ejemplar: ');
					{$I-}
					readln  (estante);
					{$I+}

					if IOResult <> 0 then
						begin
                                                        writeln;
							writeln ('Ingrese s¢lo n£meros por favor.');
                                                        writeln;
							write ('Presione una tecla para ingresar nuevamente');
							readkey;
							error:=true;
						end;
		 		end;

			idGenero := titulo[posicion_id_titulo (id, titulo)].id_genero;

			while (not pasillo_estante_valido (pasillo,estante,idGenero,genero)) do

				begin
        				clrscr;
					writeln;
					write ('La ubicaci¢n no es v lida');
					writeln;
                                        writeln;
					write ('El t¡tulo que ingres¢ pertenece al g‚nero ',genero[idGenero].nombre);
					write (' el cual ocupa desde el pasillo ',genero[idGenero].pasillo_inicial,', estante ',genero[idGenero].estante_inicial);
					writeln ('; hasta el pasillo ',genero[idGenero].pasillo_final,', estante ',genero[idGenero].estante_final);
					error:=true;
						
					while error do
						begin
							error:=false;
							writeln;
							
 write('Ingrese nuevamente el pasillo en el que desea ubicar el ejemplar: ');
							{$I-}
							readln (pasillo);
							{$I+}

							if IOResult <> 0 then
								begin
                                                                        writeln;
									writeln ('Ingrese s¢lo n£meros por favor.');
                                                                        writeln;
									write ('Presione una tecla para ingresar nuevamente');
									readkey;
									error:=true;
								end;
		 				end;
		 			
					error:=true;
		 			
					while error do
		 		
						begin
		 					error:=false;
		 					writeln;
		 					write ('Ingrese nuevamente el estante en el que desea ubicar el ejemplar: ');
		 					{$I-}
		 					readln  (estante);
		 					{$I+}

							if IOResult <> 0 then
								begin
                                                                        writeln;
									writeln ('Ingrese s¢lo n£meros por favor.');
                                                                        writeln;
									write ('Presione una tecla para ingresar nuevamente');
									readkey;
									error:=true;
								end;
		 				end;
					  
					writeln;
		 		end;

		 	ejemplar[long_vector+1].pasillo:=pasillo;
		 	ejemplar[long_vector+1].estante:=estante;
		 	ejemplar[long_vector+1].estado:=true;

		 	long_vector:=long_vector+1;

                        writeln;
		 	Write ('El ejemplar ha sido ingresado');
			readkey;


{ENDIF} 	end;
END;


Procedure Egreso (var Ejemplar:tv_ejemplar; long_vector:integer);

var
	id:integer;
	error:boolean;

begin
	error:=true;

	while error do
		begin
			error:=false;
			clrscr;
                        writeln;
			Write ('Ingrese el ID de ejemplar que desea retirar (0 para salir): ');
			{$I-}
			readln (id);
			{$I+}

			if IOResult <> 0 then
				begin
                                        writeln;
					writeln ('Ingrese s¢lo n£meros por favor.');
                                        writeln;
					write ('Presione una tecla para ingresar nuevamente');
					readkey;
					error:=true;
				end;
		end;

	while (error) OR ((ID<>0) AND (posicion_ejemplar (id,ejemplar,long_vector)=-1)) do
		begin
			ClrScr;
			writeln;
			if not error then write ('El ejemplar no existe');
			error:=false;
			writeln;
                        writeln;
			write ('Ingrese nuevamente el ID del ejemplar (0 para salir): ');
			{$I-}
			readln (id);
                        writeln;
			{$I+}
			if IOResult <> 0 then
				begin
                                        writeln;
					writeln ('Ingrese s¢lo n£meros por favor.');
                                        writeln;
					write ('Presione una tecla para ingresar nuevamente');
					readkey;
                                        writeln;
					error:=true;
				end;
        	end;

        if (ID<>0) AND (posicion_ejemplar  (id,ejemplar,long_vector)<>-1) then

		Begin
                        writeln;
                     	writeln ('El ejemplar ha sido retirado.');
                        writeln;
			write ('Se encontraba en el pasillo ',ejemplar[posicion_ejemplar (id,ejemplar,long_vector)].pasillo);
                        writeln (', estante ',ejemplar[posicion_ejemplar (id,ejemplar,long_vector)].estante);
			ejemplar[posicion_ejemplar (id,ejemplar,long_vector)].estado:=false;
			ejemplar[posicion_ejemplar (id,ejemplar,long_vector)].id_ejemplar:=0;
                        readkey;
                end;

 END;


Procedure Menu_ingreso_egreso (var Ejemplar:Tv_ejemplar; var Titulo: Tv_titulo;
                               var Genero: Tv_genero;var long_vector:integer);
var
	num_operacion:byte;

BEGIN

	repeat
		ClrScr;
		writeln;
                writeln;
		Write ('MENU INGRESO/EGRESO');
		Writeln;
		writeln;
		writeln;
		writeln ('1 -  Ingreso');
		writeln;
		writeln ('2 -  Egreso');
		writeln;
		writeln ('3 -  Salir');
		writeln;
		write ('Elija una opci¢n: ');
		{$I-}
		readln (num_operacion);
		{$I+}

		if IOResult <> 0 then
			begin
                                writeln;
				writeln ('Ingrese s¢lo n£meros por favor.');
                                writeln;
				write ('Presione una tecla para ingresar nuevamente');
				readkey;
				num_operacion:=0
			end;

		Case num_operacion of

  			1 : INGRESO ( EJEMPLAR, TITULO,GENERO, Long_VECTOR);

  			2 : EGRESO (EJEMPLAR,LOng_VECTOR);
		end;

	{      if num_operacion <> 3 then
			begin
				Write('Para volver al menú INGRESOS/EGRESOS oprima cualquier tecla... ');
				readkey;
			end;
}

	until (num_operacion=3)

END;


{*******    MOVIMIENTOS     ********}

procedure MovimientoEjemplar (var VecEjemplar: tv_ejemplar; var VecGenero: tv_genero;
                              LargoVecEjemplar: integer);

var
   NumEjemplar, PosEjemplar, NuevoPasillo, NuevoEstante : integer;


begin
     Ordenar_ejemplar(VecEjemplar, 1, LargoVecEjemplar); {Ordena VecEjemplar por id_ejemplar}
     clrscr;
     writeln('*****************************************');
     writeln('        Movimiento de Ejemplares         ');
     writeln('*****************************************');
     writeln;
     repeat
           write('N£mero de ejemplar: ');
           {$I-}
           readln(NumEjemplar);
           {$I+}
           if (IOResult<>0) or (NumEjemplar<=0)
           then begin
                writeln;
                writeln('Valor no v lido.');
                writeln('Presione una tecla para intentar de nuevo.');
                writeln;
                NumEjemplar:=0;
                end;
     until NumEjemplar>0;
     writeln;
     PosEjemplar := BuscarPos_Ejemplar(VecEjemplar, LargoVecEjemplar, NumEjemplar);
     if (PosEjemplar <> -1)
     then begin
          writeln('El ejemplar se encuentra en:');
          writeln('Pasillo: ', VecEjemplar[PosEjemplar].pasillo,'. Estante: ', VecEjemplar[PosEjemplar].estante,'.');
          writeln;
          repeat
                write('Ingrese nuevo pasillo: ');
                {$I-}
                readln(NuevoPasillo);
                {$I+}
                if (IOResult<>0) or (NuevoPasillo<=0) or (NuevoPasillo>MAX_PASILLOS)
                then begin
                     writeln;
                     writeln('Valor no v lido.');
                     writeln('Presione una tecla para intentar de nuevo.');
                     writeln;
                     NuevoPasillo:=0;
                end;
          until NuevoPasillo>0;
          writeln;
          repeat
                write('Ingrese nuevo estante: ');
                {$I-}
                readln(NuevoEstante);
                {$I+}
                if (IOResult<>0) or (NuevoEstante<=0) or (NuevoEstante>MAX_ESTANTES)
                then begin
                     writeln;
                     writeln('Valor no v lido.');
                     writeln('Presione una tecla para intentar de nuevo.');
                     writeln;
                     NuevoEstante:=0;
                end;
          until NuevoEstante>0;
          writeln;
          if BuscaGenero(VecGenero, NuevoPasillo, NuevoEstante)
             = BuscaGenero(VecGenero, VecEjemplar[PosEjemplar].pasillo, VecEjemplar[PosEjemplar].estante)
                    then begin
                         VecEjemplar[PosEjemplar].pasillo := NuevoPasillo;
                         VecEjemplar[PosEjemplar].estante := NuevoEstante;
                         writeln('El cambio se realizo satisfactoriamente');
                         end
                         else writeln('No coinciden los generos');
          writeln('Presione una tecla para continuar');
          readkey;
          end
     else begin
          writeln;
          writeln('El ejemplar ingresado no se encuentra.');
          readkey;
          end;
end;

procedure MovimientoEstantes (var VecEjemplar: tv_ejemplar; var VecGenero: tv_genero;
                              LargoVecEjemplar: integer);

var
   PasilloOrigen, EstanteOrigen: integer;
   PasilloDestino, EstanteDestino: integer;
   i: integer;


begin
     clrscr;
     writeln('*****************************************');
     writeln('          Movimiento de Estantes         ');
     writeln('*****************************************');
     writeln;
     writeln('DATOS DE ORIGEN');
     writeln('---------------');
     repeat
           write('Ingrese pasillo de origen: ');
           {$I-}
           readln(PasilloOrigen);
           {$I+}
           if (IOResult<>0) or (PasilloOrigen<=0) or (PasilloOrigen>MAX_PASILLOS)
           then begin
                writeln;
                writeln('Valor no v lido.');
                writeln('Presione una tecla para intentar de nuevo.');
                writeln;
                PasilloOrigen:=0;
                end
     until PasilloOrigen>0;
     repeat
           write('Ingrese estante de origen: ');
           {$I-}
           readln(EstanteOrigen);
           {$I+}
           if (IOResult<>0) or (EstanteOrigen<=0) or (EstanteOrigen>MAX_ESTANTES)
           then begin
                writeln;
                writeln('Valor no v lido.');
                writeln('Presione una tecla para intentar de nuevo.');
                writeln;
                EstanteOrigen:=0;
                end;
     until EstanteOrigen>0;
     writeln;
     writeln('DATOS DE DESTINO');
     writeln('----------------');
     repeat
           write('Ingrese pasillo de destino: ');
           {$I-}
           readln(PasilloDestino);
           {$I+}
           if (IOResult<>0) or (PasilloDestino<=0) or (PasilloDestino>MAX_PASILLOS)
           then begin
                writeln;
                writeln('Valor no v lido.');
                writeln('Presione una tecla para intentar de nuevo.');
                writeln;
                PasilloDestino:=0;
                end;
     until PasilloDestino>0;
     repeat
           write('Ingrese estante de destino: ');
           {$I-}
           readln(EstanteDestino);
           {$I+}
           if (IOResult<>0) or (EstanteDestino<=0) or (EstanteDestino>MAX_ESTANTES)
           then begin
                writeln;
                writeln('Valor no v lido.');
                writeln('Presione una tecla para intentar de nuevo.');
                writeln;
                EstanteDestino:=0;
                end;
     until EstanteDestino>0;
     writeln;
     if BuscaGenero(VecGenero, PasilloOrigen, EstanteOrigen) = BuscaGenero(VecGenero, PasilloDestino, EstanteDestino)
     then begin
          for i:=1 to LargoVecEjemplar do
          if (VecEjemplar[i].pasillo = PasilloOrigen) and (VecEjemplar[i].estante = EstanteOrigen)
          then begin
               VecEjemplar[i].pasillo:=PasilloDestino;
               VecEjemplar[i].estante:=EstanteDestino;
               end;
          writeln('Los moviemientos se efectuaron correctamente.');
          writeln('Presione una tecla.');
          end
     else begin
          writeln('Los datos ingresados no corresponden al mismo genero');
          writeln('Presione una tecla');
          end;
     readkey;
end;

{ ////// MOVIMIENTOS ///////}







{ * * *  M E N Ú  * * * }

procedure Menu_listados (var v_titulo : tv_titulo; var v_autor : tv_autor;
var v_genero : tv_genero; largo_titulo, largo_autor : integer);

var
	opt:byte;

Begin
	repeat
		ClrScr;
		writeln ('Men£ Listados');
		writeln ('-------------');
		writeln;
		writeln;
		writeln ('1.- Listado completo de t¡tulos');
		writeln;
		writeln ('2.- Listado completo de autores');
		writeln;
		writeln ('3.- Listado completo de g‚neros');
		writeln;
		writeln ('4.- Listado individual de t¡tulo por c¢digo');
		writeln;
		writeln ('5.- Listado individual de autor por c¢digo');
		writeln;
		writeln ('6.- Listado individual de g‚nero por c¢digo');
		writeln;
		writeln ('7.- Salir del men£ listados');
		writeln;
		write ('Elija una opci¢n: ');
		{$I-}  {*1}
		readln (opt);
		{$I+}	 {*1}
		if IOResult <> 0 then
			begin
				writeln ('Ingrese s¢lo n£meros por favor.');
				write ('Presione una tecla para ingresar nuevamente');
				readkey;
				opt:=0 {*2}
			end;

		case opt of
			1: listado_titulos (v_titulo, v_autor, v_genero, largo_titulo, largo_autor);
			2: listado_autores (v_autor, largo_autor);
			3: listado_generos (v_genero);
			4: listado_individual_titulo (v_titulo, v_autor, v_genero, largo_titulo, largo_autor);
			5: listado_individual_autor  (v_autor, largo_autor);
			6: listado_individual_genero (v_genero);
		end;

	until opt=7 {*3}

End;
{
*1 - Directivas para que no salga del programa si ingresa un valor no aceptado.
*2 - Para que vuelva al menú tras ingresar una tecla no permitida.
*3 - También puede ser 'until (opt <= 7) and (opt > 0)' para que salga después de listar.
}

Procedure Menu_movimientos (var v_genero : tv_genero; var v_ejemplar : tv_ejemplar;
                            largo_ejemplar : integer);

var
	opt:byte;

Begin
	repeat
		ClrScr;
		writeln ('Men£ Movimientos');
		writeln ('----------------');
		writeln;
		writeln;
		writeln ('1.- Movimiento de un ejemplar');
		writeln;
		writeln ('2.- Movimiento de estanterias');
		writeln;
		writeln ('3.- Salir');
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
				opt:=0
			end;

		case opt of
			1: MovimientoEjemplar (v_ejemplar, v_genero, largo_ejemplar);
			2: MovimientoEstantes (v_ejemplar, v_genero, largo_ejemplar);
                end;

	until opt=3

End;



{********* ALTA TITULO ***********}
procedure Borrar_desde_posicion(pos_Inicial:byte);
Var
   J,Y:byte;
Begin
	y:=wherey;
       	for J:=Pos_inicial to Y do
          begin	
		gotoxy(1,j);
                clreol;
          end;
       	gotoxy(1,Pos_inicial)
end;

function Valida_id(mensaje:string): integer;

var
   invalido:boolean;
   y:byte;
   id:integer;
begin
	invalido:= true;
	while invalido do
	   begin
		y:= whereY;
		write(mensaje);
		{$I-}
		    readln(id);
		{$I+}
		If IOResult <> 0 then
		   begin
			gotoXY(1,Y);
			clreol;
		   end
		 else
		       	invalido:= false;
	  end;
	valida_id:= id
end;


function Genero_del_Titulo(var v_genero:tv_genero):integer;

var
   j,yfinal,Y1,y:byte;
   Nombre,sms:string;
   tecla:char;
   id: integer;
begin

	Id:=0;
	while Id <= 0  do
	  begin
		Y:= wherey;
		sms:=' .- ID del Genero al Que quiere que pertenezca:';
		id:= valida_id(sms);

		if id <> 0 then
		   begin
			Nombre:= Buscar_genero(v_genero,id);
			if Nombre = '-1' then
		 	  begin

				writeln(' El ID debe estar entre 1 y ',MAX_GENERO);
				delay(1000);
                                Borrar_desde_posicion(Y);
                                id:=0
			   end
		       	Else
			   begin

				repeat
					Y1:=wherey;
                                        writeln(' el Género elegido es :', NOmbre);
					writeln('¨Es el que buscaba? s/n');
					  tecla:=readkey;

					if (tecla<>'n') or (tecla<>'s') then
					   Borrar_desde_posicion(Y1);

				until (tecla='n') or (tecla='s');

				if tecla='n' then
				   begin
					Borrar_desde_posicion(Y);
				   	id:= 0
				   end;


			   end
		   end;


		If id <= 0 then
		   begin
			Borrar_desde_posicion(Y);
			Id:=0;
               	   end
	   end;
	Genero_del_titulo:=id;

end;


function Autor_del_titulo(var v_autor:tv_autor; fin_autor:integer):integer;

var
   j,yfinal,Y1,Y:byte;
   sms,Nombre:string;
   id:integer;
   tecla:char;

begin
	Id:=-1;
	while id <=0 do
	  begin
		Y:= wherey;
		sms:=' .- ID del autor al que pertenece :';
		id:= valida_id(sms);

		if id > 0 then
		   begin
			Nombre:= Buscar_autor(v_autor,fin_autor,id);
    			if Nombre = '-1' then
		 	  begin
				writeln(' El ID ingresado NO pertenece a ningún autor ');
				delay(1000);
                                yfinal:=wherey;
                                for J:=Y to Yfinal do
                                   begin
				    gotoxy(1,j);
                                    clreol;
                                   end;
				gotoxy(1,y);
                                id:=0;
			   end
		       	Else
			   begin

				repeat
					Y1:=wherey;
                                        writeln(' el autor elegido es :', NOmbre);
					writeln('¨Es el que buscaba? s/n');
                                        tecla:=readkey;

					if (tecla<>'n') or (tecla<>'s') then
					   begin
						yfinal:=wherey;
                                                for J:=Y1 to Yfinal do
                                                    begin
				                         gotoxy(1,j);
                                                         clreol;
                                                         end;
						gotoxy(1,Y1)
					   end

				until (tecla='n') or (tecla='s');

				if tecla='n' then
				   begin
					yfinal:=wherey;
                                        for J:=Y to Yfinal do
                                          begin
				               gotoxy(1,j);
                                               clreol;
                                          end;
					gotoxy(1,y);
				   	id:= 0
				   end;


			   end
		   end
	   	else
				id:=0;

		If id <= 0 then
	   	    Borrar_desde_posicion(Y);
	   end;



	Autor_del_titulo:=id;

end;

function Obtener_Id_titulo(var v_titulo:tv_titulo):integer;
var
	pos,id:integer;
	y:byte;
	txt:string;
Begin
	Pos:=1;
	Id:=-1;
	while (Pos > 0) or ( id < 0) do
	  begin
		Y:=whereY;
		txt:=' Coloque un Id a el T¡tulo,entre 1  y 200 (0 para salir): ';
		id:= valida_ID(txt);
		Pos:= Check_existencia_titulo(v_titulo,Id);
		if (Pos > 0) then
		   begin
			writeln(' El Id ingresado ya está definido para otro Título');
			delay(1100);
			borrar_desde_posicion(Y);
		   end
		else if ((Id < 0) or (Id > 200)) then
		  begin
			writeln(' El Id del Titulo debe estar entre 1 y 200 ');
			delay(1100);
			borrar_desde_posicion(Y);
			id:= -1
		   end;
	  end;
	obtener_Id_titulo:=id;
end;

Procedure Alta_Titulo(var Vec_titulo: Tv_titulo;var vec_autor: Tv_autor;
var vec_Genero: Tv_genero;var largo_titulo:integer;largo_Autor:integer);

var
    Pos_titulo,Id_titulo,I,cod:integer;
    titulo: Tr_titulo;
    Id_autor,Id_genero:integer;
    Y,Y1:byte;
    tecla:char;
    txt:string;
Begin
	cod:=2;
        I:=1;
	while (vec_titulo[I].id_titulo > 0) and ( I <= MAX_TITULO) do
			I:= I + 1;

	If I > MAX_TITULO then
	   begin
		Writeln(' La lista de titulos esta llena, para ingresar uno borre otro');
		delay(1100);
		cod:=0;
	   end;


	If cod<>0 then
	 begin
		clrscr;
		writeln;
		Write(' Nombre : ');
		readln(titulo.Nombre);

		Id_titulo:= Obtener_Id_titulo(vec_titulo);

                If Id_titulo > 0 then
		   begin
			titulo.Id_titulo:=Id_titulo;

			titulo.id_autor:=Autor_del_titulo(vec_autor,largo_autor);


			titulo.id_genero:=genero_del_titulo(vec_genero);


			clrscr;
			writeln;
			writeln(' Datos del titulo ');
			writeln('------------------');
			writeln;
                	with titulo do
                	   begin
                	        write  ('NOmbre : ');
			        writeln(nombre);
			        write  ('Id del titulo (generado por el prog.) :');
			        writeln(I);
		  	      	write  ('Id de Autor : ');
			        writeln(id_autor);
		 		write  ('Id del Genero :');
		        	writeln(id_genero);
		        	writeln;
                   	   end;

				repeat
					Y1:=wherey;
					writeln('¿desea dar de alta este título? s/n ');
					{$I-}
					   read(tecla);
					{$I+}
					if (IOResult <> 0) or (tecla<>'n') or (tecla<>'s') then
					   begin
						gotoxy(1,Y1);
						clreol;
						gotoxy(1,Y1)
					   end
							
				until (tecla='n') or (tecla='s');

				if tecla='s' then
				   begin

					titulo.estado:=true;
					vec_titulo[I]:= titulo;
                                        largo_titulo:=largo_titulo + 1;
				   end
		   end;
		 	
	end;
 end;

{**************////// ALTA TITULO ///// *************}


{********* M O D I F I C A  T I T U L O **************}



Procedure Modifica_titulo(var v_titulo:tv_titulo;var V_autor: tv_autor;var V_genero:tv_genero;fin_autor:integer);
var
   nombre,mensaj,txt:string;
   posicion1,y,y1:byte;
   tecla:char;
   id_tit,posicion_titulo,opcion:integer;
   titulo:tr_titulo;
Begin
	clrscr;
	writeln;
	writeln(' Modificación de Títulos ');
	writeln(' ----------------------- ');
	writeln;
	repeat
		y:=whereY;
		Mensaj:='.- Ingrese el ID del Título a modificar(0 para salir): ';
		id_tit:=Valida_id(mensaj);

		if id_tit <> 0 then
		   begin
			Posicion_titulo:= check_existencia_titulo(v_titulo,id_tit);
	 		if posicion_titulo = -1 then
			   begin
				writeln;
				writeln('> NO existe título con ese ID ');
				delay(1100);
				Borrar_desde_posicion(Y);
			   end
		   end;
	until (Id_tit = 0) or (posicion_titulo <> -1);

	Borrar_desde_posicion(Y);

	if (id_tit <> 0) and (posicion_titulo <>-1) then
        begin
        titulo:=V_titulo[posicion_titulo];
	Writeln(' .- ¿Qué desea Modificar? ');
	writeln('    -------------------- ');
	writeln;
	with v_titulo[posicion_titulo] do
	   begin

		write  (' 1.- Nombre: ');
		writeln(Nombre);
		writeln;
		Write  (' 2.- ID:');
		writeln(Id_titulo);
		writeln;
		write  (' 3.- Autor: ');
		writeln(Id_Autor);
		writeln;
		write  (' 4.- Género: ');
		writeln(Id_genero);
		writeln;
		writeln(' 0.- Dejar de MOdificar este titulo: ');
		writeln;
	   	Posicion1:=whereY;
		repeat
                       	Txt:=' Eleccíon: ';
                        opcion:=Valida_Id(txt)

		until (opcion >-1) and (opcion <5);
	   end;
	Borrar_desde_posicion(posicion1);
	writeln;
	with titulo do
             begin
	Case opcion of
	   1: begin
	  	   Write(' Ingrese nuevo nombre');
	 	   readln(Nombre)
	      end;
	    2: Id_titulo:= Obtener_Id_titulo(v_titulo);
	    3: Id_autor := autor_del_titulo(v_autor,fin_autor);
	    4: Id_genero:= genero_del_titulo(v_genero);

	end;

        end;


	Writeln;

	repeat
		Y1:=wherey;
                Write(' ¿Desea aplicar cambios? s/n');
		{$I-}
		Readln(tecla);

		{$I+}
		if (IOResult <> 0) or(tecla<>'n') or (tecla<>'s') then
                         Borrar_desde_posicion(Y)

	until (tecla='n') or (tecla='s');

	if tecla='s' then
	  begin
                 v_titulo[posicion_titulo]:=titulo;

	  end;

end;
end;


{ * * *   BAJAS   * * * }
function Buscar_posicion_titulo (var v_titulo : tv_titulo; largo_titulo,id_titulo : integer) : integer;

var
	encontrado : boolean;
	i, resultado : integer;

Begin
	i:=1;
	resultado := -1;
	encontrado := false;
	while (i<=largo_titulo) AND (NOT (encontrado)) do
		begin
			if id_titulo = v_titulo[i].id_titulo then
				begin
					encontrado := true;
					resultado := i;
				end;
			inc(i)
		end;

	buscar_posicion_titulo := resultado;

End;


procedure Baja_logica_titulo (var v_titulo : tv_titulo; largo_titulo,id_titulo : integer);

var
	posicion : integer;

Begin
	posicion := buscar_posicion_titulo (v_titulo,largo_titulo,id_titulo);
	if posicion <> -1 then v_titulo[posicion].estado := false

End;


function Buscar_id_titulo_de_id_autor (var v_titulo : tv_titulo; largo_titulo, id_autor : integer) : integer;

var
	encontrado : boolean;
	i, resultado : integer;

Begin
	i:=1;
	resultado := -1;
	encontrado := false;
	while (i<=largo_titulo) AND (NOT (encontrado)) do
		begin
			if id_autor = v_titulo[i].id_autor then
				begin
					encontrado := true;
					resultado := v_titulo[i].id_titulo;
				end;
			inc(i)
		end;

	buscar_id_titulo_de_id_autor := resultado;

End;


function Ejemplares_de_titulo (var v_ejemplar : tv_ejemplar; var v_titulo : tv_titulo; largo_ejemplar, largo_titulo, id_titulo : integer) : boolean;

var
	i : integer;
	resultado,encontrado : boolean;

Begin
	i:=1;
	encontrado:= false;
	resultado := false;

	while (i<=largo_ejemplar) and (NOT (encontrado)) do
		begin
			if (id_titulo = v_ejemplar[i].id_titulo) then
				if (v_ejemplar[i].estado) then
					begin
						encontrado:=true;
						resultado :=true
					end;
			inc(i)
		end;

	ejemplares_de_titulo := resultado

End;

function Titulos_de_autor (var v_titulo : tv_titulo; largo_titulo, id_autor : integer) : boolean;

var
	id_titulo : integer;
	resultado : boolean;

Begin
	resultado := true;
	id_titulo := buscar_id_titulo_de_id_autor (v_titulo,largo_titulo,id_autor);

	if (id_titulo = -1) then resultado := false;

	titulos_de_autor := resultado;

End;


function Buscar_posicion_autor (var v_autor : tv_autor; largo_autor : integer; id_autor : integer) : integer;

var
	encontrado : boolean;
	i, resultado : integer;

Begin
	i:=1;
	resultado := -1;
	encontrado := false;
	while (i<=largo_autor) AND (NOT (encontrado)) do
		begin
			if id_autor = v_autor[i].id_autor then
				begin
					encontrado := true;
					resultado := i;
				end;
			inc(i)
		end;

	buscar_posicion_autor := resultado;

End;
 

procedure Baja_logica_autor (var v_autor : tv_autor; largo_autor,id_autor : integer);

var posicion : integer;

Begin

	posicion := buscar_posicion_autor (v_autor,largo_autor,id_autor);
	if posicion <> -1 then v_autor[posicion].estado := false

End;

procedure Baja_autor (var v_autor : tv_autor; var v_titulo : tv_titulo; largo_autor,largo_titulo : integer);

var
	id_autor : integer;
	opt : char;
	error,tiene_titulos : boolean;
	nombre_autor : string;

Begin
	error := true;
	while (error) do
	begin
		error:= false;
		ClrScr;
		writeln ('BAJA DE AUTORES');
		writeln ('---------------');
		writeln;
		writeln;
		write ('Ingrese el ID del autor que desea dar de baja (0 para salir): ');
		{$I-}
		readln (id_autor);
		{$I+}
		if (IOResult <> 0) then 
			begin
				error:= true;
				writeln ('Ingrese s¢lo n£meros por favor.');
				write ('Presione una tecla para ingresar nuevamente...');
				readkey
			end
	end;


	if id_autor<>0 then
	begin
		nombre_autor := buscar_autor (v_autor,largo_autor,id_autor);
		if (nombre_autor <> '-1') then
			begin
				tiene_titulos := titulos_de_autor (v_titulo,largo_titulo,id_autor);
				if tiene_titulos then
					begin
						writeln ('En la biblioteca hay titulos que pertenecen al autor ',nombre_autor,'.');
						writeln ('Si desea eliminarlo, primero debe eliminar dichos titulos');
						readkey;
					end
				else
					begin
						write ('¨Confirma la baja del autor ',nombre_autor,'? (S/N): ');
						readln (opt);
						if ((opt = 's') OR (opt = 'S')) then 
							begin
								baja_logica_autor (v_autor,largo_autor,id_autor);
								writeln ('Baja realizada exitosamente');
								readkey;
							end;
					end;
			end
		else
			begin
				writeln ('El ID ingresado no coresponde a ning£n autor');
				writeln ('Presione una tecla para volver al men£...');
				readkey;
			end;
	end
End;



procedure Baja_titulo (var v_ejemplar : tv_ejemplar; var v_titulo : tv_titulo; largo_ejemplar,largo_titulo : integer);

var
	id_titulo : integer;
	opt : char;
	error,tiene_ejemplares : boolean;
	reg_titulo : tr_titulo;

Begin
	error := true;
	while (error) do
	begin
		error:= false;
		ClrScr;
		writeln ('BAJA DE TITULOS');
		writeln ('---------------');
		writeln;
		writeln;
		write ('Ingrese el ID del titulo que desea dar de baja (0 para salir): ');
		{$I-}
		readln (id_titulo);
		{$I+}
		if (IOResult <> 0) then
			begin
				error:= true;
				writeln ('Ingrese s¢lo n£meros por favor.');
				write ('Presione una tecla para ingresar nuevamente...');
				readkey
			end
	end;


	if id_titulo<>0 then
	begin
		buscar_titulo (v_titulo,reg_titulo,largo_titulo,id_titulo);

		if (reg_titulo.estado) then
			begin
				tiene_ejemplares := ejemplares_de_titulo (v_ejemplar,v_titulo,largo_ejemplar,largo_titulo,reg_titulo.id_titulo);
				if tiene_ejemplares then
					begin
						writeln ('En la biblioteca hay ejemplares de "',reg_titulo.nombre,'".');
						writeln ('Si desea eliminar el titulo, primero debe eliminar dichos ejemplares');
						readkey;
					end
				else
					begin
						write ('¨Confirma la baja del titulo ',reg_titulo.nombre,'? (S/N): ');
						readln (opt);
						if ((opt = 's') OR (opt = 'S')) then 
							begin
								baja_logica_titulo (v_titulo,largo_titulo,id_titulo);
								writeln ('Baja realizada exitosamente');
								readkey;
							end
					end;
			end
	end
End;

{ * * *  / B A J A S  * * * }

{ * * *   A L T A   A U T O R   * * * }
Procedure Alta_Autor (var v_autor:tv_autor; var largo_autor : integer);

var
	id_au, pos_au : integer;
	error : boolean;

Begin

	if largo_autor = max_autor then
		Writeln ('Ya no se pueden ingresar más autores')
	else 
		begin
			error:= true;
			while error do
				begin
					ClrScr;
					writeln (' ALTA DE AUTOR');
					writeln ('--------------------------');
					writeln;
					error:=false;
					writeln ('Ingrese ID ');
					{$I-}
					readln (id_au);
					{$I+}
					if IOResult<>0 then 
						begin
							error:=true;
							writeln ('Ingrese sólo números positivos');
							readkey;
						end
					else
						if (id_au > MAX_AUTOR) then
							begin
								error:=true;
								writeln ('El ID debe estar entre 1 y ',MAX_AUTOR);
								readkey;
							end;
				end;

			pos_au := buscar_posicion_autor (v_autor,largo_autor,id_au);
			if (pos_au=-1) then 
				begin	
					v_autor[largo_autor+1].id_autor:=id_au;
					v_autor[largo_autor+1].estado:=true;
					Writeln;
					Write ('Ingrese el nombre del autor: ');
					readln (v_autor [largo_autor+1].nombre);
					Writeln;
					Writeln ('Las modificaciones se han realizado correctamente');
					largo_autor:=largo_autor+1;
					readkey;
				end
			else
				If  (not (v_autor[pos_au].estado)) then
					begin
						v_autor[pos_au].estado:=true;
						Writeln;
						Write ('Ingrese el nombre del autor: ');
						readln (v_autor [pos_au].nombre);
						Writeln;
						Writeln ('Las modificaciones se han realizado correctamente');
						readkey;
					end
				else
					begin
						Writeln;
						Writeln('El id ya esta siendo utilizado para otro autor');
						readkey;
					end;
		end;
end;	

{ * * *   / A L T A    A U T O R   * * * }



Procedure Menu (var v_titulo : tv_titulo; var v_autor : tv_autor;
var v_genero : tv_genero; var v_ejemplar : tv_ejemplar; largo_titulo, largo_autor, largo_ejemplar : integer);

var
	opt:byte;

Begin
	repeat
		ClrScr;
		writeln ('Men£ Principal');
		writeln ('--------------');
		writeln;
		writeln;
		writeln ('1.- Visualizacion');
		writeln;
		writeln ('2.- Listados');
		writeln;
		writeln ('3.- Ingresos/Egresos');
		writeln;
		writeln ('4.- Movimientos');
		writeln;
		writeln ('5.- Salir');
		writeln;
		writeln ('6.- Alta Titulo');
		writeln;
		writeln ('7.- Modifcacion Titulo');
		writeln;
		writeln ('8.- Baja Autor');
		writeln;
		writeln ('9.- Baja Titulo');
		writeln;
		writeln ('10.- Alta Autor');
		writeln;
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
				opt:=0
			end;

		case opt of
                	1: Visualizaciones(v_titulo,v_ejemplar,v_autor,v_genero,largo_autor,largo_titulo,largo_ejemplar);
			2: Menu_listados (v_titulo, v_autor, v_genero, largo_titulo, largo_autor);
			3: Menu_ingreso_egreso (v_ejemplar, v_titulo, v_genero, largo_ejemplar);
			4: Menu_movimientos (v_genero, v_ejemplar, largo_ejemplar);
			6: Alta_titulo(V_titulo,V_autor,v_genero,largo_titulo,largo_Autor);
                        7: Modifica_titulo(V_titulo,V_autor,v_genero,largo_autor);
			8: Baja_autor (v_autor,v_titulo,largo_autor,largo_titulo);
			9: Baja_titulo (v_ejemplar,v_titulo,largo_ejemplar,largo_titulo);
			10: Alta_Autor (v_autor,largo_autor);

		end;

	until opt=5

End;


{ * * *  / M E N Ú  * * * }

	


{  * * *  L I M P I E Z A  * * *  }

procedure Limpiar_autor (var vector : tv_autor; var largo : integer);

var
	i,j : integer;
	v_aux : tv_autor;

Begin
	j:=1;
	for i:=1 to largo do
		if vector[i].estado then
		begin
			v_aux[j] := vector[i];
			inc(j)
		end;

	vector := v_aux;
	largo:=j-1

End;


procedure Limpiar_titulo (var vector : tv_titulo; var largo : integer);

var
	i,j : integer;
	v_aux : tv_titulo;

Begin
	j:=1;
	for i:=1 to largo do
		if vector[i].estado then
		begin
			v_aux[j] := vector[i];
			inc(j)
		end;

	vector := v_aux;
	largo:=j-1

End;


procedure Limpiar_ejemplar (var vector : tv_ejemplar; var largo : integer);

var
	i,j : integer;
	v_aux : tv_ejemplar;

Begin
	j:=1;
	for i:=1 to largo do
		if vector[i].estado then
		begin
			v_aux[j] := vector[i];
			inc(j)
		end;

	vector := v_aux;
	largo:=j-1

End;


procedure Limpieza (var v_titulo : tv_titulo;  var v_autor : tv_autor; var v_ejemplar : tv_ejemplar;
var largo_titulo,largo_autor,largo_ejemplar : integer); {*1,*2}

Begin

	Limpiar_autor (v_autor,largo_autor);
	Limpiar_titulo (v_titulo,largo_titulo);
	Limpiar_ejemplar (v_ejemplar,largo_ejemplar);

End;
{
*1 - Debido a que nos manejamos con bajas lógicas, este procedimiento hace las físicas
*2 - Dependiendo de la intensidad de uso del programa, este procedimiento podría
ser llamado más veces. Por ejemplo, cada vez que vuelve al menú
}


{ * * *  / L I M P I E Z A  * * * }


{ * * *  D E C L A R A C I O N   D E   V A R I A B L E S  * * * }

var
	v_genero				:	tv_genero;
	v_autor					:	tv_autor;
	v_titulo				:	tv_titulo;
	v_ejemplar				:	tv_ejemplar;
	largo_titulo,largo_autor,largo_ejemplar	:	integer;

{ * * *  / D E C L A R A C I O N   D E   V A R I A B L E S  * * * }


{ * * *  P R O G R A M A   P R I N C I P A L  * * * }

BEGIN

	largo_autor	:= 0;
	largo_titulo	:= 0;
	largo_ejemplar	:= 0;

	Inicializar_genero (v_genero);
	Inicializar_autor (v_autor,largo_autor);
	Inicializar_titulo (v_titulo,largo_titulo);
	Inicializar_ejemplar(v_ejemplar,largo_ejemplar);
	Menu (v_titulo, v_autor, v_genero, v_ejemplar, largo_titulo, largo_autor, largo_ejemplar);
	Limpieza (v_titulo,v_autor,v_ejemplar,largo_titulo,largo_autor,largo_ejemplar);
	
END.

{ * * *  / P R O G R A M A   P R I N C I P A L  * * * }
