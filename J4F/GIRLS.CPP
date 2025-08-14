#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int n, m, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];
    sort(a + 1, a + n + 1);

    ll p[n + 1] = {0};
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i];

    ll res = -2;
    for(int i = m; i <= n; i++){
        if(a[i] - a[i - m + 1] > k) continue;
        res = max(res, p[i] - p[i - m]);
    }    
    cout<<res;
    return 0;
}