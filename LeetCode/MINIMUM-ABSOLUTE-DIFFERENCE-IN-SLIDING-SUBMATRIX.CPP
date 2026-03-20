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
//#define taskname ""

const int oo = 2e5 + 2;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin>>n>>m>>k;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    vector<vi> res;
    if(k == 1){
        res.assign(n, vi(m, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cout<<res[i][j]<<" ";
            cout<<el;
        }
        return 0;
    }

    vi tmp, row;
    for(int i = k; i <= n; i++){
        row.clear();
        for(int j = k; j <= m; j++){
            tmp.clear();

            for(int x = i - k; x < i; x++)
                for(int y = j - k; y < j; y++)
                    tmp.push_back(a[x][y]);

            sort(tmp.begin(), tmp.end());

            int minn = oo;
            for(int x = 1; x < k * k; x++)
                if(tmp[x] != tmp[x - 1])
                    minn = min(minn, tmp[x] - tmp[x - 1]);
      
            row.push_back((minn == oo ? 0 : minn));
        }
        res.push_back(row);
    }

    for(const vi& x : res){
        for(const int& y : x) cout<<y<<" ";
        cout<<el;
    }
    return 0;
}

// 2 2 2
// 1 8
// 3 -

// 2 3 2
// 1 -2 3 
// 2 3 5