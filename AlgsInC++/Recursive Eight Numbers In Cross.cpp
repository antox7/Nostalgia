// Ashurov, Anvar
// CS211 52A Homework 16: 8 Numbers In Cross

#include <iostream>
#include <cstdlib>
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

void print(int q[]){
    cout << "  " << q[0] << " " << q[1] << endl;
    cout << q[2] << " " << q[3] << " " << q[4] << " " << q[5] << " " << endl;
    cout << "  " << q[6] << " " << q[7] << " ";
    cout << endl << endl << endl;
};


void move(int* q, int i){
    if(i == 8){
        print(q);
        return;
    }

    for(int j = 1; j <= 8; j++){
        q[i] = j;
        if(ok(q, i)) move(q, i+1);
    }
};

int main(){
    int q[8];
    move(q, 0);
    return 0;
}