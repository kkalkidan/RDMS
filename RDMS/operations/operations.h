#include "../types/database.h"
#include <algorithm>

Table Union (Table t1, Table t2);
Table Intersection(Table t1, Table t2);
Table Difference(Table t1, Table t2); 
Table Projection(Table table, set<string> attr);
Table Selection(Table table, string attr, char the_operator, int value);
bool operate(int ele1, int ele2, char op);
Table Join (Table table1, Table table2);