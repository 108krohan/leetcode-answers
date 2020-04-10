Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.


class MinStack {
public:
    /** faster approach using 1 stack only */
    stack<long long> s;
    long long minVal;
    
    MinStack() {
    }
    
    void push(long long x) {
        if(s.empty()) {
            minVal = x;
            s.push(x); 
            return;
        }
        
        if(x > minVal) {
            s.push(x); 
        }
        else {
            s.push(2*x - minVal);
            minVal = x;
        }
    }
    
    void pop() {
        if(!s.empty()) {
            if(s.top() >= minVal) {
                s.pop();
            }
            else {
                // currentMin will change, here's how:
                // at push time when x < minVal
                // currentMin = 2 * x - preMinVal
                // stack_val < x < minElem. dtm
                minVal = 2*minVal - s.top(); 
                s.pop();
            }
        }
    }
    
    int top() {
        if(s.top()<minVal){
            return minVal;
        }
        return s.top();
    }
    
    int getMin() {
        return minVal;
    }
    
    // two stack approach
//     /** initialize your data structure here. */
//     stack<int> s;
//     stack<int> m; // 2 * val - min_val method can do w/ just 1 stack
    
//     MinStack() {
//     }
    
//     void push(int x) {
//         if(!m.empty() && m.top() < x) {
//             m.push(m.top());
//         }
//         else {
//             m.push(x);
//         }
//         // cout << "currently ingesting " << x << endl;
//         s.push(x);
//     }
    
//     void pop() {
//         if(!s.empty()) {
//             s.pop();
//             m.pop();
//         }
//     }
    
//     int top() {
//         if(!s.empty()) {
//             return s.top();        
//         }
//         else {
//             return INT_MIN;
//         }
//     }
    
//     int getMin() {
//         if(!m.empty()) {
//             return m.top();        
//         }
//         else {
//             return INT_MIN;
//         }
//     }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
