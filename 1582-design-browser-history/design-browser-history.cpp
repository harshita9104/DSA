class BrowserHistory {
public:
    list<string> dll;                       // Doubly linked list to store the history of urls
    list<string>::iterator current;         // Iterator to keep track of the current page

    // Constructor: initializes the browser history with the homepage
    BrowserHistory(string homepage) {
        dll.push_back(homepage);            // Push the homepage to the list
        current = dll.begin();              // Set current pointer to homepage
    }
    
    // Visit a new URL from the current page
    void visit(string url) {
        // When visiting a new url, clear all forward history
        auto it = current;
        ++it;                               // Move to the next element (i.e., one step ahead of current)
        dll.erase(it, dll.end());           // Erase everything ahead (forward history)
        dll.push_back(url);                 // Add the new url to the end of the list
        current = prev(dll.end());          // Set current to the new last element (new page)
    }
    
    // Move back in history up to 'steps', but not beyond the homepage
    string back(int steps) {
        while (steps-- && current != dll.begin()) {
            --current;                      // Move back one page at a time
        }
        return *current;                    // Return the current url
    }
    
    // Move forward in history up to 'steps', but not beyond the most recent page
    string forward(int steps) {
        while (steps-- && next(current) != dll.end()) {
            ++current;                      // Move forward one page at a time
        }
        return *current;                    // Return the current url
    }
};