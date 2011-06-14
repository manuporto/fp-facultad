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
{ * * *   / A L T A    A U T O R   * * * }