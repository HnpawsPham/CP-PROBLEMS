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

int n, m;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    string b[n];
    for(int i = 0; i < n; i++) cin>>b[i];
    vector<string> a;   

    while(m--){
        int x;
        cin>>x;
        a.push_back(b[--x]);
        if(b[x].size() != a[0].size()) return cout<<"No", 0;
        b[x] = "";
    }

    int len = a[0].size();
    bool check[len];
    memset(check, 1, sizeof check);

    for(string x : a){
        int j = 0, pos = 0;

        for(char c : x){
            check[pos++] &= (c == a[0][j++]);
            if(j == len) break;
        }
    }

    string res;
    for(int i = 0; i < len; i++){
        if(check[i]) res.push_back(a[0][i]);
        else res.push_back('?');
    }    
    if(res.empty()) return cout<<"No", 0;

    for(int i = 0; i < n; i++){
        if(b[i].empty() || b[i].length() != len) continue;

        bool ok = 1;
        for(int j = 0; j < len; j++)
            if(res[j] != '?' && b[i][j] != res[j]){
                ok = 0;
                break;
            }
        if(ok) return cout<<"No", 0;
    }
    cout<<"Yes"<<el<<res;
    return 0;
}

// 5 3
// abacaba
// aaaaaaa
// baaaaab
// caaaaac
// daaaaad
// 2 3 4