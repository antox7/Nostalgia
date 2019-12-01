// Ashurov, Anvar
// CS211 52A Homework 8 

#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[8], int c) {

        /*       ___
           _|0|1|_
          |2|3|4|5|
           `|6|7|`
        */

        int index[8][5] = {
        { -1 },
        { 0, -1 },
        { 0, -1 },
        { 0, 1, 2, -1 },
        { 0, 1, 3, -1 },
        { 1, 4, -1 },
        { 2, 3, 4, -1 },
        { 3, 4, 5, 6, -1 }};

//raw test to make sure numbers are not repeated
        for(int i = 0; i < c; i++) {
            if(q[c] == q[i]) return false;
        }
//adjacency test to make sure neighbors are not consecutive numbers
        for ( int i = 0 ; index[c][i] != -1 ; i++ )     {
                if (abs( q[c] - q[index[c][i]] ) == 1 )
                        return false;
        }
        return true;
};

void backtrack(int &c){
    c--;
    if(c == -1) return;
};

void print(int q[]){
    cout << "  " << q[0] << " " << q[1] << endl;
    cout << q[2] << " " << q[3] << " " << q[4] << " " << q[5] << " " << endl;
    cout << "  " << q[6] << " " << q[7] << " ";
    cout << endl << endl << endl;
};

int main() {
        int q[8], c = 0;
        bool from_backtrack = false;
                while(true) {
                        while(c < 8) {
                                if(!from_backtrack) q[c] = -1;  // If we arrived from backtrack, now gotta start from the beginning.
                                from_backtrack = false;
                                while(q[c] < 8) {
                            q[c]++;
    		   if(q[c] == 8){
                        backtrack(c);
                        continue;
                    }
                    if (ok(q,c)) break;
                }

            c++;
        }
        print(q);
        backtrack(c);
        from_backtrack = true;
    }
    return 0;
}
    
    
  
