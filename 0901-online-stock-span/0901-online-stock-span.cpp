class StockSpanner {
public:
    
    stack<int> s; // Stack stores the INDEX of previous days
    vector<int> stock; // Stores the stock price of each day
    
    int i = 0;

    // Constructor
    StockSpanner() {
        
    }
    
    int next(int price) {

        // Store today's price in the stock vector
        stock.push_back(price);

        // Remove all previous days whose price is less than or equal to today's price Because those days can be included in today's span
        while(!s.empty() && price >= stock[s.top()]) {
            s.pop();
        }
        int span;

        // If stack becomes empty,there is no previous greater price.Therefore, span includes all previous days + today
        if(s.empty()) {
            span = i + 1;
        }
        else {

            // Stack top gives the index of the nearest previous greater price
            int prevHigh = s.top();

            // Number of consecutive days from after prevHigh up to today
            span = i - prevHigh;
        }

        // Push today's index into the stack
        s.push(i);
        i++;
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */