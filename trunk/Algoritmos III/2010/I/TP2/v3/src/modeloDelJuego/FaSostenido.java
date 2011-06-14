package modeloDelJuego;

public class FaSostenido extends Nota{


	private String miNota;
	
	
	public FaSostenido(FiguraMusical figura) {
		super(figura);
		miNota = "FaSostenido" ;
				
	}

	public String getTipo(){
		return miNota;	
	}

}
