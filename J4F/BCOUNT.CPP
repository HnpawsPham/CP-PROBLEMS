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

    int n, q;
    cin>>n>>q;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];
    
    int p[4][n + 1];
    for(int i = 1; i <= 3; i++){
        p[i][0] = 0;
        for(int j = 1; j <= n; j++)
            p[i][j] = p[i][j - 1] + (a[j] == i);
    }

    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<p[1][r] - p[1][l - 1]<<" "<<p[2][r] - p[2][l - 1]<<" "<<p[3][r] - p[3][l - 1]<<el;
    }
    return 0;
}

// 6 3
// 2
// 1
// 1
// 3
// 2
// 1
// 1 6
// 3 3
// 2 4
