/*emeory allocation fucntions
malloc calloc
new and delete

This code is an example fo custom memory allocator. When we want to control the allocation and deallocation the memory
Need the following
--type of value
-- allocator function to allocate memory for n objects
-- deallcator to deallocate memory from these n objects. It is pointed by a pointer p

Note: allocator_traits in C++ https://en.cppreference.com/w/cpp/memory/allocator_traits
Code taken from https://www.geeksforgeeks.org/how-to-create-custom-memory-allocator-in-cpp/

*/

// C++ Program to show how to create custom allocator
#include <iostream>
#include <vector>
using namespace std;

// Custom memory allocator class
template <typename T> class myClass {
public:
    typedef T value_type;
    // Constructor
    myClass() noexcept {}
    // Allocate memory for n objects of type T
    T* allocate(std::size_t n)
    {
        return static_cast<T*>(
            ::operator new(n * sizeof(T)));
    }
    // Deallocate memory
    void deallocate(T* p, std::size_t n) noexcept
    {
        ::operator delete(p);
    }
};
int main()
{
    // Define a vector with the custom allocator
    vector<int, myClass<int> > vec;
    for (int i = 1; i <= 5; ++i) {
        vec.push_back(i);
    }
    // Print the elements
    for (const auto& elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}


