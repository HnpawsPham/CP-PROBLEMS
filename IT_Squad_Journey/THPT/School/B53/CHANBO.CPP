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
#define taskname "CHANBO"

int n, c;
vi a;

bool check(int t){
    int cnt = 1, prev = a[0];
    for(int i = 1; i < n; i++)
        if(a[i] - prev >= t){
            prev = a[i];
            cnt++;
        }
    return cnt >= c;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin>>n>>c;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());

    int l = 0, r = 1e9 + 5, mid, res;    
    while(l <= r){
        mid = (l + r) / 2;
        
        if(check(mid)){
            l = mid + 1;
            res = mid;
        }
        else r = mid - 1;
    }
    cout<<res;
    return 0;
}

// 5 3
// 1
// 2
// 8
// 4
// 9