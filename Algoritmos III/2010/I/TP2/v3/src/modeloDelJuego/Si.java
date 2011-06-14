package modeloDelJuego;

public class Si extends Nota{


	private String miNota;
	
	
	public Si(FiguraMusical figura) {
		super(figura);
		miNota = "Si" ;
				
	}

	public String getTipo(){
		return miNota;	
	}
}
