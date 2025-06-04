#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int n, m;
vector<vi> a;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vector<vi> t(m);
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        t[i].push_back(u);
        t[i].push_back(v);
    }

    // SOL 1
    // a.resize(n + 1);

    // for(const vi& v : t)
    //     a[v[0]].push_back(v[1]);    

    // vi cnt(n + 1, 0);
    // for(int u = 1; u <= n; u++)
    //     for(const int& v : a[u])
    //         cnt[v]++;

    // int res = -1;
    // for(int i = 1; i <= n; i++)
    //     if(a[i].size() == 0 && cnt[i] == n - 1){
    //         res = i;
    //         break;
    //     }

    // SOL2
    vi in(n + 1, 0), out(n + 1, 0);

    for(const vi& v : t){
        in[v[1]]++;
        out[v[0]]++;
    }

    int res = -1;

    for(int i = 1; i <= n; i++)
        if(out[i] == 0 && in[i] == n - 1){
            res = i;
            break;
        }
    cout<<res;
    return 0;
}