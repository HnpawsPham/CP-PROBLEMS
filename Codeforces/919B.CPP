#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 2e7 + 5;

bool check(int x){
    int sum = 0;
    while(x > 0){
        sum += x % 10;
        x /= 10;
    }
    return sum == 10;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin>>k;

    int prev = 10, cnt = 0;
    for(int i = 19; i <= maxn; i+=9)
        if(check(i)){
            cnt++;
            if(cnt == k) return cout<<i, 0;
        }
    return 0;
}