package modeloDelJuego;

public class Do extends Nota {

	private String miNota;
	
	
	public Do(FiguraMusical figura) {
		super(figura);
		miNota = "Do";
	}

	public String getTipo(){
		return miNota;	
	}

	
}
