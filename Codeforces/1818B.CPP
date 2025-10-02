#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        if(n == 1) cout<<1<<el;
        else if(n % 2) cout<<-1<<el;
        else{
            for(int i = 1; i < n; i+=2)
                cout<<i + 1<<" "<<i<<" ";
            cout<<el;
        }
    }
    return 0;
}