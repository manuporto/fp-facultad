Procedure Alta_Autor (var v_autor:tv_autor; var largo_autor);

var
	id_au integer;
	
Begin
	
	Writeln;
	Writeln ('Ingrese el id que desea dar de alta');
	readln (id_au)
	Writeln;
	
	If (buscar_autor(v_autor, largo_autor, id_au)=-1)   then 
	
		Begin	
			v_autor[largo_autor+1].id_autor:=id_au;
			v_autor[largo_autor+1].estado:=true;
			Writeln;
			Write ('Ingrese el nombre del autor: ');
			readln (v_autor [largo_autor+1].nombre);
			Writeln;
			Writeln ('Las modificaciones se han realizado correctamente');
		end;
	
	else
		
		If  not (v_autor[(buscar_autor(v_autor, largo_autor, id_au)].estado) then
			
			begin
				v_autor[(buscar_autor(v_autor, largo_autor, id_au)].estado:=true;
				Writeln;
				Write ('Ingrese el nombre del autor: ');
				readln (v_autor [(buscar_autor(v_autor, largo_autor, id_au)].nombre);
				Writeln;
				Writeln ('Las modificaciones se han realizado correctamente');
			end;
		else
			begin
				Writeln;
				Writeln('El id ya esta siendo utilizado para otro autor');
			end;
		end;
	end;
	
	
	
	
	


