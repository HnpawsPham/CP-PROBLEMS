#include <iostream>

int main(){
    int n;
    std::cin>>n;
    int maxn = 1e4 + 1;
    int cnt[maxn] = {0};

    while(n--){
        int x;
        std::cin>>x;
        cnt[x]++;
    }

    int res, maxx = 0;
    for(int i = 0; i < maxn; i++)
        if(cnt[i] > maxx){
            maxx = cnt[i];
            res = i;
        }
    std::cout<<res;
    return 0;
}