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
		nombre		:	string [30];
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


Procedure Inicializar_ejemplar(var vec:TV_ejemplar;var largo:integer);
var
	I:integer;

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
	v_autor[1].id_autor		:= 1;
	v_autor[1].nombre			:= 'Bla bla';
	v_autor[1].estado			:= true;

	v_autor[2].id_autor		:= 2;
	v_autor[2].nombre			:= 'Juan Pablo';
	v_autor[2].estado			:= true;

	v_autor[3].id_autor		:= 3;
	v_autor[3].nombre			:= 'Roberto G¢mez';
	v_autor[3].estado			:= true;

	v_autor[4].id_autor		:= 4;
	v_autor[4].nombre			:= 'Pedro Pablo';
	v_autor[4].estado			:= true;

	v_autor[5].id_autor		:= 5;
	v_autor[5].nombre			:= 'Pl cido Domingo';
	v_autor[5].estado			:= true;

	v_autor[6].id_autor		:= 6;
	v_autor[6].nombre			:= 'Ra£l Gomez';
	v_autor[6].estado			:= true;

	v_autor[7].id_autor		:= 7;
	v_autor[7].nombre			:= 'Don Torcuato';
	v_autor[7].estado			:= true;

	v_autor[8].id_autor		:= 8;
	v_autor[8].nombre			:= 'Dado de baja';
	v_autor[8].estado			:= false;

	v_autor[9].id_autor		:= 9;
	v_autor[9].nombre			:= 'John Hopkins';
	v_autor[9].estado			:= true;

	v_autor[10].id_autor	:= 10;
	v_autor[10].nombre		:= 'Lula da Silva';
	v_autor[10].estado		:= true;

	v_autor[11].id_autor	:= 11;
	v_autor[11].nombre		:= 'Peter Crouch';
	v_autor[11].estado		:= true;

	v_autor[12].id_autor	:= 12;
	v_autor[12].nombre		:= 'Baldomero';
	v_autor[12].estado		:= true;
	
	v_autor[13].id_autor	:= 13;
	v_autor[13].nombre		:= 'Random Guy';
	v_autor[13].estado		:= true;

	v_autor[14].id_autor	:= 14;
	v_autor[14].nombre		:= 'Pablo Picasso';
	v_autor[14].estado		:= true;

	v_autor[15].id_autor	:= 15;
	v_autor[15].nombre		:= 'Ernest Hemingway';
	v_autor[15].estado		:= true;

	v_autor[16].id_autor	:= 16;
	v_autor[16].nombre		:= 'Homero Simpson';
	v_autor[16].estado		:= true;

	v_autor[17].id_autor	:= 17;
	v_autor[17].nombre		:= 'Dado de baja';
	v_autor[17].estado		:= false;

	v_autor[18].id_autor	:= 18;
	v_autor[18].nombre		:= 'Dado de baja';
	v_autor[18].estado		:= false;

	v_autor[19].id_autor	:= 19;
	v_autor[19].nombre		:= 'Ludovica Squirru';
	v_autor[19].estado		:= true;

	v_autor[20].id_autor	:= 20;
	v_autor[20].nombre		:= 'Roger Federer';
	v_autor[20].estado		:= true;

	v_autor[21].id_autor	:= 21;
	v_autor[21].nombre		:= 'Peter Griffin';
	v_autor[21].estado		:= true;

	v_autor[22].id_autor	:= 22;
	v_autor[22].nombre		:= 'Alessandra Tu Sex¢loga';
	v_autor[22].estado		:= true;

	v_autor[23].id_autor	:= 23;
	v_autor[23].nombre		:= 'Horangel';
	v_autor[23].estado		:= true;

	v_autor[24].id_autor	:= 24;
	v_autor[24].nombre		:= 'Donatello';
	v_autor[24].estado		:= true;

	v_autor[25].id_autor	:= 25;
	v_autor[25].nombre		:= 'Domino Harvey';
	v_autor[25].estado		:= false;

	v_autor[26].id_autor	:= 26;
	v_autor[26].nombre		:= 'Atahualpa Yupanqui';
	v_autor[26].estado		:= true;

	largo_autor := 26
End;


procedure Inicializar_genero (var v_genero : tv_genero);

Begin
	with v_genero[1] do
		begin
			id_genero				:= 1;
			nombre					:= 'Novela';
			pasillo_inicial	:= 1;
			estante_inicial	:= 1;
			pasillo_final		:= 2;
			estante_final		:= 10
		end;

	with v_genero[2] do
		begin
			id_genero				:= 2;
			nombre					:= 'Ensayo';
			pasillo_inicial	:= 2;
			estante_inicial	:= 11;
			pasillo_final		:= 4;
			estante_final		:= 2
		end;

	with v_genero[3] do
		begin
			id_genero				:= 3;
			nombre					:= 'Ciencia';
			pasillo_inicial	:= 4;
			estante_inicial	:= 3;
			pasillo_final		:= 6;
			estante_final		:= 9
		end;

	with v_genero[4] do
		begin
			id_genero				:= 4;
			nombre					:= 'Humanidades';
			pasillo_inicial	:= 6;
			estante_inicial	:= 10;
			pasillo_final		:= 7;
			estante_final		:= 13
		end;

	with v_genero[5] do
		begin
			id_genero				:= 5;
			nombre					:= 'Infantil';
			pasillo_inicial	:= 7;
			estante_inicial	:= 14;
			pasillo_final		:= 8;
			estante_final		:= 8
		end;

	with v_genero[6] do
		begin
			id_genero				:= 6;
			nombre					:= 'Diccionarios';
			pasillo_inicial	:= 8;
			estante_inicial	:= 9;
			pasillo_final		:= 9;
			estante_final		:= 11
		end;

	with v_genero[7] do
		begin
			id_genero				:= 7;
			nombre					:= 'Otros';
			pasillo_inicial	:= 9;
			estante_inicial	:= 12;
			pasillo_final		:= 10;
			estante_final		:= 15
		end

End;


procedure Inicializar_titulo (var v_titulo : tv_titulo; var largo_titulo : integer);

Begin
	
		with v_titulo[1] do
			begin
				id_titulo := 1;
				nombre		:= 'Tennis';
				id_Autor	:= 20;
				id_Genero	:= 7;
				estado		:= true
			end;

		with v_titulo[2] do
			begin
				id_titulo := 2;
				nombre		:= 'Family Guy';
				id_Autor	:= 21;
				id_Genero	:= 7;
				estado		:= true
			end;

		with v_titulo[3] do
			begin
				id_titulo := 3;
				nombre		:= 'Italiano-Ruso';
				id_Autor	:= 13;
				id_Genero	:= 6;
				estado		:= true
			end;

		with v_titulo[4] do
			begin
				id_titulo := 4;
				nombre		:= 'Las Tortugas Ninja';
				id_Autor	:= 24;
				id_Genero	:= 5;
				estado		:= true
			end;

		with v_titulo[5] do
			begin
				id_titulo := 5;
				nombre		:= 'To Have and Have Not';
				id_Autor	:= 15;
				id_Genero	:= 1;
				estado		:= true
			end;

		with v_titulo[6] do
			begin
				id_titulo := 6;
				nombre		:= 'Ciencias Naturales y Sociales';
				id_Autor	:= 3;
				id_Genero	:= 3;
				estado		:= true
			end;

	with v_titulo[7] do
		begin
			id_titulo := 7;
			nombre		:= 'Caza-recompensas';
			id_Autor	:= 25;
			id_Genero	:= 7;
			estado		:= true
		end;

	with v_titulo[8] do
		begin
			id_titulo := 8;
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

procedure Ordenar_autor (var v_autor : tv_autor; tipo, largo_autor : integer);

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


procedure Ordenar_titulo (var v_titulo : tv_titulo; tipo, largo_titulo : integer);

var
	i,j : integer;
	aux : tr_titulo;

Begin
	if tipo = 1 then  {*1}
		for i:=1 to (largo_titulo-1) do
			for j:=1 to (largo_titulo-i) do
				if (v_titulo[j].id_titulo > v_titulo[j+1].id_titulo) then
					begin
						aux := v_titulo[j];
						v_titulo[j] := v_titulo[j+1];
						v_titulo[j+1] := aux
					end;

	if tipo = 2 then  {*1}
		for i:=1 to (largo_titulo-1) do
			for j:=1 to (largo_titulo-i) do
				if (v_titulo[j].nombre > v_titulo[j+1].nombre) then
					begin
						aux := v_titulo[j];
						v_titulo[j] := v_titulo[j+1];
						v_titulo[j+1] := aux
					end;

	if tipo = 3 then  {*1}
		for i:=1 to (largo_titulo-1) do
			for j:=1 to (largo_titulo-i) do
				if (v_titulo[j].id_autor > v_titulo[j+1].id_autor) then
					begin
						aux := v_titulo[j];
						v_titulo[j] := v_titulo[j+1];
						v_titulo[j+1] := aux
					end;

	if tipo = 4 then  {*1}
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
*1 - En vez de los cuatro IFs se podría hacer con un CASE, pero en los CASE me parece que queda
desprolijo si se usa código de más de una línea
}


procedure Ordenar_ejemplar (var v_ejemplar : tv_ejemplar; tipo, largo_ejemplar : integer);

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

begin
     i := 1;
     Encontrado := False;
     while not Encontrado do
           with V_Genero[i] do
           begin
                if (Pasillo>=pasillo_inicial) and (Pasillo<=pasillo_final)
                and (Estante>=estante_inicial) and (Estante<=estante_final)
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
							writeln ('ID       Nombre                  Autor                    Género'); {*2}
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


{ * * *  L I S T A D O S   I N D I V I D U A L E S * * *  }

procedure listado_individual_autor (var v_autor : tv_autor; largo_autor : integer);

var
	id_autor	:	integer;

Begin
	repeat
		ClrScr;
		write ('Ingrese el c¢digo del autor que quiere listar: ');
		{$I-}  {*1}
		readln (id_autor);
		{$I+}  {*1}
		if IOResult<>0 then
			begin
				writeln ('Ingrese s¢lo n£meros positivos');
				id_autor := -1;
			end;
		if (id_autor > 0) AND (id_autor <= largo_autor) then
			begin
				if (buscar_autor (v_autor, largo_autor, id_autor)) <> '-1' then
					begin
						writeln ('ID: ',id_autor);
						writeln ('Nombre: ',buscar_autor (v_autor, largo_autor, id_autor))
					end
				else
					write ('No existe un autor con ese c¢digo...')
			end
		else
			begin
				if id_autor<>-1 then write ('No existe un autor con ese c¢digo...');
			end;

	readkey;
	until (id_autor > 0) AND (id_autor <= largo_autor);

End;
{
*1 - Directivas para que no salga del programa si ingresa un valor no aceptado.
}


procedure listado_individual_genero (var v_genero : tv_genero);

var
	id_genero	:	integer;

Begin
	repeat
		ClrScr;
		write ('Ingrese el c¢digo del g‚nero que quiere listar: ');
		{$I-}  {*1}
		readln (id_genero);
		{$I+}  {*1}
		if IOResult<>0 then
			begin
				writeln ('Ingrese s¢lo n£meros positivos');
				id_genero := -1;
			end;
		if (id_genero > 0) AND (id_genero <= 7) then
			begin
				writeln ('ID: ',id_genero);
				writeln ('Nombre: ',buscar_genero (v_genero,id_genero));
				readkey
			end
		else
			begin
				if id_genero<> -1 then write ('No existe un g‚nero con ese c¢digo...');
				write ('Presione una tecla para ingresar nuevamente');
				readkey;
			end;
	until (id_genero > 0) AND (id_genero <= 7);

End;
{
*1 - Directivas para que no salga del programa si ingresa un valor no aceptado.
}


procedure listado_individual_titulo (var v_titulo : tv_titulo; var v_autor : tv_autor;
var v_genero : tv_genero; largo_titulo, largo_autor : integer);

var
	id_titulo			:	integer;
	reg_titulo		: tr_titulo;
	autor,genero	: string;

Begin
	repeat
		ClrScr;
		write ('Ingrese el c¢digo del t¡tulo que quiere listar: ');
		{$I-}  {*1}
		readln (id_titulo);
		{$I+}  {*1}
		if IOResult<>0 then
			begin
				writeln ('Ingrese s¢lo n£meros positivos');
				id_titulo := -1;
			end;
		if (id_titulo > 0) AND (id_titulo <= largo_titulo) then
			begin
				Buscar_titulo (v_titulo, reg_titulo, largo_titulo, id_titulo); {*2}

				if (reg_titulo.estado){ AND (autor <> '-1') }then
					begin
						with reg_titulo do
						begin
							autor := Buscar_autor(v_autor,largo_autor,id_autor);
							genero := Buscar_genero(v_genero,id_genero);

							writeln ('ID: ',id_titulo);
							writeln ('Nombre: ',nombre);
							writeln ('Autor: ',autor);
							writeln ('G‚nero: ',genero)
						end
					end
				else
					begin
						writeln ('No existe un t¡tulo con ese c¢digo...');
						id_titulo:=0
					end

			end
		else
			begin
				if id_titulo<> -1 then write ('No existe un t¡tulo con ese c¢digo...');
				write ('Presione una tecla para ingresar nuevamente');
			end;

	readkey;
	until (id_titulo > 0) AND (id_titulo <= largo_titulo);

End;
{
*1 - Directivas para que no salga del programa si ingresa un valor no aceptado.
*2 - Devuelve el registro completo del ejemplar buscado.
}

{ * * *  / L I S T A D O S   I N D I V I D U A L E S * * *  }



Function GetColoryCaracter(cod: byte):char;
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

	getColoryCaracter:= caracter
end;

Procedure MuestraMapa(P_Inic,E_Inic,P_fin,E_fin,Codigo: byte);
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

	Car:= GetColorycaracter(codigo);



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


Procedure VisualizaGeneros(var VecGeneros: Tv_Genero);
{* Va a Mostrar Los Generos, en forma de plano *}
var
	inicio,fin,k,I,J: byte;
	x,y: byte;
	Carac: char;
Begin
        TextBackground(15);
        TextColor(16);
        clrscr;
	Writeln(' Distribuci¢n de Generos en la Biblioteca');
	MuestraMapa(1,1,10,15,0);

	For J:= 1 to Max_Genero do
	begin
		With Vecgeneros[J] do
			MuestraMapa(Pasillo_inicial,estante_inicial,Pasillo_final,estante_final,J);
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
		          Carac:= GetColoryCaracter(I);
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



Function CheckTitulo(var Titulos: Tv_Titulo; Codigo: Integer): Integer;
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
		CheckTitulo:= -1
	else
		CheckTitulo:= I;
 End;


Procedure BuscaTitulo(var vecTitulo: Tv_Titulo; var PosTit: Integer; Var Cod_Titulo: Integer);
{* Una segunda validación del codigo de titulo ingresado *}
{* Llama a checkTitulo para saber si existe *}

 Begin

	PosTit:=-1;
	While (PosTit < 0) and (cod_titulo<>0) do
	Begin
                Cod_Titulo:=0;
		ClrScr;
		Writeln(' Visualizaci¢n De Informaci¢n por Titulo');
		Write('Ingrese Codigo de Titulo(0 para salir): ');
		Readln(Cod_titulo);

		PosTit:= CheckTitulo(VecTitulo,Cod_Titulo);
		If (PosTit = -1) and ( Cod_Titulo > 0) then
		Begin
			Writeln('El codigo de Titulo ingresado NO Existe');
			Delay(1500)
		end
	end
 end;


Function GetAutor(var VecAutor:Tv_Autor;Codigo:Integer):String;
{* Obtiene el Nombre del autor correstondiente al Id de titulo ingresado *}
{* regresa el string con el nombre del autor, si no lo encuentra tambián avisa *}
var
    I:integer;
    Encontrado:Boolean;

Begin
	I:=1;
	Encontrado:= False;
	While not Encontrado and (I<= Max_Autor) and (VecAutor[I].Id_Autor <> 0) do
	Begin
		With VecAutor[I] do
		Begin
			If (Id_Autor = Codigo) and estado then
				Encontrado:=True
			else
				I:=I +1
		end
	end;

	If Encontrado then
		GetAutor:=VecAutor[I].Nombre
	else
		GetAutor:='No Establecido';
end;


Function GetGenero(VecGenero:Tv_Genero;Codigo:Integer):String;
{* Obtiene el Nombre del Genero correstondiente al Id de titulo ingresado *}
{* regresa el string con el nombre del autor, si no lo encuentra tambián avisa *}

 var
   I:Integer;
   Encontrado:Boolean;

 Begin
	I:=1;
	Encontrado:= false;
	While not Encontrado and (I<= Max_Genero) and (VecGenero[I].Id_Genero <> 0)do
	Begin

		If VecGenero[I].Id_Genero = Codigo then
			Encontrado:=True
		else
			I:=I +1;
	end;

	If Encontrado then
		Getgenero:=VecGenero[I].Nombre
	else
		Getgenero:='No Establecido';
 end;


Procedure GetPosEjemplar(Ejemplares: Tv_Ejemplar;Cod:Integer;var Posicion:Integer);
{* Busca en que posicion se encuantra ejemplares que tengan Id_Titulo igual a cod*}
{* Comienza a buscar en la "Posicion" ingresada mas 1 *}
 var
   I:integer;
   Encontrado:Boolean;
Begin
	I:=Posicion+1;
	Encontrado:= false;
	While not Encontrado and (I<= Max_Ejemplar) do
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


Procedure VisualizaEjemplar(Ejemplares:Tv_Ejemplar; COdTitulo:Integer;NomTitulo:String);
{* Busca y manda a mostrar los ejemplares con el codigo de titulo ingresado *}

var
   Pos:Integer;
   car:char;
Begin
        textcolor(16); {* Negro *}
        textbackground(15); {* Blanco *}
        clrscr;

	MuestraMapa(1,1,10,15,0);
        car:= GetColoryCaracter(8);

        gotoXY(2,22);
	Write(Car,' ');
        Textcolor(16); {* Negro *}
	Writeln('Ubicaci¢n de los ejemplares del titulo : ',NomTitulo);
	Write('Presione cualquier tecla para continuar');

	Pos:=0;
	GetPosEjemplar(Ejemplares,CodTitulo,Pos);
	While Pos > 0 do
	Begin
		With Ejemplares[Pos] do
		begin

			MuestraMapa(Pasillo,estante,Pasillo,Estante,8);
		end;
		GetPosEjemplar(Ejemplares,CodTitulo,Pos)
	end;
	Readkey;

 end;


Procedure PorTitulo(var VecTit: Tv_Titulo;var vecEjem: Tv_Ejemplar;var vecAutor:Tv_Autor;var VecGen:Tv_Genero);
{* Establece y llama a todos los procedimientos y funciones necesarios  para
   mostrar los datos De los Titulos de la Biblioteca *}
var
   PosY:byte;
   Codigo:integer;
   Pos,Posicion:integer;
   NGenero,NAutor:String;
Begin
	Codigo:=1;
	While Codigo> 0 do
	begin
		BuscaTitulo(VecTit,Posicion,Codigo);
		Clrscr;

		If codigo > 0 then
		Begin
			With VecTit[Posicion] do
			begin
				Ngenero:= Getgenero(VecGen,Id_Genero);
				NAutor:= GetAutor(VecAutor,Id_Autor);

				Write('Id de titulo: ');
				Writeln(Codigo);
				Write('Titulo: ');
				Writeln(Nombre);
				Write('Autor: ');
				Writeln(NAutor);
				Write('Genero: ');
				Writeln(NGenero);
			end;
			Writeln('Presione cualquier tecla para ver los ejemplares de este Titulo ');
			Readkey;
			ClrScr;
			Pos:=0;
			GetPosEjemplar(vecEjem,Codigo,Pos);
			While Pos > 0 do
			Begin

				With VecEjem[Pos] do
				begin
					Write('Id Ejemplar: ');
					Writeln(Id_Ejemplar);
					Write('Ubicaci¢n: Pasillo: ');
					Writeln(Pasillo);
					Write('           Estante: ');
					Writeln(Estante);
			    	   	Writeln('----------------------');
					Writeln('');
					PosY:= WhereY;
					Writeln('Presione cualquier tecla para continuar ');
					Readkey;
					GotoXY(1,PosY);
                                        ClrEol;

				end;
				GetPosEjemplar(vecEjem,Codigo,Pos);

			end;
                        Clrscr;

			VisualizaEjemplar(VecEjem,Codigo,VecTit[Posicion].Nombre);
                        textcolor(15); {* Blanco *}
                        textbackground(0) {* Negro *}
		end
	end
end;


Procedure Visualizaciones(var VecTitulos: Tv_Titulo;var vecEjemplares: Tv_Ejemplar;
        var vecAutores:Tv_Autor;var VecGeneros:Tv_Genero);
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
                 Writeln(' - 1 - Mapa Por genero');
                 Writeln(' - 2 - Ubicaci¢n en el mapa por T¡tulo');
                 Writeln(' - 0 - Volver');
                 Write(' Elecci¢n :');
                 Readln(eleccion);
            end;

            Case Eleccion of
                 1: VisualizaGeneros(VecGeneros);
                 2: PorTitulo(vecTitulos,vecEjemplares,vecAutores,VecGeneros);
            end;

      end;

end;


FUNCTION POSICION_EJEMPLAR (ID:integer;var EJEMPLAR:Tv_ejemplar;LONG_VECTOR:BYTE):INTEGER;

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

FUNCTION POSICION_ID_TITULO (ID:integer;var TITULO:Tv_titulo):integer;

	var
		encontrado:boolean;
		i:byte;

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
    ubicacion_inicial,ubicacion_final,ubicacion_buscada : integer;
		
		begin

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

{			while ((k<=estante_fin) or (i<pasillo_fin)) and (not (encontrado)) do

      	begin
					if ((pas =i) and (est=k))then
						encontrado:=true;

					K:=k+1;

					if k=MAX_ESTANTES+1 then
						begin
							i:=i+1;
							k:=1;
						end;

			end;}

	ubicacion_inicial:=pasillo_inicio*100 + estante_inicio;
	ubicacion_buscada:=pas*100 + est;
	ubicacion_final:=pasillo_fin*100 + estante_fin;
	
	while ((ubicacion_inicial<=ubicacion_final) and (not encontrado)) do
	begin
		if ubicacion_inicial = ubicacion_buscada then
			encontrado:=true;

		if ((ubicacion_inicial-MAX_ESTANTES) mod 100) = 0 then
		begin
				ubicacion_inicial:=	ubicacion_inicial - MAX_ESTANTES;
				ubicacion_inicial:= ubicacion_inicial + 100;
		end;
		inc(ubicacion_inicial);
	end;
	
      pasillo_estante_valido:=encontrado;
		
		end;


PROCEDURE INGRESO (VAR EJEMPLAR: TV_EJEMPLAR; VAR TITULO:TV_TITULO; VAR GENERO: TV_GENERO; var LONG_VECTOR:INTEGER);

		var
   		id:Byte;
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
				begin
					writeln ('Ingrese s¢lo n£meros por favor.');
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
						writeln ('Ingrese s¢lo n£meros por favor.');
						write ('Presione una tecla para ingresar nuevamente');
						readkey;
						error:=true;
					end;
				end;
			end;
			
          if ID<>0 then
{BeginIF} begin
						ejemplar[long_vector+1].id_ejemplar:=id;
						error:=true;
						while error do
						begin
							clrscr;
							writeln;
							Write ('Ingrese el ID de Título: ');
			 	    	error:=false;
							{$I-}
							readln (id);
							{$I+}
							if IOResult <> 0 then
							begin
								writeln ('Ingrese s¢lo n£meros por favor.');
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
		 			error:=true;
		 			while error do
		 			begin
		 				error:=false;
		 				writeln;
		 				write ('Ingrese nuevamente el ID del título: ');
						{$I-}
						readln (id);
						{$I+}
						if IOResult <> 0 then
						begin
							writeln ('Ingrese s¢lo n£meros por favor.');
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
						writeln ('Ingrese s¢lo n£meros por favor.');
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
								writeln ('Ingrese s¢lo n£meros por favor.');
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
		 				write ('La ubicación no es válida');
		 				writeln;
		 				write ('El título que ingresó pertenece al género ',genero[idGenero].nombre);
		 				write (' el cual ocupa desde el pasillo ',genero[idGenero].pasillo_inicial,', estante ',genero[idGenero].estante_inicial);
		 				writeln ('; hasta el pasillo ',genero[idGenero].pasillo_final,', estante ',genero[idGenero].estante_final);
		 				error:=true;
		 				while error do
		 				begin
		 					error:=false;
		 					writeln;
		 					write ('Ingrese nuevamente el pasillo en el que desea ubicar el ejemplar: ');
		 					{$I-}
		 					readln (pasillo);
		 					{$I+}
							if IOResult <> 0 then
							begin
								writeln ('Ingrese s¢lo n£meros por favor.');
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
								writeln ('Ingrese s¢lo n£meros por favor.');
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

		 	Write ('El ejemplar ha sido ingresado');
			readkey;


{ENDIF} end;
END;


PROCEDURE EGRESO (var Ejemplar:tv_ejemplar; long_vector:integer);
   		var
   			id:integer;
   			error:boolean;

			begin
				error:=true;
				while error do
				begin
					error:=false;
					clrscr;
					Write ('Ingrese el ID de ejemplar que desea retirar (0 para salir): ');
					{$I-}
					readln (id);
					{$I+}
					if IOResult <> 0 then
					begin
						writeln ('Ingrese s¢lo n£meros por favor.');
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
		 				write ('Ingrese nuevamente el ID del ejemplar (0 para salir): ');
					{$I-}
					readln (id);
					{$I+}
					if IOResult <> 0 then
					begin
						writeln ('Ingrese s¢lo n£meros por favor.');
						write ('Presione una tecla para ingresar nuevamente');
						readkey;
						error:=true;
					end;
        end;

                                    if (ID<>0) AND (posicion_ejemplar  (id,ejemplar,long_vector)<>-1) then
                                    Begin
                                    	writeln ('El ejemplar ha sido retirado.');
	      			    write ('Se encontraba en el pasillo ',ejemplar[posicion_ejemplar (id,ejemplar,long_vector)].pasillo);
                                    writeln (', estante ',ejemplar[posicion_ejemplar (id,ejemplar,long_vector)].estante);

		 		    ejemplar[posicion_ejemplar (id,ejemplar,long_vector)].estado:=false;
				    ejemplar[posicion_ejemplar (id,ejemplar,long_vector)].id_ejemplar:=0;

                                    end;
		readkey;
	     end;


PROCEDURE MENU_INGRESO_EGRESO (var EJEMPLAR:Tv_ejemplar; var TITULO: Tv_titulo;
                               var GENERO: Tv_genero;var long_vector:integer);
var
		num_operacion:byte;

Begin
	
	repeat
			ClrScr;
			writeln;
                        writeln;
			Write ('MENÚ INGRESO/EGRESO');
			writeln;
			writeln;
			writeln;
			writeln ('1 -  Ingreso');
			writeln;
			writeln ('2 -  Egreso');
			writeln;
			writeln ('3 -  Salir');
			writeln;
			write ('Elija una opción: ');
		{$I-}
		readln (num_operacion);
		{$I+}
		if IOResult <> 0 then
			begin
				writeln ('Ingrese s¢lo n£meros por favor.');
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
		Write('Para volver al men£ INGRESOS/EGRESOS oprima cualquier tecla... ');
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
     write('N£mero de ejemplar: ');
     readln(NumEjemplar);
     writeln;
     PosEjemplar := BuscarPos_Ejemplar(VecEjemplar, LargoVecEjemplar, NumEjemplar);
     if (PosEjemplar <> -1)
     then begin
          writeln('El ejemplar se encuentra en:');
          writeln('Pasillo: ', VecEjemplar[PosEjemplar].pasillo,'. Estante: ', VecEjemplar[PosEjemplar].estante,'.');
          writeln;
          write('Ingrese nuevo pasillo: ');
          readln(NuevoPasillo);
          write('Ingrese nuevo estante: ');
          readln(NuevoEstante);
          writeln;
          if BuscaGenero(VecGenero, NuevoPasillo, NuevoEstante)
             = BuscaGenero(VecGenero, VecEjemplar[PosEjemplar].pasillo, VecEjemplar[PosEjemplar].estante)
                    then begin
                         VecEjemplar[PosEjemplar].pasillo := NuevoPasillo;
                         VecEjemplar[PosEjemplar].estante := NuevoEstante;
                         writeln('El cambio se realizo satisfactoriamente');
                         end
                         else writeln('No coinciden los generos');
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
   PasilloOrigen, EstanteOrigen: byte;
   PasilloDestino, EstanteDestino: byte;
   i: integer;


begin
     clrscr;
     writeln('*****************************************');
     writeln('          Movimiento de Estantes         ');
     writeln('*****************************************');
     writeln;
     writeln('DATOS DE ORIGEN');
     writeln('---------------');
     write('Ingrese pasillo de origen: ');
     readln(PasilloOrigen);
     write('Ingrese estante de origen: ');
     readln(EstanteOrigen);
     writeln;
     writeln('DATOS DE DESTINO');
     writeln('----------------');
     write('Ingrese pasillo de destino: ');
     readln(PasilloDestino);
     write('Ingrese estante de destino: ');
     readln(EstanteDestino);
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
          writeln('Oprima una tecla.');
          end
     else begin
          writeln('Los datos ingresados no corresponden al mismo genero');
          writeln('Oprima una tecla');
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


Procedure Menu (var v_titulo : tv_titulo; var v_autor : tv_autor;
var v_genero : tv_genero; var v_ejemplar : tv_ejemplar; largo_titulo, largo_autor, largo_ejemplar : integer);

var
	opt:byte;

Begin
	repeat
		ClrScr;
		writeln ('Men£ Principal');
		writeln ('-------------');
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
			1: Visualizaciones(v_titulo,v_ejemplar,v_autor,v_genero);
			2: Menu_listados (v_titulo, v_autor, v_genero, largo_titulo, largo_autor);
			3: Menu_ingreso_egreso (v_ejemplar, v_titulo, v_genero, largo_ejemplar);
			4: Menu_movimientos (v_genero, v_ejemplar, largo_ejemplar);
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
				inc(j);
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
				inc(j);
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
				inc(j);
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
	v_genero	:	tv_genero;
	v_autor		:	tv_autor;
	v_titulo	:	tv_titulo;
	v_ejemplar	:	tv_ejemplar;
	largo_titulo,largo_autor,largo_ejemplar	:	integer;

{ * * *  / D E C L A R A C I O N   D E   V A R I A B L E S  * * * }


{ * * *  P R O G R A M A   P R I N C I P A L  * * * }

BEGIN
	Inicializar_genero (v_genero);
	Inicializar_autor (v_autor,largo_autor);
	Inicializar_titulo (v_titulo,largo_titulo);
	Inicializar_ejemplar(v_ejemplar,largo_ejemplar);
	Menu (v_titulo, v_autor, v_genero, v_ejemplar, largo_titulo, largo_autor, largo_ejemplar);
	Limpieza (v_titulo,v_autor,v_ejemplar,largo_titulo,largo_autor,largo_ejemplar);

END.

{ * * *  / P R O G R A M A   P R I N C I P A L  * * * }