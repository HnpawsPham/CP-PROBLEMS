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

int n, sum = 0;
const int maxn = 105;
int a[maxn];

bool check(int t){
    int sum1 = 0;
    for(int i = 0; i < n; i++)
        sum1 += t - a[i];
    return sum1 > sum;
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
    for(int i = 0; i < n; i++){
        cin>>a[i];
        sum += a[i];
    }

    int l = *max_element(a, a + n), r = 205, mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout<<l;
    return 0;
}