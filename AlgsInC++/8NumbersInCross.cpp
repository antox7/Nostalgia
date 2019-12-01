#include <iostream>
#include <cmath>
using namespace std; 

/*       ___
       _|0|1|_
      |2|3|4|5|
       `|6|7|` 
*/

int main() {

        //index    0       1        2          3               4                5            6              7
int hood[8][5] = {{-1}, {0, -1}, {0, -1}, {0, 1, 2, -1}, {0, 1, 2, 3, -1}, {1, 4, -1}, {2, 3, 4, -1}, {3, 4, 5, 6, -1}}; //IMO, we have to check each case for each index;

/* This will print the adjacent indices

for(int i = 0; i < 8; i++) {
    cout << "{ ";
    for(int j = 0; j < 5; j++) {
        cout << hood[i][j] << ", ";
    }
    cout << " }" << endl;
}

*/

int q[8] = {0};  
q[0] = 1; 
int c = 0;

nc:
	c++;
	if(c == 8) return 0;

//test all adjacent indices 

for(int i = 0; i < c; i++) {
  	for(int j = 0; j < 5; j++) {
  		if(q[hood[i][j]] != -1) {
  			if(abs(q[c] - q[hood[i][j]]) == 1) q[c]++;
  		}
  		else goto nc;
	}
}






}
/*
//raw test 
    for(int i = 0; i < 8; i++) {
        if(q[
        }
    

*/
}
