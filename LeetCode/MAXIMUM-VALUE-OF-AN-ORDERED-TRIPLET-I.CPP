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
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    ll res = 0;
    
    for(int i = 0; i < n - 2; i++)
        for(int j = i + 1; j < n - 1; j++)
            for(int k = j + 1; k < n; k++)
                res = max(res, (ll)(a[i] - a[j]) * a[k]);
    cout<<res;

    return 0;
}