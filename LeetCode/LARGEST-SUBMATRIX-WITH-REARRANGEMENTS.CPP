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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<vi> a(n, vi(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    vi col(m, 0);
    int res = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j]) col[j]++;   
            else col[j] = 0;
        }

        vi tmp = col;
        sort(tmp.begin(), tmp.end(), greater<int>());

        for(int j = 0; j < m; j++)
            res = max(res, tmp[j] * (j + 1));
    }
    cout<<res;
    return 0;
}

// 3 3
// 0 0 1
// 1 1 1
// 1 0 1