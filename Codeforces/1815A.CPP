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

string sol(){
    int n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    if(n % 2) return "yes";

    for(int i = 1; i < n; i++){
        a[i] -= a[i - 1];
        a[i - 1] = 0;
    }
    return (a[n - 1] >= 0 ? "yes" : "no");
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