#include <iostream>
#include <vector>
using namespace std;

//Ref:https://www.youtube.com/watch?v=QkROUMxwb40
//biggest use case of move construcotr is with STL containers, where pointer i used like *data (dynamic memory allocation)
//destructor is called after move constructor, as it does for a normal constructor
//mandatory to set the data pointer to null after copying all information

class Simple{
    private:
        int *data;
    public:
        Simple(int value) : data(new int(value)) {
            cout<<"Constructor called data = "<<*data <<endl;
        } 
        ~Simple() {
            if(data) delete data;
            cout << "Destructor called "<< endl;
        }
        Simple(Simple&& other) noexcept     //if noexcept is not written Copy constructor is called while resizing vector for data 1 and 2
        //noexcept tells the compiler that it is safe to use the move constructor and it wil not throw an exception
        {    
            data = other.data;
            other.data = nullptr;
            cout<< "Move constructor called "<< *data<<endl;
        }
        Simple(const Simple&other){
            data = new int(*other.data);
            cout<<"Copy constructor called "<<*data<<endl;
        }
};

int main() {
    vector<Simple> vec;
    vec.reserve(2);

    Simple s = 1;
    //Simple(1);

    vec.push_back(Simple(1)); //if s object is passed from line 33, move constructor is not called as s is an lvalue
    vec.push_back(Simple(2));

    cout<<"Resizing "<<endl;    //if the size of vector exceeds the reserved size it allocated a bigger memory and copies aal 
    //the data to it. Its all internal process and is not visible outside

    vec.push_back(Simple(3));

    return 0;

}