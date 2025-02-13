// Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

class MyQueue {
    private:
        stack<int>s1,s2;
    public:
        MyQueue() {}
        //O(1)
        void push(int x) {
            s1.push(x);
        }
        //O(N) ~ O(1) amortised
        int pop() {
            int num;
            if(!s2.empty()){
                num = s2.top();
                s2.pop();
            }
            else{
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
                num = s2.top();
                s2.pop();
            }
                return num;
        }
         //O(N) ~ O(1) amortised
        int peek() {
            if(!s2.empty()){
                return s2.top();
            }
            else{
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
                return s2.top();
            }
        }
        
        bool empty() {
            return (s1.empty() && s2.empty());
        }
    };