
public class Valores {

	public Double P0,V0,Om,Qm,DeltaQ,Pe1,Pe2,k,Ld1,Ld2,A,D,Pc,w,h;
	public Integer T0;

	public Valores (){
		
	/*
	[T] = meses;
	[L] = metros;
	[M] = gramos;
	*/
		
		Double XYZ,Y,Z,YZ;
		
		XYZ = 606.00;
		Y = 0.00;
		Z = 6.00;
		YZ = 06.00;

//		XYZ = 052.00;
//		Y = 5.00;
//		Z = 2.00;
//		YZ = 52.00;

		h = 1.00/30.00;

		T0 = 1;							// meses;

		P0 = XYZ/100.00;				// microgramos/litro = microgramos / dm³
		
		V0 = YZ;						// Hm³
		V0 = V0*Math.pow(10, 9);		// dm³

		Om = XYZ;						// Ha = hm²
		Om = Om*Math.pow(10, 6);		// dm²
		
		Qm = (Z+1.00/Z+2.00)*5000.00;	// m³/dia
		Qm = Qm*30;						// m³/mes
		Qm = Qm*Math.pow(10,3);			// dm³/mes
		
		DeltaQ = 0.75*Qm;				// dm³/mes
		
		Pe1 = XYZ/20.00;				// microgramos/litro
		
		Pe2 = XYZ/50.00;				// microgramos/litro

		k = Math.pow(10.00, -6.00);		// m/segundo
		k = k*2592000;					// m/mes
		k = k*10;						// dm/mes
		
		Ld1 = (Z+1.00)/2500.00;			// kg/(Ha*mes) = kg (hm²*mes)
		Ld1 = Ld1*Math.pow(10,9);		// microg/(hm²*mes)
		Ld1 = Ld1/Math.pow(10,6);		// microg/(dm²*mes)

		Ld2 = (Z+1.00)/10000.00;		// kg/(Ha*mes) = kg (hm²*mes)
		Ld2 = Ld2*Math.pow(10,9);		// microg/(hm²*mes)
		Ld2 = Ld2/Math.pow(10,6);		// microg/(dm²*mes)

		A = Math.pow(XYZ,2);			// Ha = Hm²
		A = A*Math.pow(10,6);			// dm²

		D = (Y+Z)/10000.00;				// kg^(1/2) / (Ha^(2/3)*mes) = kg^(1/2) / (Hm^(4/3)*mes)
		D = D*Math.sqrt(1000000000);	// microg^(1/2) / (Hm^(4/3)*mes)
		D = D/Math.pow(10,4);			// microg^(1/2) / (dm^(4/3)*mes)
		
		Pc = 5.00;						// microgramos/litro
		
		w = (Math.PI)/6;				// 1/mes

	}

	public void imprimir (){

		System.out.println("P0: "+P0+" Mg/l");
		System.out.println("V0: "+V0+" ");
		System.out.println("Om: "+Om+" ");
		System.out.println("Qm: "+Qm+" ");
		System.out.println("DeltaQ: "+DeltaQ+" ");
		System.out.println("Pe1: "+Pe1+" ");
		System.out.println("Pe2: "+Pe2+" ");
		System.out.println("k: "+k+" ");
		System.out.println("Ld1: "+Ld1+" ");
		System.out.println("Ld2: "+Ld2+" ");
		System.out.println("A: "+A+" ");
		System.out.println("D: "+D+" ");
		System.out.println("Pc: "+Pc+" ");
	}
}
