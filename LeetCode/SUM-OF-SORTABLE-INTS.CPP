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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int p[n];
    for(int i = 0; i < n; i++)
        p[i] = 1;

    for(int i = 1; i < n; i++)
        if(a[i] >= a[i - 1])
            p[i] = p[i - 1] + 1;

    int res = 0;
    for(int k = 1; k <= n; k++){
        if(n % k) continue;

        bool ok = 1;
        int prev = -1;

        for(int i = 0; i < n && ok; i+=k){
            int minn = a[i];
            int maxx = a[i + k - 1];

            if(k > 1){
                bool gud = 0;
                if(p[i + k - 1] >= k) gud = 1;
                // bound       max 2 hills              non dec
                if(pos < i || p[pos] < pos - i + 1 || a[i] < a[i + k - 1]){
                    ok = 0;
                    continue;
                }
                if(!gud) ok = 0;
            }

            if(minn < prev) ok = 0;
            prev = maxx;
        }
        if(ok) res += k;
    }
    cout<<res;
    return 0;
}