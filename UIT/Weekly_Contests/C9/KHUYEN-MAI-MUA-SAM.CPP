#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int t, n, k;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    for(int i = 1; i <= t; i++){
        cin>>n>>k;
        cout<<"KH "<<i<<", "<<n - 1<<" san pham:";
        string res = " ";
        for(int j = 1; j <= n; j++) 
            if(j != k) 
                res = res + to_string(j) + ' ';
        
        if(!res.empty()) res.pop_back();
        cout<<res;
        cout<<'.'<<el;
    }
    return 0;
}