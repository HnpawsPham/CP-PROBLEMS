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

    int res = 0;
    for(int x : a){
        int cnt = 2, sum = 1 + x;
        for(int i = 2; i <= sqrt(x); i++){
            if(x % i == 0){
                sum += i;
                cnt++;
                if(i != x / i){
                    cnt++;
                    sum += x / i;
                }
            }
            if(cnt > 4) break;
        }
        if(cnt == 4) res += sum;
    }
    cout<<res;
    return 0;
}

// 3
// 21 4 7

// 2
// 21 21