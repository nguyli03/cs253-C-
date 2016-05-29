//
//  main.cpp
//  queueclass
//
//  Created by Linh Nguyen Le on 4/8/16.
//  Copyright © 2016 Linh Nguyen Le. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "queueclass.hpp"

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
    Queue myq;
    for (int k = 1; k<argc; k++){
        x=myatoi(argv[k]);
        cout<<x<<endl;
        //myq.enqueue(x);
        myq<<x;
    }
    
    cout << myq;
    
    while (!myq.isEmpty()){
        //x=myq.dequeue();
        myq>>x;
        cout<<x<<endl;
    }
}