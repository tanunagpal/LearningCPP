//reference counting
//control block keeps the count of reference for the pointer
//can be copied
//copy shared pointer to shared pointer increase the ref coount


#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Entity
{
    public:
        Entity()
        {
            cout<<"Created Entity"<<endl;
        }

        ~Entity()
        {
            cout<<"Destroyed Entity"<< endl;
        }
};

int main()
{
    { 
        shared_ptr<Entity> e0;
        {
               
        //shared_ptr<Entity> e1(new Entity()); //compiles fine but not efficint
        shared_ptr<Entity> e2 = make_shared<Entity>();
        e0 = e2;
        } //even though e2 goes out of scope here, it is not destroyed as a reference to e0 is still pending
    }
    //destryoed here //use breakpoint to understand better
    cin.get();
}