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

    string s;
    int l, r;
    cin>>s>>l>>r;
    if(s.back() == '1') return cout<<0, 0;

    int n = s.length();
    queue<int> q;
    q.push(0);
    bool check[1e5 + 5] = {0};
    int maxx = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(u == n - 1) return cout<<1, 0;

        for(int v = max(maxx, u + l); v <= min(n - 1, u + r); v++){
            if(s[v] == '1' || check[v]) continue;
            q.push(v);
            check[v] = 1;
        }
        maxx = max(maxx, min(n - 1, u + r));
    }
    cout<<0;
    return 0;
}

// 011010 2 3