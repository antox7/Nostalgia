// Ashurov, Anvar
// CS211 52A Homework 4 

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int q[8], i, c = 0, solution = 1;
	q[0] = 0;

nc: c++;
	if (c == 8) goto print;
	q[c] = -1;

nr: q[c]++;
	if (q[c] == 8) goto backtrack; //the value of q[c] is the row number, hence if we hit 8, we are out of boundary and need to go to backtrack. 

	//raw test
	for (i = 0; i < c; i++) {
		if (q[c] == q[i]) goto nr; //This will make sure that no collisions are on horizontal placements. 
	}

	//diagonal test
	for (i = 0; i < c; i++) {
		if((abs(q[c] - q[i])) == (c - i)) goto nr; //This make sures no queens are on both diagonals.
	}
	goto nc;

backtrack:
	c--;
	if (c == -1) return 0; //c=-1 is when we tried all backtracking options and went out of boundary, if so then program must end. 
	goto nr;

print:
	cout << "Solution #" << solution << ": " << endl << endl; 
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (q[j] == i) cout << "1 "; //For example, if first column has "7", then it will not print it since i = 0 at that point. Therefore, that queen will be placed correctly in row 7 when i = 7.  
			else cout << "0 ";
		}
		cout << endl;
	}
	cout << endl;
	solution++;
	goto backtrack;
}
