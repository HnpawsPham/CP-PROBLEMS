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

    int n, st;
    cin>>n>>st;
    int a[n];
    for(int i = 0; i < n ; i++) cin>>a[i];

    bool check[50005] = {0};
    queue<int> q;
    q.push(st);
    
    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(a[u] == 0) return cout<<1, 0;

        for(int v : {u - a[u], u + a[u]}){
            if(v < 0 || v == n || check[v]) continue;
            q.push(v);
            check[v] = 1;
        }
    }
    cout<<0;
    return 0;
}

// 7 5
// 4 2 3 0 3 1 2