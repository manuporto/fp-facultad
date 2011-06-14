package modeloDelJuego;

public class Sol extends Nota {

	private String miNota;
	
	
	public Sol(FiguraMusical figura) {
		super(figura);
		miNota = "Sol";
	}

	public String getTipo(){
		return miNota;	
	}
}
