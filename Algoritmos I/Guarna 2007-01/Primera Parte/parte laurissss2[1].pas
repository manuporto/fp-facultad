Procedure Modificacion_Autor (var v_autor:tv_autor; var largo_autor);

var
	id_au, id_nuevo: integer;
	pos_au_ant, pos_au_nuevo: byte;
	nombre_nuevo:string;
	opcion byte;

begin
				
		error:= true;
		while error do
			
			begin
				ClrScr;
				writeln (' MODIFICACION DE AUTOR');
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
					end
				else
					if (id_au > MAX_AUTOR) then
						begin
							error:=true;
							writeln ('El ID va entre 1 y ',MAX_AUTOR);
						end;
				end;
				
				pos_au_ant := buscar_posicion_autor (v_autor,largo_autor,id_au);
	
		If ops_au=-1   then 
	
			Begin	
		
				Writeln;
				Write ('El id de autor no existe');
				Writeln;
			end
	
		else
			
				begin
									
					Writeln;
					Writeln ('Usted desea'); 
					Writeln;
					Writeln;
					Writeln (' 1 - Modificar el id del autor');
					Writeln;
					Writeln (' 2 - Modificar nombre del autor');
					Writeln;
					{$I-}
					readln (opcion);
					{$I+}
						
				If opcion = 1 then 
					Begin
						Write ('Ingrese el nuevo id');
						readln (id_nuevo);
						
						pos_au_nuevo := buscar_posicion_autor (v_autor,largo_autor,id_nuevo);
						
						If pos_au_nuevo=-1  then 
							v_autor[pos_au_ant].id_autor:=id_nuevo
						else
							begin
							If  not (v_autor[pos_au_nuevo].estado) then
								begin
									v_autor[pos_au_nuevo].id_autor:=0;
									v_autor[pos_au_ant].id_autor:=id_nuevo;
								end;
							else
								Writeln ('El id ya esta siendo utilizado para otro autor');
							end;
					end;
					
				else
					begin
						Writeln ('Ingrese el nuevo nombre de autor');
						readln (v_autor[pos_au_nuevo].nombre_autor);
					end;
			end;
end;
				
								
									
									
								