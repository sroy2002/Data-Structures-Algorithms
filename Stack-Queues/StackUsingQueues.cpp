// Stack using one queue:

class MyStack {
    private:
        queue<int> q;
    
    public:
        MyStack() {}
    
        void push(int x) {
            int s = q.size();
            q.push(x);
            for (int i = 0; i < s; i++) {
                q.push(q.front());
                q.pop();
            }
        }
    
        int pop() {
            int num = q.front();
            q.pop();
            return num;
        }
    
        int top() { return q.front(); }
    
        bool empty() { return (q.size() == 0); }
    };
    


//Stack using 2 queues

#include <bits/stdc++.h>
using namespace std;

class StackUsingQueues {
    queue<int> q1, q2; 

public:
    // Push operation (O(1))
    void push(int x) {
        q1.push(x);
    }

    // Pop operation (costly)
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return;
        }

        // Move n-1 elements to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Remove last element
        q1.pop();

        // Swap q1 and q2
        swap(q1, q2);
    }

    // Top operation (O(n))
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }

        // Move n-1 elements to q2 and get last one
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int topElement = q1.front(); // Get last element
        q2.push(q1.front()); // Push it to q2
        q1.pop();

        // Swap queues
        swap(q1, q2);
        return topElement;
    }

    // Check if stack is empty (O(1))
    bool empty() {
        return q1.empty();
    }
};

int main() {
    StackUsingQueues s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl; // 30
    s.pop();
    cout << "Top after pop: " << s.top() << endl; // 20

    return 0;
}
