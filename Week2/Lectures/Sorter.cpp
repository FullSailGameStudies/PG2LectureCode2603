#include "Sorter.h"


//
// Part A-2
//
/*
		procedure bubbleSort(A : list of sortable items)
		  n := length(A)
		  repeat
			  swapped := false
			  for i := 1 to n - 1 inclusive do
				  if A[i - 1] > A[i] then
					  swap(A, i - 1, i)
					  swapped = true
				  end if
			  end for
			  n := n - 1
		  while swapped
		end procedure
*/
void Sorter::bubbleSort(std::vector<Light>& A)
{
	//n := length(A)
	int n = A.size();
	bool swapped;
	do
	{
		swapped = false;
		//for i := 1 to n - 1 inclusive do
		for (int i = 1; i <= n - 1; i++)
		{
			//if A[i - 1] > A[i] then
			if (A[i - 1].red > A[i].red)
			{
				//TODO: figure out how to swap!
				//swap(A, i - 1, i)
				std::swap(A[i - 1], A[i]);
				//OG swap
				//Light l1 = A[i - 1];
				//A[i - 1] = A[i];
				//A[i] = l1;

				//swapped = true
				swapped = true;
			}//endif
		}//endfor
		//n := n - 1
		--n;
	} while (swapped);
}//end procedure
