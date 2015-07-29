//
//  main.cpp
//  hashTable
//
//  Created by Jiancong Guo on 7/28/15.
//  Copyright (c) 2015 Jiancong Guo. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class hashtable{
    static const int tablesize = 10;
    
    struct item{
        string name;
        string drink;
        item* next;
    };
    
    item* hashItems[tablesize];
    
public:
    hashtable();
    ~hashtable();
    int Hash(string key);
    void add_item(string name, string drink);
    //number of item in index
    int num_item_index(int index);
    void print_table();
    string findDrink(string name);
};

hashtable::hashtable(){
    for(int i = 0; i< tablesize; i++){
        hashItems[i] = NULL;
    }
}
int hashtable::Hash(string key){
    int value = 0;
    for(string::iterator it = key.begin(); it != key.end(); it++){
        value += static_cast<int>(*it);
    }
    return value%tablesize;  //index
}

void hashtable::add_item(string name, string drink){
    int index = Hash(name);
    if(hashItems[index] == NULL){
        hashItems[index] = new item;
        hashItems[index]->name = name;
        hashItems[index]->drink = drink;
        hashItems[index]->next = NULL;
    }
    else if(hashItems[index] != NULL){
        item *temp = hashItems[index];
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new item;
        temp->next->name = name;
        temp->next->drink = drink;
        temp->next->next = NULL;
    }
}
int hashtable::num_item_index(int index){
    int num = 0;
    if(hashItems[index] == NULL)
        return num;
    else{
        item *temp = hashItems[index];
        num++;
        while(temp->next != NULL){
            num++;
            temp = temp->next;
        }
        
    }
    return num;
}

void hashtable::print_table(){
    for(int i = 0; i<tablesize; i++){
        if(hashItems[i] == NULL){
            cout<<"--------------------------------------\n";
            cout<< "hash table index "<<i<<" is empty. \n";
        }
        else{
            cout<<"--------------------------------------\n";
            cout<< "hash table index "<<i<<" contains "<<num_item_index(i)<<" elements\n";
            item *temp = hashItems[i];
            while(temp!= NULL){
                cout<<"ELEMENT name: "<<temp->name<<" drink: "<<temp->drink<< endl;
                temp = temp->next;
            }
        }
    }
    cout<<"------------------end-----------------\n\n";
}

string hashtable::findDrink(string name){
    int index = Hash(name);
    item *temp = hashItems[index];
    if(temp == NULL){
        cout<<"Cannot find "<<name<<endl;
        return "";
    }
    string drinklist = "";
    
    bool firstDrink = false;
    while(temp != NULL){
        if(temp->name == name && !firstDrink){
            firstDrink = true;
            drinklist +=temp->drink;
        }
        else if(temp->name == name && firstDrink)
            drinklist += "," + temp->drink;
        temp = temp->next;
    }
    
    cout<<name <<" order the following drinks: "<<drinklist<<endl;
    return drinklist;
}

int main(int argc, const char * argv[])
{
    hashtable *hashObj = new hashtable;
    hashObj->add_item("aa","1");
    hashObj->add_item("bb", "1");
    hashObj->add_item("cc", "1");
    hashObj->add_item("aa","2");
    hashObj->add_item("bb", "2");
    hashObj->add_item("bd", "3");
    hashObj->add_item("cc", "2");
    hashObj->add_item("aa","3");
    hashObj->add_item("bb", "3");
    hashObj->add_item("cc", "3");

    hashObj->print_table();
    hashObj->findDrink("cc");

    return 0;
}

