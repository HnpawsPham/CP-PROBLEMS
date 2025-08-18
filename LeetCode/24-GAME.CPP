#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
#define vdb vector<db>

int n = 4;

bool sol(vdb& v){
    int m = v.size();
    if(m == 1) {
        if(v[0] > 23 && v[0] < 25) cout<<v[0]<<'\n';
        return (fabs(v[0] - 24) < 1e-6);
    }

    for(int i = 0; i < m; i++)
        for(int j = i + 1; j < m; j++){
            vdb tmp;
            for(int x = 0; x < m; x++)
                if(x != i && x != j) tmp.push_back(v[x]);

            vdb opt = {v[i] - v[j], v[j] - v[i], v[i] + v[j], v[i] * v[j]};
            if(v[i] != 0) opt.push_back(v[j] / v[i]);
            if(v[j] != 0) opt.push_back(v[i] / v[j]);

            for(db x : opt){
                tmp.push_back(x);
                if(sol(tmp)) return 1;
                tmp.pop_back();
            }
        }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    vdb tmp(a.begin(), a.end());
    cout<<sol(tmp);
    return 0;
}