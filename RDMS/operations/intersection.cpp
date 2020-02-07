#include "operations.h"


Table Intersection(Table t1, Table t2){

    set<Tuple> relation1 = t1.getRelation();
    set<Tuple> relation2 = t2.getRelation();
    set<Tuple>:: iterator it_t1 = relation1.begin();
    set<Tuple>:: iterator it_t2 = relation2.begin();

    string inter_name = t1.getTableName() + "inter" + t2.getTableName();

    Table inter_t1_t2(inter_name, t1.getAttributes());

    
    while(it_t1 != relation1.end()){
        Tuple mytuple1 = *it_t1;
        while(it_t2 != relation2.end()){
            Tuple mytuple2 = *it_t2;
            
            if(mytuple1 == mytuple2) {
                try{
  
                    inter_t1_t2.addRow(mytuple1);
                    ++it_t2;
                }
                catch (const char* msg) {
                    ++it_t2;
                    cerr<< msg;
                    
                } 
        
            }   
            ++it_t2;         
        }++it_t1;  
}
    return inter_t1_t2;
};