 ///
 /// @file    HeapSort.cc
 /// @author  kogan(koganlee@163.com)
 /// @date    2018-03-13 14:46:51
 ///
 
#include <iostream>
#include <stdio.h>
using std::cout;
using std::endl;

//void swap(int *a, int *b)
void adjustHeap(int param1, int j, int inNums[])
{
    int temp = inNums[param1];
	for(int  k = param1*2 +1; k < j; k = k * 2 + 1)
	{
		if(k + 1 < j && inNums[k] < inNums[k + 1])
		{
			k++;
		}
		
		if(inNums[k] > temp)
		{
			inNums[param1] = inNums[k];
			param1 = k;
		}
		else
			break;
	}
    inNums[param1] = temp;
}

void HeapSort(int nums, int inNums[])
{
    for(int i = nums / 2 - 1; i >= 0; i--)
    {
		adjustHeap(i, nums, inNums);
	}

	for(int j = nums - 1; j >= 0; j--)
	 {
         int temp = inNums[0];
		 inNums[0] = inNums[j];
		 inNums[j] = temp;

		 adjustHeap(0, j, inNums);
	 }
}

int main()
{
   int data[] = {1, 2};

   HeapSort(2, data);
   for(int i = 0; i < 2; ++i)
   {
      cout << data[i] << endl;
   }
   return 0;
}
