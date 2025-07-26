#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define vi vector<int>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<vi> conflict(m);
    for(int i = 0; i < m; i++) {
        int l, r;
        cin>>l>>r;
        conflict[i] = {l, r};
    }

    vector<vi> a(n + 1);
    for(const vi& v : conflict)
        a[max(v[0], v[1])].push_back(min(v[0], v[1]));
    
    ll res = 0;
    int prevl = 0, l = 0;
    vector<ll> remove(n + 1, 0);
    
    for(int r = 1; r <= n; r++){
        for(int left : a[r]){
            if(left > l){
                prevl = l;
                l = max(l, left);
            }
            else if(l > prevl && left > prevl)
                prevl = left;
        }
        res += r - l;
        remove[l] += l - prevl;
    }
    cout<<1LL * res + *max_element(remove.begin(), remove.end());
    return 0;
}
// 4 2
// 2 3
// 1 4