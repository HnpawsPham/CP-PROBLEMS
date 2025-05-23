#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, m;

int main(){
    // freopen("HAISAO.INP", "r", stdin);
    // freopen("HAISAO.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    ll a[n], b[m];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];

    sort(b, b + m);
    ll minn[n];
    for(int i = n - 2; i >= 0; i--)
        minn[i] = min(a[i], minn[i + 1]);

    int cnt = 0, j = 0;
    for(int i = n - 2; i >= 0; i--){
        if(a[i] <= minn[i + 1]) continue;
        int pos = lower_bound(b + j, b + m, a[i] - minn[i + 1]) - b;

        if(pos != m){
            a[i] -= b[pos];
            cnt++;
            j = pos;

            minn[i] = min(a[i], minn[i + 1]);
        }
        else return cout<<-1, 0;
    }

    cout<<cnt;
    return 0;
}