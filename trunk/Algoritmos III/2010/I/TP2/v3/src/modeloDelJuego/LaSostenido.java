package modeloDelJuego;

public class LaSostenido extends Nota{


	private String miNota;
	
	
	public LaSostenido(FiguraMusical figura) {
		super(figura);
		miNota = "LaSostenido" ;
				
	}

	public String getTipo(){
		return miNota;	
	}
}
