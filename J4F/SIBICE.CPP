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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, w, h;
    cin>>n>>w>>h;
    while(n--){
        int x;
        cin>>x;
        if(x <= (int)sqrt(w * w + h * h)) cout<<"DA"<<el;
        else cout<<"NE"<<el;
    }
    return 0;
}

// 5 3 4
// 3
// 4
// 5
// 6
// 7

// 2 12 17
// 21
// 20