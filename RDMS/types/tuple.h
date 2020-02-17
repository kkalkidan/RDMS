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
        Tuple(char row[]);
        
        void display();
        
        int  get_element(int index=0) const;

        int get_size(){return size;}
   
       
};
#endif
