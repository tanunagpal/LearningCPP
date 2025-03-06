#include <iostream>
using namespace std;

class Simple {
    private:
        int* data; //class has pointer variable or dynamic memory allocation
    public:
        Simple(int(value)):data(new int(value)) {
            cout<<"Constructor called data = "<<*data<<endl;
        }

        ~Simple() {
            if(data) delete data;
            cout<<"Destructor called "<<endl;
        }

        Simple(Simple&& other) {
            data = other.data;
            other.data = nullptr;
            cout<<"Move constructor called "<<endl;
        }

        //move assignment operator
        //return with reference for function chaining. it needs a permanent object and not temporary object
        //Also to ensure that we are operating the further actions on actual objects and not on a copy 
        //of the object. Whicb may lead to issues
        Simple& operator=(Simple&& other) noexcept {
            //make sure we are not assigning to ourselves
            if(this != &other)
            {data = other.data;
            other.data = nullptr; //put the source pointer to null
            }
            cout<< "Move assignment called "<<endl;
            return *this;
        }

        Simple(const Simple& other) {
            data = other.data;
            cout<<"Copy constructor called "<<endl;
        }
};


int main()
{
    Simple obj1 = 42;
    Simple obj2 = 52;

    obj2 = std::move(obj1); //typecasting the object tio rvalue reference. not moving it

    Simple obj3 = std::move(obj1); //this is amove constructor call and not assignment call

    return 0;
}