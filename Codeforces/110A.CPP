#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll x;
    cin>>x;

    int cnt = 0;
    while(x > 0){
        if(x % 10 == 4 || x % 10 == 7)
            cnt++;
        x /= 10;
    }

    if(cnt == 0) return cout<<"NO", 0;
    while(cnt > 0){
        if(cnt % 10 != 4 && cnt % 10 != 7) return cout<<"NO", 0;
        cnt /= 10;
    }
    cout<<"YES";
    return 0;
}