#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdbool>
#include <cmath>

bool binary_search(int key, std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    int m = (end - begin) / 2;
    if ((end - begin) == 1)
        return ((key == *(begin++)) || (key == *(begin)));
    auto comp = next(begin, m);
    if (key == *comp)
        return true;
    if (begin != end) {
        if (key < *comp)
            return binary_search(key, begin, comp);
        if (key > *comp)
            return binary_search(key, comp, end);
    }
    else
        return false;
}

int main() {
    std::vector <int> v;
    int n;
    int a;
    int key;
    std::cout << "Number of elements = ";
    std::cin >> n;
    std::cout << "Write all members" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for (auto it = v.begin(); it != v.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << "Elem for searching = ";
    std::cin >> key;
    std::cout << binary_search(key, v.begin(), v.end() - 1);
    return 0;
}
