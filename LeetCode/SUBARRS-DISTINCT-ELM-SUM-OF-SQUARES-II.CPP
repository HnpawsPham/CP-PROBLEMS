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

const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;
int prev[maxn], p[maxn];

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

    memset(prev, -1, sizeof prev);
    memset(p, 0, sizeof p);

    int sum = 0, x = 0;
    for(int i = 0; i < n; i++){
        int len = i - prev[a[i]];
        int x = (prev[a[i]] != -1 ? p[i - 1] - p[prev[a[i]]] : p[i - 1]); // f(r-1)
        sum = (sum + 2 * x % MOD + len) % MOD;

        prev[a[i]] = i;
        p[i + 1] = (x + len) % MOD;

        if(prev[a[i]] != -1)
            p[i + 1] = (p[i + 1] - p[prev[a[i]]] + MOD) % MOD;
    }
    cout<<sum;
    return 0;
}