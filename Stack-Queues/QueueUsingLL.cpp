/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.
void MyQueue:: push(int x)
{
        // Your Code
        QueueNode *newNode = new QueueNode(x);
        
        if(front==nullptr){
            front = rear = newNode;
            
        }
       else{
           rear->next=newNode;
        rear = newNode;
       } 
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code  
        if(front==nullptr) return -1;
        int num = front->data;
        QueueNode *temp = front;
        front = front->next;
        if(front == nullptr)rear =nullptr;
        delete temp;
        return num;
}
