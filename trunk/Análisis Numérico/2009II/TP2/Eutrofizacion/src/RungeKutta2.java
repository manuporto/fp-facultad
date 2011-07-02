import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;


public class RungeKutta2 extends Valores {

	private DecimalFormat formatted;
	
	public void resolver(){
		
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println("RUNGEEEEEEEEEEEE KUTTAAAAAAAAAA 2");
		System.out.println();
	
		Funcion f = new Funcion();
		// Un+1 = Un + k*f(Un,Tn);
		Integer meses = 1;
		Integer t;
		Double u = 0.01;
		Double q1,q2;
		List<Double> U;
		List<Integer> T;

		U = new ArrayList<Double>();
		T = new ArrayList<Integer>();

		U.add(P0);
		T.add(T0);
		T.add(T0+1);

		f.SetMes(meses);

		t = T.get(0);

		q1 = U.get(0) + h*f.f(U.get(0),t);
		q2 = U.get(0) + h*f.f(U.get(0)+q1,T.get(1));

		System.out.print("q1: ");
		formatted = new DecimalFormat("0.000");
		System.out.println(formatted.format(q1));
		System.out.print("q2: ");
		formatted = new DecimalFormat("0.000");
		System.out.println(formatted.format(q2));
		
		
		u = U.get(0)+(1/2)*(q1+q2);
		
		formatted = new DecimalFormat("00");
		System.out.print("mes "+formatted.format(t)+"): ");
		formatted = new DecimalFormat("0.000");
		System.out.println(formatted.format(u));

		U.add(u);
		
		for (int i=1; i<241;i++){
		
			if ((i%12) == 0) T.add(12);
			else T.add(i%12);
			meses++;

			f.SetMes(meses);

			t = T.get(i);

			q1 = U.get(i) + h*f.f(U.get(i),t);
			q2 = U.get(i) + h*f.f((U.get(i)+q1),T.get(i+1));

			System.out.print("U.get(i): ");
			formatted = new DecimalFormat("0.000");
			System.out.println(formatted.format(U.get(i)));
			System.out.print("q1: ");
			formatted = new DecimalFormat("0.000");
			System.out.println(formatted.format(q1));
			System.out.print("q2: ");
			formatted = new DecimalFormat("0.000");
			System.out.println(formatted.format(q2));
			
			u = U.get(i)+(0.5)*(q1+q2);
			
			
			formatted = new DecimalFormat("00");
			System.out.print("mes "+formatted.format(t)+"): ");
			formatted = new DecimalFormat("0.000");
			System.out.println(formatted.format(u));

			U.add(u);
		}


	
	}
}
