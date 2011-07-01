import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;



public class Reconocedor {

	static BufferedWriter Txt;
	
	String imagen;

	public Reconocedor(String nombreArchivo){

		this.imagen = nombreArchivo; 

	}

	public String ejecutar() throws IOException {
		// creo una imagen a binarizar
	
		this.imagen = "data/tira5.png";
//		String imagen = "data/tira5.png";
		String csv = "data/archivo.csv";

		Txt = new BufferedWriter(new FileWriter(csv));
		Binarizar ProcesoBinario = new Binarizar(this.imagen,Txt) ;
		String resultado = "data/Resultado.jpg";
		// genero una imagen binaria a partir de una normal
			if (ProcesoBinario.GenerarImagenBinaria(resultado)== 0 ) {
		
				//generar matriz binaria
				if (ProcesoBinario.GenerarMatrizBinaria(resultado) == 0 ) {
				
					// guardo la matriz binaria en archivo txt
					ProcesoBinario.GenerarTxtBinario(resultado,"data/Resultado.txt");
				
				}else{
					System.out.println("falla aca 3");
				}
			}
				else{
					System.out.println("falla aca 2");
				}
			
			int actual=0;
			
			System.out.println("Procesando...");
			System.out.println();

			while (actual!=-1){
				actual = ProcesoBinario.cortarImagenes(actual);
			}
			Txt.close();

			
			Test test = new Test();
			String resultadoFinal = test.go(csv);
			
			return resultadoFinal;
	}
		
}
