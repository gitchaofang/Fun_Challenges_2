#include<vector>
#include<iostream>
#include<utility>
#include<climits>
#include<cmath>
#include<algorithm>
std::pair<int,int> linear(const std::vector<std::pair<int,int>>& v,const std::pair<int,int>& target){
    int dis = INT_MAX;
    std::pair<int,int>res;
    for(const std::pair<int,int>& p: v){
        int d = std::pow(p.first - target.first,2) + std::pow(p.second - target.second,2);
        if(d < dis && (p.first == target.first || p.second == target.second)){
            res = p;
            dis = d;
        }
    }
    return res;
}

std::pair<int,int> nlogn(std::vector<std::pair<int,int>>& v, const std::pair<int,int>& target){
    int n = 0;
    for(int i=0; i<v.size(); ++i){
        std::pair<int,int>p = v[i];
        if(p.first == target.first || p.second == target.second) std::swap(v[i],v[n++]);
    }
    auto cmp = [&](const std::pair<int,int>&p1, const std::pair<int,int>& p2){
        int d1 = std::pow(p1.first - target.first,2) + std::pow(p1.second - target.second,2);
        int d2 = std::pow(p2.first - target.first,2) + std::pow(p2.second - target.second,2);
        return d1 < d2;
    };
    std::sort(v.begin(),v.begin()+n,cmp);
    return v[0];

}

int main(){
    std::vector<std::pair<int,int>> input({{1,2},{1,3},{2,1},{4,3},{4,5},{6,5},{2,5}});
    std::pair<int,int>res1 = linear(input,{1,5});
    std::pair<int,int> res2 = nlogn(input,{1,5});
    std::cout << res1.first << " " << res2.first << " -> " << res1.second << " " << res2.second;
    return 0;
}
