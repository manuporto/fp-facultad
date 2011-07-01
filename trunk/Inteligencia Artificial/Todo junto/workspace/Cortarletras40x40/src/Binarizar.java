import java.awt.image.BufferedImage;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import javax.imageio.ImageIO;


public class Binarizar {
	
	 BufferedImage img;
	 String nomImagenEntrada;
     BufferedWriter bufferTxt;
     int [][] matriz = null;
     int ancho;
     int alto;
     int numeroDeNumero = 0;
	 BufferedWriter Txt;

     static final int DIMENSION_FINAL = 200;
     static final int TAMANIO_MAXIMO = 200;

	 public Binarizar(String nombreImagen,BufferedWriter Txt) throws IOException{
		 super();
		 nomImagenEntrada = nombreImagen;
		 img = ImageIO.read(new File(nomImagenEntrada));
		 ancho = img.getWidth();
		 alto = img.getHeight();
		 matriz = new int[ancho][alto];
		 this.Txt = Txt;
	 }

	public int GenerarImagenBinaria(String nombreBinaria ) {

		String comando;
		
/*		if (alto > this.TAMANIO_MAXIMO){
				comando = "convert.exe -monochrome -paint 1 -resize x"+this.TAMANIO_MAXIMO+" " + nomImagenEntrada + " " + nombreBinaria;
		}
		else {*/
			comando = "convert.exe -monochrome -paint 1 " + nomImagenEntrada + " " + nombreBinaria;
//		}
		
		try{
			Process convert = Runtime.getRuntime().exec(comando);
			convert.waitFor();
		} catch (IOException e) {
		      e.printStackTrace();
		     return 5;
		} catch (InterruptedException e) {
				
		      e.printStackTrace();
		      return 3;
	    }
		return 0;
	}	
		
	public int GenerarMatrizBinaria(String ImagenMono) throws IOException {
			
         int columna = 0;
         int fila = 0;
         BufferedImage buffImagen = ImageIO.read(new File(ImagenMono));
         
	     while (buffImagen.getHeight() > fila){
	    	 columna = 0;
	    	 
	    	 while (buffImagen.getWidth() > columna){

//	    		 int a = buffImagen.getRGB(columna,fila);
//	    		 if (a!= -1) System.out.println(a);

	    		 if (buffImagen.getRGB(columna, fila) < -200000){
	    			 matriz[columna][fila] = 1;
					}else{
						matriz[columna][fila] = 0;
					}
	    		 columna++;
	    	 }
	        	   
	    	 fila++;
	     }

//	     imprimir (matriz);
	     return 0;

	}
	
	public int GenerarTxtBinario(String ImagenMono, String nombreTxt ) {
	
		int fila = 0;
	    int columna;
	    BufferedImage buffImagen;

	    try{
	    	buffImagen = ImageIO.read(new File(ImagenMono));
	    	bufferTxt = new BufferedWriter(new FileWriter(nombreTxt));


		    while (buffImagen.getHeight() > fila){
		    	columna = 0;

				while (buffImagen.getWidth() > columna){
					
					if ((buffImagen.getWidth()- 1)  == columna ){
						
						bufferTxt.write(" " + matriz[columna][fila]);
						bufferTxt.newLine();
						
						
					}else{
						bufferTxt.write(" " + matriz[columna][fila]);
					}
	
					columna++;
		        }
		        fila++;
		    }
		    bufferTxt.close();

		} catch (Exception e) {
			return 1;
		}
		return 0;
	}

	public int cortarImagenes (int comienzo){
		int i=comienzo;
		int j=0;
		int primeraColumna=0;
		int ultimaColumna=0;
		
		do{

			while (j != 1 && i<this.ancho){
				j = recorrerColumna (i);
				if (j == 1){
					primeraColumna = i;
	//				System.out.println("La primera columna es "+i+"\n");
				}
				i++;
			}
	
			while (j != 0 && i<this.ancho){
				j = recorrerColumna (i);
				if (j == 0){
					ultimaColumna = i;
				}

				if (i==(this.ancho-1) && ultimaColumna==0){
					j = 0;
					ultimaColumna = i;
					i--;
				}

				i++;
			}
		
		}while (((ultimaColumna - primeraColumna) < 5 ) && (i !=this.ancho));

		if (i != this.ancho){
			generarNumero (primeraColumna,ultimaColumna);
		}

		if (i==this.ancho) return -1;
		return ultimaColumna;
		
	}
	
	private int[][] cuadrar (int[][] matriz){
		int ancho = matriz.length;
		int alto = matriz[0].length;
		int [][]matrizSuperAux = null;
		int dejarEnBlanco;
		
		if (ancho == alto){
			matrizSuperAux = new int[ancho][alto];
			matrizSuperAux = matriz;
		}

		if (ancho > alto){
			matrizSuperAux = new int[ancho][ancho];
			for (int i=0;i<ancho;i++){
				for (int j=0;j<alto;j++){
					matrizSuperAux[i][j] = 0;
				}
			}

			dejarEnBlanco = (ancho-alto)/2;
			for (int i=0;i<ancho;i++){
				for (int j=dejarEnBlanco;j<alto+dejarEnBlanco;j++){
					matrizSuperAux[i][j] = matriz[i][j-dejarEnBlanco];
				}
			}
		}
		if (ancho < alto){
			matrizSuperAux = new int[alto][alto];
			for (int i=0;i<ancho;i++){
				for (int j=0;j<alto;j++){
					matrizSuperAux[i][j] = 0;
				}
			}

			dejarEnBlanco = (alto-ancho)/2;
			for (int i=dejarEnBlanco;i<(ancho+dejarEnBlanco);i++){
				for (int j=0;j<alto;j++){
					matrizSuperAux[i][j] = matriz[i-dejarEnBlanco][j];
				}
				
			}
		}
		
		int [][] matrizCuadrada;

		matrizCuadrada = espejar (matrizSuperAux);
		
		generarTxt (matrizCuadrada,"data/txt/TercerPaso"+this.numeroDeNumero+".txt");
		
//		imprimir (matrizSuperAux);
//		imprimir (matrizCuadrada);
		return matrizCuadrada;
	}
	
	private void generarTxt(int[][] matriz, String nombre) {
		
		int ancho = matriz.length;
		int alto = matriz[0].length;
		
		BufferedWriter buffer;
		
	    try{
	    	buffer = new BufferedWriter(new FileWriter(nombre));

	    	for (int i=0; i<ancho;i++){
	    		for (int j=0; j<alto;j++){
	    			buffer.write(" " + matriz[i][j]);
	    		}
				buffer.newLine();
	    	}

		    buffer.close();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private int recorrerColumna (int comienzo){
		int hayUnos = 0;

		for (int j=0;j<this.alto;j++){
			if (matriz[comienzo][j] == 1){
				hayUnos = 1;
			}
		}

		if (hayUnos == 1) return 1;
		return 0;
	}

	private void redimensionar (int[][] matriz){
		int dimension = matriz.length;
		int[][] matrizFinal = new int[this.DIMENSION_FINAL][this.DIMENSION_FINAL];
		
		if (dimension > this.DIMENSION_FINAL){
			int hayUnos = 0;
			float numeroMagico = ((float)dimension/(float)(this.DIMENSION_FINAL-1));

			for (int z=0;z<this.DIMENSION_FINAL;z++){
				for (int x=0;x<this.DIMENSION_FINAL;x++){
					matrizFinal[z][x] = 0;
				}
			}

			System.out.println ("numeroMagico: "+numeroMagico);
			for (int i = 0; i < dimension; i=i+(int)numeroMagico){
//				System.out.println ("Hola2 :" +( i+(int)numeroMagico));
				for (int j = 0; j < dimension; j=j+(int)numeroMagico){
//					System.out.println ("Hola3 : " + (int)(j+numeroMagico));
					hayUnos = 0;
					for (int k=i;k<i+(int)numeroMagico;k++){
						for (int l=j;l<j+(int)numeroMagico;l++){
							if (matriz[k][l] == 1){
								hayUnos=1;
							}
						}
						if (hayUnos == 1){
							if (((int)(numeroMagico * i) < this.DIMENSION_FINAL) && ((int)(numeroMagico * j) < this.DIMENSION_FINAL)){
								matrizFinal[(int)(numeroMagico * i)][(int)(numeroMagico * j)] = 1;
							}
							else{
								System.out.println ("No entra");
							}
						}
					}
				}
				
			}
		}
		
		if (dimension == this.DIMENSION_FINAL){
			matrizFinal = matriz;
		}
		
		if (dimension < this.DIMENSION_FINAL){
			for (int z=0;z<this.DIMENSION_FINAL;z++){
				for (int x=0;x<this.DIMENSION_FINAL;x++){
					matrizFinal[z][x] = 0;
				}
			}

//			imprimir (matriz);

			float numeroMagico = ((float)(this.DIMENSION_FINAL-1) / (float)dimension);
//			int numeroMagico = (this.DIMENSION_FINAL / dimension);
//			if (this.DIMENSION_FINAL % dimension != 0) numeroMagico++;
			
			
			for (int i=0;i<dimension;i++){
				for (int j=0;j<dimension;j++){
					if (matriz[i][j] == 1){
						for (int k=(int)(numeroMagico*i);k<(int)(numeroMagico*(i+1));k++){
							for (int l=(int)(numeroMagico*j);l<(int)(numeroMagico*(j+1));l++){
//									System.out.println("i = "+i+" -> k = "+k);
									matrizFinal[k][l] = 1;
							}
						}
					}
				}
			}
	
		}
		generarTxt (matrizFinal,"data/txt/CuartoPaso"+this.numeroDeNumero+".txt");
		int[][] nuevaMatriz = Llevara40x40(matrizFinal);
		generarCSV (nuevaMatriz);
	}

	private int[][] Llevara40x40(int[][] matriz) {
		int ancho = matriz.length;
		int alto = matriz[0].length;
		int cantUnos,fil,col;
		int [][] matriz40x40 = new int [40] [40];
		
		fil=0;
		col=0;
		
		for (int i=0;i<ancho;i=i+5 ){
			col=0;
			for (int j=0;j<alto;j=j+5 ){
				cantUnos = 0;
//				System.out.println("i = " + i + " | j = " + j   );
				for(int k=i; k <i+5;k++ ){
					for(int l=j; l <j+5;l++ ){
//						System.out.println("k = " + k + " | l = " + l   );
						if (matriz[k][l] == 1) {
							cantUnos++;
						}
					}
				}
//				System.out.println("col = " + col + "fil = " + fil   );
//				System.out.println("cantUnos = " + cantUnos   );
				if (cantUnos > 2) {matriz40x40[fil][col] = 1;
//				System.out.println("matriz40x40[col][fil] = " + matriz40x40[col][fil]   );
				}else{matriz40x40[fil][col] = 0;
//				System.out.println("matriz40x40[col][fil] = " + matriz40x40[col][fil]   );
				}
				col++;
			}
			fil++;
		}

		generarTxt(matriz40x40,"data/txt/40x40" + this.numeroDeNumero + ".txt");
		
		return matriz40x40;
	}

	private int cortarVerticalmente(int[][] matriz){

		int i = 0;
		int j = 0;
		
		int primeraFila=0;
		int ultimaFila=0;

		int ancho = matriz.length;
		int alto = matriz[0].length;
		
		do {

			while (j != 1 && i<alto){
				j = recorrerFila (i,matriz);
				if (j == 1){
					primeraFila = i;
				}
				i++;
			}
	
			while (j != 0 && i<alto){
				j = recorrerFila (i,matriz);
				if (j == 0){
					ultimaFila = i;
				}

				if (i==(alto-1) && ultimaFila==0){
					j = 0;
					ultimaFila = i;
					i--;
				}
				
				i++;
			}
		
		}while ( (ultimaFila-primeraFila < 5) && (i != alto) );
		
		generarNumeroDesdeFila (primeraFila,ultimaFila,matriz);
		
		if (i==alto) return -1;
		return ultimaFila;
		
	}
	
	private void generarNumeroDesdeFila (int desde,int hasta,int[][] matriz){
		
    	int [][] matrizAuxFila;
		int ancho = matriz.length;
		int alto = hasta;
    	matrizAuxFila = new int[ancho][(hasta-desde)];

		try{
	    	String nombreTxt = "data/txt/SegundoPaso"+numeroDeNumero+".txt";
	    	bufferTxt = new BufferedWriter(new FileWriter(nombreTxt));

	    	int fila = desde;

		    while (alto > fila){
		    	int columna = 0;

				while (ancho > columna){

					if ((ancho - 1)  == columna ){

						bufferTxt.write(" " + matriz[columna][fila]);
						bufferTxt.newLine();
					}else{
						bufferTxt.write(" " + matriz[columna][fila]);
					}
					matrizAuxFila[columna][fila-desde] = matriz[columna][fila];
					columna++;
		        }
		        fila++;
		    }
		    bufferTxt.close();
		    
//		    imprimir (matrizAuxFila);
		    
		    int[][] matrizCuadrada = cuadrar (matrizAuxFila);
		    
		    redimensionar (matrizCuadrada);

	   }catch (Exception e){
		   e.printStackTrace();
	   }
}
	
	private int recorrerFila (int comienzo,int[][] matriz){
		int hayUnos = 0;

		int ancho = matriz.length;

		for (int j=0;j<ancho;j++){
			if (matriz[j][comienzo] == 1){
				hayUnos = 1;
			}
		}

		if (hayUnos == 1) return 1;
		return 0;
	}
		

private int generarNumero(int desde, int hasta){
		
	    try{
	    	String nombreTxt = "data/txt/PrimerPaso"+numeroDeNumero+".txt";
	    	bufferTxt = new BufferedWriter(new FileWriter(nombreTxt));
	    
	    	int ancho = hasta;
	    	int fila = 0;
	    	int [][] matrizAux;
	    	matrizAux = new int[(hasta-desde)][this.alto];

		    while (this.alto > fila){
		    	int columna = desde;

				while (ancho > columna){

					if ((ancho - 1)  == columna ){

						bufferTxt.write(" " + matriz[columna][fila]);
						bufferTxt.newLine();
					}else{
						bufferTxt.write(" " + matriz[columna][fila]);
					}
					matrizAux[(columna-desde)][fila] = matriz[columna][fila];

					columna++;
		        }
		        fila++;
		    }
		    bufferTxt.close();

		    cortarVerticalmente(matrizAux);
		    this.numeroDeNumero++;
		    
		} catch (Exception e) {
			return 1;
		}
		return 0;
	}

	private void imprimir (int[][] matriz){
		int ancho = matriz.length;
		int alto = matriz[0].length;

		for (int i=0;i<ancho;i++){
			for (int j=0;j<alto;j++){
				System.out.print(matriz[i][j]);
			}
			System.out.println();
		}
	}

	private int[][] espejar (int[][] matriz){
		int dimension = matriz.length;
		int [][] matrizSalida = new int [dimension][dimension];

		for (int i=0;i<dimension;i++){
			for (int j=0;j<dimension;j++){
				matrizSalida[i][j] = matriz [j][i];
			}
		}
		
		return matrizSalida;
	}

	private void generarCSV (int[][] matriz){
		
//		String nombreTxt = "data/numero"+numeroDeNumero+".csv";
		try {
//	    	BufferedWriter bufferTxt = new BufferedWriter(new FileWriter(nombreTxt));
			int ancho = matriz.length;
			int alto = matriz[0].length;
			Integer valor;
	
			for (int i=0;i<ancho;i++){
				for (int j=0;j<alto;j++){
					valor = matriz[i][j];
					Txt.write(valor.toString());
					if (i!=(ancho-1) || j!=(alto-1))
						Txt.write(",");
				}
//				Txt.newLine();
			}
			Txt.newLine();
			bufferTxt.close();
		}
		catch (Exception e){
			e.printStackTrace();
		}
	}
}