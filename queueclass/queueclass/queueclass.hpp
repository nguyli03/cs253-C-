//
//  queueclass.hpp
//  queueclass
//
//  Created by Linh Nguyen Le on 4/8/16.
//  Copyright © 2016 Linh Nguyen Le. All rights reserved.
//

#ifndef queueclass_hpp
#define queueclass_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Queue {
public:
    Queue();
    
    // The enqueue method enqueues an item on the queue.
    void enqueue(int item);
    int dequeue();
    bool isEmpty();
    friend std::ostream& operator <<(std::ostream&, const Queue&);

    
private:
    std::vector<int> list;
};

Queue& operator<<(Queue&, int);
Queue& operator>>(Queue&, int&);

std::ostream& operator <<(std::ostream&, const Queue&);
//const Queue& mean you dont want to change the queue but we dont want to make a copy of it

#endif /* queueclass_hpp */
