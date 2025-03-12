#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

double a;
ll b;

double ppow(double a, ll b){
    if(b == 0) return 1;

    if(b < 0){
        a = 1 / a;
        b *= -1;
    }

    double half = ppow(a, b / 2);
    if(b % 2 == 0) return half * half;
    return half * half * a; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b;
    cout<<ppow(a, b);

    return 0;
}