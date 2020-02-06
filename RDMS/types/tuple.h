#ifndef TUPLE_H
#define TUPLE_H

#include <iostream>
#include <set>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <boost/foreach.hpp> 
#define foreach BOOST_FOREACH  


using namespace std; 

struct Node { 
    set<set<int>> base;
    struct Node* next;
        
};

class Tuple {

    private:
        Node* first_node;
        int size = 0;

    public :
        Tuple(vector<int> v);
        
        Node* newNode(set<set<int>> base);

        Node* createNode(Node* head, vector<int> v);

        void traverse(Node* next);

        Node* getHead() {return first_node;};
        
        int  getElement(int index, Node* head) const;

        friend bool operator==(const Tuple &left, const Tuple &right){  
            if(left.size != right.size){
                return false;
            }
            int i =1;
            for(i=1; i <= right.size; i++){
                int first = left.getElement(i, left.first_node);
                int second = right.getElement(i, left.first_node);
                if(left.getElement(i, left.first_node) != right.getElement(i, left.first_node)){
                    return false;
                }
            }
            return true;
        };
        friend bool operator< (const Tuple &left, const Tuple &right){
            int i =1;
            for(i=1; i <= right.size; i++){
                int first = left.getElement(i, left.first_node);
                int second = right.getElement(i, right.first_node);
              
                if(left.getElement(i, left.first_node) < right.getElement(i, right.first_node)){
                    return true;
                }
            }
            return false;
        };
        int getSize(){return size;};
       
  
};
#endif