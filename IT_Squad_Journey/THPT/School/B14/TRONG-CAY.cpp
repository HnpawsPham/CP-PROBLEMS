#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int , float>

int n, m;

int main(){
    freopen(".\\txt\\TRONG-CAY.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vector<pii> a;
    for(int i =0;i<n;i++){
        int t;
        float x;
        cin>>t>>x;
        a.push_back({t, i});
    }
    vector<pii> b = a;
    sort(b.begin(),b.end());

    int res = 0;
    for(int i = 0; i < n;i++){
        if(a[i] != b[i]) res++;
    }
    cout<<res<<el;

    return 0;
}