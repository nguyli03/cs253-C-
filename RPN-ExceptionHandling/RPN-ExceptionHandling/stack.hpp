//
//  stack.hpp
//  RPN-ExceptionHandling
//
//  Created by Linh Nguyen Le on 4/23/16.
//  Copyright © 2016 Linh Nguyen Le. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>
#include <stdio.h>
#include <vector>
#include <iostream>
class EmptyStackException{
public:
    EmptyStackException(std::string);
    std::string getMessage();
private:
    std::string msg;
};
class QNode{
public:
    QNode();
    ~QNode();
    float getVal() const;
    QNode* getNext() const;
    void setVal(float);
    void setNext(QNode *);
private:
    float val;
    QNode* next;
};

class Stack {
public:
    Stack();
    ~Stack();
    void push(float item);
    float pop();
    bool isEmpty();
    float top();
    
private:
    QNode* head;
};

#endif /* stack_hpp */
