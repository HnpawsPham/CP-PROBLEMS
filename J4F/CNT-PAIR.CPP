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

    int n;
    cin>>n;
    int odd = 0, even = 0;
    while(n--){
        int x;
        cin>>x;
        if(x % 2 == 0) even++;
        else odd++;
    }
    cout<<1LL * odd * (odd - 1) / 2 + 1LL * even * (even - 1) / 2;
    return 0;
}