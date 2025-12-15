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

int n;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    pii a[n];
    for(int i = 0; i < n; i++) cin>>a[i].fi>>a[i].se;

    int cnt = 0;
    for(auto [x, y] : a){
        bool l = 0, r = 0, u = 0, d = 0;
        for(auto [i, j] : a){
            if(j == y && i < x) l = 1;
            if(j == y && i > x) r = 1;
            if(i == x && j > y) u = 1;
            if(i == x && j < y) d = 1;
        }
        if(l && r && u && d) cnt++;
    }
    cout<<cnt;
    return 0;
}