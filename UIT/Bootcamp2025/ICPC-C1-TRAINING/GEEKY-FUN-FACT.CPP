#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc, n;
bool check(int x){
    int mask = 0;
    while(x){
        int d = x % 10;
        if(mask & (1<<d)) return 0;
        mask |= (1<<d);
        x /= 10;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        int x;
        cin>>x;
        while(!check(x + 1)) x++;
        cout<<x + 1<<el;
    }

    return 0;
}