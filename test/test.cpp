#include "../RDMS/types/tuple.h"

#include <stdio.h> 
#include <string.h>
#include <cassert> 
#include <iostream>


void covert_string_to_tuple(){
    char str[] = "3 6 9 10";
    Tuple t(str);
    t.display();
}

void test_get_element(){
    char str[] = "3 3 9 10";
    Tuple t(str);
    
    assert(3 == t.get_element(1));
    assert(3 == t.get_element(2));
    assert(9 == t.get_element(3));
    assert(10 == t.get_element(4));
}

void compare_tuples(){

    char str[] = "3 3 9 10";
    char str2[] = "3 3 9 10";
    Tuple t1(str);
    Tuple t2(str2);
    
    assert(t1 == t2);
}
  
int main() 
{ 
   covert_string_to_tuple();
   compare_tuples();

} 