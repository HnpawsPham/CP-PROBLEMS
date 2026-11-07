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
#define taskname "CAU2"

int n;
const int maxn = 3e4 + 5;
int a[maxn];
ll p[maxn];

void sub1(){
    ll sum = 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            sum += 1LL * a[i] * a[j];
    cout<<sum;
}

void sub2(){
    p[0] = 0;
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i - 1];

    ll sum = 0;
    for(int i = 0; i < n; i++)
        sum += 1LL * a[i] * (p[n] - p[i + 1]);
    cout<<sum;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    memset(a, 0, sizeof a);
    for(int i = 0; i < n; i++)
        cin>>a[i];

    if(n <= 3000) sub1();
    else sub2();
    // sub2();
    return 0;
}

// 4
// 2 5 1 2