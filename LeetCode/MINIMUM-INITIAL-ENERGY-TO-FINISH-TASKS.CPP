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

bool comp(const vi& a, const vi& b){
    return a[1] - a[0] > b[1] - b[0];
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
    vector<vi> a(n, vi(2));
    for(int i = 0; i < n; i++) 
        cin>>a[i][0]>>a[i][1];

    sort(a.begin(), a.end(), comp);
    // int res = 0, sum = 0;

    // for(int i = 0; i < n; i++){
    //     if(sum < a[i][1]){
    //         res += a[i][1] - sum;
    //         sum = a[i][1];
    //     }
    //     sum -= a[i][0];
    // }
    // cout<<res;

    int res = a[0][1], sum = res; 
    for(int i = 0; i < n; i++){ 
        if(sum >= a[i][1]){ 
            sum -= a[i][0];
            if(sum < 0) res += 0 - sum; 
        } 
        else{ 
            res += a[i][1] - sum; 
            sum = a[i][1] - a[i][0]; 
        } 
    } 
    cout<<res;
    return 0;
}

// 3
// 1 2
// 2 4
// 4 8

// 5
// 1 3
// 2 4
// 10 11
// 10 12
// 8 9