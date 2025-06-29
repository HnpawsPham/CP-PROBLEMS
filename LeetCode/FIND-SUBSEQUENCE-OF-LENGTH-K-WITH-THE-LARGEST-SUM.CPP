#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int t[n];
    for(int i = 0; i < n; i++) cin>>t[i];

    vector<pii> a;
    for(int i = 0; i < n; i++)
        a.push_back({t[i], i});

    sort(a.begin(), a.end(), greater<pii>());
    bool check[n] = {0};

    for(int i = 0; i < k; i++)
        check[a[i].se] = 1;

    vector<int> res;
    for(int i = 0; i < n; i++)
        if(check[i]) res.push_back(t[i]);

    for(int x : res) cout<<x<<" ";
    return 0;
}