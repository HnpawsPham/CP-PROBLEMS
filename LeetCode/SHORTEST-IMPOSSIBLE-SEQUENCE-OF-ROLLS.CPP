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

bitset<100005> check;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int len = 0, cnt = 0;
    check.reset();

    for(int i = 0; i < n; i++){
        if(check[a[i]]) continue;
        check[a[i]] = 1;
        cnt++;

        if(cnt == k){
            check.reset();
            cnt = 0;
            len++;
        }
    }
    cout<<len + 1;
    return 0;
}

// 9 4
// 4 2 1 2 3 3 2 4 1