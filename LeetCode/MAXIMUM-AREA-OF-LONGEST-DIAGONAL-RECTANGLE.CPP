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
    vector<vi> a(n, vi(2));
    for(int i = 0; i < n ;i++) cin>>a[i][0]>>a[i][1];

    db maxx = 0,;
    int res = 0;
    for(const auto& v : a){
        double d = sqrt(v[0] * v[0] + v[1] * v[1]);
        int area = v[0] * v[1];
        
        if(d > maxx || d >= maxx && res < area){
            maxx = d;
            res = area;
        } 
    }
    cout<<res;
    return 0;
}