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
int res = n + 2;

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

    if(n < 3) return cout<<(a[0] != 0), 0;

    int inc = 0, dec = 0, pos0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0) pos0 = i;

        if((a[i] > a[(i + 1) % n]))
            dec++;
        else inc++;   
    }
    if(min(inc, dec) > 1) return cout<<-1, 0;

    if(inc == 1 && pos0 == n - 1) return cout<<1, 0;
    if(inc == 1 && pos0 == 0) return cout<<2, 0;
    if(inc == 1) return cout<<min(pos0 + 2, n - pos0), 0;

    if(dec == 1 && pos0 == n - 1) return cout<<min(pos0, 3), 0;
    return cout<<(pos0 != 0) * min(pos0, n - pos0 + 2), 0;
    return 0;
}

// 3 
// 0 2 1

// 3
// 1 0 2

// 4
// 2 0 1 3