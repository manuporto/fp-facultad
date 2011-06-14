package modeloDelJuego;

public class Blanca extends FiguraMusical {

	private double vecesRedonda;
	private String miFigura;
	
	public Blanca() {
		this.vecesRedonda=0.5;
		this.miFigura= "Blanca";
	}

	//devuelve la equivalencia de dicha figura en relacion a la "Redonda" que fue tomada como unidad.
	public double vecesRedonda(){
		
		return vecesRedonda;
		
	}
	public String getTipo(){
		return this.miFigura;
	}

}
