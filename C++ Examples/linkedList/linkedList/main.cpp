//
//  main.cpp
//  linkedList
//
//  Created by Jiancong Guo on 7/28/15.
//  Copyright (c) 2015 Jiancong Guo. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node *next;
};

//Node *head the head of linked list.
void insert_end_data(Node *&head, int data){
    if(head == NULL){
        head = new Node;
        head->data = data;
        head->next = NULL;
        return;
    }
    Node *temp = head;
    while(temp->next!= NULL)
        temp = temp->next;
    temp->next= new Node;
    temp->next->data = data;
    temp->next->next = NULL;
}

void insert_head_data(Node *&head, int data){
    Node *newHead = new Node;
    newHead->data = data;
    newHead->next = head;
    head = newHead;
}

int insert_data(Node *&head, int data, int index){
    if(index < 0){
        cout<<"Please enter a valid number.\n";
        return -1;
    }
    else if(index == 0){
        Node *newHead = new Node;
        newHead->data = data;
        newHead->next = head;
        head = newHead;
        return 0;
    }
    Node *temp = head;
    while(index != 1){
        if(temp->next == NULL){
            cout<<"Error: Index does not exist in linked list, enter a smaller number.\n";
            return -2;
        }
        temp= temp->next;
        index--;
    }
    Node *tempIndex = new Node;
    tempIndex->data = data;
    tempIndex->next = temp->next;
    temp->next = tempIndex;
    return 0;
}

int delete_data(Node *&head, int index){
    if(index < 0){
        cout<<"Please enter a valid number.\n";
        return -1;
    }
    else if(index == 0){
        Node *temp = head;
        head = head->next;
        delete temp;
        return 0;
    }
    else{
        Node *pre_temp = head;
        Node *temp = head->next;
        index--;
        while(index!=0){
            if(temp->next == NULL){
                cout<<"Index "<<index<<"does not exist in linked list, enter a smaller number.\n";
                return -2;
            }
            pre_temp = pre_temp->next;
            temp = temp->next;
            index--;
        }
        pre_temp->next = temp->next;
        delete temp;
        return 0;
    }
}

void reverse_list(Node *&head){
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while(current!= NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
//space complexity is O(n), iterative space complexity is O(1)
void reverse_list_stack(Node *&head){
    if(head == NULL) return;
    stack<struct Node*> S;
    Node *temp = head;
    while(temp != NULL){
        S.push(temp);
        temp = temp->next;
    }
    head = S.top();
    temp = S.top();
    S.pop();
    while(!S.empty()){
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

void print_list(Node *head){
    if(head == NULL){
        cout<< "this is an empty list.\n";
        return;
    }
    
    cout<<head->data;
    while(head->next!=NULL){
        cout<<"->"<<head->next->data;
        head = head->next;
    }
    cout<<endl;
}

int main(int argc, const char * argv[])
{
    Node *A = NULL;
    insert_head_data(A, 86);
    insert_end_data(A, 1);
    insert_end_data(A, 2);
    insert_end_data(A, 3);
    insert_end_data(A, 3);
    insert_end_data(A,56);
    delete_data(A, 3);
    print_list(A);
    insert_head_data(A,67);
    print_list(A);
    reverse_list(A);
    print_list(A);
    insert_data(A,70, 6);
    print_list(A);
    std::cout<<"reverse a list \n";
    reverse_list_stack(A);
    print_list(A);
    
    //To be implement, to delete linked list and delete all nodes.
    //delete(A);
    
    return 0;
}

