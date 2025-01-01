#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    ll a[n + 1], d[n + 1];
    d[0] = 0;
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        d[i] = a[i] - a[i - 1];
    }

    while(q--){
        int l, r, k;
        cin>>l>>r>>k;
        l++; r++;

        d[l] += k;
        d[r + 1] -= k; 
    }

    ll sum = 0;
    for(int i = 1; i <= n; i++){
        sum += d[i];
        cout<<sum<<" ";
    }

    return 0;
}