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

int sol(){
    int n;
    cin>>n;
    int a[n], cnt2 = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        cnt2 += (a[i] == 2);
    }
    
    int d = 0;
    for(int i = 0; i < n; i++){
        d += (a[i] == 2);
        if(d == cnt2 - d) return i + 1;
    }
    return -1;
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