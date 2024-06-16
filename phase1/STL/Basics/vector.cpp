// Vectors in C++ : Utilities

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Declaration and Initialization
    // Time Complexity: O(n) where n is the number of elements in the initializer list
    vector<int> myVector = {1, 2, 3, 4, 5};

    // Insert Elements
    // Time Complexity: O(1) for push_back, O(n) for insert (since it may require moving elements)
    myVector.push_back(6);
    myVector.insert(myVector.begin() + 2, 10);

    // Access Elements
    // Time Complexity: O(1) for accessing elements by index
    int firstElement = myVector[0];
    int lastElement = myVector.back();

    // Remove Elements
    // Time Complexity: O(1) for pop_back, O(n) for erase (since it may require moving elements)
    myVector.pop_back();
    myVector.erase(myVector.begin() + 1);

    // Size and Capacity
    // Time Complexity: O(1) for size, O(1) for capacity
    int size = myVector.size();
    int capacity = myVector.capacity();

    // Iteration
    // Time Complexity: O(n) for iterating through the vector
    cout << "Vector Elements: ";
    for (int i = 0; i < myVector.size(); ++i)
    {
        cout << myVector[i] << " ";
    }
    cout << endl;

    // Clear
    // Time Complexity: O(n) for clear (since it may require destroying each element)
    myVector.clear();

    // Resize
    // Time Complexity: O(n) for resize (if the new size is greater than the current size)
    myVector.resize(10);

    // Swap
    // Time Complexity: O(1) for swap (swap only involves swapping internal pointers)
    vector<int> anotherVector = {7, 8, 9};
    myVector.swap(anotherVector);

    // Display the final vector
    cout << "Final Vector Elements: ";
    for (int element : myVector)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
