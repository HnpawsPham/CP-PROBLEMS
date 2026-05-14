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

const int maxn = 3e5 + 5;
bitset<maxn> nprime;

void sieve(){
    nprime[1] = nprime[0] = 1;
    for(int i = 2; i * i < maxn; i++)
        if(!nprime[i])
            for(int j = i * i; j < maxn; j += i)
                nprime[j] = 1;
    return;
}

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
    int cnt2 = 0, cnt1 = 0;
    while(n--){
        int x;
        cin>>x;
        cnt2 += (x == 2);
        cnt1 += (x == 1);
    }

    vi a;
    if(cnt2 > 0){
        a.push_back(2);
        cnt2--;
    }
    if(cnt1 > 0){
        a.push_back(1);
        cnt1--;
    }
    while(cnt2--) a.push_back(2);
    while(cnt1--) a.push_back(1);

    sieve();
    int sum = 0, cnt = 0;
    for(const int& x : a){
        sum += x;
        if(!nprime[sum]) cnt++;
    }
    cout<<cnt;
    return 0;
}