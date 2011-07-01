import org.neuroph.core.NeuralNetwork;
import org.neuroph.contrib.ocr.OcrPlugin;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

public class Ejemplo {

	public static void man(String[] args) {

		NeuralNetwork nnet = NeuralNetwork.load("data/hand.nnet"); // load trained neural network saved with easyNeurons
		OcrPlugin ocrRecognition = (OcrPlugin)nnet.getPlugin(OcrPlugin.OCR_PLUGIN_NAME);
		File archivo;

		System.out.print("2 - ");	archivo = new File("data/ejemplo2.png");
		recog (ocrRecognition, archivo);
		System.out.print("5 - ");	archivo = new File("data/ejemplo5.png");
		recog (ocrRecognition, archivo);
		System.out.print("7 - ");	archivo = new File("data/ejemplo7.png");
		recog (ocrRecognition, archivo);
		System.out.print("8 - ");	archivo = new File("data/ejemplo8.png");
		recog (ocrRecognition, archivo);

	}

	private static void recog(OcrPlugin ocrRecognition,File archivo) {
		BufferedImage img;
		try {
		   img = ImageIO.read(archivo);
		   char output = ocrRecognition.recognizeCharacter(img);
		   System.out.println(output);
		} catch (IOException ex) {
		   System.err.println(ex.getMessage());
		   ex.printStackTrace();
		}
	}
}
