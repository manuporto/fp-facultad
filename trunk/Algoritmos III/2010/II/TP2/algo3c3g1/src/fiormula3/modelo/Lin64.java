package fiormula3.modelo;

public class Lin64 extends Motor {
		private static double velocidadMaxima = 120;
		private static double aceleracionUnicaEtapa = 12;

		public void aumentarVelocidad(double deltaTiempo) {
			  double deltaVelocidad = Lin64.aceleracionUnicaEtapa * deltaTiempo;
				setVelocidad(this.velocidad + deltaVelocidad);
				if (this.velocidad > velocidadMaxima) {
						setVelocidad(Lin64.velocidadMaxima);
				}
		}
}