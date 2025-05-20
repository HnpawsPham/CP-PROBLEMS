#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    vector<vi> q;

    while(m--){
        int l, r;
        cin>>l>>r;
        q.push_back({l, r});
    }

    int d[n + 1] = {0};
    for(const vi &v : q){
        int l = v[0], r = v[1];

        d[l]++;
        d[r + 1]--; 
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += d[i];
        if(sum < a[i]) return cout<<0, 0;
    }
    
    cout<<1;
    return 0;
}