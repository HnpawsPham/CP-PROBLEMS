#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int t, n, m, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        vector<bool> check(n + 1, 0);
        int a[m];

        for(int i = 0; i < m; i++) cin>>a[i];
        for(int i = 0; i < k; i++){
            int x; cin>>x;
            check[x] = 1;
        }

        if(k < n - 1) for(int i = 0; i < m; i++) cout<<0;
        else if(k == n) for(int i = 0; i < m; i++) cout<<1;
        else for(int i = 0; i < m; i++) cout<<(!check[a[i]]);
        cout<<el;
    }

    return 0;
}