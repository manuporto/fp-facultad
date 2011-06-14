package fiormula3.modelo;

public abstract class Motor {

		protected double velocidad;
		private static int aceleracionDeFrenado = 20; /* 12, 20, 50 */

		public static Motor tipo(String tipo) {
				if (tipo == "Lin64") return new Lin64();
			  if (tipo == "Win32") return new Win32();
				if (tipo == "MacX") return new MacX();
				// else throw an exception.
				return null;
		}

		public double velocidad() {
				return this.velocidad;
		}
		public void setVelocidad(double vel) {
				/* INVARIANTE DE CLASE: La velocidad nunca es negativa. */
				if (vel >= 0.0) this.velocidad = vel;
				// else raise an (runtime?) exception.
		}

		/* Frenado uniforme para todos los motores. */
		public void disminuirVelocidad(double deltaTiempo) {
				double deltaVelocidad = Motor.aceleracionDeFrenado * deltaTiempo;
				this.setVelocidad(this.velocidad - deltaVelocidad);
		}

		/* Cada motor acelera de manera característica. */
		public abstract void aumentarVelocidad(double deltaTiempo);
}
