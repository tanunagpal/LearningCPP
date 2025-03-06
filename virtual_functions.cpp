#include <iostream>

using namespace std;

class Fruit
{
public:
     virtual string getName() { return ("fruit"); }
     
     //virtual string getName() = 0; //it is pure virtual function. 
     //Every subclass is gauranted to have its implementation. 
     //Without its implementation you cannot instantiate the class
};

class Apple : public Fruit
{
private:
    string a_name;

public:
    Apple(const string &name) : a_name(name) {}
    string getName()  { return a_name; }
};

void printName(Fruit *e) 
{/*// without virtual keyword in base class the c
lass name present here is always cosidered to call the 
getname function. Irresptective of the object/pointer
calling this function*/
//with virtual keyword it call the getname of the class
//of the bject which called printname function

    cout << e->getName() << endl;
}
int main()
{
    Fruit *f = new Fruit();
    // cout<<f->getName()<<endl;
    printName(f);

    Apple *a = new Apple("red");
    // cout<<a->getName()<<endl;
    printName(a);

    //to check the presencr of v-table or v-pointer
    cout<<sizeof(Fruit)<<endl;

    return 0;
}
