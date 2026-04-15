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

    int n, st;
    string target;
    cin>>n>>target>>st;
    string a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int minn = n + 5;
    for(int i = 0; i < n; i++)
        if(a[i] == target) 
            minn = min(minn, min(abs(i - st), abs(n - abs(i - st))));
    cout<<(minn == n + 5 ? -1 : minn);
    return 0;
}

// 5 hello 1
// hello i am leetcode hello