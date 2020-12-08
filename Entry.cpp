#include "Entry.h"
Entry::Entry() :size(0) {}
int Entry::getSize() {
	return (size+1);
}
void Entry::inputData(const char* name, int age, int seat_no) {
	std::string newName = name;
	entries[size].age = age;
	entries[size].seat_no = seat_no;
	entries[size].name = name;
	entries[size].symbolNo = size+1;
	size++;
}
std::string** Entry::getResult() {
	std::string** s;
	s = new std::string * [MAX_SIZE + 1];
	//to accomodate the titles
	for (int i = 0; i <= size; i++) {		
		s[i] = new std::string[4];
	}
	//Setting Titles
	s[0][0] = "Symbol No.";
	s[0][1] = "Name";
	s[0][2] = "Age";
	s[0][3] = "Seat No.";
	//Setting data
	for (int i = 1; i <= size; i++) {
		s[i][0] = to_string(entries[i - 1].symbolNo);
		s[i][1] = entries[i - 1].name;
		s[i][2] = to_string(entries[i - 1].age);
		s[i][3] = to_string(entries[i - 1].seat_no);
	}
	return s;
}

//for selection sort................
void Entry::swap(Person* xp, Person* yp)
{
	Person temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void Entry::SelectionSort()
{
	int a = size;
	int min_idx;
	for (int i = 0; i < a; i++)
	{
		min_idx = i;
		for (int j = i + 1; j < a; j++)
		{
			if (entries[j].age < entries[min_idx].age)
				min_idx = j;
		}
		swap(&entries[min_idx], &entries[i]);
	}
}
void Entry::BubbleSort()
{
	int s = size;
	struct Person temp;
	for (int i = 1; i < s; i++)
		for (int j = 0; j < s - i; j++) {
			if (strcmp(entries[j].name.c_str(), entries[j + 1].name.c_str()) > 0) {
				temp = entries[j];
				entries[j] = entries[j + 1];
				entries[j + 1] = temp;
			}
		}
}
// Merges two subarrays of arr[].
	// First subarray is arr[l..m]
	// Second subarray is arr[m+1..r]
void Entry::merge(Person arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	Person L[20], R[20];

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

	// Copy the remaining elements of L[], if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of R[], if there are any
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

// l is for left index and r is right index of the sub-array
// of arr to be sorted */
void Entry::mergeSort(Person arr[], int l, int r) {
	if (l >= r) {
		return;//returns recursively
	}
	int m = (l + r - 1) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);
	merge(arr, l, m, r);	
}
void Entry::MergeSort()
{
	//two calls due to recursion
	mergeSort(entries, 0, size - 1);
}
