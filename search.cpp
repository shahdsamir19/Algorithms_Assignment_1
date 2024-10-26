#include <iostream>
#include "vector"
using namespace std;
template <typename T>
T sequentialSearchIterative(const std::vector<T>& arr, T target) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

template <typename T>
T sequentialSearchRecursive(const std::vector<T>& arr, T target, size_t index = 0) {
    if (index >= arr.size()) {
        return -1;
    }

    if (arr[index] == target) {
        return index;
    }

    return sequentialSearchRecursive(arr, target, index + 1);
}

int main() {


    return 0;
}
