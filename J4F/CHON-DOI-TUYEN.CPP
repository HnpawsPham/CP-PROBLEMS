#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;
#define el '\n'

int main(){
    // freopen("CHONDOI.INP", "r", stdin);
    // freopen("CHONDOI.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    unordered_map<char, int> id = {
        {'H', 0}, {'S', 1}, {'G', 2}, {'P', 3}, {'T', 4}};

    int cnt[5] = {0};

    while(n--){
        string ss;
        cin>>ss;
        if(id.count(ss[0]))
            cnt[id[ss[0]]]++;
    }

    ll res = 0;
    for(int i = 0; i < 5; i++)
        for(int j = i + 1; j < 5; j++)
            for(int z = j + 1; z < 5; z++)
                res += (1LL * cnt[i] * cnt[j] * cnt[z]);
    cout<<res;
    return 0;
}