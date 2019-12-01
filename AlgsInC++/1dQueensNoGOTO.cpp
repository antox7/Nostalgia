// Ashurov, Anvar
// CS211 52A Homework 7  

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std; 

bool ok(int q[], int c) { //Is the configuration OK? True=good to go. 
	for (int i = 0; i < c; i++) 
		if (q[c] == q[i] || (c - i) == abs(q[c] - q[i])) return false; //This does raw test & diagonal test at once. 
		return true;
};

void backtrack(int &col) {
	col--;
	if (col == -1) exit(1);
};

void print(int q[]) {
	//print the array q;

	static int count = 1;
	
	cout << "Solution " << count << endl << endl;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
		if (q[j] == i) cout << "1 "; //For example, if first column has "7", then it will not print it since i = 0 at that point. Therefore, that queen will be placed correctly in row 7 when i = 7.  
			else cout << "0 ";
		}
		cout << endl;
	}
	cout << endl;
	count++;
};


int main() {
	int q[8], c;
	q[0] = 0;
	c = 0;

	//from_backtrack keeps track if we need to reset the row to the top of the current column or not. 

	bool from_backtrack = false;

	// The outer loop keeps looking for solutions 
	// The program terminates from function backtrack
	// when we are forced to backtack into column -1

	while (true) {
		while (c < 8) { //this loop goes accross columns
			//if we just returned from backtrack, use current value of row
			//otherwise get ready to start at the top of this column

			if (!from_backtrack) q[c] = -1;
				while (q[c] < 8) {
					q[c]++;
					if (q[c] == 8) {
						backtrack(c);
						continue;
					}
					if (ok(q, c)) break;
				}
				c++;
				from_backtrack = false;
			}
			print(q);
			backtrack(c);
			from_backtrack = true;
		}
	return 0;
}