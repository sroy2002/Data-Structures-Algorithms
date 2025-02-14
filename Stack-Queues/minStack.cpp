// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.



class MinStack {
    private:
        stack<pair<int, int>> st;  // Stack of {value, min_value}
    
    public:
        MinStack() {}
    
        void push(int val) {
            if (st.empty()) {
                st.push({val, val});  // First element: val, Second element: min so far
            } else {
                st.push({val, min(st.top().second, val)});
            }
        }
    
        void pop() {
            if (!st.empty()) {
                st.pop();
            }
        }
    
        int top() {
            if (!st.empty()) {
                return st.top().first;
            }
            return -1;  // Default value if stack is empty
        }
    
        int getMin() {
            if (!st.empty()) {
                return st.top().second;
            }
            return -1;  // Default value if stack is empty
        }
    };
    