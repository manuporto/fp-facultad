package test;
import modeloDelJuego.*;
import junit.framework.TestCase;

public class PruebaCancion extends TestCase {

	private Cancion unaCancion;


	protected void setUp() throws Exception {
		//creo una cancion pasando un nombre,una duracion de compas en segundos ,
		//una figura y su cantidad, que representan la duracion del compas
		unaCancion= new Cancion ("cancion1",2,new Blanca(),3);
	
	}

	
	//agrego una nota a una cancion y veo si esta en la ubicacion correcta, si su 
	//tipo es correcto y si su figura es correcta
	public void testAgregarNotaValida(){
	Cancion otraCancion= new Cancion ("cancion2",2,new Blanca(),3);
	otraCancion.addNota(new Do( new Blanca()));
	Nota unaNota = otraCancion.getNota(1,1);
	assertEquals("Do",unaNota.getTipo()) ;
	assertEquals("Blanca", unaNota.getFigura());
	}
	
	
	//debe lanzar excepciones para datos invalidos
	public void testAgregarNotaInValida(){}
	
	
	//veo si las notas y figuas son las mismas que las pasadas por parametros 
	public void testNotaYFiguraValida(){
		Nota unaNota = new Do(new Negra());
		assertEquals("Do",unaNota.getTipo()) ;
		assertEquals("Negra", unaNota.getFigura());
		unaNota = new Sol(new SemiCorchea());
		assertEquals("Sol",unaNota.getTipo()) ;
		assertEquals("SemiCorchea", unaNota.getFigura());
		unaNota = new Fa(new Redonda());
		assertEquals("Fa",unaNota.getTipo()) ;
		assertEquals("Redonda", unaNota.getFigura());
	}
	
	
	
	public void testNotaYFiguraInValida(){}
	
	
	
	public void testConstruirCancion(){
		unaCancion.addNota(new Do( new Blanca()));
		unaCancion.addNota(new Re( new Blanca()));
		unaCancion.addNota(new Fa( new Blanca()));
		unaCancion.addNota(new Do( new Blanca()));
		Nota unaNota = unaCancion.getNota(1,1);
		assertEquals("Do",unaNota.getTipo()) ;
		unaNota = unaCancion.getNota(1,2);
		assertEquals("Re", unaNota.getTipo());
		unaNota = unaCancion.getNota(1,3);
		assertEquals("Fa", unaNota.getTipo());
		assertEquals(1.0, unaCancion.cantidadCompases());
		//falta agregar notas
	}

 public void testAsignarAlMapeo(){
	 Cancion otraCancion= new Cancion ("cancion2",2,new Blanca(),3);
	 otraCancion.asignarAlMapeo("Do", "tecla1");
	 otraCancion.addNota(new Do( new Blanca()));
	 Nota unaNota = otraCancion.getNota(1,1);
	 Tecla unaTecla = otraCancion.teclaDeNota(unaNota.getTipo());
	 assertEquals("tecla1",unaTecla.getTipo());
 }



}
