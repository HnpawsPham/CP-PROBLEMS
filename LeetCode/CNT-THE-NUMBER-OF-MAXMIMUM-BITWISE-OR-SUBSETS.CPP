#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int n, maxx = 0, cnt = 0;

void sol(int i, int sum, vector<int>& a){
    if(i == n){
        if(sum > maxx){
            maxx = sum;
            cnt = 0;
        }
        cnt += (sum == maxx);
        return;
    }

    sol(i + 1, sum | a[i], a);
    sol(i + 1, sum, a);

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    sol(0, 0, a);
    cout<<cnt;
    return 0;
}