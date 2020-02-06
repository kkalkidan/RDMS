
#include "database.h"
using namespace std; 

Table Database:: createTable(string table_name, set<string> attributes){

    pair<map<string,Table>::iterator,bool> ret;
     
    ret = database.insert({table_name, Table(table_name, attributes)});

    if (ret.second==false) {
         cout << "table name already exists";
        }

    return this->getTable(table_name);
};

void Database :: showDatabase(){
    
    cout << "List of Tables : \n";
    for(map<string,Table>::iterator it = database.begin(); it != database.end(); ++it) {
        cout << "\n \t" <<  it->first << "\n";
    }

};

Table Database :: getTable(string table_name){

    map<string, Table>::iterator it;
    
    it = database.find(table_name);
    
    return it->second;

};