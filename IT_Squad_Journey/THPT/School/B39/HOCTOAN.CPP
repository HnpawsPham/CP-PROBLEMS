#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

vi div(int x){
    vi res;
    for(int i = 1; i * i <= x; i++)
        if(x % i == 0){
            res.push_back(i);
            if(x / i != i) 
                res.push_back(x / i);
        }
    return res;
}

int main(){
    // freopen("HOCTOAN.INP", "r", stdin);
    // freopen("HOCTOAN.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin>>a>>b;
    if(b % a != 0) return cout<<-1, 0;

    int m = b / a, minn = INT_MAX;
    int x = -1, y = -1;

    for(int i = 1; i * i <= m; i++){
        if(m % i != 0) continue;
        int j = m / i;
        if(__gcd(i, j) != 1) continue;

        int tx = a * i, ty = a * j;
        if(tx > ty) swap(tx, ty);

        int sum = tx + ty;
        if(sum < minn || (sum == minn && tx < x)){
            minn = sum;
            x = tx;
            y = ty;
        }
    }
    if(x == -1) cout<<-1;
    else cout<<x + y<<el<<x<<" "<<y; 
    return 0;
}

// 6 36

// 2 5

// 3 831

// 1 161