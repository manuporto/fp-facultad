
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Frame;
import java.awt.GridLayout;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

import javax.swing.BorderFactory;
import javax.swing.GroupLayout;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.SpringLayout;
import javax.swing.SwingConstants;
import javax.swing.Timer;
import javax.swing.border.Border;
import javax.swing.border.EmptyBorder;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;
import javax.swing.JInternalFrame;
import javax.swing.JTabbedPane;
import javax.swing.JScrollBar;
import java.awt.ScrollPane;
import javax.swing.JProgressBar;
import java.beans.VetoableChangeListener;
import java.beans.PropertyChangeEvent;

public class Uploader extends JFrame {

	private JTextField nombreArchivo;
	private JTextField resultado;
	private JButton abrir;
	private JButton enviar;
	private String resultadoFinal;
	private static Uploader frame;
	private JTextArea textArea;
	private JScrollPane scrollPane;
	private JProgressBar progressBar;
	private JPanel p_1;
	Timer timer ;
	int i;

	public String obtenerImagen(){
		return null;
	}

	public Uploader() {
		super("Reconocimiento de caracteres");
//		this.getContentPane().setLayout(new );
		
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

	    p_1 = new JPanel();
	    p_1.setBorder(new EmptyBorder(10,10,10,10));
	    p_1.setLayout(new GridLayout(2,1,10,20));
	    p_1.add(nombreArchivoLabel);
	    p_1.add(nombreArchivo);
	    p_1.add(resultado);
	    ventana.add(p_1, BorderLayout.NORTH);	    
	    
	    progressBar = new JProgressBar(0, 20);
	    progressBar.setValue(0);
	    progressBar.setStringPainted(true);
	    progressBar.setVisible(false);
	    p_1.add(progressBar);
	    
		 
	    int interval = 1000;
		timer = new Timer(interval, new ActionListener() {
		public void actionPerformed(ActionEvent evt) {
		    
	    	if (i == 20){
	    		Toolkit.getDefaultToolkit().beep();
	    		timer.stop();	    	  
	    		progressBar.setValue(0);
	    	  }
	    	  i = i + 1;
	    	  progressBar.setValue(i);
			}
	    }
		); 
	    
	    
	    
	    
	    
	    textArea = new JTextArea();
	    getContentPane().add(textArea, BorderLayout.CENTER);
	    
	    scrollPane = new JScrollPane(textArea);	    
	    textArea.setEditable(false);
	    textArea.setFont(new java.awt.Font("Arial", Font.PLAIN, 12));
	    scrollPane = new JScrollPane(textArea,JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);	    
	    getContentPane().add(scrollPane, BorderLayout.CENTER);	    
	    
    
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
	    			
	    			progressBar.setVisible(true);
	    			i = 0;
	    			  String str = "Procesando...";
	    			  resultado.setText(str);
	    			  timer.start();
	    			
	    			try {
						resultadoFinal = reconocedor.ejecutar();
						
						progressBar.setValue(20);
						timer.stop();
						
					} catch (IOException e1) {
						e1.printStackTrace();
					}
	    			resultado.setText("Resultado: "+resultadoFinal);
	    			
	    			ObtenerDeConsola();

	    		}
	    		else
	    			resultado.setText("Archivo no válido.");
	    	}

	    }
	    

	    
	    
	    

		private void ObtenerDeConsola() {
			// Va a imprimir el Archivo de Consola
			String executionPath = System.getProperty("user.home");
			File archConsola = new File(executionPath + "\\consola.txt");
			System.out.println( executionPath + "\\consola.txt");
			try {
				BufferedReader consola = new BufferedReader(new FileReader(archConsola.getPath()));
					
				String linea;
				try {
					linea = consola.readLine();

					while (linea != null)
				{
			  
					textArea.append(linea  + "\n");
					linea = consola.readLine();
				}
					consola.close();
					archConsola.delete();
					
				} catch (IOException e) {
					e.printStackTrace();
				}
				
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
			
		}

		private boolean esValido(String text) {
			if (text.endsWith(".jpg") || text.endsWith("png"))
				return true;
			return false;
		}
	  }

	  	  
	  
	  public static void main(String[] args) {
		 frame = new Uploader();
		 run( 500, 200);
	  }

	  public static void run(int width, int height) {
	    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    frame.setBounds(200,200, width, height);
	    frame.setSize(width, height);
	    frame.setVisible(true);
	  }
}
