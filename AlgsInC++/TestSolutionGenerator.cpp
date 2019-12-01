#include <iostream> 
#include <ctime> 
using namespace std; 

int main() {
        srand(time(0));
        for(int i = 1; i <= 36; i++) {
            cout << i << ". " << char('A'+ (rand()%4)) << endl;
            }
        return 0;
    }