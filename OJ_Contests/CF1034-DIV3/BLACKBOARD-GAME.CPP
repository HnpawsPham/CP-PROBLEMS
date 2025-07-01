#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int t, n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        if(n % 4 == 0) cout<<"bob"<<el;
        else cout<<"alice"<<el;
    }

    return 0;
}