class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.size()==0){
            if(stack1.size()==0)
                cerr<<"queue is empty";
                //throw new exception("queue is empty");
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
            
        }
        int x=stack2.top();
        stack2.pop();
        return x;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};