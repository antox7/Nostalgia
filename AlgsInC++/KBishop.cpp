// Ashurov, Anvar
// CS211 52A Homework 18 

#include <cstdlib>
#include <iostream>
using namespace std;

int k, n;

bool ok(int q[], int b, int size){
    //Row and column of the bishop
    int row = q[b]/size; 
    int column = q[b]%size;
    //Current row, current column
    int cur_row, cur_col;  

    for(int i=0; i<b; i++){ 
        
        //Row and column of every bishop
        cur_row = q[i]/size;
        cur_col = q[i]%size;

        //Diagonal test
        if(abs(row-cur_row)==abs(column-cur_col)) return false;
    }

    return true;
}

void backtrack(int &bishop, int count){
    bishop--;
    if(bishop==-1){
        cout << k << " bishops can be placed on a " << n << " by " << n << " chessboard in " << count << " different ways.";
        exit(1);
    }
}

int main(){
    while(true){
        
        cout << "Enter n: ";
        cin >> n;
        if( n == -1) return 0;
        cout << "Enter k: ";
        cin >> k;
        if(n<0 || (n - k) < 0) cout << "Invalid inputs";
        break;

        //Solution/backtracking algorithm
        int* q = new int[k]; 
        int count = 0, b = 0, t;
        q[b] = 0;

        while(true){ 
            while(b<k){
                while(q[b]<n*n){
                    if(ok(q,b,n)) break;
                    else q[b]++;
                }

                if(q[b]==n*n){
                    backtrack(b, count);
                    q[b]++;
                    continue;
                }

                else{
                    t = q[b];
                    b++;
                    q[b] = t;
                }
            }
            count++;
            backtrack(b, count);
            q[b]++;
        }
    }
    return 0;
}