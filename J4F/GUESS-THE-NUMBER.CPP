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

    int l = 1, r = (int)1e6, mid, res = 1;
    while(l <= r){
        mid = (l + r) / 2;
        cout<<mid<<el;
        cout.flush();

        string rep;
        cin>>rep;

        if(rep == "<") r = mid - 1;
        else {
            l = mid + 1;
            res = mid;
        }
    }

    cout<<"! "<<res<<el;
    cout.flush();
    return 0;
}