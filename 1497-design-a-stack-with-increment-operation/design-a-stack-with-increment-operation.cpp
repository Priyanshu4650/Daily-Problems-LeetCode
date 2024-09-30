class CustomStack {
    vector<int> st;  // Stack using vector
    int cap;         // Maximum capacity of the stack
public:
    // Constructor to initialize the stack with a given maxSize
    CustomStack(int maxSize) {
        st.reserve(maxSize);  // Reserve memory for maxSize elements
        cap = maxSize;
    }
    
    // Push operation: add an element to the stack
    void push(int x) {
        if(st.size() < cap) {
            st.push_back(x);  // Push only if size < capacity
        }
    }
    
    // Pop operation: remove and return the top element from the stack
    int pop() {
        if(st.empty()) {
            return -1;  // If the stack is empty, return -1
        }
        int x = st.back();  // Get the top element
        st.pop_back();      // Remove the top element
        return x;
    }
    
    // Increment operation: increment the bottom k elements by val
    void increment(int k, int val) {
        for(int i = 0; i < st.size() && i < k; i++) {
            st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */