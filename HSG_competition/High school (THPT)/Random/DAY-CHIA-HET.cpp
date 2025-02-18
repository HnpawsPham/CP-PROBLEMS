#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    int d = 1, cnt = 0, id = 0;
    ll cur = 0;
    while(id < n){
        cur++;
        if(cur % d == 0){
            cnt++;
            id++;
            if(cnt == d){
                cnt = 0;
                d++;
            }
        }
    }
    cout<<cur;

    return 0;
}