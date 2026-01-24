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
#define taskname "TRAVEL"

int n, q;

ll d(int x, int y){
    return 1LL * abs(x - y);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    int a[n + 1] = {0}, b[n + 1] = {0};
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        b[i] = a[i];
    }

    sort(b + 1, b + n + 1);

    while(q--){
        int l, r;
        cin>>l>>r;
        if(r < l) swap(l, r);        
        
        ll maxx = LLONG_MAX;
        int pos = lower_bound(b + 1, b + n + 1, (a[r] + a[l]) / 2) - b;

        if(pos <= n)
            maxx = min(maxx, max(d(b[pos], a[l]), d(a[r], b[pos])));

        if(pos > 1) pos--;
            maxx = min(maxx, max(d(b[pos], a[l]), d(a[r], b[pos])));
        cout<<maxx<<el;
    }
    return 0;
}