#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n + 1][n + 1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin>>a[i][j];

    int p[n + 1];
    for(int i = 1; i <= n; i++){
        p[i] = 0;
        for(int j = 1; j <= n; j++)
            p[i] += a[i][j];
    }

    int cnt = 0;
    
    for(int i = 1; i <= n; i++){
        if(a[i][i] < 0) continue;
        int k = p[i] - a[i][i];
        if(a[i][i] < k) return cout<<"NO", 0;

        if(k < a[i][i]) cnt++;
    }


    if(cnt) cout<<"YES"<<el<<cnt;
    else cout<<"NO";

    return 0;
}