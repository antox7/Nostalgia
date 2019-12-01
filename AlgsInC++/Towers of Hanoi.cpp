// Ashurov, Anvar
// CS211 52A Homework 15: Towers of Hanoi

#include <iostream>
using namespace std;

void move (char f, char t, char e, int n){
	static int step = 1;
	if (n == 1)
		cout << step++ << ": Move from " << f << " to " << t << endl;
    	else {
        	move(f,e,t,(n-1));
        	cout << step++ << ": Move from " << f << " to " << t << endl;
        	move(e,t,f,(n-1));
    	}
}
int main() {
	int n;
    	cout << "Enter the number of Hanoi rings: ";
    	cin >> n;
    	move('A','B','C', n);
    	return 0;
}