#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, l, u = 0, v = 0;

int d(int x, int y){
    return (u - x) * (u - x) + (v - y) * (v - y);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    cin>>n>>l>>x>>y;
    cout<<"1 ";
    n--;

    while(n--){
        cin>>x>>y;
        if(d(x, y) < d(-x, -y)) {
            cout<<1<<" ";
            u -= x;
            v -= y;
        }
        else {
            cout<<2<<" ";
            u += x;
            v += y;
        }
    }
    return 0;
}