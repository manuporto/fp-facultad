package modeloDelJuego;

public class Corchea extends FiguraMusical {

	private double vecesRedonda;
	private String miFigura;
	
	public Corchea() {
		this.vecesRedonda=0.125;
		this.miFigura="Corchea";
	}

	//devuelve la equivalencia de dicha figura en relacion a la "Redonda" que fue tomada como unidad.
	public double vecesRedonda(){
		
		return vecesRedonda;
		
	}
	
	public String getTipo(){
		return this.miFigura;
	}

}
