
#include "tuple.h"
#include <algorithm>





Node *Tuple :: newNode(set<set<int>> base) 
{ 
    Node *new_node = new Node; 
    new_node->base = base; 
    new_node->next = NULL; 
    return new_node; 
};

Node* Tuple :: createNode(Node* head, vector<int> v) 
{ 
    set<int> first, second;
    set<set<int>> s;

    first.insert(v.front());
    if(v.size() > 1) second.insert(v.begin(), v.begin()+2);
    else second.insert(v.front());

    s.insert(first);
    s.insert(second);

    v.erase(v.begin());
    
    if (head == NULL)  
        head = newNode(s); 

    if(v.size() > 1) {
        head->next = createNode(head->next, v); 
    }
    
    return head; 
};


Tuple:: Tuple (vector<int> v){

    size = v.size();
    first_node = createNode(NULL, v);
}


void Tuple :: traverse(Node* head){
    
    if(head == NULL) return;
    set<set<int>> ::iterator it;
    set<set<int>> s = head->base;

    printf("{ ");
    for(it = s.begin(); it!= s.end(); ++it){
        set<int> :: iterator in;
        printf("{ ");
        for(in = it->begin(); in!= it->end(); ++in){
            printf("%d, ", *in);
        } printf("}, ");
    }
    printf("}");
    printf("->");
    
    traverse(head->next);
    printf("\n");
};


int Tuple :: getElement(int index, Node* head) const{
    if(index <= 0 || index > size){
        return -1;
    }else {
        Node* node = head;
        int i =1;        
        while(i < index && node->next != NULL){
            i++;
            if(node->next != NULL) node = node->next;
        } 
        set<set<int>> pairs = node->base;
        
        if(i == index){
            foreach(set<int> pair, pairs){
                if(pair.size() == 1){
                    foreach(int element, pair){
                        return element;
                    }
                }
            }
        }
        
        int first;
        set<int> second, diff;
        foreach(set<int> pair, pairs){
            if(pair.size() == 1){
                first = *(pair.begin());
            }
            if(pair.size() == 2){
                second = pair;
            }
        }
        if(second.size() == 2){
            foreach(int element, second){
                if(element != first){
                    return element;
                }
            }
        } 
        return first;     
    }
    
};

