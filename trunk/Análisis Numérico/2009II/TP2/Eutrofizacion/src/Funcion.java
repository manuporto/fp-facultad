import java.text.DecimalFormat;



public class Funcion extends Valores{

	private Double V,Qe,Qs,Ld,Pe,H;
	private Integer meses;
	private DecimalFormat formatted;
	
	public Double f(Double u,Integer t){
		Double devuelve=0.00;
		Double Raiz = 0.00;

		calculosAuxiliares(u,t);

		if (D.compareTo(0.00)!= 0) Raiz = Math.sqrt(Pc-u);
		
//		if (t==8) Imprimir(u,Raiz);

		devuelve = 1/V * (Qe*Pe-Qs*u) - (k/H) * u + (A*Ld)/V + Om*D*Raiz;

//		formatted = new DecimalFormat("00");
//		System.out.print("mes "+formatted.format(t)+"): ");
//		formatted = new DecimalFormat("0.000");
//		System.out.println(formatted.format(devuelve*meses));
//
//		if (t==12){
//			System.out.println();
//			System.out.println ("-----------------------------------");
//			System.out.println ("Happy new yeeeeaaar! ("+meses/12+")");
//			System.out.println();
//		}

		return devuelve;
		
	}

	public void calculosAuxiliares(Double P, Integer t){
		// [t] = mes

		Qe = Qm + DeltaQ * Math.cos(w*t);
		Qs = Qm + DeltaQ * Math.cos(w*(t-3));
		
		V = V0 + (Qe - Qs)*h;

		if (P.compareTo(Pc)>=0) D = 0.00;
		Ld = 0.00;
		if (t.compareTo(9)==0) Ld = Ld1;
		if (t.compareTo(3)==0) Ld = Ld2;

		if ((t.compareTo(3)>0) && (t.compareTo(9)<=0)) Pe = Pe1;
		else Pe = Pe2;
		
		H = V/Om;
		
	}
	
	public void Imprimir(Double u, Double Raiz){

		formatted = new DecimalFormat("0.000");
		System.out.println("1/V: "+formatted.format(1/V));
		formatted = new DecimalFormat("0.000");
		System.out.println("Qe: "+formatted.format(Qe));
		formatted = new DecimalFormat("0.000");
		System.out.println("Qs: "+formatted.format(Qs));
		formatted = new DecimalFormat("0.000");
		System.out.println("Pe: "+formatted.format(Pe));
		formatted = new DecimalFormat("0.000");
		System.out.println("u: "+formatted.format(u));
		formatted = new DecimalFormat("0.000");
		System.out.println("Qe*Pe: "+formatted.format((Qe*Pe)));
		formatted = new DecimalFormat("0.000");
		System.out.println("Qs*u: "+formatted.format((Qs*u)));
		formatted = new DecimalFormat("0.000");
		System.out.println("(k/H)*u: "+formatted.format((k/H)*u));
		formatted = new DecimalFormat("0.000");
		System.out.println("(A*Ld)/V: "+formatted.format((A*Ld)/V));
		formatted = new DecimalFormat("0.000");
		System.out.println("Om*D*Raiz: "+formatted.format(Om*D*Raiz));

	}

	public void SetMes(Integer meses){
		this.meses = meses;
	}
}
