#include "../RDMS/types/tuple.h"
#include "../RDMS/types/table.h"
#include "../RDMS/types/database.h"
#include <string>

void createTupleAndTraverse(){

    printf("Testing: create tuple and traverse \n");
    Tuple* head = NULL; 
    Tuple t;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    head = t.createTuple(v); 
    printf("\t");
    t.traverse(t.getHead());
}

void createTableTraverse(){

    printf("Testing: create table and traverse rows \n");
    set<string> attr;
    attr.insert("name");
    attr.insert("age");
    Table t("mytable", attr);
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    
    t = t.addRow(v);
    vector<int> s;
    s.push_back(3);
    t = t.addRow(s);

    printf("Number of rows = %ld \n", t.getRelation().size());
    t.showRows();
}


int main() 
{ 
  createTupleAndTraverse();
  createTableTraverse();

} 