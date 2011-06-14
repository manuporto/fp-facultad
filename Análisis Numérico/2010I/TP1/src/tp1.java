import java.text.*;

public class tp1 {

	
	private static final double PRECISION_A = 0.00005; /* Precisión 0.5 * 10^(-4) */
	private static final double PRECISION_B = PRECISION_A;
	private static final double PRECISION_C = PRECISION_A;
	private static final int CANTIDAD_DE_DECIMALES = 4;
	private static final int NUM_MAX_ITERACIONES = 100000;

	public static void main (String[] args) {

	    int numeroDeIteracion;
	    double precision;
		double precisionAnterior = 1;
		double arcotangente = 0;
		double arcotangente1 = 0;
		double arcotangente2 = 0;
		boolean precisionEstabilizada = false;
		Arctan arctan1;
		Arctan arctan2;

	    /* PUNTO A */
		System.out.println ("Punto A\n");
		arctan1 = new Arctan(CANTIDAD_DE_DECIMALES);

	    numeroDeIteracion = 1;
	    precision=1;
	    arcotangente = 0;
	    precisionEstabilizada = false;
		
		while ( (precision > PRECISION_A) && ( numeroDeIteracion <= NUM_MAX_ITERACIONES ) && ( !precisionEstabilizada ) ){
			
			arcotangente = arctan1.calcular(numeroDeIteracion,1);
			precision = Math.abs(4*arcotangente - Math.PI);
			imprimirPrecision (precision,numeroDeIteracion);
			if (Math.abs(precisionAnterior - precision) < PRECISION_B) precisionEstabilizada = true;
			numeroDeIteracion++;
		}
		
		imprimirPiEstimado (4*arcotangente);
		imprimirResultado(precision,PRECISION_A,numeroDeIteracion-1,precisionEstabilizada);
		
		/* FIN PUNTO A */
		
		/* PUNTO B */

		System.out.println ("\n\nPunto B\n");

		arctan1 = new Arctan(CANTIDAD_DE_DECIMALES);
		arctan2 = new Arctan(CANTIDAD_DE_DECIMALES);
		
		precision = 1;
		numeroDeIteracion = 1;
		precisionAnterior = 1;
		arcotangente1 = 0;
		arcotangente2 = 0;
		precisionEstabilizada = false;

		while ( (precision > PRECISION_B) && ( numeroDeIteracion <= NUM_MAX_ITERACIONES ) && ( !precisionEstabilizada ) ){
			arcotangente1 = arctan1.calcular(numeroDeIteracion,0.5);
			arcotangente2 = arctan2.calcular(numeroDeIteracion, 0.333);
			precisionAnterior = precision;
			precision = Math.abs(4*(arcotangente1 + arcotangente2) - Math.PI);
			imprimirPrecision (precision,numeroDeIteracion);
			if (Math.abs(precisionAnterior - precision) < PRECISION_B) precisionEstabilizada = true;
			numeroDeIteracion++;

		}

		imprimirPiEstimado(4*(arcotangente1 + arcotangente2));
		imprimirResultado(precision,PRECISION_B,numeroDeIteracion-1,precisionEstabilizada);

		/* FIN PUNTO B */
		
		
		/* PUNTO C */
		System.out.println ("\n\nPunto C\n");

		arctan1 = new Arctan(CANTIDAD_DE_DECIMALES);
		arctan2 = new Arctan(CANTIDAD_DE_DECIMALES);
		
		precision = 1;
		numeroDeIteracion = 1;
		precisionAnterior = 1;
		arcotangente1 = 0;
		arcotangente2 = 0;
		precisionEstabilizada = false;

		while ( (precision > PRECISION_C) && ( numeroDeIteracion <= NUM_MAX_ITERACIONES ) && ( !precisionEstabilizada ) ){
			arcotangente1 = arctan1.calcular(numeroDeIteracion,0.2);
			arcotangente2 = arctan2.calcular(numeroDeIteracion, 0.004184);
			precisionAnterior = precision;
			precision = Math.abs(4*(4*arcotangente1 - arcotangente2) - Math.PI);
			imprimirPrecision (precision,numeroDeIteracion);
			if (Math.abs(precisionAnterior - precision) < PRECISION_C) precisionEstabilizada = true;
			numeroDeIteracion++;
		}

		imprimirPiEstimado(4*(4*arcotangente1 - arcotangente2));
		imprimirResultado(precision,PRECISION_C,numeroDeIteracion-1,precisionEstabilizada);

		/* FIN PUNTO C */
	}

	private static void imprimirPiEstimado(double valor) {
		DecimalFormat numeroFormateado; /* Objeto para darle formato a los números */
		numeroFormateado = new DecimalFormat("0.00000");
		System.out.println("El valor de PI estimado es: "+numeroFormateado.format(valor));
	}

	private static void imprimirResultado(double precision, double precisionRequerida, int numeroDeIteracion, boolean precisionEstabilizada) {
		
		if (precision < precisionRequerida) System.out.println ("Se alcanzó la precisión en la iteración "+numeroDeIteracion);
		else
			if (numeroDeIteracion == NUM_MAX_ITERACIONES) System.out.println ("Se superó el máximo de "+NUM_MAX_ITERACIONES+" iteraciones.");
			else
				if (precisionEstabilizada) System.out.println("La precisión no varió entre las iteraciones "+(numeroDeIteracion - 1)+" y "+numeroDeIteracion);	
	}

	private static void imprimirPrecision(double precision,	int numeroDeIteracion) {

		DecimalFormat numeroFormateado; /* Objeto para darle formato a los números */
		numeroFormateado = new DecimalFormat("0.00000");

		if (numeroDeIteracion == 1) System.out.println ("Precisión\tIteración");
		
		if (		( numeroDeIteracion <= 20 )
				||  ( ((numeroDeIteracion % 50) == 0) && (numeroDeIteracion <= 1000) )
				||  ( ((numeroDeIteracion % 1000) == 0) && (numeroDeIteracion > 1000) )
			)

			System.out.println(numeroFormateado.format(precision)+"\t\t"+numeroDeIteracion);
	}

}
