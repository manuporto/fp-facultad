/*
Grupo 10

Bessone Alex Lionel. Padrón: 86606
Ribotta, Mariano. Padrón 86052

*/

import java.text.DecimalFormat;

public class TP {

	public static void main (String[] args) {
		System.out.println ("Cálculo con n=6");
		System.out.println ("---------------");
		resolucion(6);
		System.out.println ("Cálculo con n=9");
		System.out.println ("---------------");
		resolucion(9);
		System.out.println ("Cálculo con n=12");
		System.out.println ("----------------");
		resolucion(12);
		System.out.println ("Cálculo con n=30");
		System.out.println ("----------------");
		resolucion(30);
	}
	
	public static void resolucion(int n){
		
		// Variables
		SOR sor;
		double w=1.3;
		double tolerancia=0.001;
		int iteraciones = 20; // Cantidad de iteraciones utilizadas para hallar el w óptimo
		double auxwMin=0;
		double wMin=0; // Primer omega que minimiza la cantidad de iteraciones del método SOR
		double wMax=0; // Último omega que minimiza la cantidad de iteraciones del método SOR (por si hay más de uno)
		int numIteraciones=0;
		int minNumIteraciones;
		double rango=0.0001;
		DecimalFormat formatted;

		sor = new SOR (n);

		System.out.println("");
		System.out.println("Cálculo de b");
		System.out.println("------------");
		System.out.println("");
		sor.setW(w);
		sor.hallarB();
		sor.toString();

		System.out.println("");
		System.out.println("Cálculo con tolerancia 0.001");
		System.out.println("----------------------------");
		System.out.println("");
		w = 1;
		sor.setW(w);
		System.out.println("Iteraciones realizadas: "+sor.resolver(tolerancia));
		System.out.println("");
		sor.toString();

		System.out.println("");
		System.out.println("Cálculo del parámetro de sobrerelajación");
		System.out.println("----------------------------------------");
		System.out.println("");
			
		minNumIteraciones = 100000;
		for (int i=0;i<iteraciones;i++){
			w = 1+0.05*i;
			sor.setW(w);
			numIteraciones = sor.resolver(tolerancia);
			if (numIteraciones <= minNumIteraciones){
				wMax = w;
				if (numIteraciones < minNumIteraciones){
					minNumIteraciones = numIteraciones;
					wMin = w;
				}
			}
			formatted = new DecimalFormat("0.000");
			System.out.print("w: "+formatted.format(w));

			formatted = new DecimalFormat("00");
			System.out.println(" | Iteraciones: "+formatted.format(numIteraciones));
		}
		wMax += 0.025;
		wMin -= 0.025;
		System.out.println ("");
		formatted = new DecimalFormat("0.000");
		System.out.print("El w que minimiza el número de iteraciones está entre "+formatted.format(wMin));
		formatted = new DecimalFormat("0.000");
		System.out.println(" y "+formatted.format(wMax));
		System.out.println ("");

		System.out.println("");
		System.out.println("Cálculo del parámetro de sobrerelajación óptimo");
		System.out.println("-----------------------------------------------");
		System.out.println("");

		tolerancia = 0.00000001;
		if (wMax == wMin){
			rango = 1/(double)iteraciones;
		}

		else{
			rango = wMax - wMin;
		}

		minNumIteraciones = 100000;
		for (int i=0;i<=iteraciones;i++){
			w = wMin+(i*(rango/iteraciones));
			sor.setW(w);
			numIteraciones = sor.resolver(tolerancia);
			if (numIteraciones < minNumIteraciones){
				minNumIteraciones = numIteraciones;
				auxwMin = w;
			}
			


			formatted = new DecimalFormat("0.000");
			System.out.print("w: "+formatted.format(w));

			formatted = new DecimalFormat("00");
			System.out.println(" | Iteraciones: "+formatted.format(numIteraciones));
		}

		tolerancia = 0.001;

		System.out.println("");
		formatted = new DecimalFormat("0.000");
		System.out.println("w que minimiza es: "+formatted.format(auxwMin));

		System.out.println("");
		System.out.println("Estimación del radio espectral");
		System.out.println("------------------------------");
		System.out.println("");

		sor.setW(1);
		sor.resolver(tolerancia);
		sor.imprimirRadioEspectral();


		System.out.println("");
		System.out.println("Cálculo del omega óptimo a partir de la estimación del radio espectral");
		System.out.println("----------------------------------------------------------------------");
		System.out.println("");
	
		sor.hallarwOptimo();

	}
	
}
