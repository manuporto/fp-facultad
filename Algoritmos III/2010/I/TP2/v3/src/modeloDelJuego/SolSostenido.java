package modeloDelJuego;

public class SolSostenido extends Nota{


	private String miNota;
	
	
	public SolSostenido(FiguraMusical figura) {
		super(figura);
		miNota = "SolSostenido" ;
				
	}

	public String getTipo(){
		return miNota;	
	}
	
}
