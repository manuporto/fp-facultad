Program Fecha;

uses crt;
Var
dia1, mes1, anio1,dia2, mes2,anio2:longint;

function Bisiesto (Anio:integer) : Boolean;
begin
	Bisiesto := ((Anio mod 4 = 0) and not (Anio mod 100 = 0)) or (Anio mod 400 = 0);
end;


function dias_mes (mes,anio:longint) : longint;
begin
	case mes of
		1,3,5,7,8,10,12 : dias_mes := 31;
		4,6,9,11 : dias_mes := 30;
		2 : if (bisiesto(anio)) then
					dias_mes := 29
				else
					dias_mes := 28;
	end;
end;


function sumar_dias (fecha : longint; dias : longint) : longint;
var
	dia,mes,anio : longint;
	dias_del_mes : longint;

begin
        anio:= fecha div 10000;
	mes:= fecha - anio*10000;
	mes:= mes div 100;
	dia:= fecha - anio*10000 - mes*100;

        writeln ('Ingresado: ',dia,'/',mes,'/',anio);
        readkey;
	dia := dia + dias;

        dias_del_mes := dias_mes (mes,anio);
        while (dia > dias_del_mes) do
		begin
                        dia:=dia - dias_del_mes;
			mes:=mes+1;
			if mes>12 then
				begin
					anio:= anio+1;
					mes := 1;
				end;
			dias_del_mes := dias_mes (mes,anio)
		end;
        writeln (dia,'/',mes,'/',anio);
        readkey;
        sumar_dias := anio*10000 + mes*100 + dia;
end;


Function cant_dias (dia1, mes1, anio1, dia2, mes2, anio2:longint):longint;

var v_dia1, v_mes1, v_anio1, v_dia2, v_mes2, v_anio2, cantidad_dias:longint;

Begin
cantidad_dias:=0;
v_dia1:=dia1;
v_dia2:=dia2;

		if mes1<12 then
			begin
			v_mes1:=mes1+1;
			v_anio1:=anio1
			end
		else
			if mes1=12 then
				begin
					v_mes1:=1;
					v_anio1:=anio1+1
                                end
			else writeln ('error');

				
		if mes2>1 then
			begin
			v_mes2:=mes2-1;
			v_anio2:=anio2
			end
		else
			if mes2=1 then
				begin
					v_mes2:=12;
					v_anio2:=anio2-1
                                end
			else writeln ('error');

	
	While (v_anio1*100+v_mes1)<=(v_anio2*100+v_mes2) do
		Begin
			cantidad_dias:=cantidad_dias + dias_mes
                        (v_mes1, v_anio1);
			if v_mes1=12 then
				begin
					v_mes1:=1;
					v_anio1:=v_anio1+1
                                end
			else
					v_mes1:=v_mes1+1;





                end;

                If v_dia1>v_dia2 then
                   cant_dias:=cantidad_dias + dias_mes (mes1, anio1)+v_dia2-v_dia1
                   else
                   if (v_dia2>v_dia1) and (mes1=mes2) then
                   cant_dias:= cantidad_dias +v_dia2- v_dia1
                   else
                   if (v_dia2>v_dia1) and (mes1<>mes2) then
                   cant_dias:= cantidad_dias + dias_mes (mes1,anio1) + v_dia2- v_dia1
                   else

                   if mes1=mes2 then cant_dias:=cantidad_dias
                   else
                       cant_dias :=cantidad_dias + dias_mes (mes1,anio1);

                end;


Begin

Write ('Ingrese el dia: ');
readln (dia1);
Write ('Ingrese el mes: ');
readln (mes1);
Write ('Ingrese el a¤o: ');
readln (anio1);

Write ('Ingrese el dia: ');
read (dia2);
Write ('Ingrese el mes: ');
read (mes2);
Write ('Ingrese el a¤o: ');
readln (Anio2);

Writeln ('La diferencia es :', cant_dias (dia1, mes1, anio1, dia2, mes2, anio2));
readkey;
end.




	
