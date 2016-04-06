#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

template<typename T>
const T &max_element(const vector<T> &v)
{
    auto max_index = 0;
    for (int i = 1; i < v.size(); ++i)
        if (v.at(i) > v.at(max_index))
            max_index = i;
    return v.at(max_index);
}

int main()
{
    vector<double> values{1., 3.7, 9.9, 9.5, 0.1, 7.39};
    cout << max_element(values) << endl;
}
