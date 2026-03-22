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

int n, a, b, c;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>a>>b>>c;
    
    ll cnt = 0;
    for(int z = 0; z <= c; z++){
        int s = 2 * n - 4 * z;
        if(s < 0) break;

        int l = max(0, (s - a + 1) / 2);
        int r = min(s / 2, b);
        if(l <= r) cnt += r - l + 1;
    }
    cout<<cnt;
    return 0;
}