#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc = 1;

string sol(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    bool has1 = 0;
    for(int x : a)
        if(x == 1) has1 = 1;
    
    if(!has1) return "YES";
    sort(a, a + n);
    for(int i = 1; i < n; i++)
        if(a[i] - a[i - 1] == 1) return "NO";
    return "YES";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}