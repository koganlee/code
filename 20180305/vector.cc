 ///
 /// @file    vector.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-05 20:35:34
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main()
{
  vector<int>VecInt {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  //vector<int>VecInt =  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  //  vector<int> VecInt(3, 10);
  //	vector<int> Vec(VecInt);
  //  vector<int> V(1,100);

#if 0
  for(size_t num = 0; num < V.size(); ++num)
    {
      cout << "V:" << num << "] = " << V[num] << endl;
    }
#endif
  auto it = VecInt.begin();
  it += 2;
  VecInt.erase(it);
  VecInt.pop_back();
  for(size_t num = 0; num < VecInt.size(); ++num)
   {
      cout << "VecInt[" << num << "] = " << VecInt[num] << endl;
   }
  return 0;
}
