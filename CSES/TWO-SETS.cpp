#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll sum = 1LL *  n * (n + 1) / 2;

    if(sum % 2) return cout<<"NO", 0;
    cout<<"YES"<<el;

    vector<int> g1, g2;
    ll sum1 = 0, sum2 = 0, k = sum / 2;

    for(int i = n; i > 0; i--){
        if(sum1 + i <= k){
            g1.push_back(i);
            sum1 += i;
        }    
        else{
            g2.push_back(i);
            sum2 += i;
        }
    }
    cout<<g1.size()<<el;
    for(const int& x : g1) cout<<x<<" ";

    cout<<el<<g2.size()<<el;
    for(const int& x : g2) cout<<x<<" ";

    return 0;
}
