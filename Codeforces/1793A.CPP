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

int tc = 1;

ll sol(){
    int a, b, n, k;
    cin>>a>>b>>n>>k;
    ll cost = 1LL * n * b;
    int gr = n / (k + 1);
    int left = n % (k + 1);

    cost = min(cost, 1LL * gr * k * a + 1LL * left * a);
    cost = min(cost, 1LL * gr * k * a + 1LL * b * left);
    return cost;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}