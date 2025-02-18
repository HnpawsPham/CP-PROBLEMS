#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int t, q;
ll n, m1;

ll calc(ll pos, int dir){
    pos += dir;
    if(pos < 1) pos = 1;
    if(pos > n) pos = n;
    return pos;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>t;
    while(t--){
        cin>>n>>m1>>q;
        unordered_set<ll> s;
        ll m2 = m1;

        while(q--){
            ll pos;
            cin>>pos;

            if(pos == m1 || pos == m2) s.insert({(ll)1, n});
            if(m1 == m2){
                if(pos < m1) s.insert({m1, m2 = calc(m1, -1)});
                if(pos > m1) s.insert({m1, m2 = calc(m1, 1)});
            }
            else{
                s.insert({m1, m2});
                if(m1 > m2) swap(m1, m2);

                if(pos < m1) s.insert({m1 = calc(m1, -1)});
                if(pos < m2) s.insert({m2 = calc(m2, -1)});
                if(pos > m1) s.insert({m1 = calc(m1, 1)});
                if(pos > m2) s.insert({m2 = calc(m2, 1)});
            }
            cout<<s.size()<<" ";
        }
        cout<<el;
    }

    return 0;
}