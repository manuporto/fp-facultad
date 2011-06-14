public class TP {

	public static void main(String[] args) {

		// Metodo Eulerij es el método Euler para el caso i, usando hj
		double t = 0;
		double x,y,h;
		
		h = 1;    x= 0.5; y=0; Metodo euler11 = new Euler(h,t,x,y); Metodo RK211 = new RungeKuttaOrden2 (h,t,x,y);  Metodo RK411 = new RungeKuttaOrden4 (h,t,x,y); Metodo nystrom11 = new Nystrom(h,t,x,y);
		h = 0.1;  x= 0.5; y=0; Metodo euler12 = new Euler(h,t,x,y); Metodo RK212 = new RungeKuttaOrden2 (h,t,x,y);  Metodo RK412 = new RungeKuttaOrden4 (h,t,x,y); Metodo nystrom12 = new Nystrom(h,t,x,y); 
		h = 0.01; x= 0.5; y=0; Metodo euler13 = new Euler(h,t,x,y); Metodo RK213 = new RungeKuttaOrden2 (h,t,x,y);  Metodo RK413 = new RungeKuttaOrden4 (h,t,x,y); Metodo nystrom13 = new Nystrom(h,t,x,y);
		h = 1;    x= 1.0; y=0; Metodo euler21 = new Euler(h,t,x,y); Metodo RK221 = new RungeKuttaOrden2 (h,t,x,y);  Metodo RK421 = new RungeKuttaOrden4 (h,t,x,y); Metodo nystrom21 = new Nystrom(h,t,x,y);
		h = 0.1;  x= 1.0; y=0; Metodo euler22 = new Euler(h,t,x,y); Metodo RK222 = new RungeKuttaOrden2 (h,t,x,y);  Metodo RK422 = new RungeKuttaOrden4 (h,t,x,y); Metodo nystrom22 = new Nystrom(h,t,x,y);
		h = 0.01; x= 1.0; y=0; Metodo euler23 = new Euler(h,t,x,y); Metodo RK223 = new RungeKuttaOrden2 (h,t,x,y);  Metodo RK423 = new RungeKuttaOrden4 (h,t,x,y); Metodo nystrom23 = new Nystrom(h,t,x,y);
		h = 1;    x= 1.5; y=0; Metodo euler31 = new Euler(h,t,x,y); Metodo RK231 = new RungeKuttaOrden2 (h,t,x,y);  Metodo RK431 = new RungeKuttaOrden4 (h,t,x,y); Metodo nystrom31 = new Nystrom(h,t,x,y);
		h = 0.1;  x= 1.5; y=0; Metodo euler32 = new Euler(h,t,x,y); Metodo RK232 = new RungeKuttaOrden2 (h,t,x,y);  Metodo RK432 = new RungeKuttaOrden4 (h,t,x,y); Metodo nystrom32 = new Nystrom(h,t,x,y);
		h = 0.01; x= 1.5; y=0; Metodo euler33 = new Euler(h,t,x,y); Metodo RK233 = new RungeKuttaOrden2 (h,t,x,y);  Metodo RK433 = new RungeKuttaOrden4 (h,t,x,y); Metodo nystrom33 = new Nystrom(h,t,x,y);

		System.out.println ("Euler-11: "+euler11.resolver()); System.out.println ("RK2-11: "+RK211.resolver()); System.out.println ("RK4-11: "+RK411.resolver()); System.out.println ("Nystrom-11: "+nystrom11.resolver()+"\n");
		System.out.println ("Euler-12: "+euler12.resolver()); System.out.println ("RK2-12: "+RK212.resolver()); System.out.println ("RK4-12: "+RK412.resolver()); System.out.println ("Nystrom-12: "+nystrom12.resolver()+"\n");
		System.out.println ("Euler-13: "+euler13.resolver()); System.out.println ("RK2-13: "+RK213.resolver()); System.out.println ("RK4-13: "+RK413.resolver()); System.out.println ("Nystrom-13: "+nystrom13.resolver()+"\n");
		System.out.println();
		System.out.println ("Euler-21: "+euler21.resolver()); System.out.println ("RK2-21: "+RK221.resolver()); System.out.println ("RK4-21: "+RK421.resolver()); System.out.println ("Nystrom-21: "+nystrom21.resolver()+"\n");
		System.out.println ("Euler-22: "+euler22.resolver()); System.out.println ("RK2-22: "+RK222.resolver()); System.out.println ("RK4-22: "+RK422.resolver()); System.out.println ("Nystrom-22: "+nystrom22.resolver()+"\n");
		System.out.println ("Euler-23: "+euler23.resolver()); System.out.println ("RK2-23: "+RK223.resolver()); System.out.println ("RK4-23: "+RK423.resolver()); System.out.println ("Nystrom-23: "+nystrom23.resolver()+"\n");
		System.out.println();
		System.out.println ("Euler-31: "+euler31.resolver()); System.out.println ("RK2-31: "+RK231.resolver()); System.out.println ("RK4-31: "+RK431.resolver()); System.out.println ("Nystrom-31: "+nystrom31.resolver()+"\n");
		System.out.println ("Euler-32: "+euler32.resolver()); System.out.println ("RK2-32: "+RK232.resolver()); System.out.println ("RK4-32: "+RK432.resolver()); System.out.println ("Nystrom-32: "+nystrom32.resolver()+"\n");
		System.out.println ("Euler-33: "+euler33.resolver()); System.out.println ("RK2-33: "+RK233.resolver()); System.out.println ("RK4-33: "+RK433.resolver()); System.out.println ("Nystrom-33: "+nystrom33.resolver()+"\n");
		System.out.println();
		
		System.out.println("Diferencias de energia");
		System.out.println ("Euler-11: "+euler11.diferenciaDeEnergias()); System.out.println ("RK2-11: "+RK211.diferenciaDeEnergias()); System.out.println ("RK4-11: "+RK411.diferenciaDeEnergias()); System.out.println ("Nystrom-11: "+nystrom11.diferenciaDeEnergias()+"\n");
		System.out.println ("Euler-12: "+euler12.diferenciaDeEnergias()); System.out.println ("RK2-12: "+RK212.diferenciaDeEnergias()); System.out.println ("RK4-12: "+RK412.diferenciaDeEnergias()); System.out.println ("Nystrom-12: "+nystrom12.diferenciaDeEnergias()+"\n");
		System.out.println ("Euler-13: "+euler13.diferenciaDeEnergias()); System.out.println ("RK2-13: "+RK213.diferenciaDeEnergias()); System.out.println ("RK4-13: "+RK413.diferenciaDeEnergias()); System.out.println ("Nystrom-13: "+nystrom13.diferenciaDeEnergias()+"\n");
		System.out.println();
		System.out.println ("Euler-21: "+euler21.diferenciaDeEnergias()); System.out.println ("RK2-21: "+RK221.diferenciaDeEnergias()); System.out.println ("RK4-21: "+RK421.diferenciaDeEnergias()); System.out.println ("Nystrom-21: "+nystrom21.diferenciaDeEnergias()+"\n");
		System.out.println ("Euler-22: "+euler22.diferenciaDeEnergias()); System.out.println ("RK2-22: "+RK222.diferenciaDeEnergias()); System.out.println ("RK4-22: "+RK422.diferenciaDeEnergias()); System.out.println ("Nystrom-22: "+nystrom22.diferenciaDeEnergias()+"\n");
		System.out.println ("Euler-23: "+euler23.diferenciaDeEnergias()); System.out.println ("RK2-23: "+RK223.diferenciaDeEnergias()); System.out.println ("RK4-23: "+RK423.diferenciaDeEnergias()); System.out.println ("Nystrom-23: "+nystrom23.diferenciaDeEnergias()+"\n");
		System.out.println();
		System.out.println ("Euler-31: "+euler31.diferenciaDeEnergias()); System.out.println ("RK2-31: "+RK231.diferenciaDeEnergias()); System.out.println ("RK4-31: "+RK431.diferenciaDeEnergias()); System.out.println ("Nystrom-31: "+nystrom31.diferenciaDeEnergias()+"\n");
		System.out.println ("Euler-32: "+euler32.diferenciaDeEnergias()); System.out.println ("RK2-32: "+RK232.diferenciaDeEnergias()); System.out.println ("RK4-32: "+RK432.diferenciaDeEnergias()); System.out.println ("Nystrom-32: "+nystrom32.diferenciaDeEnergias()+"\n");
		System.out.println ("Euler-33: "+euler33.diferenciaDeEnergias()); System.out.println ("RK2-33: "+RK233.diferenciaDeEnergias()); System.out.println ("RK4-33: "+RK433.diferenciaDeEnergias()); System.out.println ("Nystrom-33: "+nystrom33.diferenciaDeEnergias()+"\n");
		System.out.println();

	}

}
