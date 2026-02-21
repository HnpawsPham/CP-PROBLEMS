#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin>>n>>q;
    ll a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    ll d[n + 2] = {0};
    while(q--){
        int l, r, x;
        cin>>l>>r>>x;
        d[l] += x;
        d[r + 1] -= x;
    }

    for(int i = 1; i <= n; i++){
        d[i] += d[i - 1];
        a[i] += d[i];
    }

    for(int i = 1; i <= n; i++) 
        cout<<a[i]<<" ";
    return 0;
}