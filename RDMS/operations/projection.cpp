#include "operations.h"

Table Projection(Table table, set<string> attr){
    set<Tuple> relation = table.getRelation();
    string proj_name = table.getTableName() + "proj";
   

    Table proj_table(proj_name, attr);

    foreach (Tuple tuple1, relation){
        vector<int> rows;
        foreach(string s, attr){
            int index = table.getIndex(s);
            int element = tuple1.getElement(index, tuple1.getHead());
            if(element == -1){
                throw "Attribute name Not Found!";
                return proj_table;
            }
            rows.push_back(element);
        }

        proj_table.addRow(rows);
    }

    return proj_table;

};