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
#define taskname "CSCH"

int n, q;
const int maxn = 1e5 + 5;
int a[maxn];
vector<pii> que;

int brute(int l, int r){
    ll cnt = 0;
    for(int i = l - 1; i < r; i++)
        for(int j = l - 1; j < r; j++)
            if(a[i] % a[j] == 0) cnt++;
    return cnt;
}

namespace sub1{
    void sol(){
        for(const auto& [l, r]: que)
            cout<<brute(l, r)<<el;
    }
};

namespace sub2{
    vi div[maxn];
    int check[maxn] = {0};

    void prepare(){
        for(int i = 1; i < maxn; i++)
            for(int j = i; j < maxn; j += i)
                div[j].push_back(i);
    }

    void sol(){
        prepare();

        for(const auto& [l, r] : que){
            ll cnt = 0;

            for(int i = l - 1; i < r; i++)
                check[a[i]]++;

            for(int i = l - 1; i < r; i++)
                for(int x : div[a[i]])
                    cnt += check[x];

            for(int i = l - 1; i < r; i++)
                check[a[i]] = 0;

            cout<<cnt<<el;
        }
    }
}

namespace sub3{
    int check[maxn] = {0};

    void sol(){
        for(const auto& [l, r] : que){
            ll cnt = 0;

            for(int i = l - 1; i < r; i++)
                check[a[i]]++;

            for(int i = 1; i < maxn; i++){
                if(!check[i]) continue;
                for(int j = i; j < maxn; j += i)
                    cnt += check[i] * check[j];
            }

            for(int i = l - 1; i < r; i++)
                check[a[i]] = 0;

            cout<<cnt<<el;
        }
    }
}

namespace sub5{
    bool checksub = 1;
    int mul[maxn] = {0};
    int check[maxn] = {0};
    vi div[maxn];

    void prepare(){
        for(int i = 1; i < maxn; i++)
            for(int j = i; j < maxn; j += i)
                div[j].push_back(i);
    }

    void sol(){
        prepare();

        int prev = 0;
        ll res[n + 1];
        memset(res, 0, sizeof res);

        for(int i = 0; i < n; i++){
            res[i + 1] = res[i] + 1;
            res[i + 1] += mul[a[i]];

            for(int x : div[a[i]])
                res[i + 1] += check[x];

            check[a[i]]++;
            for(int x : div[a[i]])
                mul[x]++;
        }

        for(const auto& [l, r]: que)
            if(l == 1) cout<<res[r]<<el;
            else cout<<brute(l, r)<<el;
    }
};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < q; i++){
        int l, r;
        cin>>l>>r;
        que.push_back({l, r});
        if(que[i].fi != 1) sub5::checksub = 0;
    }

    if(n <= 100 && q <= 100)
        sub1::sol();
    else if(sub5::checksub)
        sub5::sol();
    else sub3::sol();
    // sub2::sol();
    return 0;
}