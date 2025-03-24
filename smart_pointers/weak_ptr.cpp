//copy shared pointer to shared pointer increase the ref coount
//copy shared pointer to weak pointer doesn't increase the ref count

//reference counting
//control block keeps the count of reference for the pointer
//can be copied

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
        weak_ptr<Entity> w0;
        {
               
        //shared_ptr<Entity> e1(new Entity()); //compiles fine but not efficint
        shared_ptr<Entity> e2 = make_shared<Entity>();
        weak_ptr<Entity> w1 = e2; //copied but ref count is not incremented //dont want the ownership
        w0 = e2;
        } //ref count is not incresed so the e2 get destroyed here even if w0 is refering to it
    }
 //use breakpoint to understand better
    cin.get();
}