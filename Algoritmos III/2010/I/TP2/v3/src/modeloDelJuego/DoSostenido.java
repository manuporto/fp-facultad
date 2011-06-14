package modeloDelJuego;

public class DoSostenido extends Nota{


	private String miNota;
	
	
	public DoSostenido(FiguraMusical figura) {
		super(figura);
		miNota = "DoSostenido" ;
				
	}

	public String getTipo(){
		return miNota;	
	}

}
