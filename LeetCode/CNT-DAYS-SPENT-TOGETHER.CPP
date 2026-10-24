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

int sum[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string sa, ea, sb, eb;
    cin>>sa>>ea>>sb>>eb;

    sa = max(sa, sb);
    ea = min(ea, eb);
    if(sa > ea) return cout<<0, 0;

    int endmonth = (ea[0] - '0') * 10 + (ea[1] - '0');
    int res = sum[endmonth - 1] + (ea[3] - '0') * 10 + (ea[4] - '0');

    int stmonth = (sa[0] - '0') * 10 + (sa[1] - '0');
    res -= sum[stmonth - 1] + (sa[3] - '0') * 10 + (sa[4] - '0') - 1;
    cout<<res;
    return 0;
}

// 08-15
// 08-18
// 08-16
// 08-19

// 10-01
// 10-31
// 11-01
// 12-31