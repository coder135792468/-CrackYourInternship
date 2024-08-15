class StockSpanner {
public:
    vector<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
       int res = 1;
       while(!st.empty() and price >= st.back().first)
                  res+=st.back().second, st.pop_back();
       st.push_back({price,res});
       return st.back().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */