class MyStack {
private:
    queue<int> q1;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
        int sz = q1.size();
        while(sz>1){
            int num = q1.front();
            q1.pop();
            q1.push(num);
            sz--;
            
        }
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = q1.front();
        q1.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */