//
//  binary_tree.h
//  binary_tree_implementation
//
//  Created by Jiancong Guo on 7/19/15.
//  Copyright (c) 2015 Jiancong Guo. All rights reserved.
//

#ifndef binary_tree_implementation_binary_tree_h
#define binary_tree_implementation_binary_tree_h
#include <iostream>

struct node{
    int key_value;
    node *left;
    node *right;
};

class btree{
private:
    node *root;
    void insert(int key, node *&leaf);
    void insert1(int key, node *leaf);
    void insert2(int key, node *leaf);
    node *search(int key, node *leaf);
    node *search1(int key, node *leaf);
    void destroy_tree(node *leaf);
    int count_node(node *leaf);
    void pre_order_print(node *leaf);
    void post_order_print(node *leaf);
    void in_order_print(node *leaf);
    int depth_of_tree(node *leaf);
    
public:
    btree(){root = NULL;}
    ~btree(){destroy_tree();}
    void insert(int key);
    void insert1(int key);
    void insert2(int key);
    node *search(int key);
    node *search1(int key);
    void destroy_tree();
    int count_node();
    void pre_order_print();
    void post_order_print();
    void in_order_print();
    int depth_of_tree();
};

#endif
