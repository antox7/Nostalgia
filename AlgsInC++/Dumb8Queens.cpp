// Ashurov, Anvar
// CS211 52A Homework 9 

#include <iostream>
#include <cmath>
using namespace std; 

bool ok(int q[8][8]) {
	
	//raw test
	//no more than 1 Queen in row & diagonal
	
	int r = 0;

	for(int row = 0; row < 8; row++) {
		for(int col = 0; col < 8; col++) {
			
			//rawtest		
			if(q[row][col] == 1) r++;
			if(r > 1) return false;	

			//updiagonaltest
			for(int i = 1; ((row-i)>=0) && ((col-i) >= 0); i++) {
				if(q[row-i][col-i] ==1 && q[row][col] == 1) return false; 	
			}
			
			//downdiagonaltest	
			for(int j = 1; ((row+j)  < 8 && (col-j) >= 0); j++) {
				if(q[row+j][col-j] == 1 && q[row][col] == 1) return false;
			}
		}
		r = 0;
	}
	return true;
}

void print(int board[8][8], int count){
    cout << "Solution #" << count << ": " << endl;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			cout << board[i][j] << " ";
		}
        cout << endl;
	}
	cout << endl << endl;
}

int main() {
	int board[8][8] = {0};
	int count = 0;
	for(int i0 =0; i0 <8; i0++)
 		for(int i1 =0; i1 <8; i1++)
 			for(int i2 =0; i2 <8; i2++)
 				for(int i3 =0; i3 <8; i3++)
 					for(int i4 =0; i4 <8; i4++)
 						for(int i5 =0; i5 <8; i5++)
 							for(int i6 =0; i6 <8; i6++)
								for(int i7 =0; i7 <8; i7++) {
					// use the indices of the loops to set a configuration in array board
   			        // if this configuration is conflict-free, print the count and the board	
									board[i0][0]=1;
                                    board[i1][1]=1;
                                    board[i2][2]=1;
                                    board[i3][3]=1;
                                    board[i4][4]=1;
                                    board[i5][5]=1;
                                    board[i6][6]=1;
                                    board[i7][7]=1;

                                    if(ok(board)) print(board, ++count);
                    // reset the board for the next configuration
                                    board[i0][0]=0;
                                    board[i1][1]=0;
                                    board[i2][2]=0;
                                    board[i3][3]=0;
                                    board[i4][4]=0;
                                    board[i5][5]=0;
                                    board[i6][6]=0;
                                    board[i7][7]=0;
                                    
                                }
    	return 0;		
}
							
