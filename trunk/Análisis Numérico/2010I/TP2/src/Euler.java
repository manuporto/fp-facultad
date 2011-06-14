
public class Euler extends Metodo{

	public Euler (double h, double t, double x, double v){
		this.h = h;
		this.t0 = t;
		this.x0 = x;
		this.v0 = v;
	}

	public double resolver(){
		
		double xn=0, vn=0, tn=0;
		double xn_1=0, vn_1=0;
		int n=0;

		x.clear();
		v.clear();
		
		x.add(redondear(x0,4));
		v.add(redondear(v0,4));
		
		tn = t0+n*h;

		double en = this.energia(x0,v0);

		this.energia.add(redondear(en,4));
		
		while ( (tn<T_LIMITE) && (!corte) ){
			
			xn = x.get(n);
			vn = v.get(n);

			xn_1 = xn + h*f1(tn,xn,vn);
			vn_1 = vn + h*f2(tn,xn,vn);
			en = this.energia(xn_1,vn_1);
			
			if ( ((Double)xn_1).isNaN() || ((Double)vn_1).isNaN() || ((Double)en).isNaN() || ((Double)xn_1).isInfinite() || ((Double)vn_1).isInfinite() || ((Double)en).isInfinite())
			{
				corte = true;
				xn_1 = xn;
			}
			else {
				this.x.add(redondear(xn_1,4));
				this.v.add(redondear(vn_1,4));
				this.energia.add(redondear(en,4));

				n++;
				tn = t0+n*h;
			}
		
		}

		return (x.get(x.size()-1));
	}
	
}
