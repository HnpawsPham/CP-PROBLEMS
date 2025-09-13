#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n + 1], b[n + 1], wa[n + 1], wb[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <=n; i++) cin>>b[i];
    for(int i = 1; i <= n; i++) cin>>wa[i];
    for(int i = 1; i <= n; i++) cin>>wb[i];

    ll sum = 0;
    for(int i = 1; i <= n; i++) sum += b[i];

    int d[n + 1];
    for(int i =1 ;i <= n; i++) d[i] = a[i]- b[i];
    sort(d + 1, d + n + 1);

    ll pwa[n + 1] = {0}, pwb[n + 1] = {0}, pd[n + 1] = {0};
    for(int i = 1; i <= n; i++) pwa[i] = pwa[i - 1] + wa[i];
    for(int i = 1; i <= n; i++) pwb[i] = pwb[i - 1] + wb[i];
    for(int i = 1; i <= n; i++) pd[i] = pd[i - 1] + d[i];

    ll res = LLONG_MAX;
    for(int i = 0; i <= n; i++){
        res = min(res, sum + pd[i] + pwa[i] + pwb[n - i]);
    }
    cout<<res;
    return 0;
}