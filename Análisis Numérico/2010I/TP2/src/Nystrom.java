import java.util.ArrayList;


public class Nystrom extends Metodo {
	
	double xp0; // X prima
	
	public Nystrom (double h, double t, double x, double xp){
		this.t0 = t;
		this.h = h;
		this.x0 = x;
		this.xp0 = xp;
	}
	
	public double resolver(){
		
		
		ArrayList<Double> xp = new ArrayList<Double>();
		double tn=0; 
		double xn=0; 	 // x sub n
		double xpn=0;	// x prima sub n
		double xn_1 = 0; // x sub n+1
		double xnm1 = 0; // x sub n-1
		double x1;	// x sub 1

		int n=0;
		
		x.clear();
		xp.clear();
		
		x.add(redondear(x0,4));
		xp.add(redondear(xp0,4));

		double en = this.energia(x0,xp0);
		this.energia.add(redondear(en,4));

	
		x1 = x0+h*xp0+(0.5)*Math.pow(h,2)*(x0-Math.pow(x0,3));
		x.add(redondear(x1,4));
		n++;
		
		xnm1 = x0;

		while (tn<T_LIMITE){

			xn = x.get(n);
			xn_1 = 2*xn - xnm1 + Math.pow(h,2)*(xn - Math.pow(xn, 3));
	
			xpn = (xn_1 - xnm1) / (2*h);
			
			this.x.add(redondear(xn_1,4));
			xp.add(redondear(xpn,4));

			en = this.energia(xn,xpn);
			this.energia.add(redondear(en,4));

			xnm1 = xn;

			n++;
			tn = t0+n*h;
		}
		
		return (x.get(x.size()-1));

	}	
	
}
