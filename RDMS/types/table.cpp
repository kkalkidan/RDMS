#include "table.h" 
#include <boost/foreach.hpp> 
#define foreach BOOST_FOREACH  
    
Table::Table(string table_name, set<string> attributes){
    table_name = table_name;
    attributes = attributes;
    Relations = {};
}
Table Table:: addRow(vector<int> row){

    Tuple t;
    t.createTuple(row);
    Relations.insert(t);
    return *this;

}

void Table:: showRows(){

    foreach(Tuple element, this->Relations) {
        element.traverse(element.getHead());
        printf("\n");
    }
}




