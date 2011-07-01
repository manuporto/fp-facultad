import javax.swing.JFrame;
import java.awt.Rectangle;

import javax.swing.JFileChooser;
import javax.swing.JTextField;
import javax.swing.JButton;

public class Test extends JFrame {

   private javax.swing.JPanel jContentPane = null;

   private javax.swing.JCheckBox jCheckBox = null;
   private javax.swing.JLabel jLabel = null;

private JTextField jTextField = null;
private JTextField filename = new JTextField(),
dir = new JTextField();
private JButton jButton = null;
   /**
 * This method initializes jTextField	
 * 	
 * @return javax.swing.JTextField	
 */
private JTextField getJTextField() {
	if (jTextField == null) {
		jTextField = new JTextField();
		jTextField.setBounds(new Rectangle(80, 30, 129, 23));
	}
	return jTextField;
}
/**
 * This method initializes jButton	
 * 	
 * @return javax.swing.JButton	
 */
private JButton getJButton() {
	if (jButton == null) {
		jButton = new JButton();
		jButton.setBounds(new Rectangle(231, 28, 35, 29));
		jButton.setText("...");
		jButton.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent e) {

				JFileChooser c = new JFileChooser();
			      // Demonstrate "Open" dialog:
			      int rVal = c.showOpenDialog(Test.this);
			      if (rVal == JFileChooser.APPROVE_OPTION) {
			        filename.setText(c.getSelectedFile().getName());
			        dir.setText(c.getCurrentDirectory().toString());
			      }
			      if (rVal == JFileChooser.CANCEL_OPTION) {
			        filename.setText("You pressed cancel");
			        dir.setText("");
			      }				

			}
		});
	}
	return jButton;
}
public static void main(String[] args) {
      Test test = new Test();
      test.setDefaultCloseOperation(EXIT_ON_CLOSE);
      test.setVisible(true);
   }
   /**
    * This is the default constructor
    */
   public Test() {
      super();
      initialize();
   }
   /**
    * This method initializes this
    * 
    * @return void
    */
   private void initialize() {
      this.setContentPane(getJContentPane());
      this.setSize(300, 200);
   }
   /**
    * This method initializes jContentPane
    * 
    * @return javax.swing.JPanel
    */
   private javax.swing.JPanel getJContentPane() {
      if (jContentPane == null) {
         jContentPane = new javax.swing.JPanel();
         jContentPane.setLayout(null);
         jContentPane.add(getJCheckBox(), null);
         jContentPane.add(getJLabel(), null);
         jContentPane.add(getJTextField(), null);
         jContentPane.add(getJButton(), null);
      }
      return jContentPane;
   }
   /**
    * This method initializes jCheckBox
    * 
    * @return javax.swing.JCheckBox
    */
   private javax.swing.JCheckBox getJCheckBox() {
      if (jCheckBox == null) {
         jCheckBox = new javax.swing.JCheckBox();
         jCheckBox.setBounds(87, 70, 21, 21);
         jCheckBox
            .addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent e) {
               jLabel.setText(
                  jCheckBox.isSelected() ? "Checked" : "Unchecked");
            }
         });
      }
      return jCheckBox;
   }
   /**
    * This method initializes jLabel
    * 
    * @return javax.swing.JLabel
    */
   private javax.swing.JLabel getJLabel() {
      if (jLabel == null) {
         jLabel = new javax.swing.JLabel();
         jLabel.setBounds(111, 73, 110, 22);
         jLabel.setText("Unchecked");
      }
      return jLabel;
   }
} //  @jve:visual-info  decl-index=0 visual-constraint="9,8"
