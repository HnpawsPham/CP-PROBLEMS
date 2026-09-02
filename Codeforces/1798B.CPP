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

void sol(){
    int m, n, x;
    cin>>m;
    vi a[m];

    for(int i = 0; i < m; i++){
        cin>>n;
        for(int j = 0; j < n; j++){
            cin>>x;
            a[i].push_back(x);
        }
    }

    int res[m];
    bool check[50005];
    memset(check, 0, sizeof check);

    for(int i = m - 1; i >= 0; i--){
        int cur = -1;
        for(const int& x : a[i]){
            if(!check[x] && cur == -1)
                cur = x;
            check[x] = 1;
        }

        if(cur == -1){
            cout<<-1;
            return;
        }
        res[i] = cur;
    }
    for(const int& x : res)
        cout<<x<<" ";
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
        sol();
        cout<<el;
    }
    return 0;
}