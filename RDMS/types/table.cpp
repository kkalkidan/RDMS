#include "table.h" 
#include <boost/foreach.hpp> 
#define foreach BOOST_FOREACH  
    
Table::Table(string name, set<string> attri){
    table_name = name;
    attributes = attri;
    Relations = {};
};
template <>
Table Table:: addRow(vector<int> row){ 
    if(attributes.size() != row.size()) {
        throw "More row elements than attributes! ";
    }
    Relations.insert(Tuple(row));
    return *this;

};
template <>
Table Table:: addRow(Tuple tuple){

    if(tuple.getSize() != attributes.size()){
        throw "More row elements than attributes! ";
    }
    Relations.insert(tuple);

    return *this;

};

void Table:: showRows(){

    foreach(Tuple element, this->Relations) {
        element.traverse(element.getHead());
        printf("\n");
    }
};

int Table:: getIndex(string attr){
    int i = 1;
    foreach(string a, attributes){
        if(a.compare(attr) == 0){
            return i;
        }
        i++;
    }
    return -1;
}



