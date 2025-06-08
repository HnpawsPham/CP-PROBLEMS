#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int const maxn = 1e4 + 5;
int cnt = 0;
int child[maxn * 50][26];
bool check[maxn * 50];

void add(string& s){
    int u = 0;
    int n = s.length();

    for(int i = 0; i < n; i++){
        int k = s[i] - 'a';
        if(!child[u][k]) child[u][k] = ++cnt;
        
        u = child[u][k];
    }
    check[u] = 1;
    return;
}

bool query(string& s){
    int u = 0;
    int n = s.length();

    for(int i = 0; i < n; i++){
        int k = s[i] - 'a';
        if(!child[u][k]) return 0;

        u = child[u][k];
    }
    return check[u];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n;
    string s;

    while(n--){
        cin>>s;
        add(s);
    }

    cin>>m;
    while(m--){
        cin>>s;
        cout<<query(s)<<el;
    }

    return 0;
}