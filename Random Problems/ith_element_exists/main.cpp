#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

bool has_ith_element_aux(const vector<int> &A, int from, int to)
{
    if (from == to)
        return A[from] == from;

    auto middle = (from + to) / 2;
    if (A[middle] == middle)
        return true;
    
    if (A[middle] > middle)
        return has_ith_element_aux(A, from, middle - 1);
    else
        return has_ith_element_aux(A, middle + 1, to);
}

bool has_ith_element(const vector<int> &A)
{
    return has_ith_element_aux(A, 0, A.size() - 1);
}

void test_vector(const vector<int> &A)
{
    if (has_ith_element(A))
       cout << "Yes" << endl; 
    else
       cout << "No" << endl;
}

int main()
{
    test_vector(vector<int>{{-7, -2, 0, 3, 7, 9, 11, 18, 99, 100, 101, 102, 199, 200}});
    // .................................^ A[3] == 3

    test_vector(vector<int>{{-3, -1, 0, 7, 9, 15, 16, 60, 999}});
    // (No A[i] == i)

    test_vector(vector<int>{{0}});
    // ......................^ A[0] == 0

    test_vector(vector<int>{{-1}});
    // (No A[i] == i)
}

