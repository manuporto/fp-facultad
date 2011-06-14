package fiormula3.modelo;

public class Auto {
  
		private Motor motor;
		private Ruedas ruedas;
		private double velocidad;
		private double distanciaRecorrida;

		public Auto(Motor motor, Ruedas ruedas) {
				this.motor = motor;
				this.ruedas = ruedas;
				this.velocidad = 0.0;
				this.distanciaRecorrida = 0.0;
		}
		public Auto(Motor motor, Ruedas ruedas, double vel) {
				this(motor, ruedas);
				this.setVelocidad(vel);
		}
  
		/* Solo se permite acceso para lectura. */
		public double distanciaRecorrida() {
				return this.distanciaRecorrida;
		}

		/* Accesso para lectura y escritura (este último para testeo). */
		public void setVelocidad(double vel) {
				/* Invariante de clase: La velocidad nunca es negativa. */
				if (vel >= 0.0) this.velocidad = vel;
				// else raise an (runtime?) exception.
				// o talvez no, dependiendo de cómo esté implenentado "frenar".
		}
		public double velocidad() {
				return this.velocidad;
		}

		/*	public void acelerar(double deltaTiempo) */
		public void aumentarVelocidad(double deltaTiempo) {
				/* Acelero el motor durante este tiempo. */
				motor.aumentarVelocidad(deltaTiempo);

				/* La velocidad al final de deltaTiempo es... */
				double nuevaVelocidad = calcularVelocidadDelAuto();

				/* En este tiempo, con aumento lineal de la velocidad, se recorrio... */
				this.distanciaRecorrida = deltaTiempo * (this.velocidad + nuevaVelocidad) / 2;

				setVelocidad(nuevaVelocidad);
		}
		/* public void frenar(double deltaTiempo) */
		public void disminuirVelocidad(double deltaTiempo) {
				/* Freno el motor durante este timpo. */
				motor.disminuirVelocidad(deltaTiempo);

				this.setVelocidad(calcularVelocidadDelAuto());
		}

		/* Transformación que computa la vel del auto a partir de la del motor y
		 * del daño de las ruedas. */
		private double calcularVelocidadDelAuto() {
				return motor.velocidad() * (1 - ruedas.daño() / 100);
		}
}