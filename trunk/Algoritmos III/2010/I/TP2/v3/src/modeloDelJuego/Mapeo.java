package modeloDelJuego;

import java.util.*;


public class Mapeo {
	private List<ElementoMapeo> elementosMap; 
	
	public Mapeo(){
		this.elementosMap = new ArrayList<ElementoMapeo>();	
	}

	
	public void add(String tipoNota,String tipoTecla){
		ElementoMapeo elemMap = new ElementoMapeo(tipoNota,tipoTecla);
		this.elementosMap.add(elemMap);
		
	}


	public Tecla buscarTecla(String tipoNota) {
		int i = 0;
		ElementoMapeo elemMap;
		Tecla unaTecla;
		while(elementosMap.size()>i){
			elemMap = elementosMap.get(i);
			if(elemMap.getTipoNota() == tipoNota ){
				unaTecla= elemMap.getTecla();
				return unaTecla;
			}
			i++;
		}
		
		return null;
	}



}
