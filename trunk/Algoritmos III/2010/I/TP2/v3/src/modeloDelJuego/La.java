package modeloDelJuego;

public class La extends Nota{


	private String miNota;
	
	
	public La(FiguraMusical figura) {
		super(figura);
		miNota = "La";
	}

	public String getTipo(){
		return miNota;	
	}
}
