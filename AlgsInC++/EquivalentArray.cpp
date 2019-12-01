// Ashurov, Anvar
// CS211 52A Homework 1 

#include <iostream>
using namespace std;

bool match(int a[], int b[], int n){   //When it's called, this function is supposed to check if two arrays are a match.
    bool isMatch = true;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){              //If a specific element from a[] is not equal to a specific element from b[] then arrays are not a match.
            isMatch = false;
            break;
        }
    }
    return isMatch;                    //This will be in action only if all elements in an array a[] correspondce to all elements in an array b[] repective to their indices.
}

bool equal(int a[], int b[], int n){

    bool isEqual = false;
    int temp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            temp = a[n-1];             //This line and the next two lines will help for right shifting.
            a[n-1] = a[j];
            a[j] = temp;
        }
        if(match(a, b, n)){            //After necessary shift(s) is/are done, "match" function will decide whether the arrays are shift equivalent or not and report back a Boolean expression.
            isEqual = true;
            break;
        }
    }
    return isEqual;
}

int main()
{
    int a[5], b[5];

    cout << "Enter five values for your first array a : ";

    for (int i = 0; i < 5; i++) {
        cin >> a[i];
        }

    cout << "Enter five values for your second array b : ";

    for (int i = 0; i < 5; i++) {
        cin >> b[i];
        }

        if(equal(a, b, 5)) {
            cout << "They are shift equivalent!";
        }
        else{
            cout << "They are not shift equivalent!";
        }
        return 0;
}