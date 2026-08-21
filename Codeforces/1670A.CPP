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

int tc = 1;

string sol(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int mid = 0;
    for(const int& x: a)
        mid += x < 0;
    
    if(mid == 0 || mid == n){
        for(int i = 1; i < n; i++)
            if(a[i] < a[i - 1]) return "NO";
        return "YES";
    }

    int cntn = a[mid] < 0, cntp = a[0] > 0;
    for(int i = 1; i < mid; i++){
        cntp += a[i] > 0;
        if(abs(a[i]) > abs(a[i - 1]))
            return "NO";
    }

    for(int i = mid + 1; i < n; i++){
        cntn += a[i] < 0;
        if(abs(a[i]) < abs(a[i - 1]))
            return "NO";
    }
    return (cntp == cntn ? "YES" : "NO");
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}