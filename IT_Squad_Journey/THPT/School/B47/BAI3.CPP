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
#define taskname "BAI3"

int n;
const ll oo = 1e15 + 5;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll a[n] = {0};
    for(int i = 0; i < n; i++) cin>>a[i];

    ll sum = a[0], maxx = a[0];
    for(int i = 1; i < n; i++){
        sum = max(sum + a[i], (ll)a[i]);
        maxx = max(maxx, sum);
    }
    cout<<maxx;
    return 0;
}

// 6
// -2 7 -8 4 6 -1

// 7
// 3 5 -2 -4 6 1 2