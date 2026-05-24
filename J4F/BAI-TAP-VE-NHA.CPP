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

    int n, x;
    cin>>n>>x;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    const ll oo = 1e14 + 5;
    ll sum = 0, maxx = -oo, minn = oo;
    for(int i = 0; i < n; i++){
        if(x < 0){
            sum = min(1LL * a[i], sum + a[i]);
            minn = min(minn, sum);
        }
        else{
            sum = max(sum + a[i], 1LL * a[i]);
            maxx = max(maxx, sum);
        }
    }

    ll res = -oo;
    if(maxx != -oo) res = max(maxx * 1LL * x, 1LL * *max_element(a, a + n));
    if(minn != oo) res = max(minn * 1LL * x, res);
    cout<<res;
    return 0;
}