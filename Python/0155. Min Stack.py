# Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
# push(x) -- Push element x onto stack.
# pop() -- Removes the element on top of the stack.
# top() -- Get the top element.
# getMin() -- Retrieve the minimum element in the stack.
# Example:
# MinStack minStack = new MinStack();
# minStack.push(-2);
# minStack.push(0);
# minStack.push(-3);
# minStack.getMin();   --> Returns -3.
# minStack.pop();
# minStack.top();      --> Returns 0.
# minStack.getMin();   --> Returns -2.
# https://leetcode.com/problems/min-stack/description/
# 
# Author: Adam Yu Wen
# Date: May 17, 2018

class MinStack(object):
    
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.numStack = []
        self.minStack = []
        
    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.numStack.append(x)
        if len(self.minStack) == 0 or x <= self.minStack[-1]:
            self.minStack.append(x)

    def pop(self):
        """
        :rtype: void
        """
        if self.numStack[-1] == self.minStack[-1]:
            del(self.numStack[-1])
            del(self.minStack[-1])
        else:
            del(self.numStack[-1])

    def top(self):
        """
        :rtype: int
        """
        return self.numStack[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.minStack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
