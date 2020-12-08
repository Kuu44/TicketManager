// C++ program for Merge Sort
#include <iostream>
using namespace std;
struct Person
{
	int age;
	int seatN;
	string name;
};

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(Person arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temp arrays
	Person L[20], R[20];

	// Copy data to temp arrays L[] and R[]
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Merge the temp arrays back into arr[l..r]

	// Initial index of first subarray
	int i = 0;

	// Initial index of second subarray
	int j = 0;

	// Initial index of merged subarray
	int k = l;

	while (i < n1 && j < n2) {
		if (L[i].age <= R[j].age) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of
	// L[], if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of
	// R[], if there are any
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(Person arr[], int l, int r) {
	if (l >= r) {
		return;//returns recursively
	}
	int m = (l + r - 1) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);
	merge(arr, l, m, r);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(Person A[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << A[i].age << " ";
		cout << A[i].seatN << " ";
		cout << A[i].name << " " << endl;
	}

}

// Driver code
int main()
{
	
	int arr_size = 4;
	Person per[4];
	for (int i = 0; i < 4; i++)
	{
		cout << "enter the age" << endl;
		cin >> per[i].age;
		cout << "enter the seat num" << endl;
		cin >> per[i].seatN;
		cout << "enter the name" << endl;
		cin >> per[i].name;
	}

	cout << "Given array is \n";
	printArray(per, arr_size);

	mergeSort(per, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(per, arr_size);
	return 0;
}

// This code is contributed by Mayank Tyagi
