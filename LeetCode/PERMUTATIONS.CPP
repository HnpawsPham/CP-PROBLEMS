#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    sort(a.begin(), a.end());
    vector<vector<int>> res;

    do res.push_back(a);
    while(next_permutation(a.begin(), a.end()));

    for(auto v : res){
        for(int x : v) cout<<x<<" ";
        cout<<el;
    }
    return 0;
}