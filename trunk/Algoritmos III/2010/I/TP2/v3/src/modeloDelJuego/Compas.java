package modeloDelJuego;

import java.util.*;

public class Compas {
	private List<Nota> notas ;
	
	
	public Compas() {
		this.notas= new ArrayList<Nota>();
	}

	public void agregarNota(Nota unaNota){
		notas.add(unaNota);
		
	}

	public boolean vacio() {
		
		return (notas.size()==0);
	}

	public Nota obtenerNota(int indice){
			return notas.get(indice);
	}
		
		
	

}
