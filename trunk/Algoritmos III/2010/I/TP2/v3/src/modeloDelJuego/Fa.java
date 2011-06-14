package modeloDelJuego;

public class Fa extends Nota {


	private String miNota;
	
	
	public Fa(FiguraMusical figura) {
		super(figura);
		miNota = "Fa";
	}

	public String getTipo(){
		return miNota;	
	}
}
