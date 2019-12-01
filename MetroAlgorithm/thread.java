class MyThread extends Thread {
	
	static int N_m = 13;      //we need to find
	
	public int n, N_t, N_f;
	public double B, C, T;
	
	MyThread(int n, double B, double C, double T, int N_t, int N_f) {
		this.n = n;
		this.B = B;
		this.C = C;
		this.T = T;
		this.N_f = N_f;
		this.N_t = N_t;
	}

	double[] array_of_m = new double[N_m];  //contains values of m of a thread.
	double[] array_of_cp = new double[N_m]; //contains values of c of a thread.
	
	double avrg_m = 0.0;
	double avrg_cp = 0.0;
	
	double[] arr = new double[2];
	
	public void run() {
		//each thread calls the Metropolis Algorithm N_m times in a loop.
		for(int i = 0; i < N_m; i++) {
			arr = metro.metroAlg(n, B, C, T, N_f);
			array_of_m[i] = arr[0]; 	
			/*
			 * It took me ~ 6 hours to fix this "bug".
			 * I had array_of_cp[0] instead of i. 
			 * It made me reconsider my life choices for a few seconds.
			 */
			array_of_cp[i] = arr[1];
		} //end of Metropolis Algorithm calls
	
		for(int i = 0; i < N_m; i++) {
			avrg_m = avrg_m + array_of_m[i];
			avrg_cp = avrg_cp + array_of_cp[i];			
		}
		avrg_m = avrg_m/N_m;
		avrg_cp = avrg_cp/N_m;
	//end of run
	}
}
