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

    string s;
    cin>>s;
    const int MOD = 1e9 + 7;

    int cnts = 0, cntp = 0;
    ll res = 1;
    for(const char& x : s){
        if(x == 'S'){
            cnts++;
            
            if(cnts % 2 == 0){
                res = res * (cntp + 1) % MOD;
                cntp = 0;
            }
        }
        else if(cnts && cnts % 2 == 0) cntp++;
    }

    if(cnts % 2 || cnts == 0) cout<<0;
    else cout<<res;
    return 0;
}

// SSPPSPS

// PPSPSP

// S