//
//  main.cpp
//  RPN-ExceptionHandling
//
//  Created by Linh Nguyen Le on 4/23/16.
//  Copyright © 2016 Linh Nguyen Le. All rights reserved.
//

#include <iostream>

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include "stack.hpp"

using namespace std;
float doMath(char x,float no1, float no2){
    float result;
    if (x=='*'){
        result= no1*no2;
    }
    else if (x=='+'){
        result=no1+no2;
    }
    else if (x=='-'){
        result=no1-no2;
    }
    else if (x=='/'){
        result=no1/no2;
    }
    return result;
}
int main(int argc, char** argv) {
    float result;
    float memory=0;
    
    string s;
    string no;
    cout<<"Please enter an expression: ";
    getline(cin,s);
    while (s!="") {
        Stack myStack;
        istringstream sin(s);
//        string x;
        char x;
        sin>>x;
        while (!sin.eof()){
//            cout<<x<<endl;
            if ((x=='*') or (x=='/') or(x=='+') or (x=='-'))  {
                float no1;
                float no2;
                try{
                    no2=myStack.pop();
                    no1=myStack.pop();
                    result=doMath(x,no1,no2);
                    myStack.push(result);
                }catch(EmptyStackException* ex){
                    cerr<<ex->getMessage()<<endl;
                    delete ex;
                }
            }
            else if (x=='s'){
                memory=myStack.top();
                
            }
            else if (x=='r'){
                myStack.push(memory);
            }
            else{
                sin.putback(x);
                sin>>no;
                myStack.push(atoi(no.c_str()));
            }
            sin>>x;
        }
        float final;
        try {
            final=myStack.pop();
            if (myStack.isEmpty()){
                std::cout<<"The answer is: "<<final<<std::endl;
            }
            else{
                std::cout<<"Invalid expression"<<std::endl;
            }
        }catch(EmptyStackException* ex){
           // cerr<<ex->getMessage()<<endl;
        }
        cout<<"Please enter an expression: ";
        getline(cin,s);
    }
    cout<<"program end."<<endl;
    
    return 0;
    
}

