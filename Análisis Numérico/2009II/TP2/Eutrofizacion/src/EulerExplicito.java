import java.text.DecimalFormat;
import java.util.*;

public class EulerExplicito extends Valores{

	private DecimalFormat formatted;

	public void resolver (){
		Funcion f = new Funcion();
		// Un+1 = Un + k*f(Un,Tn);
		Integer meses = 1;
		Integer t;
		Double u = 0.01;
		List<Double> U;
		List<Integer> T;

		U = new ArrayList<Double>();
		T = new ArrayList<Integer>();

		U.add(P0);
		T.add(T0);
		
		t = T.get(0);

		f.SetMes(meses);
		u = U.get(0) + h*f.f(U.get(0),t);

		formatted = new DecimalFormat("00");
		System.out.print("mes "+formatted.format(t)+"): ");
		formatted = new DecimalFormat("0.000");
		System.out.println(formatted.format(u));

//		if (t==12){
//			System.out.println();
//			System.out.println ("-----------------------------------");
//			System.out.println ("Happy new yeeeeaaar! ("+meses/12+")");
//			System.out.println();
//		}
		
		
		U.add(u);
		
		for (int i=1; i<241;i++){
		
//			if (i==12) T.add(1);
//			else T.add(i+1);
			if ((i%12) == 0) T.add(12);
			else T.add(i%12);
			meses++;
			
			t = T.get(i);
			f.SetMes(meses);
			u = U.get(i) + h*f.f(U.get(i),t);
			formatted = new DecimalFormat("00");
			System.out.print("mes "+formatted.format(t)+"): ");
			formatted = new DecimalFormat("0.000");
			System.out.println(formatted.format(u));

			U.add(u);
		}

}

}
