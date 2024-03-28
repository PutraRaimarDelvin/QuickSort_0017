#include <iostream>
using namespace std;

int arr[20];
int cmp_count = 0;
int mov_counnt = 0;
int n;


void input() {
	while (true)
	{
		cout << "Masukkan Panjang Element array: ";
		cin >> n;
		if (n <= 20)
			break;
		else
			cout << "\nMaksimum Panjang Array adalah 20" << endl;
	}
	cout << "\n-------------------" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n-------------------" << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "<" << (i + 1) << ">";
			cin >> arr[i];

		}
}

void swap(int x, int y, int mov_count)
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
	mov_count++ ;
}

void q_short(int low, int high)
{
	int temp;
	int pivot, i, j;
	if (low > high) { //step 1
		return;
	}

	pivot = arr[low]; //step2
	i = low + 1;	//step3
	j = high;		//step 4

	while (i <= j) // step10
	{
		while ((arr[i] <= pivot) && (i <= high)) //step 5
		{
			i++; //step 6
			cmp_count++;
		}
		cmp_count++;
		while ((arr[j] > pivot) && (j >= low)) //step 7
		{
			j--; //step 8
			cmp_count++;
		}
		cmpt_count++;
		if (i < j) // step 9 
		{
			swap(i, j);
		}
	}

}


