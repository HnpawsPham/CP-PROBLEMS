#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc;

string sol(){
    int n;
    string a, b;
    cin>>n>>a>>b;
    int cnta = 0, cntb = 0;

    for(int i = 0; i < n; i++){
        if(a[i] > b[i]) cnta++;
        else if(a[i] < b[i]) cntb++;
    }

    if(cnta > cntb) return "RED";
    else if(cntb > cnta) return "BLUE";
    return "EQUAL";
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