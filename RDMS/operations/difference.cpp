#include "operations.h"


Table Difference(Table t1, Table t2){

    set<Tuple> relation1 = t1.getRelation();
    set<Tuple> relation2 = t2.getRelation();
    set<Tuple>:: iterator it_t1 = relation1.begin();
    set<Tuple>:: iterator it_t2 = relation2.begin();

    string diff_name = t1.getTableName() + "diff" + t2.getTableName();

    Table diff_t1_t2(diff_name, t1.getAttributes());

    
    while(it_t1 != relation1.end()){
        Tuple mytuple1 = *it_t1;
        bool add = true;
        while(it_t2 != relation2.end()){
             Tuple mytuple2 = *it_t2;
            if(mytuple1 == mytuple2) {
                add = false;
                break;      
            } 
            ++ it_t2;
            } 
        if(add) {
            diff_t1_t2.addRow(mytuple1); 
        }++it_t1; it_t2 = relation2.begin();
    } 

    it_t1 = relation1.begin();
    it_t2 = relation2.begin();

    while(it_t2 != relation2.end()){
        Tuple mytuple2 = *it_t2;
        bool add = true;
        while(it_t1 != relation1.end()){
            Tuple mytuple1 = *it_t1;
            if(mytuple1 == mytuple2) {
                add = false;
                break;      
            } 
            ++it_t1;
            } 
        if(add) {
            diff_t1_t2.addRow(mytuple2); 
        }++it_t2; it_t1 = relation1.begin();
    }  
    
    return diff_t1_t2;
};
