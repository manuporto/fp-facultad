package modeloDelJuego;

public class Negra extends FiguraMusical {

	private double vecesRedonda;
	private String miFigura;
	
	public Negra() {
		this.vecesRedonda=0.25;
		miFigura="Negra";
	}

	//devuelve la equivalencia de dicha figura en relacion a la "Redonda" que fue tomada como unidad.
	public double vecesRedonda(){
		return vecesRedonda;
	}

	public String getTipo(){
		return this.miFigura;
	}


}
