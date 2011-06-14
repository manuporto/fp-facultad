package modeloDelJuego;

public class Mi extends Nota{


	private String miNota;
	
	
	public Mi(FiguraMusical figura) {
		super(figura);
		miNota = "Mi";
	}

	public String getTipo(){
		return miNota;	
	}
}
