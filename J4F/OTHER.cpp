#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll res = 1;
    for(int i = 2; i<=n;i++) res *= i;

    while(res % 10 == 0){
        res /= 10;
    }

    cout<<res % 10<<el;

    return 0;
}