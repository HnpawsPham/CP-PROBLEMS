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
#define psi pair<string, int>
#define taskname "BAI4"

int n;
const int maxn = 1e6 + 6;
int child[maxn][26];
bool check[maxn];
vi mp[maxn];
int cnt = 0;

void add(const string& s, int id){
    int u = 0;
    int n = s.length();

    for(int i = 0; i < n; i++){
        int k = s[i] - 'a';
        if(!child[u][k]) 
            child[u][k] = ++cnt;

        u = child[u][k];
    }
    mp[u].push_back(id);
    check[u] = 1;
}

vector<pii> ans;
vi query(int u){
    vi res = mp[u];
    for(int i = 0; i < 26; i++){
        if(!child[u][i]) continue;
        vi tmp = query(child[u][i]);
        for(const int& x: tmp)
            res.push_back(x);
    }

    while(check[u] && res.size() >= 2){
        ans.push_back({res.back(), 0});
        res.pop_back();
        ans.back().se = res.back();
        res.pop_back();
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

    cin>>n;
    memset(child, 0, sizeof child);
    for(int i = 0; i < 2 * n; i++){
        string s;
        cin>>s;
        add(s, i + 1);
    }

    query(0);
    sort(ans.begin(), ans.end());
    for(const pii& x: ans)
        cout<<x.fi<<" "<<x.se<<el;
    return 0;
}