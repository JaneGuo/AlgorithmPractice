//
//  main.cpp
//  reverse_words_in_a_string
//
//  Created by Jiancong Guo on 7/18/15.
//  Copyright (c) 2015 Jiancong Guo. All rights reserved.
//

#include <iostream>
#include <vector>
/*
void reverse_string(std::string::iterator start, std::string::iterator end){
    
    char tmp;
    while((start != end) && (start != end --)){
        tmp = *start;
        *start = *end;
        *end= tmp;
        ++start;
    }
}
*/
// This version is not trailing multiple spaces
void reverseWords(std::string &s){
    reverse(s.begin(), s.end());
    std::cout<<"This is the totally reversed string "<<s<<std::endl;
    
    std::string::iterator w_begin = s.begin(); //beginning of a word
    std::string::iterator w_end = s.begin(); //end of a word
    std::string::iterator it = s.begin();
    
    while(it!=s.end()){
        //this it is not a space, then move the w_end
        if(!isspace(*it)){
            w_end = it;
            it++;
            
        }
        //If it is a space and is the end of a word
        else if((isspace(*it))&& w_begin < w_end){
            reverse(w_begin, w_end+1);
            //reset w_begin and w_end
            w_begin = ++it;
            w_end = w_begin;
        }
        //If there are multiple spaces in the string, or a single letter word
        else if(isspace(*it) && w_begin == w_end){
            w_begin = ++it;
            w_end = w_begin;
        }
        else
            std::cout<<"Error: this situation is not handled. ";
    }
    
    //this is the end word in the string
    if(w_end>w_begin){
        reverse(w_begin,w_end+1);
    }
}

void reverseWords2(std::string &s){
    
    std::vector<std::string> words; // words used to store words in the string
    for(size_t i=0; i < s.size(); i++){
        if(isalpha(s[i])||isnumber(s[i])){   //note: depend on the question, it might be !isspace(s[i])
            size_t word_begin = i;
            for(++i; i < s.size(); i++){
                if(isspace(s[i]))
                    break;
            }
            words.push_back(s.substr(word_begin, i - word_begin));
        }
    }
    s = "";
    if(words.size() == 0) return;
    std::vector<std::string>::iterator iter;
    for(iter = --words.end(); iter!=words.begin(); iter--){
        s += *iter+" ";
    }
    s += *iter;
}

/*
void reverse_string(std::string *start, std::string *end){
    
    std::string tmp;
    while(start < end){
        tmp = *start;
        *start = *end;
        *end= tmp;
        std::cout<<"reverse string "<<*start<<"\t"<<*end<<std::endl;
        std::cout<<"this is a test";
        start = start +1;
        end = end +1;
        std::cout<<"fuck";
    }
}
*/

int main(int argc, const char * argv[])
{

    // insert code here...
    std::string a="this is a  dog";
    reverseWords(a);
    
    std::string b = "abc";
    reverse(b.begin(),b.end());
    
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    
    std::string c="this is 1 dog";
    reverseWords2(c);
    std::cout<<"reverse words 2 '"<<c<<"'"<<std::endl;
    
    return 0;
}

