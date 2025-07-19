#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    string s;
    cin>>s;
    vector<char> low, up;

    for(const char& x : s)
        if('a' <= x && x <= 'z')
            low.push_back(x);
        else up.push_back(x);

    sort(low.begin(), low.end(), greater<char>());
    sort(up.begin(), up.end(), greater<char>());

    for(const char&x : up) cout<<x;
    for(const char&x : low) cout<<x;
    return 0;
}