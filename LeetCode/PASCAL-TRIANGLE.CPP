#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    vector<vector<int>> a;
    a.push_back({1});

    for(int i = 2; i <= n; i++){
        vector<int> v;
        v.push_back(1);

        int sz = a.back().size();
        
        for(int i = 0; i < sz - 1; i++)
            v.push_back(a.back()[i] + a.back()[i + 1]);
        
        v.push_back(1);
        a.push_back(v);
    }

    for(vector<int> v : a){
        for(int x : v)
            cout<<x<<" ";
        cout<<el;
    }

    return 0;
}