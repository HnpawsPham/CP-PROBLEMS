#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
#define taskname "DENDUONG"

int d1, a, d2, b, k;
const int maxl = 1e5 + 1;

ll lcm(int a, int b){
    return a * b / __gcd(a, b);
}

namespace sub1{
    void sol(){
        int res = 0;
        for(int i = max(a, b); i < maxl; i++){
            int cnt = 0;
            for(int x = i; x <= i + k; x++)
                if((x - a) % d1 == 0 && (x - b) % d2 == 0)
                    cnt++;
            res = max(res, cnt);
        }
        cout<<res;
    }
}

namespace sub2{
    void sol(){
        bool found = 0;
        ll d = lcm(d1, d2);

        for(ll x = max(a, b); x <= max(a, b) + d; x++){
            if((x - a) % d1 == 0 && (x - b) % d2 == 0){
                found = 1;
                break;
            }
        }
        cout<<found * (k / d + 1);
    }
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>d1>>a>>d2>>b>>k;

    if(k <= 100)
        sub1::sol();
    else if(d1 <= 100 && d2 <= 100)
        sub2::sol();
    return 0;
}