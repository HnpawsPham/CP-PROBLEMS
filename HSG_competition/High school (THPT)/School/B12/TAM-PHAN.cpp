#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n";
#define MOD 1000000007

int n;

ll customPow(int a, int b){
    if(b == 0) return 1;
    if(b % 2 == 0) return customPow(a, b / 2) * customPow(a, b / 2);
    else return customPow(a, b / 2) * customPow(a, b / 2) * a;
}

int main(){
    freopen(".\\txt\\TAM-PHAN.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cout<<customPow(3, n) - 1<<el;

    return 0;
}