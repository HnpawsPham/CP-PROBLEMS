#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a, b;
    cin>>n>>a>>b;
    int d = (n + 1) / 2, r = n / 2;
    int t1 = (a * b + 1) / 2, t2 = a * b / 2;

    if(!((d <= t1 && r <= t2) || (d <= t2 && r <= t1))) return cout<<-1, 0;

    int x = 2, y = 1;
    if(!(d <= t1 && r <= t2)) swap(x, y);

    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            if((i + j) % 2){
                if(x <= n) cout<<x<<" ";
                else cout<<0<<" ";
                x += 2;
            }
            else{
                if(y <= n) cout<<y<<" ";
                else cout<<0<<" ";
                y += 2;
            }
        }
        cout<<el;
    }
    return 0;
}