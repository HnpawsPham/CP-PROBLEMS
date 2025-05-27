#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int n;
vi check;

void dfs(int u){
    check[u] = 1;

    for(int v : a[u])
        if(!check[v])
            dfs(v);

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    check.assign(n, 0);

    vector<vi> t(n, vi(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin>>t[i][j];

    vector<vi> a(n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j && t[i][j]){
                a[i].push_back(j);
                a[j].push_back(i);
            }

    int cnt = 0;
    for(int i = 0; i < n; i++)
        if(!check[i]){
            dfs(i);
            cnt++;
        }
    cout<<cnt;
    return 0;
}