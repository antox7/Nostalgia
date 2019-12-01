//Ashurov, Anvar
//CS 211 52A HW#11

/*
You have n men and n woman, and their preference rankings of each other, and you need
to match them up so that the total matching is “stable.”
*/

#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std; 

bool ok(int q[], int column) {

    int mp[3][3]={
                 {0,2,1},
                 {0,2,1},
                 {1,2,0}};
    int wp[3][3]={
                 {2,1,0},
                 {0,1,2},
                 {2,0,1}};

	for (int i=0; i<column; i++){
        if (q[column]==q[i]){ 
        	return false;
        }
    	if((mp[i][q[column]] < mp[i][q[i]] && wp[q[column]][i] < wp[q[column]][column]) || (mp[column][q[i]] < mp[column][q[column]] && wp[q[i]][column] < wp[q[i]][i])) {
        	return false;
    	}
	}
    return true;
}

void backtrack(int &col){
    col--;
    if(col == -1){
        exit(1);
    }
}

void print(int q[]){
    static int count = 1; 
    cout << "Stable #" << count << ": " << endl;
    cout << "Men:   0 1 2" << endl << "Women: ";
    for (int i = 0; i < 3; i++)
        cout << q[i] << ' ';
    cout << endl << endl;
    count++;
}

int main() {
	int q[3], c;
	q[0] = 0;
	c = 0;

	//from_backtrack keeps track if we need to reset the row to the top of the current column or not. 

	bool from_backtrack = false;

	// The outer loop keeps looking for solutions 
	// The program terminates from function backtrack
	// when we are forced to backtack into column -1

	while (true) {
		while (c < 3) { //this loop goes accross columns
			//if we just returned from backtrack, use current value of row
			//otherwise get ready to start at the top of this column

			if (!from_backtrack) 
			    q[c] = -1;
			    from_backtrack = false;
				while (q[c] < 3) {
					q[c]++;
					if (q[c] == 3) {
						backtrack(c);
						continue;
					}
					if (ok(q, c)) break;
				}
				c++;
			}
			print(q);
			backtrack(c);
			from_backtrack = true;
		}
	return 0;
}