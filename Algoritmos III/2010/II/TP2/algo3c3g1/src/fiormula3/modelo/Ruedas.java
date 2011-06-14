package fiormula3.modelo;

public abstract class Ruedas {

		private double daño;

		public double daño() { return this.daño; }
		public void setDaño(double d) {
				if ((d >= 0.0) && (d <= 1.0)) this.daño = d;
		}
}
