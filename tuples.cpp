#include<iostream>
#include<set>
#include<string>
#include<boost/variant.hpp>
using namespace std;
template<class T>
class Tuples{
public:
set<set<set<T>>> tuples(T a,T b){
set<T> total_set;
set<set<T>>first_orderd;

total_set.insert(x);
total_set.insert(y);


first_orderd.insert(total_set);
return first_orderd;
}

 };

int main(){

set<set<set<boost::variant<double,std::string,int>>>> result;
string a ;
int b ;
string c ;
std::cout << "enter the name: " ;
std::cin >> x;
std::cout << "enter the id: " ;
std::cin >>y;
Tuples<boost::variant<double,std::string,int>>  Tu ;

result = Tu.tuples(a,b,c);
std::cout << "(" ;
for (set<set<set<boost::variant<double,std::string,int>>>>::iterator it_ex=result.begin();it_ex!=result.end();++it_ex){
for (set<set<boost::variant<double,std::string,int>>>::iterator it_in=it_ex->begin();it_in!=it_ex->end();++it_in){
cout<<" "  << *it_in1<<" ";
cout<<")"<<endl;
}
}


return 0;
}
