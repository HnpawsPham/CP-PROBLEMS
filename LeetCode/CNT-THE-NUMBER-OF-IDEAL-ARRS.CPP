#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define MOD 1000000007

int n, maxx;

int bruteforce(){
    int res = 0;
    for(int i = 1; i <= maxx; i++){
        int d = 1, cnt = 0;
        while(i * d <= maxx && cnt < n){
            cout<<i<<", ";
            d++;
            cnt++;
        }
        res++;
        cout<<el;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>maxx;
    int cnt = 0;

    cout<<bruteforce();
    return 0;
}