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
    int n, m;
    cin>>n>>m;

    vi dis;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dis.push_back(max(i, n - i - 1) + (max(j, m - j - 1)));
    sort(dis.begin(), dis.end());

    for(int i = 0; i < n * m; i++)
        cout<<dis[i]<<" ";
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