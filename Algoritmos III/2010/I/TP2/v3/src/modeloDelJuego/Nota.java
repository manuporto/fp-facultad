package modeloDelJuego;

public abstract class Nota {
	
	FiguraMusical figura;
	
	public Nota(FiguraMusical figura) {
		this.figura = figura ;
	}

	//devuelve el valor que caracteriza a la figura en relacion a la "Redonda"
	//considerada como la unidad
	public double valorFigura(){
		
		return figura.vecesRedonda();
	}
	//devuelve el tipo de la nota
	public abstract String getTipo();

	//devuelve el tipo de la figura Musical asociada a dicha nota
	public String getFigura(){
		return figura.getTipo();
	}
}
