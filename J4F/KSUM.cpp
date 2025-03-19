#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, k;
const int maxn = 100005;
ll a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>a[i];

    ll sum = 0;
    for(int i = 0; i < k; i++) sum += a[i];
    ll res = sum;

    for(int i = 1; i + k - 1 < n; i++){
        sum = sum - a[i - 1] + a[i + k - 1];
        res = max(res, sum);
    }
    cout<<res;
    return 0;
}