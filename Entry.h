#pragma once
#include<iostream>

using namespace std;

struct Person
{
	int age;
	char name[50];
	int seat_no;
};
class Entry
{
	/*void merge(int arr[], int l, int m, int r)
	{
		int n1 = m - l + 1;
		int n2 = r - m;

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
			if (L[i] <= R[j]) {
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
	// of arr to be sorted
	void mergeSort(int arr[], int l, int r) {
		if (l >= r) {
			return;//returns recursively
		}
		int m = (l + r - 1) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}*/

	//for selection sort................
	void swap(Person* xp, Person* yp)
	{
		Person temp = *xp;
		*xp = *yp;
		*yp = temp;

	}
	void SelectionSort(Person data[], int a)
	{
		int min_idx;
		for (int i = 0; i < a; i++)
		{
			min_idx = i;
			for (int j = i + 1; j < a; j++)
			{
				if (data[j].age < data[min_idx].age)
					min_idx = j;
			}
			swap(&data[min_idx], &data[i]);
		}
	}

	void show_data(Person a)
	{
		//cout << "age " << " name " << " seatNum " << endl;
		cout << a.age << "   " << a.name << "    " << a.seat_no << endl;
	}
	void sort(Person l[], int s)
	{
		struct Person temp;
		for (int i = 1; i < s; i++)
			for (int j = 0; j < s - i; j++) {
				if (strcmp(l[j].name, l[j + 1].name) > 0) {
					temp = l[j];
					l[j] = l[j + 1];
					l[j + 1] = temp;
				}
			}

	}
	int main()
	{

		Person p[10]{}, temp;
		int n = 3;
		for (int i = 0; i < n; i++)
		{
			cout << "enter your age" << endl;
			cin >> p[i].age;
			cout << "enter your name" << endl;
			cin >> p[i].name;
			cout << "the seat number is" << endl;
			cin >> p[i].seat_no;
		}
		cout << "age " << " name " << " seatNum " << endl;
		for (int i = 0; i < n; i++)
		{
			show_data(p[i]);
		}
		SelectionSort(p, n);
		//sort(p, n);
		cout << "after sorting on basis of age" << endl;
		cout << "age " << " name " << " seatNum " << endl;
		for (int i = 0; i < n; i++)
		{
			show_data(p[i]);
		}

	}

};

