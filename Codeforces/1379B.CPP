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

void sol(){
    int l, r;
    ll m;
    cin>>l>>r>>m;

    for(ll a = l; a <= r; a++){
            ll n = (m - (r - l) + a - 1) / a;
            if(n < 1) n = 1;

            ll d = m - n * a;
            if(d >= -(r - l) && d <= (r - l)){
                ll b, c;
                if(d >= 0){
                    b = l + d;
                    c = l;
                } 
                else {
                    b = l;
                    c = l - d;
                }
                cout<<a<<" "<<b<<" "<<c;
                return;
            }
        }
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
        sol();
        cout<<el;
    }
    return 0;
}