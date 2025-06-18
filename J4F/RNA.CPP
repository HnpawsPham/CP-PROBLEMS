#include <bits/stdc++.h>
using namespace std;
#define el "\n"

const int maxn = 1e5;
int n, q, cnt = 0;
string s;
int cnt_pre[maxn * 50] = {0}, 
    cnt_suff[maxn * 50] = {0}, 
    child[maxn * 50][26] = {0};

void add(string& s){
    int u = 0;

    for(char& x : s){
        int k = x - 'A';
        if(!child[u][k]) child[u][k] = ++cnt;

        u = child[u][k];
        cnt_pre[u]++;
    }
    return;
}

int query_pre(string& s){
    int u = 0;

    for(char& x : s){
        u = child[u][x - 'A'];
        if(!u) return 0;
    }
    return cnt_pre[u];
}

int query_suff(string& s){
    int u = 0;

    for(char& x : s){
        u = child[u][x - 'A'];
        if(!u) return 0;
    }
    return cnt_suff[u];
}

int main(){
    // freopen("RNA.INP", "r", stdin);
    // freopen("RNA.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;

    while(n--){
        cin>>s;
        add(s);
    }

    string x, y;
    while(q--){
        cin>>x>>y;
        cout<<query_pre(x)<<el;
    }

    return 0;
}