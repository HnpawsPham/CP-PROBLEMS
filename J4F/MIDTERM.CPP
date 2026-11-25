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
int a[maxn], t[maxn];
int last[maxn];

bool check(int k){
    memset(last, -1, sizeof last);

    for(int i = 0; i < k; i++)
        if(a[i]) last[a[i]] = i;
    
    for(int i = 1; i <= m; i++)
        if(last[i] == -1)
            return 0;

    int free = 0;
    for(int i = 0; i < k; i++){
        if(a[i] && last[a[i]] == i){
            if(free < t[a[i] - 1]) 
                return 0;
            free -= t[a[i] - 1];
        }
        else free++;
    }
    return 1;
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
    for(int j = 0; j < m; j++) cin>>t[j];

    int l = m, r = n, mid, res = -1;
    while(l <= r){
        mid = (l + r) / 2;
        if(check(mid)){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    } 
    cout<<res;
    return 0;
}