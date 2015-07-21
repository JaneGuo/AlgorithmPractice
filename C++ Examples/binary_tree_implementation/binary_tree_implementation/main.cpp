//
//  main.cpp
//  binary_tree_implementation
//
//  Created by Jiancong Guo on 7/19/15.
//  Copyright (c) 2015 Jiancong Guo. All rights reserved.
//

#include <iostream>
#include "binary_tree.h"

int main(int argc, const char * argv[])
{
    btree b;
    b.insert(10);
    b.insert2(10);
    b.insert(6);
    b.insert1(14);
    b.insert1(5);
    b.insert1(8);
    b.insert(11);
    b.insert(18);

    b.in_order_print();
    b.pre_order_print();
    b.post_order_print();
    b.count_node();
    std::cout<<b.search(19)<<std::endl;
    std::cout<<b.search(10)<<std::endl;
    std::cout<<b.search1(11)<<std::endl;
    
    b.depth_of_tree();
    b.destroy_tree();
    
    
    return 0;
}

