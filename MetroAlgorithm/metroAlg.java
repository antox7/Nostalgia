import java.util.Random;

/*
 * Metropolis Algorithm: It is used to calculate weighted magnetization
 * and pair correlation per spin.
 * 
 * by Anvar Ashurov
 */

class metro {

	public static double[] metroAlg(int in_n, double in_B, double in_C, double in_T, int in_Nf) {
		
		//this array will store the values of <m> and <c_p> that will be returned by this function
		double array_result[] = new double[2];
		
		//number of times Metropolis Algorithm repeats per call. 
		int repeat = 0;
						
		int n = in_n; //number of spins
		int N_f = in_Nf;
		double B = in_B; //constant
		double C = in_C;  //constant
		double T = in_T; //Temperature
		
		//our current configuration made up of spins.
		//n+1 compensates for calculations that demand i and i+1 where i+1 equals to index 0.
		//to mimic circularly linked list. 
		int[] curr_config = new int[n+1];
		
		//populating first configuration using the following rule: If C>=0, all spins point up, 1. 
		if(C >= 0) {
			for(int i = 0; i < n; i++) {
				curr_config[i] = 1;
				//this is the "mimicking" part. 
				curr_config[n] = curr_config[0];
			}
		}
		//otherwise, alternate the signs of the spins, s_i = (-1)^i
		else {
			for(int i = 0; i < n; i++) {
				curr_config[i] = (int) Math.pow((-1), i);
				curr_config[n] = curr_config[0];
			}
		}
		//this 
		int[] init_config = new int[n+1]; 
		
		for(int j = 0; j < n; j++) {
			init_config[j] = curr_config[j];
			init_config[n] = curr_config[0];
		}	
		
		while(repeat < n*N_f) {
			
			double E1 = 0.0;
			
			//calculate the energy after the flip of a random index. 
			for(int i = 0; i < n; i++) {
				E1 = E1 + (-B*curr_config[i]-C*curr_config[i]*curr_config[i+1]);  
			}
			//generate random number.
			Random rand = new Random();
			//index is a member of [0, n)
			int index = rand.nextInt(n);
			//r is to be compared to p. 
			double r = rand.nextDouble();
			
			if(curr_config[index] == -1) {
				curr_config[index] = 1;
				if(index == 0) {
					curr_config[n] = 1;
				}
			}
			else{
				curr_config[index] = -1;
				if(index == 0) {
					curr_config[n] = -1;
				}
			}
			
			double E2 = 0.0;
			
			for(int j = 1; j < n; j++) {
				E2 = E2 + (-B*curr_config[j]-C*curr_config[j]*curr_config[j+1]);  
			}
			
			/*
			//index specific component of E to calculate the Delta E. 
			double component_E= 0.0;
			if(index == 0) {
				component_E = -C*curr_config[n-1]*curr_config[index]-B*curr_config[index]-C*curr_config[index]*curr_config[index+1];
			}
			else {
				component_E = -C*curr_config[index-1]*curr_config[index]-B*curr_config[index]-C*curr_config[index]*curr_config[index+1];
			}
			//delta Energy: difference between energy level of configuration before and after the flip.
			System.out.println(index);
			
			double deltaE2 = component_E;
			*/
			double deltaE = E2-E1;
			
			//System.out.println("True: " + deltaE);
			//probability p
			double pr = Math.exp(-deltaE/T);
			
			if(deltaE < 0.0) {
				//do nothing since current configuration is the latest configuration after the flip.
			}
			//otherwise, follow the instructions as provided in page 5. 
			else {
				if(r < pr) {
					//do nothing since current configuration is the latest configuration after the flip.
				}
				//otherwise, reject current configuration and go back to previous configuration.
				else {
					if(curr_config[index] == 1) {
						curr_config[index] = -1;
						if(index == 0) curr_config[n] = -1;
					}
					else {
						curr_config[index] = 1;
						if(index == 0) curr_config[n] = 1;
					}
				}
			}
			//loop does at least n flips. 
			repeat++;
		}//while
		
		//calculate the thermodynamic averages <m> and  <c_p> based on the latest configuration.
		double m = 0.0;
		double c_p = 0.0;
		
		for (int q = 0; q < n; q++) {
			m = m + (curr_config[q])/(double)n;
		}		
		for (int s = 0; s < n; s++) {
			c_p = c_p + (curr_config[s]*curr_config[s+1])/(double)n;
		}
		array_result[0] = m;
		array_result[1] = c_p;

		return array_result;
	}
}

