#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int ppow(int a, int b){
    if(b == 0) return 1;
    int half = ppow(a, b / 2);
    
    if(b % 2) return half * half * a;
    return half * half;
}

int main(){
    cin>>n;
    cout<<(n > 0 && ppow(3, 19) % n == 0);
    return 0;
}