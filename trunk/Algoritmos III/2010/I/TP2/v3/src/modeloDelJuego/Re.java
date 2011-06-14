package modeloDelJuego;

public class Re extends Nota {


	private String miNota;
	
	
	public Re(FiguraMusical figura) {
		super(figura);
		miNota = "Re";
	}

	public String getTipo(){
		return miNota;	
	}
}
