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
    int minn = 1e5 + 5;
    while(n--){
        int x;
        cin>>x;
        minn = min(minn, abs(x));
    }
    cout<<minn;
    return 0;
}