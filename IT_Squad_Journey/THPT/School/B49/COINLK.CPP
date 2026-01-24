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
#define taskname "COINLK"

int tc = 1;

void sol(){
    string s;
    cin>>s;

    int cnts = 0, cntn = 0;
    for(const char&x : s){
        if(x == 'S') cnts++;
        else cntn++;
    }

    int gcd = __gcd(cnts, cntn);
    cnts /= gcd;
    cntn /= gcd;
    
    cout<<cnts<<'/'<<cntn<<el;
    return;
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
        // cout<<sol()<<el;
        sol();
    }
    return 0;
}