
public class RungeKuttaOrden4 extends Metodo {

	public RungeKuttaOrden4 (double h, double t, double x, double v){
		this.h = h;
		this.t0 = t;
		this.x0 = x;
		this.v0 = v;
	}
	
	public double resolver(){
		
		double xn=0, vn=0, tn=0, xn_1=0, vn_1=0;
		double k11, k12, k13, k14, k21, k22, k23, k24;

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
			
			k11 = h*f1(tn,xn,vn);
			k21 = h*f2(tn,xn,vn);
			
			k12 = h*f1(tn+(0.5)*h,xn+(0.5)*k11,vn+(0.5)*k21);
			k22 = h*f2(tn+(0.5)*h,xn+(0.5)*k11,vn+(0.5)*k21);
			
			k13 = h*f1(tn+(0.5)*h,xn+(0.5)*k12,vn+(0.5)*k22);
			k23 = h*f2(tn+(0.5)*h,xn+(0.5)*k12,vn+(0.5)*k22);
			
			k14 = h*f1(tn+h,xn+k13,vn+k23);
			k24 = h*f2(tn+h,xn+k13,vn+k23);

			xn_1 = xn+(0.16667)*(k11+2*k12+2*k13+k14);
			vn_1 = vn+(0.16667)*(k21+2*k22+2*k23+k24);
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
