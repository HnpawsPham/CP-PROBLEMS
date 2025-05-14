#include <iostream>
#include <vector>
using namespace std;
#define el "\n"

int n;

int sum(int x){
    int res = 1 + x;

    for(int i = 2; i * i <= x; i++)
        if(x % i == 0) {
            res += i;
            if(x / i != i) res += x / i;
        }
    return res;
}

int main(){
    // freopen("GHH.INP", "r", stdin);
    // freopen("GHH.OUT", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int cnt = 0;
    vector<int> res;

    while(n--){
        int x;
        cin>>x;
        if(2 * x <= sum(x)){
            cnt++;
            res.push_back(x);
        }
    }
    cout<<cnt<<el;
    for(int x : res) cout<<x<<el;

    return 0;
}