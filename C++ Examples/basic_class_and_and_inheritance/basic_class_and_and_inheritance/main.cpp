//
//  main.cpp
//  basic_class_and_and_inheritance
//
//  Created by Jiancong Guo on 7/26/15.
//  Copyright (c) 2015 Jiancong Guo. All rights reserved.
//

#include <iostream>
using namespace std;

#define NAME_SIZE 50

class Person{
    int id;
    char name[NAME_SIZE];
    
public:
    virtual ~Person(){
        cout<< "Deleting a Person.\n";
    }
    virtual void aboutMe(){
        cout<<"I am a person.\n";
    }
    virtual bool addCourse(string s) = 0;
};

class Student : public Person{
public:
    ~Student(){
        cout<< "Deleting a student. \n";
    }
    void aboutMe(){
        cout<<"I am a student. \n";
    }
    bool addCourse(string s){
        cout<<"Added course "<<s<<" to student.\n"<<endl;
        return true;
    }
};

int main(int argc, const char * argv[])
{
    Person *p = new Student;
    p->aboutMe();
    p->addCourse("History");
    delete p;
    return 0;
}

