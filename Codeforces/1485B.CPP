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

    int n, q, k;
    cin>>n>>q>>k;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<(a[r] - a[l]) + (k - 1) - 2 * (r - l)<<el;
    }
    return 0;
}