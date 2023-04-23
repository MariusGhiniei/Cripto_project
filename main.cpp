#include <iostream>
using namespace std;


int gcd (int n, int x){
    if (n == 1) return 1;
    while(n!=x){
        if(n > x) n = n - x;
        else x = x - n;
    }
    return x;
}
long long gcd_rec(int a, int b){
    if(b!=0) return gcd_rec(b,a%b);
    else return a;
}

long long lcm(int a, int b) {
    int x = gcd_rec(a,b);
    return a*b/x;
}

int primeGenerator(int n){
    if(n == 1) return 7;
    int x = primeGenerator(n-1);
    return x + gcd_rec(n,x);

}

long long primeGeneratorLCM(int n){
    if(n == 1) return 1;
    int x = primeGeneratorLCM(n-1);
    return x + lcm(n,x);
}

int main() {
    cout<<"With GCD"<<endl;
    for(int i = 2 ; i<100000 ; i++){
        if(primeGenerator(i) - primeGenerator(i-1) != 1)
            cout<< primeGenerator(i) - primeGenerator(i-1)<< " ";
    }

    cout<<endl;

    cout<<"With LCM"<<endl;

    for(int i = 2 ; i<40; i++){
        if(primeGeneratorLCM(i)/ primeGeneratorLCM(i-1) - 1 != 1)
            cout<< primeGeneratorLCM(i)/ primeGeneratorLCM(i-1) - 1 << " ";
    }

    return 0;
}
