#include <iostream>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int pos[(int)1e5 + 5] = {};
    int res = n;

    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        if(pos[x] != 0) res = min(res, i + 1 - pos[x]);
        pos[x] = i + 1;
    }
    cout<<(res < n ? res : -1);
    return 0;
}