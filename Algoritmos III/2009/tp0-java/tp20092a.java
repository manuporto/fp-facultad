public class tp20092a {

	public static void main(String[] args) {
		String nombreItem = "detergente";
		int cantidad = 1;
		double precioUnitario = 1.0;
		
		Factura factura = new Factura();
		ItemFactura item1 = new ItemFactura(nombreItem, cantidad, precioUnitario);
		factura.addItem(item1);
		
		if(factura.getMontoTotal() == 1.0)
			imprimirPruebaOk(1);
		else
			imprimirPruebaError(1);

		cantidad = 2;
		precioUnitario = 2.0;
		nombreItem = "lavandina";
		ItemFactura item2 = new ItemFactura(nombreItem, cantidad, precioUnitario);
		factura.addItem(item2);

		if(factura.getMontoTotal() == 5.0)
			imprimirPruebaOk(2);
		else
			imprimirPruebaError(2);

		if(factura.getCantidadItems() == 2)
			imprimirPruebaOk(3);
		else
			imprimirPruebaError(3);

		if(factura.getCantidadProductos() == 3)
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
