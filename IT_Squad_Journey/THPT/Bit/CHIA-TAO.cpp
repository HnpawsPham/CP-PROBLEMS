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
    ll a[n];
    for(int i = 0; i < n;i++) cin>>a[i];

    ll sum1 = 0, sum2 = 0, res = LLONG_MAX;
    
    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            if((i >> j) &1) sum1 += a[j];
            else sum2 += a[j];
        }
        res = min(abs(sum1 - sum2), res);
        sum1 = sum2 = 0;
    }
    cout<<res<<el;

    return 0;
}