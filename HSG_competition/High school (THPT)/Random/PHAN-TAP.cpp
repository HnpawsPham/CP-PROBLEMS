#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define bit(i, j) ((i >> j)&1)
 
int n, cnt = 0;
const int maxn = 35;
ll a[maxn];
ll dis = LLONG_MAX, tsum = 0;
vector<ll> g1, g2;

// void bruteforce(int i, ll sum1, ll sum2){
//     if(i == n) {
//         ll d = abs(sum1 - sum2);
        
//         if(dis > d){
//             dis = d;
//             cnt = 1;
//         }
//         else if(d == dis) cnt++;
 
//         return;
//     }
 
//     bruteforce(i + 1, sum1 + a[i], sum2);
//     bruteforce(i + 1, sum1, sum2 + a[i]);
 
//     return;
// }
 
void sol1(int i, ll sum){
    if(i == n / 2){
        g1.push_back(sum);
        return;
    }

    sol1(i + 1, sum);
    sol1(i + 1, sum + a[i]);
}

void sol2(int i, ll sum){
    if(i == n){
        g2.push_back(sum);
        return;
    }

    sol2(i + 1, sum);
    sol2(i + 1, sum + a[i]);
}

void combine(ll x, int sz){
    int pos = -1, l = 0, r = sz - 1;
    ll ss = tsum - 2 * x;

    while(l <= r){
        int mid = (l + r)/2;
        if(2 * g2[mid] <= ss){
            pos = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    if(pos == -1) return;
    ll k = abs(ss - 2 * g2[pos]);
    if(abs(ss - 2 * g2[pos + 1]) < k) k = abs(ss - 2 * g2[++pos]); 

    if(k > dis) return;
    int d = 0;
    l = pos - 1, r = pos;
    while(l >= 0 && abs(ss - 2 * g2[l]) == k){
        l--;
        d++;
    }
    while(r < sz && abs(ss - 2 * g2[r]) == k){
        r++;
        d++;
    }
    
    if(k < dis){
        dis = k;
        cnt = d;
    }
    else cnt += d;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        tsum += a[i];
    }

    sol1(0, 0);
    sol2(n /2, 0);

    sort(g2.begin(), g2.end());
    int sz = g2.size();

    for(ll x : g1) combine(x, sz);
    cout<<dis<<" "<<cnt/2;

    return 0;
} 