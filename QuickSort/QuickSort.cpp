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
	mov_count++;
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
		cmp_count++;
		if (i < j) // step 9 
		{
			swap(i, j);
		}
	}
	if (low < j) { //step11
		swap(low, j);

	}
	q_short(low, j - 1); //step12
	q_short(j + 1, high); // step 13

}

void display() {
	cout << "\n------------" << endl;
	cout << "\nSorted Array" << endl;
	cout << "\n------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n\nNumber of comparasions: " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;

}
int main()
{
	char ch;
	do {
		input();
		q_short(0, n - 1);
		display();
		cout << "\n\nDo you want  to continue? (y/n): ";
		cin >> ch;
		if (ch == 'n' || ch == 'n')
			break;
		system("pause");
		system("cls");


	} while (true);
	return 0;
}



