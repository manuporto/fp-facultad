package modeloDelJuego;

public class ReSostenido extends Nota{


	private String miNota;
	
	
	public ReSostenido(FiguraMusical figura) {
		super(figura);
		miNota = "ReSostenido" ;
				
	}

	public String getTipo(){
		return miNota;	
	}

}
