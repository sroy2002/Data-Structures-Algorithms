// Problem is REVERSE A STACK USING RECURSION

// TIME Complexity: O(n^2) Space Complexity: O(n)



#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>&st,int num){
    if(st.empty()){
        st.push(num);
    }else{
        int top = st.top();
        st.pop();
        insertAtBottom(st,num);
        st.push(top);
    }
}

void reverseStack(stack<int>&st){
    if(st.empty()){
        return;
    }
    int top = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,top);
}


int main()
{
    int n;
    cout << "Enter the stack size = ";
    cin >> n;
    stack<int> st;
    cout << "Enter the elements: " << endl;
    for(int i=1;i<=n;i++){
        int val;
        cin >> val;
        st.push(val);
    }

    reverseStack(st);
    cout << "After reversing the stack becomes: " << endl;
    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}
