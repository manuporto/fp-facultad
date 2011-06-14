import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.*;

public class Metodo implements Constantes{

	double h, t0, x0, v0;
	boolean corte = false;
	ArrayList<Double> x = new ArrayList<Double>();
	ArrayList<Double> v = new ArrayList<Double>();
	ArrayList<Double> energia = new ArrayList<Double>();
	BufferedWriter out;


	public Metodo (){
	try {
		FileWriter fstream = new FileWriter("out.txt");
		out = new BufferedWriter(fstream);
	}
	catch (Exception e){}
	}

	public double f1(double t, double x, double y){
		return y;
	}

	public double f2(double t, double x, double y){
		return ( (a/m)*x - (b/m)*Math.pow(x,3) );
	}

	public double resolver(){
		throw new RuntimeException();
	}

	private double potencial(double x){
		
		return ( ((0.25)*b*Math.pow(x, 4) ) - ( (0.5)*a*Math.pow(x,2)) );
	}
	
	private double cinetica (double x){
		return ((0.5)*m*Math.pow(x,2));
	}
	
	public double energia(double x, double y){
		return (this.cinetica(y) + this.potencial(x));
	}

	public double diferenciaDeEnergias(){
		Double en_inicial, en_final;

		en_inicial = energia.get(0);
		en_final = energia.get(energia.size() - 1);
		
		return (Math.abs(en_final - en_inicial));

	}

	public void imprimir(){
		
		double en;
		double tn=0;
		int n = 0;

		while ( n < energia.size() ){

			tn = t0+h*n;
			en = energia.get(n);
	        try {
	        	out.write(tn+") ");
	        	out.write(en+"\n");
	        }
	        catch (Exception e){e.printStackTrace();}
	        n++;
		}
        try {out.close();} catch (Exception e){}
	}

	  public double redondear (double x,int cantidadDeDecimales){
		  int redondeo = (int) Math.pow(10,cantidadDeDecimales+1);
		  long y = Math.round (x*redondeo);
		  return (double) y /redondeo;
	  }

}
