#include<vector>
#include<iostream>
#include<numeric>
#include<map>
#include<algorithm>
std::pair<int,int> bs(const std::vector<std::pair<double,double>>& input,double x){  
    int left = 0;
    int right = input.size()-1;
    while(left < right){
        int mid = (right - left)/2 + left;
        if(input[mid].first < x) left = mid+1;
        else right = mid;
    } 
    return {right-1,right};

}
std::vector<double> linear(std::vector<std::pair<double,double>>& input, const std::vector<double>& query){
    if(input.size() == 1){
        std::vector<double>res(query.size(),input[0].second);
        return res;
    }
    auto cmp = [](const std::pair<double,double>& p1, const std::pair<double,double>& p2){
        if(p1.first == p2.first) return p1.second < p2.second;
        return p1.first < p2.first;
    };
    std::sort(input.begin(),input.end(),cmp);
    std::vector<double> res;
    for(const double& x: query){
        std::pair<double,double>p = bs(input,x);
        if(p.first < 0){
            p.first = p.second;
            p.second = p.first + 1;
        }
        else if(p.second >= input.size()){
            p.second = p.first;
            p.first = p.second - 1;
        }
        
        double x1 = input[p.first].first;
        double y1 = input[p.first].second;
        double x2 = input[p.second].first;
        double y2 = input[p.second].second;
        if(x1 == x2){
            if(x > x2) res.push_back(y2);
            else res.push_back(y1);
        }
        else{ 
            double slope = (y2 - y1) / (x2 - x1);
            if(slope == 0) res.push_back(y1);
            else{
                res.push_back(slope * (x-x2) + y2);
            }
        }
    }
    return res;
    
}

int main(){
    std::vector<std::pair<double,double>> input = {{2.4,22},{1.2,33},{1.2,12},{3.5,12.4},{4.3,14.5},{5.3,6.3},{0.3,20.1}};
    std::vector<double> query = {3.4,2.4,0.9,1.4,0.2};
    std::vector<double> res = linear(input,query);
    for(int i=0; i<query.size(); ++i){
        std::cout << query[i] << " " << res[i] << '\n';
    }
    return 0;
}
