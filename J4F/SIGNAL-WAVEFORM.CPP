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
int a[maxn];

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

    int l = 0, prev = 0;;
    ll cnt = 0;
    bool inc = 0;
    for(int i = 1; i < n; i++){
        if(a[i] != a[i - 1]){
            bool dir = (a[i] > a[i - 1]);
            if(dir == inc)
                l = prev;

            inc = dir;
            prev = i;
        }
        cnt += i - l;
    }
    cout<<cnt;
    return 0;
}