#ifndef TUPLE_H
#define TUPLE_H

#include <iostream>
#include <set>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <boost/foreach.hpp> 


using namespace std; 

struct Node { 
    set<set<int>> base;
    struct Node* next;
}; 

class Tuple {

    private:
        Node* head;

    public :
        Node* newNode(set<set<int>> base);

        Node* createNode(Node* head, vector<int> v);

        void traverse(Node* next);
        
        Tuple* createTuple(vector<int> v);

        Node* getHead() {return head;};

        friend bool operator==(const Tuple &left, const Tuple &right){
            Node* left_head = left.head;
            Node* right_head = right.head;
            while(left_head != NULL && right_head != NULL){
                if(left_head->base != right_head->base){
                    return false;
                }
                left_head = left_head->next;
                right_head = right_head->next;
            }
            if(left_head != NULL || right_head != NULL){
                return false;
            }
            return true;
        };
        friend bool operator< (const Tuple &left, const Tuple &right){
            Node* left_head = left.head;
            Node* right_head = right.head;
            if(left_head != NULL && right_head != NULL){
                if(left_head->base > right_head->base){
                    return false;
                }
            } return true;
            
        };
  
};
#endif