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

    int n, k;
    cin>>n>>k;

    vi a;
    for(int i = 9; i >= 2; i--)
        while(n % i == 0){
            n /= i;
            a.push_back(i);
        }

    if(n != 1) return cout<<-1, 0;

    int sz = k - a.size();
    for(int i = 0; i < sz; i++) a.push_back(1);
    reverse(a.begin(), a.end());

    for(int x : a) cout<<x;
    return 0;
}