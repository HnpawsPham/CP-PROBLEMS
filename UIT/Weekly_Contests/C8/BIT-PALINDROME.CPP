#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

bool palin(int x) {
    int rev = 0, tmp = x;
    while (tmp > 0) {
        rev = (rev << 1) | (tmp & 1);
        tmp >>= 1;
    }
    return rev == x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    int cnt = 0;
    for(int i = 1; ; i++){
        if(palin(i)) cnt++;
        if(cnt == n) return cout<<i, 0;
    }

    return 0;
}