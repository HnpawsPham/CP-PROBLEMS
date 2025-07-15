#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vector<vi> flower(n);
    for(int i = 0; i < n; i++){
        int l, r;
        cin>>l>>r;
        flower[i] = {l, r};
    }

    cin>>m;
    vi t(m);
    for(int i = 0; i < m; i++) cin>>t[i];

    vi l(n), r(n);
    for(int i = 0; i < n; i++){
        l[i] = flower[i][0];
        r[i] = flower[i][1];
    }

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    vi res(m);
    for(int i = 0; i < m; i++){
        int val = upper_bound(l.begin(), l.end(), t[i]) - l.begin();
        val -= lower_bound(r.begin(), r.end(), t[i]) - r.begin();
        res[i] = val;
    }
    for(int x : res) cout<<x<<" ";
    return 0;
}

// 4
// 1 6
// 3 7
// 9 12
// 4 13
// 4
// 2 3 7 11
