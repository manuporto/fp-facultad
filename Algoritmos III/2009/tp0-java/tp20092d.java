
public class tp20092d {

	public static void main(String[] args) {

		Bolsa bolsa = new Bolsa();
		
		String nombre = "papa";
		double peso = 2.4;
		Alimento alimento1 = new Alimento(nombre, peso);
		bolsa.addAlimento(alimento1);
		
		nombre = "batata";
		peso = 1.6;
		Alimento alimento2 = new Alimento(nombre, peso);
		bolsa.addAlimento(alimento2);
		
		nombre = "banana";
		peso = 3.0;
		Alimento alimento3 = new Alimento(nombre, peso);
		bolsa.addAlimento(alimento3);

		nombre = "papa";
		peso = 3.0;
		Alimento alimento4 = new Alimento(nombre, peso);
		bolsa.addAlimento(alimento4);
		
		if(bolsa.getCantidadKilosDe("papa") == 5.4)
			imprimirPruebaOk(1);
		else
			imprimirPruebaError(1);
		
		if(bolsa.getCantidadKilosTotales() == 10)
			imprimirPruebaOk(2);
		else
			imprimirPruebaError(2);

		if(bolsa.getCantidadKilosDe("tomate") == 0)
			imprimirPruebaOk(3);
		else
			imprimirPruebaError(3);
		
		bolsa.vaciar();

		if(bolsa.getCantidadKilosTotales() == 0)
			imprimirPruebaOk(4);
		else
			imprimirPruebaError(4);

	}
	
	public static void imprimirPruebaOk(int numeroPrueba){
		String mensaje = "Prueba " + numeroPrueba + ": Ok";
		System.out.println(mensaje);
	}

	public static void imprimirPruebaError(int numeroPrueba){
		String mensaje = "Ok " + numeroPrueba + ": Error";
		System.out.println(mensaje);
	}
}
