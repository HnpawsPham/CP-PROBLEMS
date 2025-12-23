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
    return a[1] < b[1]; 
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
    vector<vi> a(n, vi(3));
    for(int i = 0; i < n; i++)
        cin>>a[i][0]>>a[i][1]>>a[i][2];

    vector<vi> b = a;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), comp);

    int res = 0, maxx = 0;
    for(int i = 0, j = 0; i < n; i++){
        res = max(res, a[i][2]);
        while(j < n && b[j][1] < a[i][0]){
            maxx = max(maxx, b[j][2]);
            j++;
        }
        res = max(res, maxx + a[i][2]);
    }
    cout<<res;
    return 0;
}

// 3
// 1 3 2
// 4 5 2
// 2 4 3

// 3
// 1 3 2
// 4 5 2
// 1 5 5 

// 3
// 1 5 3
// 1 5 1
// 6 6 5