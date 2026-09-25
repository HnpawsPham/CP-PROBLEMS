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
//#define taskname ""

int n;
const int maxn = 2e5 + 5;
const int maxp = 2e6 + 5;
int a[maxn], cnt[maxp];
vi spec;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];

    for(int i = 1; i < 10; i++)
        spec.push_back(i);

    for(int i = 11; i < maxp; i++){
        int x = i, prev = -1;
        bool ok = 1;
        while(x > 0){
            if(prev != -1 && (x % 10) != prev){
                ok = 0;
                break;
            }
            prev = x % 10;
            x /= 10;
        }
        if(ok) spec.push_back(i);
    }

    memset(cnt, 0, sizeof cnt);
    ll res = 0;

    for(int i = 0; i < n; i++){
        for(const int& x: spec) 
            if(a[i] <= x)
                res += cnt[x - a[i]];
        cnt[a[i]]++;
    }
    cout<<res;
    return 0;   
}