class BrowserHistory {
    stack<string> browserStack, forwardStack; // Using Two Stacks for browser visit and forward history...
public:
    BrowserHistory(string homepage) {
        browserStack.push(homepage); // By DEFAULT Brower pr HomePage Render ho rha hoga...
    }
    
    void visit(string url) {
        while(!forwardStack.empty()){ // If forward stack empty h toh ruk jao...
            forwardStack.pop(); // Jitni dfa hum visit krenge Forward history pop ho jayega...
        }
        browserStack.push(url); // visit url...
    }
    
    string back(int steps) {
        while(steps--){
            if(browserStack.size() > 1){ // tb tk hum back ja skte h jb tk home page nhi aa jata...
                forwardStack.push(browserStack.top()); // back krne k baad forward history ko store kr lo..
                browserStack.pop();
            }
            else{
                // Means hum homepage pr h back nhi ja skte ho break kr jao...
                break;
            }
        }
        return browserStack.top();
    }
    
    string forward(int steps) {
        while(steps--){ // tb tk hum forward ja skte h jb tk forward history empty nhi ho jata...
            if(!forwardStack.empty()){
                browserStack.push(forwardStack.top()); // forward krne k baad forward history ko pop kr lo..
                forwardStack.pop();
            }
            else{
                break; // Means forward history empty ho chuki h...
            }
        }
        return browserStack.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */