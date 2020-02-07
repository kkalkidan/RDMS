#include "operations.h"


Table Selection(Table table, string attr, char the_operator, int value){

    set<Tuple> relation = table.getRelation();
    string sel_name = table.getTableName() + "_sel";
    

    Table sel_table(sel_name, table.getAttributes());
    int index = table.getIndex(attr);
    foreach(Tuple tuple1, relation){
        
        int element = tuple1.getElement(index, tuple1.getHead());
        if(element == -1){
                throw "Attribute name Not Found!";
                return sel_table;
            }
        if(operate(element, value, the_operator)){
            sel_table.addRow(tuple1);
        }
    }

    return sel_table;

};

bool operate(int ele1, int ele2, char op){
    switch(op){
        case '=':
            return ele1 == ele2;
        case '>':
            return ele1 > ele2;
        case '<':
            return ele1 < ele2;
        default:
            return false;
    };
}