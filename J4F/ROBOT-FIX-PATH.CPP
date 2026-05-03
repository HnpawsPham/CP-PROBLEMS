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

string sol(){
    int n, k, x, y, u, v;
    string s;
    cin>>n>>k>>x>>y>>u>>v>>s;

    int px[n + 1] = {0}, py[n + 1] = {0};
    for(int i = 1; i <= n; i++){
        px[i] = px[i - 1];
        py[i] = py[i - 1];

        if(s[i - 1] == 'L' || s[i - 1] == 'R')
            px[i] += (s[i - 1] == 'L' ? -1 : 1);
        if(s[i - 1] == 'D' || s[i - 1] == 'U')
            py[i] += (s[i - 1] == 'D' ? 1 : -1);
    }
    
    for(int i = 1; i + k - 1 <= n; i++){
        int dx = px[i - 1] + px[n] - px[i + k - 1];
        int dy = py[i - 1] + py[n] - py[i + k - 1];
        if(abs(u - x - dx) + abs(v - y - dy) <= k) return "YES";
    }
    return "NO";
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