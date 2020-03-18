int dc(const std::vector<double>&v, int k){ 
    int n = v.size();
    std::vector<double> median((n-1)/5);
    for(int i=0; i<(n - 1)/5; ++i){
        std::vector<double> tv(5,0);
        for(int j = 0; j<5; ++j) tv[j] = v[i*5 + j]; 
        std::sort(tv.begin(),tv.end());
        median[i] = tv[2];
    }   
    std::vector<double> tv; 
    for(int i = ((n-1)/5)*5; i<n; ++i) tv.push_back(v[i]);
    std::sort(tv.begin(),tv.end());
    median.push_back(tv[tv.size()/2]);
    int pivit = 0;
    if(median.size() <= 5) pivit = median[median.size() / 2]; 
    else pivit = dc(median,median.size() / 2); 
    
    //partition
    std::vector<double> low;
    std::vector<double> high;
    for(const int& d: v){ 
        if(d < pivit) low.push_back(d);
        else if(d > pivit) high.push_back(d);
    }   
   

    if(low.size() < k && n-high.size() >=k) return pivit;
    if(low.size() >= k) return dc(low, k); 
    return dc(high,k - n + high.size()); 
}
int main(){
    std::vector<double> input({2,3,4,1,7,5,8,10,22,50,42,11,32,33,66,77,46});
    int d1 = dc(input,int(input.size()+1)/2);
    int d2 = dc(input,int(input.size()+2)/2);
    std::cout << (double(d1) + double(d2))/2.0;
    return 0;
}
