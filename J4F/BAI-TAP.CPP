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

int n, m;
const int maxn = 1e5 + 5;
int a[maxn];

bool check1(int t){
    int cnt = 1;
    for(int i = 1; i < n; i++)
        if(a[i] - a[i - 1] <= t){
            cnt++;
            if(cnt >= m) return 1;
        }
        else cnt = 1;
    return (cnt >= m);
}

bool check2(int t){
    int cnt = 0;
    for(int i = 1; i < n; i++){
        if(a[i] - a[i - 1] <= t) continue;
        if(t == 0) return 0;
        cnt += (a[i] - a[i - 1] - 1) / t;
    }
    return cnt <= m - n;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);

    int lim= 0;
    for(int i = 1; i < n; i++)
        lim = max(lim, a[i] - a[i - 1]);

    if(n == m) cout<<lim;
    else if(n > m){
        int l = 0, r = lim, mid, res = lim;
        while(l <= r){
            mid = (l + r) / 2;
            if(check1(mid)){
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        } 
        cout<<res;
    }
    else{
        int l = 0, r = lim, mid, res = lim;
        while(l <= r){
            mid = (l + r) / 2;
            if(check2(mid)){
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        } 
        cout<<res;
    }
    return 0;
}