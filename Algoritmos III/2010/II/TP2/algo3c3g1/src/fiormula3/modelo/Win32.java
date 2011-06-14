package fiormula3.modelo;

public class Win32 extends Motor {
		private static double velocidadMaxima = 100;
		private static double aceleracionUnicaEtapa = 20;

		public void aumentarVelocidad(double deltaTiempo) {
			  double deltaVelocidad = Win32.aceleracionUnicaEtapa * deltaTiempo;
				setVelocidad(this.velocidad + deltaVelocidad);
				if (this.velocidad > velocidadMaxima) {
						setVelocidad(Win32.velocidadMaxima);
				}
		}
}