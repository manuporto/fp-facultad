package fiormula3.modelo;

public class MacX extends Motor {
		private static double velocidadEtapaUno = 100;
		private static double aceleracionEtapaUno = 50;
		private static double velocidadEtapaDos = 150;
		private static double aceleracionEtapaDos = 3.3;

		/* Notar que: si durante deltaTiempo se cambió de etapa, el tiempo de
		 * aceleración de la segunda etapa se descarta; es decir, el motor solo
		 * acelera hasta velocidadEtapaUno durate ese deltaTiempo. */
		public void aumentarVelocidad(double deltaTiempo) {

				/* En la primera etapa de aceleración. */
				if (this.velocidad < MacX.velocidadEtapaUno) {
						double deltaVelocidad = MacX.aceleracionEtapaUno * deltaTiempo;
						setVelocidad(this.velocidad + deltaVelocidad);
						if (this.velocidad > velocidadEtapaUno) {
								setVelocidad(MacX.velocidadEtapaUno); /* Descarto! */
						}
				} else {
						double deltaVelocidad = MacX.aceleracionEtapaDos * deltaTiempo;
						setVelocidad(this.velocidad + deltaVelocidad);
						if (this.velocidad > velocidadEtapaDos) {
								setVelocidad(MacX.velocidadEtapaDos); /* Limite de velocidad */
						}
				}
						
		}
}