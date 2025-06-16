#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
int nums[4] = {6,28,496,8128};

int main(){
    freopen("QUA.INP", "r", stdin);
    freopen("QUA.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int cnt = 0;
    vector<int> res;

    while(n--){
        int x;
        cin>>x;
        if(find(nums, nums + 4, x) < nums + 4){
            cnt++;
            res.push_back(x);
        }
    }
    cout<<cnt<<el;
    for(int x : res) cout<<x<<" ";

    return 0;
}