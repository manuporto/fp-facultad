package modeloDelJuego;

public class SemiCorchea extends FiguraMusical {

	private double vecesRedonda;
	private String miFigura;
	
	public SemiCorchea() {
		this.vecesRedonda=0.0625;
		this.miFigura="SemiCorchea";
	}

	//devuelve la equivalencia de dicha figura en relacion a la "Redonda" que fue tomada como unidad.
	public double vecesRedonda(){
		return vecesRedonda;
	}

	public String getTipo(){
		return this.miFigura;
	}
}
