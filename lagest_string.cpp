class Solution {
public:
    string lastSubstring(string s) {
        char c = 'a';
        for(const char& d:s){
            if(d > c) c = d;
        }
        std::vector<int>v;
        int n =s.size();
        for(int i=0; i<s.size(); ++i){
            if(s[i] == c) v.push_back(i);
        }
        int i = 0;
        int j = 1;
        int k = 0;
        std::cout << v.size();
        while(j<v.size() && v[j]+k < n){
            if(s[v[i]+k] == s[v[j]+k]) ++k;
            else if(s[v[i]+k] < s[v[j]+k]){
                i = j++;
                k=0;
            }
            else{
                k=0;
                ++j;
            }
        }
        return s.substr(v[i]);
    }
};
