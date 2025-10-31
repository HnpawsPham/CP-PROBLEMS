#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    bool check[104] = {0};
    vi res;
    for(int x : a){
        if(check[x]) res.push_back(x);
        else check[x] = 1;
    }
    for(int x : res) cout<<x<<" ";
    return 0;
}