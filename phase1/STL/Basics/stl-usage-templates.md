## Important Functions

1. sort and reverse
```cpp 
sort(vec.begin(), vec.end());
reverse(vec.begin(), vec.end());
```

2. `lower_bound` : iterator to 1st element >= x
3. `upper_bound` : iterator to 1st element >= x

```cpp
auto it = std::lower_bound(vec.begin(), vec.end(), 5);
auto it = std::upper_bound(vec.begin(), vec.end(), 5);

```

\

4. `nth_element` : rearranges elements in a range such that the element at the nth position is the one that would be in that position if the range was fully sorted.
```cpp
nth_element(vec.begin(), vec.begin() + 2, vec.end());
```

5. Remove consecutive duplicate elements from a sorted range : `unique`
```cpp
auto it = std::unique(vec.begin(), vec.end());
vec.erase(it, vec.end());  // erase garbage tail
```

6. Generate the next lexicographically greater permutation of a range
```cpp
std::next_permutation(vec.begin(), vec.end());
```

---

## Templates in STL

- allows creating generic functions or classes
- that can work with any data type
- without the need of rewritting codes for different datatypes

**Usage 1: Functions**
```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << max(10, 5) << std::endl;      // The compiler generates int max(int, int)
    std::cout << max(10.5, 20.5) << std::endl; // The compiler generates double max(double, double)
    return 0;
}
```


**Usage 2: Class**
```cpp
template <typename T>
class Box {
public:
    T content;

    void setContent(T newContent) {
        content = newContent;
    }

    T getContent() {
        return content;
    }
};

int main() {
    Box<int> intBox;
    intBox.setContent(123);
    std::cout << intBox.getContent() << std::endl;

    Box<std::string> stringBox;
    stringBox.setContent("Hello Templates");
    std::cout << stringBox.getContent() << std::endl;

    return 0;
}
```


