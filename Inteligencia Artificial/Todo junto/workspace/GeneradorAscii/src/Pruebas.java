import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;



public class Pruebas {

	 static BufferedWriter Txt;
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// creo una imagen a binarizar

		Txt = new BufferedWriter(new FileWriter("data/entrenamiento.csv"));
		Binarizar ProcesoBinario = new Binarizar("data/ejemplo1.jpg",Txt) ;
		
		String resultado = "data/Resultado.jpg";
		// genero una imagen binaria a partir de una normal
			if (ProcesoBinario.GenerarImagenBinaria(resultado)== 0 ) {
		
				//generar matriz binaria
				if (ProcesoBinario.GenerarMatrizBinaria(resultado) == 0 ) {
				
					// guardo la matriz binaria en archivo txt
					System.out.println(ProcesoBinario.GenerarTxtBinario(resultado,"data/Resultado.txt"));
				
				}else{
					System.out.println("falla aca 3");
				}
			}
				else{
					System.out.println("falla aca 2");
				}
			
			int actual=0;

			while (actual!=-1){
				actual = ProcesoBinario.cortarImagenes(actual);
			}
			Txt.close();
		}

}
