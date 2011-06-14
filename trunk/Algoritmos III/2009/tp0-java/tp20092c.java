
public class tp20092c {

	public static void main(String[] args) {

		String nombreCurso = "Matematica discreta";
		Curso unCurso = new Curso(nombreCurso);

		String nombreAlumno = "Matias";
		double nota = 7;
		Alumno unAlumno= new Alumno(nombreAlumno, nota);
		unCurso.inscribir(unAlumno);

		nombreAlumno = "Eugenio";
		nota = 9;
		Alumno otroAlumno= new Alumno(nombreAlumno, nota);
		unCurso.inscribir(otroAlumno);

		nombreAlumno = "Pablo";
		nota = 8;
		Alumno otroAlumno2 = new Alumno(nombreAlumno, nota);
		unCurso.inscribir(otroAlumno2);
		

		nombreAlumno = "Pablo";
		nota = 5;
		Alumno otroAlumno3 = new Alumno(nombreAlumno, nota);
		unCurso.inscribir(otroAlumno3);

		int cantidadDeInscriptos = unCurso.getCantidadDeInscriptos();
		if(cantidadDeInscriptos == 4)
			imprimirPruebaOk(1);
		else
			imprimirPruebaError(1);

		double notaMasAlta = unCurso.obtenerNotaMasAlta();
		if(notaMasAlta == 9.0)
			imprimirPruebaOk(2);
		else
			imprimirPruebaError(2);

		int cantidadDeAlumnosConNombreX = unCurso.obtenerAlumnosPorNombre("Pablo");
		if(cantidadDeAlumnosConNombreX == 2 )
			imprimirPruebaOk(3);
		else
			imprimirPruebaError(3);
		
		cantidadDeAlumnosConNombreX = unCurso.obtenerAlumnosPorNombre("Oscar");
		if(cantidadDeAlumnosConNombreX == 0 )
			imprimirPruebaOk(4);
		else
			imprimirPruebaError(4);
	}
	
	
	public static void imprimirPruebaOk(int numeroPrueba){
		String mensaje = "Prueba " + numeroPrueba + ": Ok";
		System.out.println(mensaje);
	}

	public static void imprimirPruebaError(int numeroPrueba){
		String mensaje = "Ok " + numeroPrueba + ": Error";
		System.out.println(mensaje);
	}
}
