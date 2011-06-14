/*
Grupo 10

Bessone Alex Lionel. Padrón: 86606
Ribotta, Mariano. Padrón 86052

*/

import java.util.*;
import java.text.*;

public class SOR {
	
	private double[] v0;
	private double[] v1;
	private double[] v3;
	private double[] b;
	private double[] x;
	private double[] xant;
	private double[] x0;
	List<Double> radioEspectral; // Guarda en la posición i, el logaritmo del radio espectral de la iteración i+1;
	private int n=0;
	private double w=1.3;
	DecimalFormat formatted;
	
	public SOR (int n){
		b = new double[n];
		x = new double[n];
		xant = new double[n];
		x0 = new double[n];
		inicializacionVectores();
		radioEspectral = new ArrayList<Double>();
		this.n = n;
		crearMatriz(n);
	}

	private void inicializacionVectores() {
		for (int i=0;i<n;i++){
			b[i]=0;
			xant[i]=0;
			x0[i]=0;
			x[i]=0;
		}
	}

	public void setW(double w){
		this.w = w;
	}
	
	public String toString (){

		System.out.print("b = [\t");
		for (int i=0;i<n;i++){
			formatted = new DecimalFormat("0.00000");
			System.out.print(formatted.format(b[i])+"\t");
		}
		System.out.println("]");

		System.out.print("x = [\t");
		for (int i=0;i<n;i++){
			formatted = new DecimalFormat("0.00000");
			System.out.print(formatted.format(x[i])+"\t");
		}
		System.out.println("]");
		
		return "";
	}

	public int resolver(double tolerancia){
		double aux=0;
		double RTOL = tolerancia+1;
		int cantIteraciones=0;
		crearSemilla();
		radioEspectral.clear();
		while (RTOL > tolerancia){
			for (int i=0;i<n;i++)
			{
				if (cantIteraciones==0){
					x0[i] = x[i];
				}
				xant[i]=x[i];
				aux = Aux(i);
				x[i] = ((1-w)*x[i])+(w/v0[i])*(b[i]-aux);
			}
			RTOL = calculoTolerancia();
			cantIteraciones++;
			radioEspectral.add(calculoRadioEspectral(cantIteraciones));
		}
		return cantIteraciones;
	}
	
	private Double calculoRadioEspectral(int k) {
		double[] resta1;
		double[] resta2;
		resta1 = new double[n];
		resta2 = new double[n];
		for (int i=0;i<n;i++){
			resta1[i]=x[i]-1;
			resta2[i]=x0[i]-1;
		}
		double numerador = Math.log(normaInfinito(resta1)/normaInfinito(resta2));
		double denominador = k;

		return numerador/denominador;
	}

	private double calculoTolerancia() {
		double[] resta;
		resta = new double[n];

		for (int i=0;i<n;i++){
			resta[i]=x[i]-xant[i];
		}
		return (normaInfinito(resta)/normaInfinito(x));
	}
	
	private double normaInfinito(double vector[]){
		double max=0;
		for (int i=0;i<n;i++){
			if (Math.abs(vector[i]) > max)
				max = Math.abs(vector[i]);
		}
		return max;
	}

	public double Aux(int i){
		double aux=0;

		if ((i>=3) && (i<(n-3))){
			for (int j=(i-3);j<=(i+3);j++){
				aux += x[j]*dist(i,j);
			}
		}
		if (i<3){
			for (int j=0;j<=(i+3);j++){
				aux += x[j]*dist(i,j);
			}
		}

		if (i>=(n-3)){
			for (int j=(i-3);j<=(n-1);j++){
				aux += x[j]*dist(i,j);
			}
		}
		return aux;
	}
	
	public double dist(int i,int j){
		if (Math.abs(i-j)==1){
			int min = Math.min(i,j);
			return v1[min];
		}
		else {
			if (Math.abs(i-j)==3){
				int min = Math.min(i,j);
				return v3[min];
				
			}
			else {
				return 0;
			}
		}
	}
	
	public void hallarB(){
		double aux;
		setX();

		for (int i=0;i<n;i++)
		{
			aux=0;
			for (int j=(i-3);j<=(i+3);j++){
				try {
					aux+=dist(i,j);
				}
				catch (ArrayIndexOutOfBoundsException e){}
			}
			b[i]=aux+v0[i];
		}
		
	}

	private void crearMatriz (int n){
		if (((n % 3) != 0) || (n<6)) {
			throw new IllegalArgumentException();
		}
		else
		{
			v0 = new double[n];
			v1 = new double[n-1];
			v3 = new double[n-3];
			// Lleno v0
			for (int i=0;i<3;i++){
				v0[i] = 2;
				v0[n-i-1]=3;
			}
			for (int i=3;i<(n-3);i++){
				v0[i] = 4;
			}

			// Lleno v1
			for (int i=0;i<2;i++){
				v1[i] = -0.5;
				v1[n-i-2]=-0.5;
			}
	
			v1[2] = 0;
			
			for (int i=3;i<(n-3);i=i+3){
				v1[i]= 	-1;
				v1[i+1]= -1;
				v1[i+2] = 0;
			}
			
			// Lleno v3
			for (int i=0;i<(n-3);i++){
				v3[i] = -1;
			}
		}
	}
	


	private void crearSemilla(){
		for (int i=0;i<n;i++)
		{
			x[i]=0;
		}
	}
	
	private void setX(){
		for (int i=0;i<n;i++){
			x[i]=1;
		}
	}
	
	public void imprimirRadioEspectral(){
/*		for (int i=0;i<radioEspectral.size();i++){
			formatted = new DecimalFormat("00");
			System.out.print("k: "+formatted.format(i+1));

			formatted = new DecimalFormat("0.00000");
			System.out.println(" | Rho: "+formatted.format(Math.exp(radioEspectral.get(i))));
		}
*/
		int i = radioEspectral.size();

		formatted = new DecimalFormat("0.00000");
		System.out.print("Rho: "+formatted.format(Math.exp(radioEspectral.get(i-1))));
		formatted = new DecimalFormat("00");
		System.out.println(" (Con k: "+formatted.format(i+1)+")");
		System.out.println("");
	}

	public void hallarwOptimo(){
		double denominador;
		double argumentoRaiz;
		double wOptimo;
//		for (int i=0;i<radioEspectral.size();i++){
//			argumentoRaiz = 1-Math.exp(radioEspectral.get(i));
//			denominador = 1+ (Math.sqrt(argumentoRaiz));
//			wOptimo = 2/denominador;
//			formatted = new DecimalFormat("00");
//			System.out.print("k: "+formatted.format(i+1));
//
//			formatted = new DecimalFormat("0.000");
//			System.out.println(" | wOpt: "+formatted.format(wOptimo));
//		}

		argumentoRaiz = 1-Math.exp(radioEspectral.get(radioEspectral.size()-1));
		denominador = 1+ (Math.sqrt(argumentoRaiz));
		wOptimo = 2/denominador;
		formatted = new DecimalFormat("0.000");
		System.out.println("wOpt: "+formatted.format(wOptimo));

		System.out.println("");
		System.out.println("");
	}
	
}

