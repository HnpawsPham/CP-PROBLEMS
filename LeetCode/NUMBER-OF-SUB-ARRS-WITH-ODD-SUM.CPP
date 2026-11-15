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

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int cnt[2] = {1, 0};
    const int MOD = 1e9 + 7;

    int res = 0, sum = 0;
    for(int i = 0; i < n; i++){
        sum = (sum + a[i]) % 2;
        res = (res + cnt[1 - sum]) % MOD;
        cnt[sum]++;
    }
    cout<<res;
    return 0;
}