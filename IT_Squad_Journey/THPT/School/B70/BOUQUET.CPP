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
#define taskname "BOUQUET"

struct flower{
    int l, r, id;
    flower(){};
    flower(int l1, int r1, int id1): l(l1), r(r1), id(id1){};
};

int n;
const int maxn = 2e5 + 5;
flower a[maxn];

namespace sub1{
    void sol(){
        int last = -1, res = 0;
        for(int i = 0; i < n; i++)
            if(max(0, i - a[i].l) > last){
                res++;
                last = i;
            }
        cout<<res;
    }
}

namespace sub2{
    void sol(){
        
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

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i].l>>a[i].r;
        a[i].id = i;
    }

    sub1::sol();
    return 0;
}