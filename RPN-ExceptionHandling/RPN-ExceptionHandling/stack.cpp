//
//  stack.cpp
//  RPN-ExceptionHandling
//
//  Created by Linh Nguyen Le on 4/23/16.
//  Copyright © 2016 Linh Nguyen Le. All rights reserved.
//

#include "stack.hpp"

EmptyStackException::EmptyStackException(std::string message) {
    msg = message;
}

std::string EmptyStackException::getMessage() {
    return msg;
}

QNode::QNode(){
    val=0;
    next=NULL;
}
QNode::~QNode(){
    if (next==nullptr){
        return;
    }
    try {
        delete next;
    }catch(...){
        std::cerr<<"Cannot delete Node, something wrong happened"<<std::endl;
    }
}
QNode* QNode::getNext() const{
    return next;
}
float QNode::getVal() const{
    return val;
}
void QNode::setVal(float x){
    val=x;
}
void QNode::setNext(QNode *ptr){
    next=ptr;
}

Stack::Stack(){
    head=NULL;
}
Stack::~Stack(){
    try{
        delete head;
    }catch(...){
        std::cerr<<"Cannot delete Stack, something wrong happened"<<std::endl;
    }
}

bool Stack::isEmpty(){
    return head==NULL;
}

void Stack::push(float item){
    QNode* temp;
//    try{
//        temp=new QNode();
//        throw new std::bad_alloc;
//    }catch(std::bad_alloc* exc){
//        std::cerr<<"Out of memory when push the item"<<std::endl;
//    }
    temp=new QNode();
    temp->setVal(item);
    temp->setNext(head);
    head=temp;
}

float Stack::pop(){
    if (this->isEmpty()){
        throw new EmptyStackException("Invalid expression");
        return 0;
    }
    float x;
    x=head->getVal();
    QNode* tmp;
    tmp=head;
    head=tmp->getNext();
    tmp->setNext(NULL);
    delete tmp;
    return x;
    
    
}
float Stack::top(){
    return head->getVal();
}