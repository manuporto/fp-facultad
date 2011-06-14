Program TrabajoPractico;

uses
     CRT,DOS;

const
     MAXPASILLO = 9;
     MAXCOLUMNA = 20;
     MAXESTANTE = 5;

type
    t_NumSerie = 0..9999; {El valor cero significa que el lugar está vacío}
    t_Datos    = 1..9999;
    t_Columna  = 1..20;
    t_Pasillo  = 1..9;
    t_Estante  = 1..5;

    t_Caja     = Record
                       NumSerie    : t_Datos;
                       CodMaterial : t_Datos;
                       Cantidad    : Integer;
                 End;

    t_Deposito = array [t_Pasillo] of Array [t_Columna] of Array [t_Estante] of t_Caja;
    
var

   Caja     : t_Caja;
   Deposito : t_Deposito;
   


Procedure InicializarDeposito (var Deposito : t_Deposito);
var     i,j,k           :integer;
        CajaVacia       : t_Caja;

Begin

CajaVacia.NumSerie:=0;
CajaVacia.CodMaterial:=0;
CajaVacia.Cantidad:=0;


for i:=1 to MAXPASILLO do
        for j:=1 to MAXCOLUMNA do
                for k:=1 to MAXESTANTE do
                        deposito[i][j][k]:=CajaVacia;

End;

function BuscarLugar(Pasillo : t_Pasillo; Columna : t_Columna; Estante : t_Estante; var Deposito : t_Deposito; Posicion : String) : Boolean;

     var
        posPas,posCol,posEst,cero : String;
        Encontrado                : Boolean;
        i                         : t_Pasillo;
        j                         : t_Columna;
        k                         : t_Estante;
        valor,error               : Integer;


     Begin

         {i := 1;
         j := 1;
         k := 1;}
         Encontrado := false;
         if (Deposito[Pasillo][Columna][Estante].NumSerie = 0 ) then
            Begin
                Posicion := '0';
                BuscarLugar := True;
            End
         else       { Esta parte es para el segundo enunciado, donde se pide encontrar la primer posicion libre }
            Begin
              {-} i := 1; {-}
                  While (i < MAXPASILLO) and (not Encontrado) do
                     Begin
                   {-} j := 1; {-}
                       While (j < MAXCOLUMNA) and (not Encontrado) do
                          Begin
                        {-} k := 1; {-}
                            While (k < MAXESTANTE) and (not Encontrado) do
                                Begin
                                     if (Deposito[i][j][k].NumSerie = 0) then
                                        Begin
                                             Encontrado := true;
                                             posPas     := chr(i);
                                             posCol     := chr(j);
                                             posEst     := chr(k);
                                        End;
                                     inc(k);
                                End;
                            inc(j);
                          End;
                       inc(i);
                     End;
                  cero := '0';
                  posicion := '0';
                  insert(posicion,posPas,1);
                  val(posCol,valor,error);
                  if ( valor > 10) then
                     insert(posicion,posCol,2)
                  else
                      Begin
                      insert(posicion,cero,2);
                      insert(posicion,posCol,3);
                      end;
                  insert(posicion,cero,4);
                  insert(posicion,posEst,5);
                 BuscarLugar := False;
            End;
     End;



procedure RegistrarCaja(Pasillo : t_Pasillo; Columna : t_Columna; Estante : t_Estante; var Deposito : t_Deposito; Caja : t_Caja);

     Begin
         Deposito[Pasillo][Columna][Estante] := Caja;
         Writeln('Caja ingresada con Exito');
     End;


procedure DefinirCaja(var Caja : t_Caja);

     Begin
         Write('Por favor ingrese el numero de serie de la caja: ');
         readln(Caja.NumSerie);
         Write('Por favor ingrese el Codigo del material que contiene la caja: ');
         readln(Caja.CodMaterial);
         Write('Por favor ingrese la cantidad del material en la caja: ');
         readln(Caja.Cantidad);
     End;


procedure IngCajaDetLugar(var Caja : t_Caja; var Deposito : t_Deposito);     {Le permite al usuario ingresar el lugar donde se guardara la caja}
                                                                         {Llama al procemdimiento BuscarLugar, para validar que ese lugar este libre}
    var
       posicion : String;
       pasillo  : t_Pasillo;
       columna  : t_Columna;
       estante  : t_Estante;
       Lugar    : Boolean;

    Begin

        posicion := '0';
        DefinirCaja(Caja);
        writeln('Bienvenido este modulo le permitira elegir donde desea depositar la caja');
        writeln('************************************************************************');
        write('Ingrese el numero de pasillo (1-9): ');
        readln(pasillo);
        write('Ingrese el numero de columna (1-20): ');
        readln(columna);
        write('Ingrese el numero de estante (1-5): ');
        readln(estante);
        Lugar := BuscarLugar(pasillo,columna,estante,Deposito,posicion);
        if (not Lugar) then
           writeln('Imposible ingresar la caja en ese lugar, el lugar ya est  ocupado')
        else RegistrarCaja(pasillo,columna,estante,Deposito,Caja);
    End;



{Funci¢n para buscar por Numero de Serie, no s‚ si quer‚s generalizarla
para buscar todo, cualquier cosa fijate y se hace}
function BuscarNumSerie (var Deposito : t_Deposito; NumSerie : t_NumSerie ;
                         var Pasillo : t_Pasillo; var Columna : t_Columna;
                         var Estante : t_Estante; var Encontrado : boolean) : t_Caja;

Begin
Encontrado:= false;
Pasillo:=1;
while (Pasillo <= MAXPASILLO) and (Not (Encontrado)) do
     Begin
        Columna:=1;
        while (Columna <= MAXCOLUMNA) and (Not (Encontrado)) do
             Begin
                Estante:=1;
                while (Estante <= MAXESTANTE) and (Not (Encontrado)) do
                Begin
                   if Deposito[Pasillo][Columna][Estante].NumSerie = NumSerie then
                        Begin BuscarNumSerie:= Deposito[Pasillo][Columna][Estante];
                         Encontrado:= true;
                        End;
                inc(Estante);
                End;
             Inc(Columna);
             End;
     inc(Pasillo);
     End;

if Not Encontrado then writeln ('No existe una caja con ese n£mero de serie');

End;

Procedure Eliminar (Deposito : t_Deposito; Pasillo : t_Pasillo;
                    Columna : t_Columna; Estante :  t_Estante);

Begin
Deposito[Pasillo][Columna][Estante].NumSerie:=0;
writeln ('Caja eliminada exitosamente');
End;


procedure EgresoCajaNumSerie (var Deposito : t_Deposito);
var
    NumSerie               : t_NumSerie;
    Caja                   : t_Caja;
    Pasillo                : t_Pasillo;
    Columna                : t_Columna;
    Estante                : t_Estante;
    Error,CajaEncontrada   : Boolean;
    Opt                    : Char;

Begin
        write ('Ingrese el n£mero de serie de la caja que desea sacar: ');
        readln (NumSerie);

        Caja:= BuscarNumSerie (Deposito,NumSerie,Pasillo,Columna,Estante,CajaEncontrada);

        if CajaEncontrada then
        Begin
                writeln ('Caja: ');
                writeln ('Pasillo: ', Pasillo);
                writeln ('Columna: ', Columna);
                writeln ('Estante: ', Estante);
                writeln ('N£mero de Serie: ',Caja.NumSerie);
                writeln ('C¢digo de Material: ',Caja.CodMaterial);
                writeln ('Cantidad de Material: ',Caja.Cantidad);
                writeln;
                write ('Desea eliminar esta caja? (s/n): ');

                Error:= True;
                while Error do
                Begin
                        readln (Opt);
                        Error:= False;
                        case Ord (Opt) of
                                78,110: writeln ('Se cancel¢ la eliminaci¢n de la caja');
                                83,115: Eliminar (Deposito,Pasillo,Columna,Estante);
                        else Begin
                                writeln ('Ingresar s¢lo "s" o "n"');
                                write ('Desea eliminar esta caja? (s/n): ');
                                error:= True;
                             End;
                        End;
                End;
        End;
End;

Begin

InicializarDeposito (Deposito);
IngCajaDetLugar (caja,deposito);
EgresoCajaNumSerie (deposito);
Readkey;
End.


