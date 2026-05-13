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

int n, k;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<int> d(2 + 2 * k, 0);
    for(int i = 0; i < n / 2; i++){
        int l = min(a[i], a[n -i - 1]);
        int r = max(a[i], a[n - i - 1]);

        d[2] += 2;
        d[l + 1] -= 1;
        d[l + r] -= 1;
        d[l + r + 1] += 1;
        d[r + k + 1] += 1;
    }

    int sum = 0, res = n * 3;
    for(int i = 2; i <= 2 * k; i++){
        sum += d[i];
        res = min(res, sum);
    }
    cout<<res;
    return 0;
}