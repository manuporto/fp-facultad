public class Equipo {
	//variables
	int ultimo;
	Jugador[] equipo;

	public Equipo (int CantidadDeIntegrantesEsperada) {
		equipo = new Jugador[CantidadDeIntegrantesEsperada];
		ultimo = 0;
	}
	
	public void addJugador (Jugador jugador) {
		equipo[ultimo] = jugador;
		ultimo++;
	}
	
	public Jugador getJugador (String nombre) {
		int encontrado = 0;
		int i = 0;

		while ((i<ultimo) && (encontrado == 0)){
			if (nombre.equals(equipo[i].getNombre()))
				encontrado = 1;
			else
				i++;
		}
		return equipo[i];
	}
	
	public int getCantidadJugadores() {
		return ultimo;
	}
	
	public int getHabilidadEquipo() {
		int suma = 0;

		for (int j=0;j<ultimo;j++)
			suma += equipo[j].getHabilidad();
		return suma;
	}
}
