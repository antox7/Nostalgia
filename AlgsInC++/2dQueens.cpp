// Ashurov, Anvar
// CS211 52A Homework 3 

#include <iostream> 
using namespace std; 
int main() {
	
int b[8][8] = {0}, r, c = 0;
int i, j;
b[0][0] = 1;
int solution = 1;
	
nc:
    c++;
	if(c == 8) goto print; //if we reached column 8 (out of boundary) then we finished the task. 
	r = -1;
	
nr: 
	r++;
	if( r == 8) goto backtrack;

//rawtest
	for(i = 0; i < c; i++) {
		if(b[r][i] == 1) goto nr; //if found queen, check the next raw.
	}

//updiagonaltest
	for(i = 1; (r-i>=0 && c-i >= 0 ); i++) {
		if(b[r-i][c-i] == 1) goto nr; 	
	}

//downdiagonaltest	
	for(i = 1; (r+i  < 8 && c-i >= 0); i++) {
		if(b[r+i][c-i] == 1) goto nr;
	}
		
	b[r][c] = 1;     //no conflict (more like else statement)
	goto nc;  
		
	
backtrack: 
	c--; //go back 1 column
	if(c == -1) return 0; //exit if we went out of boundary (no more backtracking)
	r = 0; 
	while(b[r][c] != 1)
	r++; 					//column constant, raw changing. if find 1(Queen), replace with 0. 
	b[r][c] = 0;
	goto nr;
	
print:
	cout << "Solution #" << solution << ":" << endl << endl;
	for(i = 0; i < 8; i++) {
		for(j = 0; j < 8; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	solution ++; //sequentially prints the other solutions via backtrack. 
	goto backtrack;
}
