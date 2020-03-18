class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    void del(int t){
        if(m.empty()) return;
        auto it = m.begin();
        while(it != m.end()){
            std::string str = it -> first;
            ++it;
            if(m[str] <= t - 10) m.erase(str);
        }
        return;
    }
    bool shouldPrintMessage(int timestamp, string message) {
        del(timestamp);
        if(m.find(message) == m.end()){
            m[message] = timestamp;  
            return true;
        } 
        else return false;
    }
private:
    std::unordered_map<std::string,int>m;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
