#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pli pair<ll, int>

int n, k;
vector<ll> palin;
map<ll, int> mp;
set<map<ll, int>> s;
ll fact_n, fact_n1;

void make(int i, bool first, string s) {
    if (i > (n % 2 == 0 ? n / 2 - 1 : n / 2)) {
        for (int j = 0; j < n / 2; j++)
            s += s[n / 2 - j - 1];

        ll num = stoll(s);
        if (num % k == 0) palin.push_back(num);
        return;
    }

    for (int j = 0; j < 10; j++) {
        if (!first) make(i + 1, false, s + to_string(j));
        else if (j > 0) make(i + 1, false, s + to_string(j));
    }
    return;
}

ll fact(ll x){
    ll res = 1;
    for(int i = 2; i <= x; i++) res *= i;
    return res;
}

ll permu(){
    ll res = fact_n;
    for(pli x : mp)
        res /= fact(x.second);
    return res;
}

ll permu0(){
    if(!mp[0]) return 0;
    mp[0]--;

    ll res = fact_n1;
    for(pli x : mp)
        res /= fact(x.second);
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    ll cnt = 0;
    if(n == 1) {
        for(int i = k; i < 10; i+=k) cnt++;
        return cout<<cnt, 0;
    }

    make(0, 1, "");
    fact_n = fact(n);
    fact_n1 = fact(n - 1);
    // for(ll x : palin) cout<<x<<el;
    make(0, 1, ""); 
    fact_n = fact(n);
    fact_n1 = fact(n - 1);

    for (ll x : palin) {
        mp.clear();
        while (x > 0) {
            mp[x % 10]++;
            x /= 10;
        }

        if(s.count(mp)) continue;

        s.insert(mp);
        cnt += permu() - permu0();
    }
    cout<<cnt;
    return 0;
}