//
//  binary_tree.cpp
//  binary_tree_implementation
//
//  Created by Jiancong Guo on 7/19/15.
//  Copyright (c) 2015 Jiancong Guo. All rights reserved.
//

#include "binary_tree.h"
#include <queue>

/* This part is wrong
void btree::destroy_tree(node *leaf){
    
    if(leaf != NULL){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete(leaf);
    }
}
*/

void btree::destroy_tree(){
    destroy_tree(root);
}
void btree::insert(int key, node *&leaf){
    if(leaf == NULL){
        node *temp = new node;
        temp->key_value = key;
        temp->left = NULL;
        temp->right = NULL;
        
        leaf = temp;
        std::cout<< "insert key value: "<<leaf->key_value<<"\n";
    }
    else if(key <= leaf->key_value){
        
        insert(key, leaf->left);
    }
    else if(key > leaf->key_value){
        insert(key, leaf->right);
    }
}
void btree::insert(int key){
    insert(key, root);
}

//this version is the easy version of insert, which does not use pointer to address
void btree::insert2(int key, node *leaf){
    //public version of insert function take care of the situation where leaf is NULL;
    if(key <= leaf->key_value){
        if(leaf->left != NULL)
            insert(key,leaf->left);
        else{
            leaf->left = new node;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
            leaf->left->key_value = key;
        }
    }
    else {
        if(leaf->right != NULL)
            insert(key, leaf->right);
        else{
            leaf->right = new node;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
            leaf->right->key_value = key;
        }
    }
}

void btree::insert2(int key){
    if(root!= NULL)
        insert(key, root);
    else{
        root = new node;
        root->key_value = key;
        root->left = NULL;
        root->right = NULL;
    }
}


int btree::count_node(node *leaf){
    if(leaf == NULL)
        return 0;
    int count = 1;
    count += count_node(leaf->left);
    count += count_node(leaf->right);
    return count;
}

int btree::count_node(){
    int root_count = count_node(root);
    std::cout<<"the count of the tree is "<<root_count<<std::endl;
    return root_count;
}

void btree::pre_order_print(node *leaf){
    if(leaf != NULL){
        std::cout<<leaf->key_value<<'\t';
        pre_order_print(leaf->left);
        pre_order_print(leaf->right);
    }
}
void btree::pre_order_print(){
    std::cout<<"binary tree pre-order print:";
    pre_order_print(root);
    std::cout<<std::endl;
}

void btree::post_order_print(node *leaf){
    if(leaf != NULL){
        post_order_print(leaf->left);
        post_order_print(leaf->right);
        std::cout<<leaf->key_value<<'\t';
    }
}
void btree::post_order_print(){
    std::cout<<"binary tree post-order print:";
    post_order_print(root);
    std::cout<<std::endl;
}
void btree::in_order_print(node *leaf){
    if(leaf != NULL){
        in_order_print(leaf->left);
        std::cout<<leaf->key_value<<'\t';
        in_order_print(leaf->right);
    }
}
void btree::in_order_print(){
    std::cout<<"binary tree in-order print:";
    in_order_print(root);
    std::cout<<std::endl;
}

//Level Order (Breadth Order) print
void Level_order_print(node *root){
    if(root == NULL) return;
    std::queue<node *> Q;
    Q.push(root);
    while(!Q.empty()){
        node *current = Q.front();
        std::cout<<current->key_value<<"\t";
        if(current->left != NULL)
            Q.push(current->left);
        if(current->right != NULL)
            Q.push(current->right);
        Q.pop();
    }
}

// insert funtion using loop
void btree::insert1(int key, node *leaf){
    
    while(leaf != NULL){
        if(key < leaf->key_value && leaf->left!=NULL){
            leaf = leaf->left;
        }
        else if(key < leaf->key_value && leaf->left ==NULL){
            leaf->left = new node;
            leaf->left->key_value = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
            
            return;
        }
        else if(key > leaf->key_value && leaf->right != NULL){
            leaf= leaf->right;
        }
        else if(key >leaf->key_value && leaf->right == NULL){
            leaf->right = new node;
            leaf->right->key_value = key;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
            
            return;
        }
    }
}
void btree::insert1(int key){
    if(root == NULL){
        root = new node;
        root->key_value = key;
        root->left = NULL;
        root->right = NULL;
        return;
    }
    else
        insert1(key, root);
}

node *btree::search(int key, node* leaf){
    
    if(leaf == NULL)
        return NULL;
    else{
        
        if(key == leaf->key_value)
            return leaf;
        else if(key < leaf->key_value)
            return search(key, leaf->left);
        else
            return search(key, leaf->right);
    }
}

node *btree::search(int key){
    std::cout<< "search for number "<<key<<std::endl;
    return search(key, root);
}

//search function using loop
node *btree::search1(int key, node *leaf){
    if(leaf == NULL)
        return NULL;
    while(leaf != NULL){
        if(key == leaf->key_value)
            return leaf;
        else if(key <= leaf->key_value)
            leaf = leaf->left;
        else
            leaf = leaf->right;
    }
    return NULL;
}
node *btree::search1(int key){
    std::cout<< "search for number "<<key<<std::endl;
    return search1(key, root);
}

int btree::depth_of_tree(node *leaf){
    if(leaf == NULL)
        return 0;
    int left_depth = depth_of_tree(leaf->left);
    int right_depth = depth_of_tree(leaf->right);
    return (left_depth > right_depth)? (left_depth+1) : (right_depth + 1);
}

int btree::depth_of_tree(){
    int tree_depth = depth_of_tree(root);
    std::cout << "the depth of the tree is "<<tree_depth<<std::endl;
    return tree_depth;
}







