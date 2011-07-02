
public class Principal {

	public static void main (String[] args){
		Valores v = new Valores();
		v.imprimir();
		
		EulerExplicito e = new EulerExplicito();
		e.resolver();
		
		RungeKutta2 rk2 = new RungeKutta2();
		rk2.resolver();
		
	}
	
}
