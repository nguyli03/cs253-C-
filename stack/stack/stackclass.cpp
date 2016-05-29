//
//  stackclass.cpp
//  stack
//
//  Created by Linh Nguyen Le on 4/10/16.
//  Copyright © 2016 Linh Nguyen Le. All rights reserved.
//

#include "stackclass.hpp"
Stack::Stack(){}

void Stack::push(int item){
    stack.push_back(item);
}

int Stack::pop(){
    int number=stack.back();
    stack.pop_back();
    return number;
}

bool Stack::isEmpty(){
    return stack.size()==0;
}