/*Lamda Function
--Introduced in C++11.
--Allow inline functions for short code snippets.
--Do not require a name
--Used for anonymous function objects.
--Encapsulate a few lines of code passed to algorithms or asynchronous functions.
--Provide a way to create compact, inline functions on the fly.

Capture
[&]: capture all external variables by reference.
[=]: capture all external variables by value.
[a, &b]: capture ‘a’ by value and ‘b’ by reference.

(): Input arguments
{}: Body

Note:Mutable keyword is used in capture by value lambdas because, by default, value captured objects are const.
*/

#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v) {
    for (auto x : v) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> v1, v2;

    // Capture v1 and v2 by reference
    auto byRef = [&] (int m) {
        v1.push_back(m);
        v2.push_back(m);
    };
    
    // Capture v1 and v2 by value
    auto byVal = [=] (int m) mutable {
        v1.push_back(m);
        v2.push_back(m);
    };
    
    // Capture v1 by reference and v2 by value
    auto mixed = [=, &v1] (int m) mutable {
        v1.push_back(m);
        v2.push_back(m);
    };

    // Push 20 in both v1 and v2
    byRef(20);
    
    // Push 234 in both v1 and v2
    byVal(234);
    
    // Push 10 in both v1 and v2
    mixed(10);
    
    print(v1);
    print(v2);
    
    return 0;
}

