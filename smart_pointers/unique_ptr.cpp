//when it goes out of scope, it will call delete
//scoped pointer
//cannot be copied
//lower overhead

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

        void Print() 
        {

        }
};

int main()
{
    { //created new scope to check if the unique pointer exist outside the scope or not. No they don't
        unique_ptr<Entity> entity(new Entity());  
        //= new Entity() will not work as unique pointer doesnt have implicit conversion
        //only explicit conversion

        //preferred way for unique pointer as it is safer in case of exception occurs
        //no dangling pointer is left in this type
        unique_ptr<Entity> entity1 = make_unique<Entity>();
        entity->Print();
    }
    cin.get();
}