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

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<pii> b;
    for(int i = 0; i < n; i++) 
        b.push_back({a[i], i});
    sort(b.begin(), b.end());

    vi res(n);
    int cur = 1;
    for(int i = 0; i < n; i++){
        if(i > 0 && b[i].fi != b[i - 1].fi)
            cur++;
        res[b[i].se] = cur;
    }

    for(int x : res) cout<<x<<" ";
    return 0;
}