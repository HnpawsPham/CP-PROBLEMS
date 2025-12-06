#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second

int tc = 1;

int sol(){
    int n, m;
    cin>>n>>m;
    char a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    int w[n][m];
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < m; j++){
            if(a[i][j] == '*') cnt++;
            else cnt = 0;
            w[i][j] = cnt;
        }

        cnt = 0;
        for(int j = m - 1; j >= 0; j--){
            if(a[i][j] == '*') cnt++;
            else cnt = 0;
            w[i][j] = min(w[i][j], cnt);
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int x = i, k = 1; x < n; x++, k++){
                if(w[x][j] < k) break;
                res++;
            }
    return res;
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