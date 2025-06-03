#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int n, m;

void inp(vi& a){
    for(int i = 0; i < n; i++) cin>>a[i];
    return;
}

void inp2(vector<vi>& a){
    for(int i = 0; i < n; i++){
        int m, x;
        cin>>m;
        for(int j = 0; j < m; j++){
            cin>>x;
            a[i].push_back(x);
        }
    }
    return;
}

int sol(vector<bool> &status, vi& init, vi& val, vector<vi>& key, vector<vi>& container){
    queue<int> q;
    int res = 0;
    vector<bool> has(n, 0), check(n, 0);

    // collect initial boxes
    for(const int& x : init){
        has[x] = 1;

        if (status[x]) {
            q.push(x);
            res += val[x];
            check[x] = 1;
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : key[u]){
            status[v] = 1;
            
            if(has[v] && !check[v]){
                res += val[v];
                check[v] = 1;
                q.push(v);
            }
        }

        for(int v : container[u]){
            has[v] = 1;

            if(!status[v] || check[v]) continue;
            
            q.push(v);
            res += val[v];
            check[v] = 1;
        }
    }

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vector<bool> status(n);
    vi val(n), init;
    vector<vi> key(n), container(n);

    // INPUT
    int x;
    for(int i = 0; i < n; i++){
        cin>>x;
        status[i] = x;
    }
    inp(val);

    cin>>m;
    while(m--){
        cin>>x;
        init.push_back(x);
    }
    inp2(key);
    inp2(container);

    // SOL
    cout<<sol(status, init, val, key, container);
    return 0;
}