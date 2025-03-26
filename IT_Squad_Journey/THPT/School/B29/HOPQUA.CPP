#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, m;

int main(){
    freopen("HOPQUA.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    ll a[n], b[m];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];

    sort(a, a + n);
    sort(b, b + m);

    int i = 0, j = 0;
    ll res = 0;

    while(i < n && j < m){
        if(a[i] >= b[j]){
            res += a[i];
            j++;
        }
        i++;
    }
    cout<<(j >= m - 1 ? res : -1);

    return 0;
}