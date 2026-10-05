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
#define taskname "ABC"

int n;
const int maxn = 2005;
pii a[maxn];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i =0 ; i< n; i++) 
        cin>>a[i].fi>>a[i].se;

    ll cnt = 0;
    for(int i = 1; i < n; i++){
        map<pii, int> mp;
        for(int j = 0; j < i; j++){
            int dx = a[i].fi - a[j].fi;
            int dy = a[i].se - a[j].se;

            int gcd = __gcd(abs(dx), abs(dy));
            dx /= gcd;
            dy /= gcd;

            if(dx < 0 || (dx == 0 && dy < 0)){
                dx = -dx;
                dy = -dy;
            }
            cnt += mp[{dx, dy}];
            mp[{dx, dy}]++;
        }
    }
    cout<<cnt;
    return 0;
}