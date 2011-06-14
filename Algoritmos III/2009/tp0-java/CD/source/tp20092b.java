
public class tp20092b {

	public static void main(String[] args) {

		int cantidadDeIntegrantesEsperada = 3;
		int habilidad = 1;
		String nombre = "Juan"; 
		Equipo equipo = new Equipo(cantidadDeIntegrantesEsperada);
		
		Jugador jugador1 = new Jugador(nombre, habilidad);
		equipo.addJugador(jugador1);

		if(equipo.getCantidadJugadores() == 1)
			imprimirPruebaOk(1);
		else
			imprimirPruebaError(1);
		
		nombre = "pepe";
		habilidad = 5;
		Jugador jugador2 = new Jugador(nombre, habilidad);
		equipo.addJugador(jugador2);
		
		if(equipo.getHabilidadEquipo() == 6)
			imprimirPruebaOk(2);
		else
			imprimirPruebaError(2);

		Jugador jugador3 = equipo.getJugador("nicolas");
		if(jugador3 == null)
			imprimirPruebaOk(3);
		else
			imprimirPruebaError(3);

		Jugador jugador4 = equipo.getJugador("pepe");
		if(jugador4 != null && jugador4.getNombre() == "pepe")
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
