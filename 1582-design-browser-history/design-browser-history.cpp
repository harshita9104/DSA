class BrowserHistory {
public:
    string current;                // Current page
    stack<string> backward;        // Stack for back history
    stack<string> forward_;        // Stack for forward history

    BrowserHistory(string homepage) {
        current = homepage;        // Start at homepage
    }
    
    void visit(string url) {
        // On visiting new url, push current to back stack
        backward.push(current);
        current = url;
        // Clear forward stack (can't go forward after a new visit)
        while (!forward_.empty()) forward_.pop();
    }
    
    string back(int steps) {
        // Go back up to 'steps' times or until you can't go back more
        while (steps > 0 && !backward.empty()) {
            forward_.push(current);         // Push current to forward stack
            current = backward.top();       // Pop from back stack and make it current
            backward.pop();
            steps--;
        }
        return current;
    }
    
    string forward(int steps) {
        // Go forward up to 'steps' times or until you can't go forward more
        while (steps > 0 && !forward_.empty()) {
            backward.push(current);         // Push current to back stack
            current = forward_.top();       // Pop from forward stack and make it current
            forward_.pop();
            steps--;
        }
        return current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */