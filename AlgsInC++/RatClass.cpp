// Ashurov, Anvar
// CS211 52A Homework 20 

#include <iostream>
using namespace std;

class Rat{
private:
    int n;
    int d;
public:
 
    Rat(){
        n = 0;
        d = 1;
    }

    // 2 parameter constructor
    Rat(int i, int j){
        n = i;
        d = j;
    }
    // conversion constructor
    Rat(int i){
        n = i;
        d = 1;
    }
    //accessor functions
    
    int getN(){ return n; }
    int getD(){ return d; }
    void setN(int i){ n=i; }
    void setD(int i){ d=i; }

    //arithmetic operators
    Rat operator+(Rat r){
        Rat t;
        t.n=n*r.d+d*r.n;
        t.d=d*r.d;
        lowestTerms(t);
        improperFraction(t);
        return t;
    } 
 
    // Operator- 
    Rat operator-(Rat r){
       Rat t;
       t.n=n*r.d-d*r.n;
       t.d=d*r.d;
       lowestTerms(t);
       improperFraction(t);
       return t;
    }
  
    // Operator*
    Rat operator*(Rat r){
        Rat t;
        t.n=n*r.n;
        t.d=d*r.d;
        lowestTerms(t);
        improperFraction(t);
        return t;
    }
 
    // Operator/

    Rat operator/(Rat r){
        Rat t;
        t.n=n*r.d;
        t.d=d*r.n;
        lowestTerms(t);
        improperFraction(t);
        return t;
    }
 
    int gcd(int a, int b) {
        if(b == 0) {
	        return a;
        }
        else {
            return gcd(b, a % b);
        }
    }
    
    void lowestTerms(Rat &t) {
        int x = t.gcd(t.getN(), t.getD());
        t.n = t.n / x;
        t.d = t.d / x;
    }
    
    void improperFraction(Rat &t) {
        if (t.n > t.d) {
            cout << t.n/t.d << " ";
            t.n%=t.d;
        }
    }
    

    // 2 overloaded i/o operators
    friend ostream& operator<<(ostream& os, Rat r);
    friend istream& operator>>(istream& is, Rat& r);

}; //end Rat

    ostream& operator<<(ostream& os, Rat r){
        os << r.n << " / " << r.d <<endl;
        return os;
    }
    
    
    istream& operator>>(istream& is, Rat& r){
        is >> r.n >> r.d;
        return is;
    }
    
int main(){
    
        Rat x(1, 2), y(2, 3), z;
        
        z = x.operator+(y);
        cout << z << endl;
        
        x.setN(3);
        y.setD(2);
        
        z = x.operator+(y);
        cout << z << endl;
        
        cin >> x;
        cout << endl << x << endl;
        
        z = x + 5;
        cout << z << endl;

        return 0;
}   