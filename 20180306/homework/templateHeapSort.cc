 ///
 /// @file    templateHeapSort.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-13 23:26:55
 ///
 
#include <iostream>
using std::cout;
using std::endl;
template<typename T>//, typename Compare = std::less<T> >
class HeadSort
{
public:
	HeadSort(int length,int array[]) : _length(length), _array(new T[length]()) {
	      for(int i = 0; i < length; ++i)
        	{
              *(_array + i) = array[i];
			  cout << *(_array + i)  << endl;
			}
	}
	void adjust(int num, int len);
	void sort();
    void print()
	{
      for(int i = 0; i < _length; ++i)
	  {
          cout << *(_array + i) << endl;
	  }
	}
private:
    int _length;
	T * _array;
};

template<typename T>
void HeadSort<T>::adjust(int parent, int len)
{
     int temp = *(_array+parent);
	 for(int i = parent * 2 + 1; i < len; i = i * 2 + 1)
	 {
        if(*(_array+i) < *(_array+i+1) &&  i + 1 < len)
		{
		    ++i; 
		}
          
		if(*(_array+i) > temp)
		{
			*(_array+parent) = *(_array+i);
		    parent = i;
		}
		else
			break;
	 }
     *(_array+parent) = temp;
}

template<typename T>
void HeadSort<T>::sort()
{
    for(int i = _length / 2 - 1; i>= 0; --i)
	{
      adjust(i, _length);
	}
    int temp;
	for(int j = _length - 1; j >= 0; --j)
	{
       temp = *_array;
	   *_array = *(_array + j);
       *(_array + j) = temp;

       adjust(0, j);
	}
}



int main()
{
	int a[10] = {4, 3 ,8, 29, 38, 68, 12, 32, 18, 99};
    HeadSort<int> h(10, a);
	h.sort();
	h.print();

	return 0;
}
