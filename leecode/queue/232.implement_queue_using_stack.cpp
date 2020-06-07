#include<stack>

class MyQueue {
private:
        stack<int> A;
        stack<int> B;
public:
    /** Initialize your data structure here. */
 
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        A.push(x);
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(B.empty()){
            while(!A.empty()){
                B.push(A.top());
                A.pop();
            }
        }
        int num = B.top();
        B.pop();
        return num;
        
    }
    
    /** Get the front element. */
    int peek() {
        if(B.empty()){
            while(!A.empty()){
                B.push(A.top());
                A.pop();
            }
        }
        return B.top();
        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return A.empty()&&B.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */