import java.util.Random;
import java.lang.Math;

public class main {
	
	//N_m is in thread class.
	static int N_f = 15;  
		
	static int n = 100;
	static double B = 1.1;
	static double C = -0.1;
	static double T= 0.01;
	static int N_t = 1000;

	public static void main(String[] args) {
		
		//double tempT = 0.0;
		//double tempM = 0.0;
		//double tempB = 0.0;
		//double tempC = 0.0;
		
		//for(B = 0.1; B <= 2.0; B=B+0.5) {
		//	for(C = -0.1; C >= -2.0; C=C-0.5) {	
		//		System.out.println(" B = " + B + "  C = " + C + "\n");
				
				
					for(T = 0.1; T < 2.0; T=T+0.2) {
								
						double global_avrg_m = 0.0;
						double global_avrg_cp = 0.0;
			
						MyThread myt[] = new MyThread[N_t];
			
						for(int i = 0; i < N_t; i++) {
							myt[i] = new MyThread(n, B, C, T, N_t, N_f);
							myt[i].start();
						}
			
						for (int i = 0; i < N_t; i++) {
							try {
								if(myt[i].isAlive()) {
									myt[i].join();
								}
							}
							catch (Exception e) {}
						}
	
						for(int i = 0; i < N_t; i++) {
							global_avrg_m = global_avrg_m + myt[i].avrg_m/N_t;
							global_avrg_cp = global_avrg_cp + myt[i].avrg_cp/N_t;
						}
	
						double c_p = 0.0;
						double r_c = 0.0;
						double sig = 0.0;
			
						c_p = (Math.exp(C/T)-Math.exp(-C/T))/(Math.exp(C/T)+Math.exp(-C/T));
						//System.out.println("<c_p> is " + c_p);
			
						if(c_p != 0.0) {
				
							for(int i = 0; i < N_t; i++) {
								r_c = r_c + (myt[i].avrg_cp - c_p)/(c_p); 
							}
							r_c = r_c/(double)N_t;
							//System.out.println("<r_p> is " + r_c);
							
							for(int i = 0; i < N_t; i++) {
								sig = sig + Math.pow((((myt[i].avrg_cp - c_p)/c_p)-r_c),2); 
							}
							sig = sig/(double)N_t;
							//	System.out.println("sigma is " + sig);
						}
						
	    				/*	
						if(global_avrg_m > tempM) {
							tempM = global_avrg_m;
							tempT = T;
							tempB = B;
							tempC = C;
						}
						
						*/
						// && global_avrg_m != 1 && global_avrg_cp != 1 && global_avrg_cp != -1
						/*
						if(global_avrg_m == 0) {
							// +global_avrg_cp
							System.out.println(" " + global_avrg_m +"   ");
						}
						*/
						System.out.println(T+ " " + global_avrg_m +" " + global_avrg_cp);
				 }	//T loop
				//System.out.println("-----------------------------");	
			//}//C loop
				
		//}//B loop
		//System.out.println(tempM + " " + tempT + " " + tempB + " " + tempC);
	}//main args
}//main class
