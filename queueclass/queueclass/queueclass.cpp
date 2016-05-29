//
//  queueclass.cpp
//  queueclass
//
//  Created by Linh Nguyen Le on 4/8/16.
//  Copyright © 2016 Linh Nguyen Le. All rights reserved.
//

#include "queueclass.hpp"

Queue::Queue() {}

void Queue::enqueue(int item) {
    
    list.push_back(item);
}

int Queue::dequeue() {
    
    int item = list.front();
    list.erase(list.begin());
    
    return item;
}

bool Queue::isEmpty() {
    return list.size() == 0;
}

Queue& operator<<(Queue& q, int x) {
    q.enqueue(x);
    
    return q;
}
// alow to write queue>>x; where queue is a queue and x is an integer; it functions like a dequeue
Queue& operator>>(Queue& q, int& x) {
    x = q.dequeue();
    
    return q;
}
//Use & when you think you'll change the value of the thing you change it.

std::ostream& operator << (std::ostream& out, const Queue& q){
    out<<"-----------------------------------------"<<endl;
    out<<"front | ";
    int k;
    for (k=0;k<q.list.size();k++){
        out <<q.list[k]<<" ";
    }
    out<<" | back"<<endl;
    out<<"--------------------------------"<<endl;
    return out;
}

