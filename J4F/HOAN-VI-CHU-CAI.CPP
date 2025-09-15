#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define el '\n'
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    sort(s.begin(), s.end());
    vector<string> res;

    do{
        res.push_back(s);
    } while(next_permutation(s.begin(), s.end()));

    cout<<res.size()<<el;
    for(const string& x : res) cout<<x<<el;
    return 0;
}