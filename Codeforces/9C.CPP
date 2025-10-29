#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, cnt = 0;
void sol(int x){
    if(x > n) return;
    cnt++;
    
    sol(x * 10);
    sol(x * 10 + 1);
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; ; i++){
        string s;
        int x = i;
        while(x > 0){
            s.push_back(x % 2 + '0');
            x /= 2;
        }
        reverse(s.begin(), s.end());

        if(stoll(s) > n) break;
        cnt++;
    }
    // sol(1);
    cout<<cnt;
    return 0;
}

// 7
// 1678
// 2
// 345345
// 567567
// 434
// 58900
// 1000000
