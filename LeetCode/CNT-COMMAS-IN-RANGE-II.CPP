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

    ll n;
    cin>>n;

    ll i = 1000, res = 0;
    int cnt = 1;
    while(i * 1000 <= n){
        res += cnt * 999 * i;
        i *= 1000;
        cnt++;
    }
    cout<<res + max(cnt * (n - i + 1), 0LL);
    return 0;
}