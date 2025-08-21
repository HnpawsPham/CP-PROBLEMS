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

    int n, m;
    cin>>n>>m;
    vector<vi> a(n, vi(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    int res = 0;
    vi b(m, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            b[j] = (b[j] + 1) * a[i][j];
        
        for(int j = 0; j < m; j++){
            int minn = n + 5;
            for(int x = j; x < m; x++){
                minn = min(minn, b[x]);
                res += minn;
            }
        }
    }
    cout<<res;
    return 0;
}

// 3 3
// 1 0 1
// 1 1 0
// 1 1 0