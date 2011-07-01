
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import javax.swing.BorderFactory;
import javax.swing.GroupLayout;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.SpringLayout;
import javax.swing.SwingConstants;
import javax.swing.border.Border;
import javax.swing.border.EmptyBorder;

public class Uploader extends JFrame {

	private JTextField nombreArchivo;
	private JTextField resultado;
	private JButton abrir;
	private JButton enviar;
	private String resultadoFinal;

	public String obtenerImagen(){
		return null;
	}

	public Uploader() {
		super("Reconocimiento de caracteres");
		
		JLabel nombreArchivoLabel =new JLabel("Ruta de la imagen a reconocer: ");
		nombreArchivo = new JTextField();
		resultado = new JTextField();
		abrir = new JButton("Buscar imagen"); 
		enviar = new JButton("Reconocer");
		JPanel p = new JPanel();

		nombreArchivoLabel.setPreferredSize(new Dimension(1,10));
		nombreArchivoLabel.setLabelFor(nombreArchivo);
		nombreArchivoLabel.setHorizontalAlignment(SwingConstants.RIGHT);
		nombreArchivo.setBorder(BorderFactory.createEmptyBorder());
		resultado.setBorder(BorderFactory.createEmptyBorder());

	    abrir.addActionListener(new OpenL());

	    p.add(abrir);
	    enviar.addActionListener(new SaveL());
	    p.add(enviar);
	    Container ventana = getContentPane();
	    ventana.add(p, BorderLayout.SOUTH);

//	    nombreArchivo.setEditable(false);
	    resultado.setEditable(false);

	    p = new JPanel();
	    p.setBorder(new EmptyBorder(10,10,10,10));
	    p.setLayout(new GridLayout(2,1,10,20));
	    p.add(nombreArchivoLabel);
	    p.add(nombreArchivo);
	    p.add(resultado);
	    ventana.add(p, BorderLayout.NORTH);
	  }

	  class OpenL implements ActionListener {
	    public void actionPerformed(ActionEvent e) {
	      JFileChooser c = new JFileChooser();

	      int rVal = c.showOpenDialog(Uploader.this);
	      if (rVal == JFileChooser.APPROVE_OPTION) {
	        nombreArchivo.setText(c.getCurrentDirectory().toString()+"\\"+c.getSelectedFile().getName());
	        resultado.setText("");
//	        directorio.setText(c.getCurrentDirectory().toString());
	      }
	      if (rVal == JFileChooser.CANCEL_OPTION) {
//	        nombreArchivo.setText("Cancelaste");
//	        directorio.setText("");
	      }
	    }
	  }

	  class SaveL implements ActionListener {
	    public void actionPerformed(ActionEvent e) {
	    	if ((nombreArchivo.getText().compareTo("") == 0) ){
	    		resultado.setText("No se eligió el archivo");
	    	}
	    	else{
	    		System.out.println(nombreArchivo.getText());

	    		if (esValido(nombreArchivo.getText())){
	    			resultado.setText("Procesando..."); // No sé por qué esto no se muestra
	    			Reconocedor reconocedor = new Reconocedor(nombreArchivo.getText());
	    			try {
						resultadoFinal = reconocedor.ejecutar();
					} catch (IOException e1) {
						e1.printStackTrace();
					}
	    			resultado.setText("Resultado: "+resultadoFinal);
	    		}
	    		else
	    			resultado.setText("Archivo no válido.");
	    	}

	    }

		private boolean esValido(String text) {
			if (text.endsWith(".jpg") || text.endsWith("png"))
				return true;
			return false;
		}
	  }

	  public static void main(String[] args) {
	    run(new Uploader(), 500, 200);
	  }

	  public static void run(JFrame frame, int width, int height) {
	    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    frame.setSize(width, height);
	    frame.setVisible(true);
	  }
}
