// Ashurov, Anvar
// CS211 52A Homework 16: Recursive Stable Marriage 

#include <iostream>
#include <cstdlib>
using namespace std;

bool ok(int q[], int col){

    int mp[3][3]={
                
                {0, 2, 1},
                {0, 2, 1},
                {1, 2, 0}
                
                };
                
    int wp[3][3]={
                
                {2, 1, 0},
                {0, 1, 2},
                {2, 0, 1}
                
                };
    //current man, current woman, new man, new woman
    int cm, cw, nm, nw;

    for(int i = 0; i < col; i++){
        cm=i;
        cw=q[i]; //woman assigned to man i
        nm=col;
        nw=q[col];
        if(nw == cw) return false;
    }

    for(int i=0; i<col; i++){
        
        cm=i;
        cw=q[i]; //woman assigned to man i
        nm=col;
        nw=q[col];

        if(mp[cm][cw]>mp[cm][cw]&& wp[nw][cm]<wp[nw][nm]) return false;

        if(mp[nm][cw]<mp[nm][nw]&& wp[cw][nm]<wp[cw][cm]) return false;
    }
    return true;
}

void print(int q[]){
    static int count=0;
    cout << "Solution " << count++ << endl;
    cout << "Man Woman" << endl;
    for(int i = 0; i < 3; i++){
        cout << " " << i << "    " << q[i] << endl;
    }
    cout << endl << endl;
}

void move(int* q, int i){
    if(i == 3){
        print(q);
        return;
    }

    for(int j = 0; j < 3; j++){
        q[i] = j;
        if(ok(q, i)) move(q, i+1);
    }
};

int main(){
    int q[3];
    move(q, 0);
    return 0;
}