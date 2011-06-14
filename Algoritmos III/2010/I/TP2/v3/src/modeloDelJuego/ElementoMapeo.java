package modeloDelJuego;

public class ElementoMapeo {
	private String tipoNota;
	private Tecla unaTecla;
	
	
	public ElementoMapeo(String tipoNota,String tipoTecla){
			this.tipoNota = tipoNota;
			this.unaTecla = new Tecla(tipoTecla);
	
	}

	public String getTipoNota(){
		return tipoNota;
		
		
	}

	public Tecla getTecla() {
		return unaTecla;
	}

}
