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
    sort(a, a + n);

    int minn = 2e9 + 5, cnt = 0;
    for(int i = 1; i < n; i++)
        if(a[i] - a[i - 1] < minn){
            minn = a[i] - a[i - 1];
            cnt = 1;
        }
        else if(a[i] - a[i - 1] == minn)
            cnt++;

    cout<<minn<<" "<<cnt;
    return 0;
}