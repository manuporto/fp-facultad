public class Jugador{
	//variables
	String jnombre;
	int jhabilidad;

	public Jugador (String nombre,int habilidad){
		jnombre = nombre;
		jhabilidad = habilidad;
	}
	
	public String getNombre () {
		return jnombre;
	}

	public int getHabilidad() {
		return jhabilidad;
	}
}
