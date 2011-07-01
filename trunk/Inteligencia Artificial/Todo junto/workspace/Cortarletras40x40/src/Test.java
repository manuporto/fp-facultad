

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Vector;

import org.neuroph.core.NeuralNetwork;
import org.neuroph.nnet.MultiLayerPerceptron;

import au.com.bytecode.opencsv.CSVReader;

public class Test {
	
	static double valor;
	NeuralNetwork net;
	BufferedWriter consola; 
	File a;
	String executionPath;
	
	public Test(){
		net = MultiLayerPerceptron.load("neural/perceptronWeb5.nnet");
		try {
			executionPath = System.getProperty("user.home");
			a = new File(executionPath + "\\consola.txt");	
			System.out.println(a.createNewFile());
			consola = new BufferedWriter(new FileWriter(executionPath + "\\consola.txt"));
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
	
	
	public String go(String nombre){
		
		List<String[]> valor = new ArrayList<String[]>();
		
		double[] input = new double [1600];
//		double[] resultado = new double[12];
		String resultadoFinal = "";
		Vector<Double> resultado = new Vector<Double>();
		
		try {
			CSVReader reader = new CSVReader(new FileReader(nombre));
			int i;

			valor = reader.readAll();
			for (String[] linea : valor){
				i = 0;
				for (String elemento : linea){
					input [i] = Double.parseDouble(elemento);
					i++;
				}

				net.setInput(input);
				net.calculate();
				resultado = net.getOutput();

				int j = 0;
				int posicion=0;
				double mayor=0;
				for (double posibilidad : resultado){
					if (posibilidad>mayor){
						mayor = posibilidad;
						posicion = j;
					}
					j++;
				}
				String numero = correspondeA(posicion);
				resultadoFinal=resultadoFinal+numero;
				if(posicion == 10){
					consola.write("El resultado es: , ("+Math.floor(mayor*100)+"%) "+resultado);
				}else{ if(posicion == 11){
					consola.write("El resultado es: . ("+Math.floor(mayor*100)+"%) "+resultado);
						}else{
							consola.write("El resultado es: "+posicion+" ("+Math.floor(mayor*100)+"%) "+resultado);
						}
				}
				System.out.println("El resultado es: "+posicion+" ("+Math.floor(mayor*100)+"%) "+resultado);
				consola.newLine();
				consola.newLine();
			}
			
			consola.close();
			return resultadoFinal;
		}catch (Exception e){
			e.printStackTrace();
		}

		return resultadoFinal;
	}


	private String correspondeA(int posicion) {
		switch (posicion){
		case 0: return "0";
		case 1: return "1";
		case 2: return "2";
		case 3: return "3";
		case 4: return "4";
		case 5: return "5";
		case 6: return "6";
		case 7: return "7";
		case 8: return "8";
		case 9: return "9";
		case 10: return ",";
		case 11: return ".";

		default: return "";
		
		}
	}
	
	
}
