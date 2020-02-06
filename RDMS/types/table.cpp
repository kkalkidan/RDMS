#include "table.h" 
#include <boost/foreach.hpp> 
#define foreach BOOST_FOREACH  
    
Table::Table(string name, set<string> attri){
    table_name = name;
    attributes = attri;
    Relations = {};
};
Table Table:: addRow(vector<int> row){ 
    if(attributes.size() != row.size()) {
        throw "More row elements than attributes! ";
    }
    Relations.insert(Tuple(row));
    return *this;

};

void Table:: showRows(){

    foreach(Tuple element, this->Relations) {
        element.traverse(element.getHead());
        printf("\n");
    }
};





