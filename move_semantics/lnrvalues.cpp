/*lrvalue: has memory location address like int i
lvalue reference: int& GetValue(){....}
rvalue: no memory location like 10. Cannot assign something to it like 10=i
can also be a return of a function like return 10

void SetValue(int v){...} can be called with both lvalue and rvalue

void SetValue(int& v){...} takes lvaue reference as input,,,can be called with lvalue only

int& a = 10 gives an error cannot have lvalue ref of an rvalue
const int& a =10 is OK as it is a workaround . const lvalue reference accepts rvalue

rvalue reference accepts only rvalue/temp objects
void PrintName(st::string&& name){...} will not accept lvaues but only rvalues
*/


#include <iostream>
using namespace std;

int SetValue(int num)
{
    //void SetValue(int v){...} can be called with both lvalue and rvalue
    //void SetValue(int& v){...} takes lvaue reference as input...can be called with lvalue only
    //void SetValue(int&& v){...} takes rvalue reference as input...can be called with rvalue only

}
int GetValue()
{
    return 10; //return rvalue
}
int main()
{
    int i=10; //i is lvalue and 10 is rvalue
    int a = i; //both a and i are lvalue

    int j = GetValue();  //j is lavaue and the return from GetValue is rvalue
    //GetValue() = 5; //rvalue cannot be assigned to another rvalue

    //int& b = 10; //lvalue reference cannot have rvalue
    const int& b = 10; //const lvalue refernce can have rvalue

    SetValue(i); //calling with lvalue
    SetValue(10); //calling withrvalue
}