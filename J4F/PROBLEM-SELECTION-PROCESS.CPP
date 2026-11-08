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

int sol(){
    int n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int del = 0;
    for(int i = n - 1; i > 0; i--){
        if(a[i] > a[i - 1]){
            del++;
            a[i - 1] += a[i];
        }
    }
    return n - del;
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