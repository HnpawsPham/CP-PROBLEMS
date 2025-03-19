#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int q, n = 1;
const int maxn = (int)1e5 + 5;
int sz[maxn], parent[maxn];

void makeSet(){
    for(int i = 0; i <= maxn;i++){
        parent[i] = i;
        sz[i] = 1;
    }
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void add(int a, int b){
    sz[a]++;
    parent[b] = a;

    n++;
    return;
}

void del(int a){
    sz[a] = 0;
    a = find(a);
    sz[a]--;    
    return;
}

int main(){
    freopen(".\\txt\\TREE.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    makeSet();

    while(q--){
        string str;
        cin>>str;
        int u = stoi(str.substr(1));
        
        if(str[0] == '+') add(u, n);
        else if(str[0] == '-') del(u);
        else cout<<sz[u]<<el;
    }

    return 0;
}