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
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int cnt = 0;
    while(1){
        bool ok = 1;
        for(int i = 1; i < a.size(); i++)
            if(a[i] < a[i - 1]){
                ok = 0;
                break;
            }
        if(ok) break;

        int minn = 100000005, pos;
        for(int i = 1; i < a.size(); i++){
            if(a[i] + a[i - 1] < minn){
                minn = a[i] + a[i - 1];
                pos = i;
            }
        }

        a.insert(a.begin() + pos, a[pos] + a[pos - 1]);
        a.erase(a.begin() + pos + 1);
        a.erase(a.begin() + pos - 1);
        cnt++;
    }
    cout<<cnt;
    return 0;
}

// 4
// 5 2 3 1

// 3
// 1 2 2