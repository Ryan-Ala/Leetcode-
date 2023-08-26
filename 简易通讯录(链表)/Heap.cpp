#include "Heap.h"

void swap(peoinform** a, peoinform** b)
{
	if (!a)
	{
		cerr << ":)  ERROR!    The first parameter of the function is nullptr" << endl;
		exit(1);
	}
	if (!*a)
	{
		cerr << ":)  ERROR!    The first parameter of the function  [ *a ]  is nullptr!" << endl;
		exit(1);
	}
	if (!b)
	{
		cerr << ":)  ERROR!    The second parameter of the function is nullptr" << endl;
		exit(1);
	}
	if (!*b)
	{
		cerr << ":)  ERROR!    The second parameter of the function  [ *b ]  is nullptr!" << endl;
		exit(1);
	}
	peoinform* s = *a;
	*a = *b;
	*b = s;
}

void AdjustDown(Datatype** a, int n, int parent)
{
	if (!a)
	{
		cerr << ":)  ERROR!    The first parameter of the function is nullptr" << endl;
		exit(1);
	}
	if (!*a)
	{
		cerr << ":)  ERROR!    The first parameter of the function  [ *a ]  is nullptr!" << endl;
		exit(1);
	}
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && strcoll((a[child + 1])->name, (a[child])->name) > 0)
		{
			child++;
		}
		if (strcoll((a[child])->name, (a[parent])->name) > 0)
		{
			swap(&(a[child]), &(a[parent]));
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(Datatype** a, int n)
{
	if (!a)
	{
		cerr << ":)  ERROR!    The first parameter of the function is nullptr" << endl;
		exit(1);
	}
	if (!*a)
	{
		cerr << ":)  ERROR!    The first parameter of the function  [ *a ]  is nullptr!" << endl;
		exit(1);
	}
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(&(a[0]), &(a[end]));
		AdjustDown(a, end, 0);
		--end;
	}
}

