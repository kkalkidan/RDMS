#ifndef TUPLE_H
#define TUPLE_H

#include <iostream>
#include <set>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <boost/foreach.hpp> 
#define foreach BOOST_FOREACH  


using namespace std; 

class Tuple {

    private:
        set<set<set<int>>> tuple;
        int first_element;
        int size = 0;

    public :
        Tuple();
        Tuple(char row[]);
        
        void display();
        
        int  get_element(int index=0) const;

        int get_size(){return size;};

        friend bool operator==(const Tuple &left, const Tuple &right){
            if(left.size != right.size) return false;  
            for(int i=1; i< left.size+1; i++){
                if(left.get_element(i) != right.get_element(i)){
                    return false;
                }
            }
            return true;
        };

        friend bool operator>(const Tuple &left, const Tuple &right){
            if(left.get_element(1) > left.get_element(1)){return true;}
            return false;
        };
};
#endif
