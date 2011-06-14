package modeloDelJuego;

import java.util.*;

public class Cancion {
	private String nombre;
	private List<Compas> compases ;
	private Compas unCompasActual;//lo puedo poner dentro del metodo, que lo usa, como privado
	private double tiempoDeCompas,tiempoNotasAcumulado;
	private FiguraMusical figuraDelCompas;
	private int cantidadFiguraDelCompas;
	private double cantidadCompases, cantidadNotas,cantidadNotasCompas;
	private Mapeo unMapeo;
	
	
	public Cancion(String nombre,double tiempoDeCompasEnSeg,FiguraMusical figuraDelCompas,int cantidadDeFigura) {
	
	this.nombre =nombre;
	this.compases= new ArrayList<Compas>();	
	this.figuraDelCompas= figuraDelCompas;
	this.tiempoDeCompas = tiempoDeCompasEnSeg;
	this.cantidadFiguraDelCompas = cantidadDeFigura;
	this.unCompasActual= new Compas();
	this.tiempoNotasAcumulado = 0;
	this.cantidadCompases = 0;
	this.cantidadNotasCompas = 0;
	this.cantidadNotas= 0;
	this.unMapeo = new Mapeo(); 
	}

	
	public void addNota(Nota unaNota) {
		double tiempo = duracionDeRedonda(tiempoDeCompas, figuraDelCompas, cantidadFiguraDelCompas);
		//la duracion de la figura de "unaNota" sera: el valor de la figura en relacion a la "Redonda"
		//multiplicada por la duracion de una Redonda(que es la unidad)
		
		double tiempoNota = ((unaNota.valorFigura())* tiempo);
		
		if((tiempoNota+ this.tiempoNotasAcumulado)<=tiempoDeCompas){
			unCompasActual.agregarNota(unaNota);	
			this.tiempoNotasAcumulado += tiempoNota ;
			this.cantidadNotas +=1;
			this.cantidadNotasCompas +=1;
		}
		else{	//si superé el tiempo de compas
			if(unCompasActual.vacio()== false) //si el compas tiene notas cargadas
				compases.add(unCompasActual);
				this.unCompasActual = new Compas(); //reinicio el compas
				this.tiempoNotasAcumulado=0;
				this.cantidadNotasCompas=0;
				this.cantidadCompases+=1;
		}
	
	}

	
	public Nota getNota(int numCompas, int numNota){
		Nota unaNota1;
		//puede ocurrir que el compas pedido no se haya cargado a la lista de compases
		//por no haber completado con las notas la totalidad del compas,pero
		//puede tener el compas pedido algunas notas cargadas
			if(Math.abs(numCompas - compases.size())==1){//si la diferencia es mayor a 1 en valor
			 										//absoluto es porque ese compas no existe en la cancion
													//hacer el chequeo de que no pueden ser numeros <0
			
				if(unCompasActual.vacio()== false){ //el compas pedido tiene notas cargadas
				unaNota1=unCompasActual.obtenerNota(numNota-1);
				return unaNota1;
			 	}
			} 
		
		 Compas unCompas1=compases.get(numCompas-1);
		 unaNota1=unCompas1.obtenerNota(numNota-1);
		return unaNota1;
	}
	
	
	
	//calcula la duracion de una Redonda
	private double duracionDeRedonda(double tiempoDeCompas,
			FiguraMusical figuraDelCompas, int cantidadFiguraDelCompas) {
			double valorDeFigura = figuraDelCompas.vecesRedonda();
			double tiempoDeRedonda = (tiempoDeCompas)/((cantidadFiguraDelCompas)*(valorDeFigura));
		
		return tiempoDeRedonda;
	}
	
	
	//devuelve la cantidad de compases que tiene la cancion
	public double cantidadCompases(){
		return this.cantidadCompases;
	}
	
	
	//devuelve la cantidad de notas que tiene una determinada cancion
	public double cantidadNotas(){
		return this.cantidadNotas;
		
	}

	public void asignarAlMapeo(String tipoNota,String tipoTecla){
		
		this.unMapeo.add(tipoNota, tipoTecla);
	}


	public Tecla teclaDeNota(String tipoNota) {
		Tecla unaTecla= unMapeo.buscarTecla(tipoNota);
		
		
		return unaTecla;
	}

}
