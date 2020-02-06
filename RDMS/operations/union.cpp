
#include "operations.h"

Table Union (Table t1, Table t2){

    set<Tuple> relation1 = t1.getRelation();
    set<Tuple> relation2 = t2.getRelation();
    set<Tuple>:: iterator it_t1 = relation1.begin();
    set<Tuple>:: iterator it_t2 = relation2.begin();

    string union_name = t1.getTableName() + "union" + t2.getTableName();

    Table union_t1_t2(union_name, t1.getAttributes());

    
    while(it_t1 != relation1.end()){
        Tuple mytuple = *it_t1;
        try{
            union_t1_t2.addRow(mytuple);
            ++it_t1;
            }
        catch (const char* msg) {
            ++it_t1;
            cerr<< msg;
            
        }        
    }

     while(it_t2 != relation2.end()){
        Tuple mytuple = *it_t2;
        try{
            union_t1_t2.addRow(mytuple);
            ++it_t2;
            }
        catch (const char* msg) {
            ++it_t2;
            cerr<< msg;
            
        }        
    }
    
    return union_t1_t2;
}