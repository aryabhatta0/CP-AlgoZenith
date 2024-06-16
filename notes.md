<!-- Things I revised  -->

**getline**
```cpp
    string line;
    getline(cin, line);
```

**stringstream**
```cpp
    stringstream ss(line);

    vector<string> words;
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
```

### Dynamic Memory Allocation
Pointers are commonly used to allocated or deallocated memory during program execution.

**new and delete**
```cpp
int *ptr = new int;    // Dynamically allocating memory for an integer
*ptr = 10;              // Assigning a value to the dynamically allocated memory
delete ptr;             // Deallocating the memory
```


