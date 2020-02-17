
#include "tuple.h"
#include <stdio.h> 
#include <string.h> 
  




Tuple::Tuple(char row[]) 
{   
    char *token = strtok(row, " ");
    string prev;

    while(token != NULL){     
        if(!prev.empty()){
            set<int> first = {atoi(prev.c_str())};
            set<int> second = {atoi(prev.c_str()), atoi(token)};
            tuple.insert({first, second});
        } else first_element = atoi(token);
        prev = token; 
        token = strtok(NULL, " ");
    }
    size = tuple.size() +1;
    
};


void Tuple::display(){

    get_element();

};

int Tuple::get_element(int index) const{
    
    bool display = false;
    if(index == 0){
        display = true;
        index = tuple.size()+1;
    } 

    if(!display){
        if(index > tuple.size()+1) {throw "Error!";}
        if(index == 1){return first_element;}
    }else printf("%d, ", first_element);

    int element = first_element;
    for(int i=1; i < index; i++){
        foreach(set<set<int>> base, tuple){
            if(base.find({element}) != base.end()){
                foreach(set<int> ele , base){
                    if(ele.size() == 2){
                        foreach(int number, ele){
                            if(number != element){
                                element = number;
                            }
                        }
                    }
                }
            break;
            }
        }
        if(display) printf("%d, ", element);
    }     
    
    return element;

}
