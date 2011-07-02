import junit.framework.TestCase;

public class ListaDeEnterosTests extends TestCase {

	private ListaDeEnteros lista;
	private Integer numero;

	public void setUp()
	{
		lista = new ListaDeEnteros();
	}

	// Agrega un elemento y prueba si la cantidad de elementos es 1.
	public void testAgregarUnEnteroYCompararCantidad()
	{
		numero = new Integer("55");
		lista.agregar(numero);
		assertEquals(lista.obtenerCantidadDeElementos(),1);
	}

	// Agrega un elemento y luego lo remueve y lo compara.
	public void testAgregarUnEntero()
	{
		numero = new Integer("55");
		lista.agregar(numero);
		Integer numeroRemovido = lista.remover(0);
		assertEquals(numeroRemovido,numero);
		assertTrue (numeroRemovido == numero);
	}

	// Agrega dos elementos y luego prueba si la cantidad de elementos es 2.
	public void testAgregarDosEnterosYCompararCantidad()
	{
		numero = new Integer("42");
		lista.agregar(numero);
		numero = new Integer("55");
		lista.agregar(numero);
		assertEquals(lista.obtenerCantidadDeElementos(),2);
	}

	// Agrega dos elementos y luego remueve uno y lo compara.
	public void testAgregarDosEnterosYComparar()
	{
		numero = new Integer("42");
		lista.agregar(numero);
		numero = new Integer("55");
		lista.agregar(numero);
		Integer numeroRemovido = lista.remover(1);
		assertEquals(numeroRemovido,numero);
		assertTrue (numeroRemovido == numero);
	}

	// Trata de agregar un elemento nulo.
	public void testAgregarNull()
	{
		numero = null;
		try
		{
			lista.agregar(numero);
			fail ("Agregó un elemento nulo");		
		}
		catch (NullPointerException error)
		{
			assertTrue(true);
		}
	}
	
	public void testAgregarTrasRemover()
	{
		numero = new Integer ("55");
		lista.agregar(numero);
		numero = new Integer ("42");
		lista.agregar(numero);
		numero = lista.remover(1);
		numero = lista.remover(0);
		numero = new Integer ("123");
		lista.agregar (numero);
		Integer numeroRemovido = lista.remover(0);
		assertEquals(numeroRemovido,numero);
		assertTrue (numeroRemovido == numero);
	}
	
	// Trata de remover un elemento de una lista vacía y comprueba si da una excepción.
	public void testRemoverDeListaVacia()
	{
		try
		{
			numero = lista.remover(0);
			fail ("Removió de una lista vacía");
		}
		catch (IndexOutOfBoundsException e)
		{
			assertTrue(true);
		}
	}

	// Ingresa tres elementos y compara si son los ingresados.
	public void testRemover()
	{
		Integer numero0 = new Integer("42");
		lista.agregar(numero0);
		Integer numero1 = new Integer("55");
		lista.agregar(numero1);
		Integer numero2 = new Integer("8");
		lista.agregar(numero2);

		Integer numeroRemovido = lista.remover(2);
		assertEquals(numeroRemovido,numero2);
		assertTrue (numeroRemovido == numero2);

		numeroRemovido = lista.remover(1);
		assertEquals(numeroRemovido,numero1);
		assertTrue (numeroRemovido == numero1);

		numeroRemovido = lista.remover(0);
		assertEquals(numeroRemovido,numero0);
		assertTrue (numeroRemovido == numero0);
}

	// Ingresa dos elementos, remueve el primero y compara si es el primer ingresado.
	public void testRemoverDespuesDeVaciar()
	{
		numero = new Integer("42");
		lista.agregar(numero);
		numero = new Integer("55");
		lista.agregar(numero);
		numero = new Integer("8");
		lista.agregar(numero);
		lista.vaciar();
		try
		{
			numero = lista.remover(0);
			fail ("Removió de una lista vacía");
		}
		catch (IndexOutOfBoundsException e)
		{
			assertTrue(true);
		}
		
	}

	// Prueba la cantidad de elementos tras crear la lista.
	public void testCantidadDeElementosInicial()
	{
		assertEquals(lista.obtenerCantidadDeElementos(),0);
	}

	// Prueba la cantidad de elementos tras agregar 3.
	public void testCantidadDeElementos()
	{
		numero = new Integer("8");
		lista.agregar(numero);
		numero = new Integer("55");
		lista.agregar(numero);
		numero = new Integer("42");
		lista.agregar(numero);
		assertEquals(lista.obtenerCantidadDeElementos(),3);
	}

	// Prueba la cantidad de elementos tras crear la lista.
	public void testCantidadDeElementosListaRecienCreada()
	{
		assertEquals(lista.obtenerCantidadDeElementos(),0);
	}

	// Prueba la cantidad de elementos tras agregar varios y luego vaciarla removiendo los elementos.
	public void testCantidadDeElementosTrasVaciarRemoviendo()
	{
		numero = new Integer("8");
		lista.agregar(numero);
		numero = new Integer("55");
		lista.agregar(numero);
		numero = new Integer("42");
		lista.agregar(numero);
		lista.remover(0);
		lista.remover(0);
		lista.remover(0);
		assertEquals(lista.obtenerCantidadDeElementos(),0);
	}

	// Prueba la cantidad de elementos tras agregar varios y luego vaciarla con la función Vaciar.
	public void testCantidadDeElementosTrasVaciar()
	{
		numero = new Integer("8");
		lista.agregar(numero);
		numero = new Integer("55");
		lista.agregar(numero);
		numero = new Integer("42");
		lista.agregar(numero);
		lista.vaciar();
		assertEquals(lista.obtenerCantidadDeElementos(),0);
	}

	// Prueba la cantidad de elementos tras agregar dos y remover uno.
	public void testCantidadDeElementosTrasAgregarYQuitar()
	{
		numero = new Integer("8");
		lista.agregar(numero);
		numero = new Integer("55");
		lista.agregar(numero);
		numero = lista.remover(1);
		assertEquals(lista.obtenerCantidadDeElementos(),1);
	}

	// Prueba la cantidad de elementos tras agregar dos, remover uno y volver a agregar.
	public void testCantidadDeElementosTrasAgregarQuitarYAgregar()
	{
		numero = new Integer("8");
		lista.agregar(numero);
		numero = new Integer("55");
		lista.agregar(numero);
		numero = lista.remover(1);
		numero = new Integer("42");
		lista.agregar(numero);
		assertEquals(lista.obtenerCantidadDeElementos(),2);
	}

	// Prueba que vaciar una lista vacía no tire excepciones.
	public void testVaciarYaVaciaPorExcepcion()
	{
		try {
			lista.vaciar();
			assertEquals(lista.obtenerCantidadDeElementos(),0);
		}
		catch (Exception error)
		{
			fail ("Hubo una excepcion");
		}
	}

	// Prueba que ordenar una lista vacía no tire excepciones.
	public void testOrdenarListaVacia()
	{
		try {
			lista.ordenar();
			assertTrue(true);
		}
		catch (Exception error)
		{
			fail ("Hubo una excepcion");
		}
	}

	// Prueba agregar dos elementos desordenados y compara si lo ordena.
	public void testOrdenarUnElemento()
	{
		numero = new Integer("55");
		lista.agregar(numero);
		lista.ordenar();
		Integer numeroRemovido = lista.remover(0);
		assertEquals(numeroRemovido,numero);
		assertTrue (numeroRemovido == numero);
	}

	// Prueba agregar dos elementos desordenados y compara si lo ordena.
	public void testOrdenarDosElementosDesordenados()
	{
		numero = new Integer("55");
		lista.agregar(numero);
		numero = new Integer("42");
		lista.agregar(numero);
		lista.ordenar();
		Integer menorNumero = lista.remover(0);
		Integer mayorNumero = lista.remover(0);
		assertEquals(menorNumero.compareTo(mayorNumero),-1);
	}

	// Prueba agregar dos elementos ya ordenados y compara si lo ordena.
	public void testOrdenarDosElementosOrdenados()
	{
		numero = new Integer("42");
		lista.agregar(numero);
		numero = new Integer("55");
		lista.agregar(numero);
		lista.ordenar();
		Integer menorNumero = lista.remover(0);
		Integer mayorNumero = lista.remover(0);
		assertEquals(menorNumero.compareTo(mayorNumero),-1);
	}

	// Prueba agregar tres elementos desordenados y compara si lo ordena.
	public void testOrdenarTresElementosDesordenados()
	{
		numero = new Integer("8");
		lista.agregar(numero);
		numero = new Integer("55");
		lista.agregar(numero);
		numero = new Integer("42");
		lista.agregar(numero);
		lista.ordenar();
		Integer menorNumero = lista.remover(0);
		Integer segundoNumero = lista.remover(0);
		Integer mayorNumero = lista.remover(0);
		assertEquals(menorNumero.compareTo(segundoNumero),-1);
		assertEquals(mayorNumero.compareTo(segundoNumero),1);
	}

	// Prueba agregar tres elementos ya ordenados y compara si lo ordena.
	public void testOrdenarTresElementosOrdenados()
	{
		numero = new Integer("8");
		lista.agregar(numero);
		numero = new Integer("42");
		lista.agregar(numero);
		numero = new Integer("55");
		lista.agregar(numero);
		lista.ordenar();
		Integer menorNumero = lista.remover(0);
		Integer segundoNumero = lista.remover(0);
		Integer mayorNumero = lista.remover(0);
		assertEquals(menorNumero.compareTo(segundoNumero),-1);
		assertEquals(mayorNumero.compareTo(segundoNumero),1);
	}

}
