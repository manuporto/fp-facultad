
public class Arctan {

	double resultado;
	int cantidadDeDecimales;
	
	public Arctan(int cantidadDeDecimales){
		resultado = 0;
		this.cantidadDeDecimales = cantidadDeDecimales;
	}
	
	public double calcular(int i, double x){
		resultado += ( redondear(Math.pow(-1,i+1),cantidadDeDecimales)*redondear (Math.pow(x,2*i - 1),cantidadDeDecimales )) / ( 2*i - 1 );
		return resultado;
	}
	
  public double redondear (double x,int cantidadDeDecimales)
    {
    	int redondeo = (int) Math.pow(10,cantidadDeDecimales+1);
    	long y = Math.round (x*redondeo);
    	return (double) y /redondeo;
    }

	
}
