#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define pii pair<int, int>
#define vi vector<int>
#define fi first
#define se second

bool check(int h, int m){
    while(h > 0){
        if(h % 10 == 9) return 1;
        h /= 10;
    };

    while(m > 0){
        if(m % 10 == 9) return 1;
        m /= 10;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, h, m;
    cin>>x>>h>>m;

    int cnt = 0;
    while(!check(h, m)){
        m -= x;

        if(m < 0){
            m += 60;
            h--;
            if(h < 0) h = 23;
        }
        cnt++;
    }
    cout<<cnt;
    return 0;
}