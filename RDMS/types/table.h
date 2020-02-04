
#ifndef TABLE_H
#define TABLE_H

#include<iostream>
#include<set>
#include "tuple.h"

using namespace std; 

class Table {

    private: 
        string table_name;
        set<string> attributes;
        set<Tuple> Relations;
    public:

        Table(string table_name, set<string> attributes);

        Table addRow(vector<int> row);

        set<Tuple> getRelation(){return Relations;};

        set<string> getAttributes(){return attributes;};

        string getTableName(){return table_name;};

        void showRows();
};
     
 
#endif