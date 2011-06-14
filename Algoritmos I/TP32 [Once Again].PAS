Program Tp1;
{******************************************************
*           Trabajo Practico N£mero 1                 *
*                 Algoritmos I                        *
* Fecha: 15/05/2005                                   *
* Version: 0.1                                        *
* --------------------------------------------------- *
* Profesor: Fernando J. Lage                          *
*                                                     *
* Integrantes:                                        *
*             - Mat¡as Cherepinsky                    *
*             - Cristian Desplats                     *
*             - Mariano Ribotta                       *
*             - Ezequiel Tolstanov                    *
******************************************************}

Uses CRT, DOS;

Const

    P = 2;
    N = 3; {Cantidad de medicamentos}
    M = 4; {Cantidad de trimestres}
    O = 4; {Cantidad de a¤os}

Type

   Matriz = array [1..M,1..O,1..N] of longint;
   Tabla = array [1..P,1..N] of longint;
   Tabla2 = array [1..M,1..O] of longint;
   Tabla3 = array [1..M+1,1..N] of longint;
   Tabla4 = array [1..M,1..N+1] of real;
   Vector_Drogas = array [1..N] of string;

Var

   Mat:Matriz;
   VD:Vector_Drogas;
   T_1999:Tabla3;
   TT_Ventas:Tabla4;
   T_suma:Tabla2;
   opcion:integer;

{**********************************************************}

Procedure Inicializar(var Mat:Matriz);
var i,j,k:integer;
begin
    for i:=1 to N do
      for j:=1 to O do
        for k:=1 to M do
          mat[i,j,k]:=0;
end;

{**********************************************************}

{Procedure Inicializar_A_Mano(var Mat:Matriz);
begin
*Este procedimiento lo usamos unicamente para probar el funcionamiento con
valores predeterminados. Una vez que corroboremos que el programa funciona,
este procedimiento sera comentado con llaves.*
    mat[1,1,1]:=5;
    mat[1,1,2]:=26;
    mat[1,1,3]:=99;

    mat[1,2,1]:=45;
    mat[1,2,2]:=84;
    mat[1,2,3]:=1520;

    mat[1,3,1]:=30;
    mat[1,3,2]:=2;
    mat[1,3,3]:=115;

    mat[1,4,1]:=12;
    mat[1,4,2]:=67;
    mat[1,4,3]:=8;

    mat[2,1,1]:=10;
    mat[2,1,2]:=33;
    mat[2,1,3]:=502;

    mat[2,2,1]:=12;
    mat[2,2,2]:=1;
    mat[2,2,3]:=788;

    mat[2,3,1]:=23;
    mat[2,3,2]:=108;
    mat[2,3,3]:=400;

    mat[2,4,1]:=4;
    mat[2,4,2]:=67;
    mat[2,4,3]:=9;

    mat[3,1,1]:=25;
    mat[3,1,2]:=41;
    mat[3,1,3]:=501;

    mat[3,2,1]:=9;
    mat[3,2,2]:=21;
    mat[3,2,3]:=40;

    mat[3,3,1]:=0;
    mat[3,3,2]:=80;
    mat[3,3,3]:=214;

    mat[3,4,1]:=150;
    mat[3,4,2]:=8;
    mat[3,4,3]:=5;

    mat[4,1,1]:=30;
    mat[4,1,2]:=37;
    mat[4,1,3]:=3784;

    mat[4,2,1]:=18;
    mat[4,2,2]:=7;
    mat[4,2,3]:=67;

    mat[4,3,1]:=28;
    mat[4,3,2]:=65;
    mat[4,3,3]:=11;

    mat[4,4,1]:=3;
    mat[4,4,2]:=12;
    mat[4,4,3]:=60;
end;}

{**********************************************************}

function validar:longint;
var
    validos:set of char;
    car:char;
    s:string[30];
    aux:longint;
    codigo:integer;
begin
    s:='';
    validos:=['0'..'9', #8];
    car:=readkey;
    repeat
    if car in validos then
    	begin
        	write(car);
            if(car='.') or (car=',') then
            begin
            	validos:=validos - [',','.'];
                car:='.'
                end;
                s:=s+car
            end;
            car:=readkey;
        until car = #13;
        val(s,aux,codigo);
        validar:=aux
    end;

{**********************************************************}

Procedure Carga_Datos(var Mat:Matriz);
var i,j,k:integer;
    a,b:string;
begin
        for k:=1 to O do
                for j:=1 to M do
                    for i:=1 to N do
                        begin
                                case i of
                                1: a:= 'Redol¢n';
                                2: a:= 'Asaz';
                                3: a:= 'Lecitina';
                                end;
                                case k of
                                1: b:='1998';
                                2: b:='1999';
                                3: b:='2000';
                                4: b:='2001';
                                end;
 write ('Ingrese las ventas de ',a,' en el ',j, 'øTrimestre de ',b, ': ');
                        Mat[k,j,i]:=Validar;
                        writeln;
                        end;
end;

{*********************************************************}

Function No_cargo( var Mat:Matriz):boolean;

var i,j,k,cantidad_ceros:integer;
    ceros:boolean;
begin
        ceros:=(1=2);
        cantidad_ceros:=0;
        for k:=1 to O do
                for j:=1 to M do
                    for i:=1 to N do
                        if (mat[k,i,j] = 0) then
                            inc(cantidad_ceros);
                        if cantidad_ceros = 48 then
                           ceros:=(1=1);
        No_cargo:=ceros
end;

{**********************************************************}

Procedure Cargar_Drogas(var VD:Vector_Drogas);
begin
   VD[1]:='Redolon';
   VD[2]:='Asaz';
   VD[3]:='Lecitina';
end;

{**********************************************************}

Procedure Achato_Matriz(var T_Suma:Tabla2; var Mat:Matriz);
var i,j,k:integer;
begin
    for i:=1 to O do
      for j:=1 to M do
        for k:=1 to N do
          T_Suma[i,j] := T_Suma[i,j] + Mat[i,j,k];
end;

{**********************************************************}

Function Calcular_Mayor_Venta(var mat:Matriz; var T_Suma:Tabla2):string;
var
    cad:string;
    i,j,k,subt,suba:integer;
    mayor:longint;
    {SUBA sera el subindice de los a¤os y SUBT el subindice de los
trimestres}
begin
          Achato_Matriz(T_suma, Mat);
          mayor:=t_suma[1,1];
          for i:=1 to O do
            for j:=1 to M do
              if T_Suma[i,j] >= mayor then
                begin
                  mayor:=T_suma[i,j];
                  subt:=j;
                  suba:=i;
                end;
              case subt of
                1: cad:='1er. Trimestre';
                2: cad:='2do. Trimestre';
                3: cad:='3er. Trimestre';
                4: cad:='4to. Trimestre';
              end;
              case suba of
                1: cad:=cad + ' de 1998.';
                2: cad:=cad + ' de 1999.';
                3: cad:=cad + ' de 2000.';
                4: cad:=cad + ' de 2001.';
              end;
              Calcular_Mayor_Venta := cad;
end;

{**********************************************************}

Procedure Venta_Drogas(var VRed, VAsa, VLec:longint; var Mat:Matriz );
var i,j:integer;
begin
{VRed sera el total de ventas de Redolon. Analogamente para VAsa y VLec}
    VRed:=0;
    VAsa:=0;
    VLec:=0;
    for i:=1 to M do
      for j:=1 to O do
        VRed:=VRed + Mat[i,j,1];
    for i:=1 to O do
      for j:=1 to M do
        VAsa:=VAsa + Mat[i,j,2];
    for i:=1 to O do
      for j:=1 to M do
        VLec:=VLec + Mat[i,j,3];
    {Armo la tabla con las sumas}
end;

{**********************************************************}

Procedure Tabla_Ventas(var VRed, VAsa, VLec:longint; var T:tabla);
var i,j:integer;
begin
    T[1,1]:=1;
    T[1,2]:=2;
    T[1,3]:=3;
    T[2,1]:=VRed; {Le asignamos de entrada los valores desordenados}
    T[2,2]:=VAsa;
    T[2,3]:=VLec;

end;

{**********************************************************}

Procedure Ordenar_Dec_tabla(var T:tabla; var VD:Vector_Drogas);
var i,j,k,z:integer;
aux,aux2:longint;
begin
    for j:=1 to N-1 do
      for i:=1 to N-j do
           if T[2,i] < T[2,i+1] then
             begin
               for k:=1 to N do
                 begin
                   aux:=T[k,i+1];
                   T[k,i+1]:= T[k,i];
                   T[k,i]:=aux;
                 end;
             end;
      for z:=1 to N do
       begin
        case T[1,z] of
            1: begin
                 Writeln(VD[1]);
                 Writeln(T[2,z]);
                 Writeln;
               end;
            2: begin
                 Writeln(VD[2]);
                 Writeln(T[2,z]);
                 Writeln;
               end;
            3: begin
                 Writeln(VD[3]);
                 Writeln(T[2,z]);
                 Writeln;
               end;
            end;
        end;
        readkey
end;

{**********************************************************}

Procedure Ordenar_Crec_Tabla(var T:tabla3);
var i,j,k:integer;
aux:longint;
begin
    for j:=1 to N-1 do
      for i:=1 to N-J do
           if T[2,i] > T[2,i+1] then
             begin
               for k:=1 to M+1 do
                 begin
                   aux:=T[k,i+1];
                   T[k,i+1]:= T[k,i];
                   T[k,i]:=aux;
                 end;
             end;
end;

{**********************************************************}

Procedure Ventas_1999_2doTrim(var Mat:Matriz; var T_1999:Tabla3;var
VD:Vector_Drogas);
var i,j,z:integer;
begin
     for j:=1 to N do
       for i:=1 to M do
         T_1999[i,j] := mat[2,i,j];

	  for j:=1 to N do
           T_1999[5,j]:=T_1999[5,j]+j;
     Ordenar_Crec_Tabla(T_1999);
     for i:=1 to N do
      begin
        case T_1999[5,i] of
          1: writeln(VD[1]);
          2: writeln(VD[2]);
          3: writeln(VD[3]);
        end;
      for j:=1 to M do
         writeln(j,'ø Trimestre       Total   ',T_1999[j,i],'          ');
         writeln;
      end;

end;

{**********************************************************}

Procedure Ventas_Anios(var mat:Matriz; var TT_Ventas:Tabla4);
var i,j,k:integer;
begin
   for k:=1 to N do
      for i:=1 to M do
         for j:=1 to O do
            TT_Ventas[i,k]:=TT_Ventas[i,k]+mat[i,j,k];

end;

{**********************************************************}

procedure Promedios_Ventas(var T:Tabla4);
var i,j:integer;
begin
   for i:=1 to N do
      for j:=1 to M do
         T[j,i]:=T[j,i] / 4 ;
     writeln;
end;

{**********************************************************}

Procedure Colocar_Anos(var T:Tabla4);
var i:integer;
begin
     for i:=1 to M do
       T[i,4]:=1997+i;
end;

{**********************************************************}

Procedure Graficar_Tabla (var T:tabla4);
var i:integer;
Begin


             gotoxy (5,4); writeln ('Redolon');
             gotoxy (15,4); writeln ('Asaz');
             gotoxy (25,4); writeln ('Lecitina');
             gotoxy (36,4); writeln ('A¤o');

             {A¤os}
             for i:=1 to O do
             begin
             gotoxy (36,i+5); write (t[i,4]:2:0);
             end;


             gotoxy (5,6); write (t[1,1]:2:2);
             gotoxy (15,6); write (t[1,2]:2:2);
             gotoxy (25,6); writeln (t[1,3]:2:2);

             gotoxy (5,7); write (t[2,1]:2:2);
             gotoxy (15,7); write (t[2,2]:2:2);
             gotoxy (25,7); writeln (t[2,3]:2:2);

             gotoxy (5,8); write (t[3,1]:2:2);
             gotoxy (15,8); write (t[3,2]:2:2);
             gotoxy (25,8); writeln (t[3,3]:2:2);

             gotoxy (5,9); write (t[4,1]:2:2);
             gotoxy (15,9); write (t[4,2]:2:2);
             gotoxy (25,9); writeln (t[4,3]:2:2);
End;


{**********************************************************}

Procedure Ord_Crec_Tabla_Lec(var T:tabla4);
var i,j,k:integer;
    aux:real;
begin
    writeln;
    Colocar_Anos(T);
    for i:=1 to M-1 do
      for j:=1 to M-i do
           if T[j,3] < T[j+1,3] then
             begin
               for k:=1 to N+1 do
                 begin
                   aux:=T[j+1,k];
                   T[j+1,k]:= T[j,k];
                   T[j,k]:=aux;
                 end;
             end;

             Graficar_Tabla(T);


end;

{**********************************************************}

Procedure Menu (var Mat:Matriz; var T_suma:Tabla2); forward;

{**********************************************************}

Procedure M1;
begin
    clrscr;
    writeln('-------------------Menu Principal----------------------');
    writeln;
    writeln('     1. Cargar Datos.');
    writeln('     2. Menu de opciones.');
    writeln('     3. Salir');
    writeln('-------------------------------------------------');
    writeln;
end;

{**********************************************************}

Procedure PMenu (Var Mat:Matriz ; var opcion:integer);

begin
    M1;
    while (opcion<>3) do
    begin
      write('Elija Opcion: ');
      opcion:=validar;
      writeln;
      while (opcion>3) do
      begin
           write ('Elija Opcion: ');
           opcion:=validar;
           writeln;
      end;
       case Opcion of
          1: begin
                clrscr;
                 Carga_Datos(mat);
                 M1;
             end;
           2: begin

                if  (no_cargo(mat)) then
                   begin
                      writeln('Debe cargar las ventas previamente');
                      readkey
                   end
                else Menu(Mat,T_Suma);   {Pregunta Cristian: Fijate aca que entra T_Suma si hay
                que pasar por referencia o que?}
                {Contestacion de colo a Crsitian: Claro que hay que pasarlo
                por referencia, la estructuras se deben pasar por referencia.}

                {En esta linea estaba la salida forzada lo que cambie fue el
                llamado al procedimiento y ahora paso una variable por
referencia
                llamada opcion que es un integer y arregla todo, aca puse la
nueva
                funcion que verifica la carga}
             end;
       end;

       end;
       clrscr;
       writeln;
       writeln('Usted ha elegido Salir del menu de Opciones');
end;

{**********************************************************}

Procedure M2;
begin
    clrscr;
    writeln('-------------------Opciones----------------------');
    writeln;
    writeln('     1. A¤o y Trimestre de mayor venta.');
    writeln('     2. Listado de Volumen Total de Ventas.');
    writeln('     3. Ventas del a¤o 1999.');
    writeln('     4. Promedio Anual de Ventas.');
    writeln('     5. Salir');
    writeln('-------------------------------------------------');
    writeln
end;
{**********************************************************}

Procedure Menu;
var T1,T2,T3,Option:longint;
    T_Ventas:Tabla;
begin
    while (option<>5) do
    begin
    M2;
    write('Elija Opcion: ');
	 option:=validar;
      writeln;
      while (option>5) do
      begin
           write ('Elija Opcion: ');
           option:=validar;
           writeln;
      end;
    case Option of
        1: begin
              clrscr;
              Writeln('EL trimestre y a¤o con mayor volumen de venta fue');
              writeln(Calcular_Mayor_Venta(mat,t_suma));
              {Aca se le borro la llamada que estaba al pedo.}
              readkey;
           end;
        2: begin
              clrscr;
              writeln('Listado del Volumen Total de Ventas por Droga');
              Venta_Drogas(T1,T2,T3,mat);
              Tabla_Ventas(T1,T2,T3,T_Ventas);
              Ordenar_Dec_Tabla(T_Ventas,VD);
           end;
        3: begin
              clrscr;
              writeln('Ventas Correspondientes a 1999');
              Ventas_1999_2doTrim(mat,T_1999,VD);
              readkey;
           end;
        4: begin
              clrscr;
              writeln('Promedio Anual de Ventas Ordenado por Lecitina');
              Ventas_Anios(mat,TT_Ventas);
              Promedios_Ventas(TT_Ventas);
              Ord_Crec_Tabla_Lec(TT_Ventas);
              readkey;
           end;
        5: begin
              writeln;
              writeln('Usted ha elegido Salir del menu de Opciones');

           end;
        end;
        end;
        PMenu( Mat, opcion );
end;

{**********************************************************}

begin
    Inicializar(mat);
    {Inicializar_A_Mano(mat)};
    Cargar_Drogas(VD);
    PMenu(mat,opcion);
    readkey;
end.




