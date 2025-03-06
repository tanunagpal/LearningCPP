/*Sorting using lambda function*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {100, 1, 28, 83, 92, 12};

    //ascending order
    sort(v.begin(), v.end(), [] (const int& a, const int&b) {
        return a < b;
    });

    for (int x : v)
        cout << x << " ";
    return 0;
}