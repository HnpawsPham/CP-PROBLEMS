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

    int l, r;
    cin>>l>>r;

    vector<ll> a;
    for(int i = 1; i < 10; i++){
        ll x = i;
        int d = i + 1;
        for(int len = 2; len < 10 && d < 10; len++){
            x = x * 10 + d;
            a.push_back(x);
            d++;
        }
    }
    sort(a.begin(), a.end());
    // for(ll x : a) cout<<x<<" ";

    vi res;
    for(const int& x : a){
        if(x > r) break;
        if(x >= l) res.push_back((int)x);
    }

    for(int x : res) cout<<x<<" ";
    return 0;
}