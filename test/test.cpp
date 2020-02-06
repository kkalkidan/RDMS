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

void TupleGetElement() {

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


void createTableTraverse(){
    try {
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
    } catch (const char* msg) {
        printf("\n");
        cerr << msg << endl;
        printf("\n");
   }
}

void moreThanOneRow() {
    try {
        printf("Testing: Handling multiple Rows\n");
        set<string> attr;
        attr.insert("name");
        attr.insert("age");
        Table t("mytable", attr);
        vector<int> v;
        v.push_back(9);
        v.push_back(2);
        t = t.addRow(v);

        vector<int> z;
        z.push_back(2);
        z.push_back(9);
        t.addRow(z);

        printf("\n");
        if(t.getRelation().size() == 2){
            printf("\tPassed");
        }
        printf("\n\n");
        } catch (const char* msg) {
        printf("\n");
        cerr << msg << endl;
        printf("\n");
   }
}

void DuplicateRows() {
    try {
        printf("Testing: Handling duplicate rows \n");
        set<string> attr;
        attr.insert("name");
        attr.insert("age");
        Table t("mytable", attr);
        vector<int> v;
        v.push_back(9);
        v.push_back(2);
        t.addRow(v);
        int size = t.getRelation().size();
        vector<int> z;
        z.push_back(9);
        z.push_back(2);
        t.addRow(z);
        printf("\n");
        if(size = t.getRelation().size()){
            printf("\tPassed");
        }
        printf("\n\n");
    } catch (const char* msg) {
        printf("\n");
        cerr << msg << endl;
        printf("\n");
   }

}


int main() 
{ 
  createTupleAndTraverse();
  TupleGetElement();
  createTableTraverse();
  moreThanOneRow();
  DuplicateRows();

  
} 