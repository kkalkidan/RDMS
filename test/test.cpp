#include "../RDMS/types/tuple.h"
#include "../RDMS/types/table.h"
#include "../RDMS/types/database.h"
#include <string>

void createTupleAndTraverse(){

    printf("Testing: Create Tuple and Traverse \n");
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    Tuple tuple1(v);
    printf("\n");
    tuple1.traverse(tuple1.getHead());
    printf("\tPassed");
    printf("\n");
}

void TupleGetElement(){

    printf("Testing: Tuple get element \n");
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    Tuple myfirst(v);
    printf("\n");

    if(myfirst.getElement(2, myfirst.getHead()) == 20){
        printf("\tPassed\n");
    }
    printf("\n");

}


Table createTableTraverse(){

    printf("Testing: create table and traverse rows \n");
    set<string> attr;
    attr.insert("name");
    attr.insert("age");
    Table t("mytable", attr);
    vector<int> v;
    v.push_back(9);
    v.push_back(2);
    t = t.addRow(v);

    t.showRows();
    printf("\tPassed");
    printf("\n\n");

    return t;
}



void DuplicateRows(Table t) {
    printf("Testing: Handling duplicate rows \n");

    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    int size = t.getRelation().size();

    vector<int> z;
    v.push_back(2);
    v.push_back(2);
    printf("\n");
    if(size == t.getRelation().size()){
        printf("\tPassed\n");
    }
     printf("\n");

}


int main() 
{ 
  createTupleAndTraverse();
  TupleGetElement();
  Table t = createTableTraverse();
  DuplicateRows(t);

  
} 