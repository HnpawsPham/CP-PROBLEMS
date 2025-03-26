#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int n, m, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    vi a;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            int x;
            cin>>x;
            a.push_back(x);
        }
    sort(a.begin(), a.end());
    n = a.size();

    int median = a[n / 2], res = 0;
    for(int x : a){
        if(x % k != median % k) return cout<<-1, 0;
        res += (abs(median - x)/ k);
    }
    cout<<res;
    return 0;
}