#include "../RDMS/types/tuple.h"
#include "../RDMS/types/table.h"
#include "../RDMS/types/database.h"
#include <string>
#include "../RDMS/operations/operations.h"

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

void createDatabase(){

    printf("Testing: Creating a database, creating Table, Showing Rows \n");
    Database database;
    set<string> attributes;
    attributes.insert("name");
    attributes.insert("age");
    Table t = database.createTable("mytable", attributes);
    database.showDatabase();

    
    vector<int> v;
    v.push_back(9);
    v.push_back(2);
    t = t.addRow(v);
    t.showRows();

    printf("\n");
    printf("Passed");
    printf("\n");

}

void CreateMultipleTablesInsideDatabase(){
    printf("Testing: Creating Multiple Tables Inside Database \n");
    Database database;
    set<string> attributes;
    attributes.insert("name");
    attributes.insert("age");
    Table t1 = database.createTable("mytable1", attributes);
    Table t2 = database.createTable("mytable2", attributes);
    Table t3 = database.createTable("mytable3", attributes);
    database.showDatabase();

    printf("\n");
    printf("Passed");
    printf("\n");
}

void TestUnion() {
    printf("Testing: Union Operation \n");
    set<string> attributes;
    attributes.insert("name");
    attributes.insert("age");
    Table t1("table1", attributes);

    
    vector<int> v;
    v.push_back(10);
    v.push_back(20);

    t1.addRow(v);

    Table t2("table2", attributes);

    vector<int> z;
    z.push_back(10);
    z.push_back(20);

    t1.addRow(z);

    Table uni = Union(t1, t2);

    printf("\n\n union size = %d\n\n", uni.getSize());
    printf("\n\n Passed \n\n");

}

void TestIntersection(){
    printf("Testing: Intersection Operation \n");
    set<string> attributes;
    attributes.insert("name");
    attributes.insert("age");
    Table t1("table1", attributes);
    Table t2("table2", attributes);

    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    
    t1.addRow(v);

    vector<int> z;
    z.push_back(30);
    z.push_back(20);
    t2.addRow(v);
    t2.addRow(z);
    
    Tuple tuple1(v);
    Tuple tuple2(z);

    Table inter = Intersection(t1, t2);

    printf("\nintersection size = %d",inter.getSize());
    if(inter.getSize() == 1){
        printf("\nPassed\n");
    }
}

void TestDifference(){
    printf("Testing: Difference Operation \n");
    set<string> attributes;
    attributes.insert("name");
    attributes.insert("age");
    Table t1("table1", attributes);
    Table t2("table2", attributes);

    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    
    t1.addRow(v);

    vector<int> z;
    z.push_back(30);
    z.push_back(20);

    t2.addRow(z);
    
    Tuple tuple1(v);
    Tuple tuple2(z);

    Table diff = Difference(t1, t2);

    printf("\ndifference size = %d",diff.getSize());
    if(diff.getSize() == 2){
        printf("\nPassed\n");
    }
}

void TestProjections(){
    printf("Testing: Projections Operation \n");
    set<string> attributes;
    attributes.insert("name");
    attributes.insert("age");

    Table t1("table1", attributes);
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    t1.addRow(v);

    set<string> proj_attributes;
    proj_attributes.insert("name");
    Table t2 = Projection(t1, proj_attributes);
    t2.showRows();
}

void TestSelection(){
    printf("Testing: Selection Operation \n");
    set<string> attributes;
    attributes.insert("name");
    attributes.insert("age");

    Table t1("table1", attributes);
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    t1.addRow(v);

    vector<int> z;
    z.push_back(30);
    z.push_back(40);
    t1.addRow(z);

    Table t2 = Selection(t1, "name", '=', 20);
    t2.showRows();   
}


int main() 
{ 
  createTupleAndTraverse();
  TupleGetElement();
  createTableTraverse();
  moreThanOneRow();
  DuplicateRows();
  createDatabase();
  CreateMultipleTablesInsideDatabase();
  TestUnion();
  TestIntersection();
  TestDifference();
  TestProjections();
  TestSelection();

  
} 