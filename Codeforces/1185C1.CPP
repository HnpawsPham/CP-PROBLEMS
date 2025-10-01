#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    multiset<int, greater<int>> ms;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];

        if(sum <= m) cout<<0<<" ";
        else{
            int target = sum - m;
            int del = 0, cnt = 0;
            auto tmp = ms;

            while(del < target){
                del += *tmp.begin();
                tmp.erase(tmp.begin());
                cnt++;
            }
            cout<<cnt<<" ";
        }
        ms.insert(a[i]);
    }
    return 0;
}