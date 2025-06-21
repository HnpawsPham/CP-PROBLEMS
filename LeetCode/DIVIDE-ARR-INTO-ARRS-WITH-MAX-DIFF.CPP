#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<vi> res;

    sort(a.begin(), a.end());

    for(int i = 0; i < n - 2; i += 3){
        if(a[i + 2] - a[i] > k){
            res.clear();
            break;
        }

        res.push_back({a[i], a[i + 1], a[i + 2]});
    }

    for(vi v : res){
        for(int x : v) cout<<x<<" ";
        cout<<el;
    }
    return 0;
}