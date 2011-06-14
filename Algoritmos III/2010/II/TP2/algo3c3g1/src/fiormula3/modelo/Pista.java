package fiormula3.modelo;

import java.util.List;

public class Pista {
	
		private Auto auto;
		private List<Obstaculo> obstaculos;
		private List<Superficie> superficies;
	
		/* Constructor principal */
		public Pista (Auto auto, List<Obstaculo> obs, List<Superficie> sups) {
				this.auto = auto;
				this.obstaculos = obs;
				this.superficies = sups;
		}
	
		public Auto auto() {
				return this.auto;
		}
		public void setAuto(Auto auto) {
				this.auto = auto;
		}	
}