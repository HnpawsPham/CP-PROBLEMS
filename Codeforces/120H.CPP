#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, id;
const int maxn = 205;
const int maxID = 1e6 + 5;
vector<string> word(maxn);
unordered_set<string> dict;
unordered_map<string, int> sub;
vector<vi> a(maxn);

void gensub(int i, int len, string cur, int idx){
    if(i == word[idx].length() || len == 4){
        if(len == 0) return; 

        if(!sub.count(cur))
            sub[cur] = ++id;

        a[idx].push_back(sub[cur]);
        return;
    }

    gensub(i + 1, len + 1, cur + word[idx][i], idx);
    gensub(i + 1, len, cur, idx);
    return;
}

int match_l[maxn];
vi match_r(maxID, 0);
bool check[maxID];

bool dfs(int u){
    for(int v : a[u]){
        if(check[v]) continue;
        check[v] = 1;

        if(match_r[v] == 0 || dfs(match_r[v])){
            match_r[v] = u;
            match_l[u] = v;
            return 1;
        } 
    }
    return 0;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    id = n;
    for(int i = 1; i <= n; i++) cin>>word[i];

    for(int i = 1; i <= n; i++)
        gensub(0, 0, "", i);

    memset(check, 0, sizeof check);

    for(int i = 1; i <= n; i++)
        if(!check[i]){
            memset(check, 0, sizeof check);
            if(!dfs(i)) return cout<<-1, 0;
        }

    string conv[id + 1];
    for(auto x : sub) conv[x.se] = x.fi;

    for(int i = 1; i <= n; i++)
        cout<<conv[match_l[i]]<<el;
    return 0;
}