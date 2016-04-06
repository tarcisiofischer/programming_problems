/**
 * Given a vector with N elements, with duplicated elements. The problem is to
 * remove all duplicated elements from the vector in O(n * log n)
 */
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

template<typename T>
vector<T> merge_removing(vector<T> left, vector<T> right)
{
    vector<T> result;
    auto i = 0;
    auto j = 0;
    for (auto k = 0; k < left.size() + right.size(); ++k) {
        if (i == left.size() || j == right.size())
            break;

        if (left[i] < right[j]) {
            result.push_back(left[i]);
            ++i;
        } else if (right[j] < left[i]) {
            result.push_back(right[j]);
            ++j;
        } else {
            ++i;
        }
    }

    while (i < left.size()) {
        result.push_back(left[i]);
        ++i;
    }

    while (j < right.size()) {
        result.push_back(right[j]);
        ++j;
    }

    return result;
}

template<typename T>
vector<T> remove_duplicates_aux(const vector<T> &A, int from, int to)
{
    if (from == to) {
        return vector<T>{{A[from]}};
    }

    int middle = (from + to) / 2;
    auto left = remove_duplicates_aux(A, from, middle);
    auto right = remove_duplicates_aux(A, middle + 1, to);

    return merge_removing(left, right);
}

template<typename T>
vector<T> remove_duplicates(const vector<T> &A)
{
    return remove_duplicates_aux(A, 0, A.size() - 1);
}

int main()
{
    vector<int> numbers{{1, 2, 4, 1, 1, 2, 5, 5, 9, 0, 2}};
    auto no_duplicates = remove_duplicates(numbers);

    cout << "Original numbers:\n";
    for (auto i = begin(numbers); i < end(numbers); ++i) {
        cout << *i << ", ";
    }
    cout << "\n";

    cout << "Removed duplicates:\n";
    for (auto i = begin(no_duplicates); i < end(no_duplicates); ++i) {
        cout << *i << ", ";
    }
    cout << endl;
}
