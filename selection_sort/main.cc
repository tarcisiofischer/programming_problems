#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

template<typename T>
void swap(T& v1, T& v2)
{
    T tmp = v1;
    v1 = v2;
    v2 = tmp;
}

template<typename T>
void selection_sort(vector<T> &v)
{
    for (size_t i = 0; i < v.size(); ++i) {
        auto min_index = i;
        for (size_t j = i; j < v.size(); ++j)
            if (v[j] < v[min_index])
                min_index = j;    
        swap(v[i], v[min_index]);
    }
}

template<typename T>
void print_values(const vector<T> &v)
{
    for (auto i = begin(v); i < end(v); ++i)
        cout << *i << ", ";
    cout << endl;
}

template<typename T>
void run_example(vector<T> &v)
{
    print_values(v);
    selection_sort(v);
    print_values(v);
}

int main()
{
    vector<int> integers{5, 7, 9, 8, 9, 1, 1, 10, 60, 9, 365, -9, 1, 0, 0, 0};
    run_example(integers);

    vector<char> chars{'a', 'z', 'b', 'h', 'l', 'p', 'x'};
    run_example(chars);
}
