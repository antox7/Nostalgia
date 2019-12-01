// Ashurov, Anvar
// CS211 52A Homework 1 

#include <iostream>
#include <climits>
using namespace std;

int main() {
    for(int i = 4; i <= INT_MAX; i++) {                        // Starts with 4*4 = 16 since 3*3 = 9 and that does not have two digits. 
        if( ((i*i)%10)%2 != 0 && ((((i*i)/10)%10)%2) != 0) {   //Checks the last two digits of the squared number.
            cout << i*i;  
            break;                                             //Without break, it runs infinetely since such number does not exist. 
        }
    }
    return 0;
}


/* This program will print -2147479015 and break. 
Such number does not exist. 
Assume a number n is expressed in form n = a + 10b. 
The squared form is n^2 = 100b^2 + 20ab + a^2.
Focusing on the last two terms (since 100b^2 does not contribute to the last two digits), 
we are left with 20ab + a^2. From here one can see that any result of a*b multiplied by 20 will be even since 
odd * even = even and even * even = even so what a and b do not really matter. This 
tells us that the second to last digit is never odd thus such number does not exist and therefore
the program will run infinetely many times (without break)
*/