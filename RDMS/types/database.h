#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <map>
#include <set>
#include "table.h"
#include "tuple.h"

using namespace std; 
class Database{

    private:
        map<string, Table> database;

    public:

        Table createTable(string table_name, set<string> attributes);

        void showDatabase();

        Table getTable(string table_name);
};
 
#endif