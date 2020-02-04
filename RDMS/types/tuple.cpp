
#include "tuple.h"




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
        head= newNode(s); 

    if(v.size() > 1) {
        head->next = createNode(head->next, v); 
    }
    
    return head; 
};

Tuple* Tuple:: createTuple (vector<int> v){

    head = createNode(NULL, v);
    return this;
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


