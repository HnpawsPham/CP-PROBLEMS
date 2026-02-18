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

int n, d;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>d;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int cnt[d] = {0};
    cnt[0] = 1;

    ll res = 0, sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        int x = (sum % d + d) % d;
        res += cnt[x];
        cnt[x]++;
    }
    cout<<res;
    return 0;
}