#include "operations.h"


Table Join (Table table1, Table table2){
    
    set<Tuple> relation1 = table1.getRelation();
    set<Tuple> relation2 = table2.getRelation();

    set<Tuple>:: iterator it_t1 = relation1.begin();
    set<Tuple>:: iterator it_t2 = relation2.begin();

    set<string> attribute1 = table1.getAttributes();
    set<string> attribute2 = table2.getAttributes();

    int index1, index2;

    string join_name = table1.getTableName()+  "_join_" + table1.getTableName();
    
    
    set<string>common;
    set<string> new_attr;

    foreach(string attr1, attribute1){
        if(attribute2.find(attr1) != attribute2.end()){
            common.insert(attr1);
        }
        new_attr.insert(attr1);
          
    }

    foreach(string attr2, attribute2){
        if(attribute1.find(attr2) != attribute1.end()){
            common.insert(attr2);
        }
        new_attr.insert(attr2);
        
    }
    
    Table join_table(join_name, new_attr);

    while(it_t1 != relation1.end()){
        Tuple tuple1 = *it_t1;
        while(it_t2 != relation2.end()){
            Tuple tuple2 = *it_t2;
            bool add = true;
            foreach(string a, common){
                index1 = table1.getIndex(a);
                index2 = table2.getIndex(a);
                if(tuple1.getElement(index1, tuple1.getHead()) 
                    != tuple2.getElement(index2, tuple2.getHead())){
                    add = false;
                }
            }
            if(add){
                vector<int> row;
                foreach(string a, new_attr){
                    index1 = table1.getIndex(a);
                    if(index1 != -1){
                        row.push_back(tuple1.getElement(index1, tuple1.getHead()));
                    }else {
                        index2 = table2.getIndex(a);
                        row.push_back(tuple2.getElement(index2, tuple2.getHead()));
                    }
                }
                join_table.addRow(row);                   
                }
            it_t2++;
            } it_t1++; it_t2 = relation2.begin();
        }

        return join_table;
    }





