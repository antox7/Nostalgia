// Ashurov, Anvar
// CS211 52A Homework 10  

#include <iostream>
#include <cmath>
#include <stdlib.h> 

using namespace std; 

void print (int q[8]) {
 
 int i,j,k,l;
 char b =  char(219);
 typedef char box[5][7];
 box bb,wb, wq, bq, * board[8][8];
 
 //fill in bb=black box and wb=whitebox
 
 for(i = 0; i < 5; i++)
 	for(j = 0; j < 7; j++) {
 		wb[i][j]=' ';
 		bb[i][j]=b;
 	}

 //white queen
 
 	for(i = 0; i < 5; i++) 
 		for(j = 0; j < 7; j++) {
 			if(i == 0 || i == 4) {
 				wq[i][j] = b;
 			}
 			if(i == 1) {
 				if((i+j)%2 == 0) {
 					wq[i][j] = ' ';
 				}
 				else wq[i][j] = b;
 			}
 			if(i == 2 || i == 3) {
 				if(j == 0 || j == 6) wq[i][j] = b; 
 				else wq[i][j] = ' ';
 				}
 			}
 			
 //black queen 
 
 	for(i = 0; i < 5; i++) 
 		for(j = 0; j < 7; j++) {
 			if(wq[i][j] == ' ') bq[i][j] = b;
			if(wq[i][j] == b) bq[i][j] = ' ';
		}
			

 //fill board with pointers to bb and wb in alternate positions
 
 for(i = 0; i < 8; i++)
 	for(j = 0; j < 8; j++)
 		if((i+j)%2 == 0)
 			board[i][j]=&wb;
 		else
 			board[i][j]=&bb;

 // print the board via the pointers in array board
 //print the array q;

	static int count = 1;
	
	cout << "Solution " << count << endl << endl;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (q[j] == i) {//For example, if first column has "7", then it will not print it since i = 0 at that point. Therefore, that queen will be placed correctly in row 7 when i = 7.  
				if(board[i][j] == &wb) board[i][j] = &bq;
				else board[i][j] = &wq;
			}
		}
	}
	count++;

 // first print upper border

 cout << " ";
 for(i = 0; i < 7*8; i++)
 	cout<<'_';
 cout << endl;
 
 // now print the board
 
 for(i = 0; i < 8; i++)
 	for(k = 0; k < 5; k++) {
 		cout << " "<<char(179); //print left border
    	for(j = 0;j < 8; j++)
 	        for(l = 0; l < 7; l++) 
 		        cout << (*board[i][j])[k][l];
 	cout << char(179) << endl; // at end of line print bar and then newline
 	}
 
 //before exiting print lower border
 
 cout << " ";
 for(i = 0; i < 7*8; i++)
 	cout<<char(196);
 cout << endl;

}

bool ok(int q[], int c) { //Is the configuration OK? True=good to go. 
	for (int i = 0; i < c; i++) 
		if (q[c] == q[i] || (c - i) == abs(q[c] - q[i])) return false; //This does raw test & diagonal test at once. 
		return true;
};

void backtrack(int &col) {
	col--;
	if (col == -1) exit(1);
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