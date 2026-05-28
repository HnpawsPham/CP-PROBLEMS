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

const int maxn = 5e3 + 5;
int child[maxn * 50][26], best[maxn * 50];
bool check[maxn * 50];
int id = 0;

void add(const string& s, int pos, const vector<string>& a){
    int u = 0;
    int n = s.length();

    for(int i = n - 1; i >= 0; i--){
        int k = s[i] - 'a';
        if(!child[u][k])
            child[u][k] = ++id;
        u = child[u][k];

        if(best[u] == -1) best[u] = pos;
        else{
            if(a[pos].length() < a[best[u]].length())
                best[u] = pos;
        }
    }
    check[u] = 1;
    return;
}

int query(const string& s){
    int u = 0, res = best[0];
    int n = s.length();

    for(int i = n - 1; i >= 0; i--){
        int k = s[i] - 'a';
        if(!child[u][k]) return res;

        u = child[u][k];
        res = best[u];
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

    int n, m;
    cin>>n>>m;
    vector<string> a(n), b(m);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];

    int root = 0;
    for(int i = 1; i < n; i++)
        if(a[i].size() < a[root].size())
            root = i;
    best[0] = root;
    
    for(int i = 0; i < n; i++) add(a[i], i, a);

    vector<int> res;
    for(const string& s : b)
        res.push_back(query(s));
    return 0;
}

// 3 3
// abcd bcd xbcd
// cd bcd xyz