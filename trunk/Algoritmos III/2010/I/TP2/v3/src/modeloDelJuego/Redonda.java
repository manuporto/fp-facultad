package modeloDelJuego;

public class Redonda extends FiguraMusical {

	private double vecesRedonda;
	private String miFigura;
	
	public Redonda() {
		
	 this.vecesRedonda=1;
	 this.miFigura="Redonda";
	}

	//devuelve la equivalencia de dicha figura en relacion a la "Redonda" que fue tomada como unidad.
	public double vecesRedonda(){
		return vecesRedonda;
	}
	public String getTipo(){
		return this.miFigura;
	}

}
