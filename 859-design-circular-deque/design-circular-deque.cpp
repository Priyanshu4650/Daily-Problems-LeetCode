class MyCircularDeque {
    deque<int> dq;
    int maxCap; // Maximum capacity of the deque
public:
    MyCircularDeque(int k) {
        maxCap = k; // Initialize maximum capacity
    }
    
    bool insertFront(int value) {
        if (dq.size() == maxCap)  // Check if the deque is full
            return false;
        
        dq.push_front(value);  // Insert element at the front
        return true;
    }
    
    bool insertLast(int value) {
        if (dq.size() == maxCap)  // Check if the deque is full
            return false;
        
        dq.push_back(value);  // Insert element at the back
        return true;
    }
    
    bool deleteFront() {
        if (dq.empty())  // Check if the deque is empty
            return false;
        
        dq.pop_front();  // Remove element from the front
        return true;
    }
    
    bool deleteLast() {
        if (dq.empty())  // Check if the deque is empty
            return false;
        
        dq.pop_back();  // Remove element from the back
        return true;
    }
    
    int getFront() {
        return dq.empty() ? -1 : dq.front();  // Return the front element or -1 if empty
    }
    
    int getRear() {
        return dq.empty() ? -1 : dq.back();  // Return the rear element or -1 if empty
    }
    
    bool isEmpty() {
        return dq.empty();  // Check if the deque is empty
    }
    
    bool isFull() {
        return dq.size() == maxCap;  // Check if the deque is full
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
