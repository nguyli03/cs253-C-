//
//  main.cpp
//  stack
//
//  Created by Linh Nguyen Le on 4/10/16.
//  Copyright © 2016 Linh Nguyen Le. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include "stackclass.hpp"

using namespace std;

int myatoi(char *ptr){
    int sum=0;
    while (*ptr!=0){
        sum=sum*10+ (*ptr-'0');
        ptr++;
    }
    return sum;
}
int main(int argc, char **argv)
{
    int x;
    Stack myStack;
    for (int k = 1; k<argc; k++){
        x=myatoi(argv[k]);
        myStack.push(x);
        cout<<x<<endl;
    }
    while (!myStack.isEmpty()){
        x=myStack.pop();
        cout<<x<<endl;
    }
}
