#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

int q;
ll n;

bool check(ll x){
    int tmp = (int)sqrt(x);
    return 1LL * tmp * (tmp + 1) == x;
}

int main(){
    freopen("SPECIAL.INP", "r", stdin);
    freopen("SPECIAL.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    while(q--){
        cin>>n;
        set<int> res;

        for(ll i = 1; i * i * i <= n; i++){
            if(n % (i * (i + 1)) == 0) res.insert(i);
            if(n % i == 0)
                if(check(n / i)) 
                    res.insert((int)sqrt(n / i));
        }

        if(res.empty()) cout<<-1;
        else for(int x : res) cout<<x<<" ";
        cout<<el;
    }

    return 0;
}