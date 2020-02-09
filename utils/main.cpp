
#include "../RDMS/operations/operations.h"
#include "../RDMS/types/tuple.h"
#include "../RDMS/types/table.h"
#include "../RDMS/types/database.h"
#include "../RDMS/operations/operations.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {

    Database mydatabase;

    string table_name1 = "table1";
    string table_name2 = "table2";
    string table_name3 = "table3";

    set<string> attr1 = {"id", "age", "phone", "score"};
    set<string> attr2 = {"id", "salary", "hour"};

    Table table1 = mydatabase.createTable(table_name1, attr1);
    Table table2 = mydatabase.createTable(table_name2, attr2);
    Table table3 = mydatabase.createTable(table_name3, attr1);
    
    mydatabase.showDatabase();

    vector<int> id;

    id.push_back(1);
    id.push_back(2);
    id.push_back(3);
    id.push_back(4);
    
    vector<int> age;

    age.push_back(11);
    age.push_back(21);
    age.push_back(31);
    age.push_back(41);

    vector<int> phone;

    phone.push_back(111);
    phone.push_back(221);
    phone.push_back(331);
    phone.push_back(441);

    vector<int> score;

    score.push_back(5);
    score.push_back(6);
    score.push_back(7);
    score.push_back(8);

    int i = 0;
    printf("\n\nTable 1 \n\n");
    for(int j =0; j < score.size(); j++){
        vector<int> row;
        foreach(string a, attr1){
           
            if(a.compare("age") == 0){
                row.push_back(age.at(i));
            }
            else if(a.compare("id") == 0){
                row.push_back(id.at(i));
            }
            else if(a.compare("phone") == 0){
                row.push_back(phone.at(i));
            }
            else if(a.compare("score") == 0){
                row.push_back(score.at(i));
            }
            if(i==0) printf(" %s ", a.c_str());
        }
        printf("\n");
        if(j < 1) table1.addRow(row);
        else table3.addRow(row);
        if(j == 1){
            table1.addRow(row);
            table3.addRow(row);
        }
        i++;
    }

  
    table1.showRows();

    vector<int> id2;

    id2.push_back(2);
    id2.push_back(3);
    id2.push_back(4);

    vector<int> salary;

    salary.push_back(52);
    salary.push_back(53);
    salary.push_back(54);

    vector<int> hour;

    hour.push_back(23);
    hour.push_back(33);
    hour.push_back(43);
    i = 0;
    printf("\n\nTable 2 \n\n");
    for(int j =0; j < hour.size(); j++){
        vector<int> row;
        foreach(string a, attr2){
           
            if(a.compare("id") == 0){
                row.push_back(id2.at(i));
            }
            else if(a.compare("salary") == 0){
                row.push_back(salary.at(i));
            }
            else if(a.compare("hour") == 0){
                row.push_back(hour.at(i));
            }
            if(i==0) printf(" %s ", a.c_str());
        }
        printf("\n");
        table2.addRow(row);
        i++;
    }

    
    table2.showRows();


    printf("\n\nTable 3 \n\n");

    table3.showRows();

    printf("\n\n Union table 1 and table 3 \n\n");
    Table uni = Union(table1, table3);
    uni.showRows();

    printf("\n\nIntersection table 1 and table 3 \n\n");
    // table3.showRows();
    Table inter = Intersection(table1, table3);

    inter.showRows();

    printf("\n\nDifference table 1 and  table 3 \n\n");
    // table3.showRows();
    Table diff = Difference(table1, table3);

    diff.showRows();

    printf("\n\nSelecting a row from table 3 \n\n");

    Table sel = Selection(table3, "id", '=', 3);
    sel.showRows();

    printf("\n\nProjections  table 3 \n\n");
    set<string> proj_attrs;

    proj_attrs.insert("id");
    proj_attrs.insert("age");

    Table proj = Projection(table3, proj_attrs);
    proj.showRows();

    printf("\n\nJoin  table 3  and table 2 \n\n");
    
    Table join = Join(table3, table2);
    join.showRows();

}