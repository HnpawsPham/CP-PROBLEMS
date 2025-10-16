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

    int n, p, q;
    cin>>n>>p;
    int cnt[n + 1] = {0};
    while(p--){
        int x;
        cin>>x;
        cnt[x] = 1;
    }    
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        cnt[x] = 1;
    }
    for(int i = 1; i <= n; i++)
        if(!cnt[i]) return cout<<"Oh, my keyboard!", 0;
    cout<<"I become the guy.";
    return 0;
}