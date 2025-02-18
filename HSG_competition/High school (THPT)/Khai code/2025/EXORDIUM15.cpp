#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, q;
const int maxn = (int)1e6 + 5;
ll a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i = 1; i <= n; i++) cin>>a[i];
    
    while(q--){
        int i; ll x;
        cin>>i>>x;
        a[i] = x;
    }
    for(int i = 1; i <= n; i++) cout<<a[i]<<" ";

    return 0;
}