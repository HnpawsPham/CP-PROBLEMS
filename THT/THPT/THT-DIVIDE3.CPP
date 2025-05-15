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
    for(int i = 0; i < n; i++) cin>>a[i];

    int c0 = 0, c1 = 0, c2 = 0;
    for(int x : a){
        if(x % 3 == 0) c0++;
        else if(x % 3 == 1) c1++;
        else c2++;
    }

    int t = (c0 + c1 + c2) / 3;
    cout<<max(0, c0 - t) + max(0, c1 - t) + max(0, c2 - t);
    return 0;
}