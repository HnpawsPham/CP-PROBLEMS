#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, k;
const int maxn = 5000;
const ll oo = 1e11;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    ll res = oo;
    for(int i = 1; i <= maxn; i++){
        ll tmp = 0;
        int d = i;

        for(int i = 0; i < n; i++){
            tmp += abs(a[i] - d);
            d += k;
        }
        res = min(res, tmp);
    }
    cout<<res;
    return 0;
}