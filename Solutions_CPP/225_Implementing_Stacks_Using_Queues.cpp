// 225 Implementing Stacks Using Queues
/* Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:
  void push(int x) Pushes element x to the top of the stack.
  int pop() Removes the element on the top of the stack and returns it.
  int top() Returns the element on the top of the stack.
  boolean empty() Returns true if the stack is empty, false otherwise.

Notes:
You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
*/

/*
Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
 
Constraints:
1. 1 <= x <= 9
2. At most 100 calls will be made to push, pop, top, and empty.
3. All the calls to pop and top are valid.
*/

/*
=> Push Operation
  Enqueue the new element at the back of q.
  To ensure that the last element can be accessed from the front, rotate the queue by dequeueing and enqueuing each element except the newly pushed element.
=> Pop and Top Operations
  Simply dequeue from the front for pop and peek at the front for top.
=> isEmpty Operation
  Simply check if the Queue is empty or not
*/

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
class MyStack {
private:
    std::queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i = 0; i < q.size() - 1; ++i){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
