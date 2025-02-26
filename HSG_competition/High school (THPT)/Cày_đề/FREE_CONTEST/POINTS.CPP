#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, k;

int main(){
    freopen("POINTS.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n], d[n] = {};
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < k; i++){
        int x; cin>>x;
        d[x - 1]++;
    }
    for(int i = 0; i < n; i++) cout<<a[i] + k - d[i]<<" ";

    return 0;
}