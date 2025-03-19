#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#pragma GCC optimize("O2,unroll-loops,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int left = 1;
    for(int i = n - 1; i>=0, left; i--){
        a[i] = (a[i] + 1) % 10;
        left = a[i] / 10;
        a[i] %= 10;
    }
    for(int i = 0; i < n; i++) cout<<a[i];
    
    return 0;
}