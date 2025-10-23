#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc = 1;

string sol(){
    int n, m;
    cin>>n>>m;
    int a[n][m], b[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>b[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            bool ok = 1;
            for(int x = 0; x < n; x++)
                for(int y = 0; y < m; y++)
                    if(a[x][y] != b[(i + x) % n][(j + y) % m]) {
                        ok = 0;
                        break;
                    }

            if(ok) return "YES";
        }
    return "NO";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}