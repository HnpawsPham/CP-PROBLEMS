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

int tc = 1;
const int maxn = 105;
int a[maxn][maxn];

ll sol(){
    int n, m;
    cin>>n>>m;
    for(int i =0 ; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];
            
    ll res =0;
    for(int i = 0; i < (n + 1) / 2; i++){
        for(int j = 0; j < (m + 1) / 2; j++){
            vi v;
            v.push_back(a[i][j]);
            if(m - j - 1 != j)
                v.push_back(a[i][m - j - 1]);
            if(i != n - i - 1)
                v.push_back(a[n - i - 1][j]);
            if(i != n - i - 1 && m - j- 1 != j)
                v.push_back(a[n - i - 1][m - j - 1]);
            
            sort(v.begin(), v.end());

            for(const int& x : v)
                res += abs(v[v.size() / 2] - x);
        }
    }
    return res;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}