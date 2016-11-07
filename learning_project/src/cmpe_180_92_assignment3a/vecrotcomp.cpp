/*
#include <vector>
using namespace std;

vector<int> rot(const vector<int>& a)
{
   vector<int> copy = a;

   for(int i = 0; i < a.size() - 1; i++ ){
       copy[i] = a [i+1];
   }
   copy[a.size() - 1] = a[0];

    return copy;
}
*
   Computes all rotations of a given vector.
   @param a a vector of integers
   @return a vector of all rotations, first by 0, then by
   one, two, and so on, up to n - 1, where n is the size
   of the vector. For example, if a is {1, 7, 2, 9}
   then a vector {{1, 7, 2, 9}, {7, 2, 9, 1}, {2, 9, 1, 7}, {9, 1, 7, 2}} is returned.


vector<vector<int>> allrot(const vector<int>& a)
{
    std::vector<vector<int>> list;
    std::vector<int> current = a;

    for(int i = 0; i < a.size(); i++){
        list.push_back(current);
        current = rot(current);
    }

    return list;
}


*/
