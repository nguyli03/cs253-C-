//
//  stackclass.hpp
//  stack
//
//  Created by Linh Nguyen Le on 4/10/16.
//  Copyright © 2016 Linh Nguyen Le. All rights reserved.
//

#ifndef stackclass_hpp
#define stackclass_hpp

#include <stdio.h>
#include <vector>
using namespace std;

class Stack{
public:
    Stack();
    void push(int item);
    int pop();
    bool isEmpty();
private:
    vector<int> stack;
};

#endif /* stackclass_hpp */
