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
#define taskname "CAU1"

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    cin>>x>>y;
    ll cnt = 0;
    for(int m = 1; m <= y; m++)
        for(int j = 1; j < m; j++)
            if(1LL * j * 1LL * (m + 1) <= x) cnt++;
    cout<<cnt;
    return 0;
}