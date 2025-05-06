#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<int> res;
    for(int i = 0; i < n; i++)
        res.push_back(a[a[i]]);

    for(int x : res) cout<<x<<" ";
    return 0;
}