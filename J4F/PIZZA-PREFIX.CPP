#include <bits/stdc++.h>
using namespace std;
#define el "\n"

const int maxn = 1e6 + 5;
int child[maxn][26], 
    cnt_en[maxn] = {0}, // tien to cua u 
    cnt_pre[maxn] = {0}; // co u la tien to
int cnt = 0;

void add(string& s){
    int u = 0;
    int n = s.length();

    for(int i = 0; i < n; i++){
        int k = s[i] - 'a';
        if(!child[u][k]) child[u][k] = ++cnt;
        
        u = child[u][k];
        cnt_pre[u]++;
    }
    cnt_en[u]++;
    return;
}

int query1(string& s){
    int u = 0, res = 0;
    
    for(const char& x : s){
        u = child[u][x - 'a'];
        if(!u) break;

        res += cnt_en[u];
    }
    return res;
}

int query2(string &s){
    int u = 0;

    for(const char& x : s){
        u = child[u][x - 'a'];
        if(!u) return 0;
    }
    return cnt_pre[u];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    string s;
    cin>>n;

    while(n--){
        cin>>q>>s;

        if(q == 0) add(s);
        else if(q == 1) cout<<query1(s)<<el;
        else cout<<query2(s)<<el;
    }

    return 0;
}