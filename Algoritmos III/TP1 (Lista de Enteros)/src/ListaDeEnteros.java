
import java.util.ArrayList;
import java.util.Collections;

public class ListaDeEnteros {

	// variables
	private ArrayList listaDeEnteros;

	public ListaDeEnteros() {
		listaDeEnteros = new ArrayList();
	}
	
	public void agregar (Integer numero)
	{
	 // Si el objeto Integer ingresado es nulo, devuelve una excepción, sino, lo agrega a la lista.
		if (numero == null) throw new NullPointerException();
		else listaDeEnteros.add(numero);
	}
	
	public Integer remover (int posicion)
	{
		return ((Integer)listaDeEnteros.remove(posicion));
	}
	
	public int obtenerCantidadDeElementos()
	{
		return listaDeEnteros.size();
	}
	
	public void vaciar()
	{
		listaDeEnteros.clear();
	}
	
	public void ordenar ()
	{
		Collections.sort(listaDeEnteros);
	}
}
