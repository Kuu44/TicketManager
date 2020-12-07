#pragma once
#include<iostream>
#include<cstring>
#include<string>
#define MAX_SIZE 50

using namespace std;

struct Person
{
public:
	int symbolNo;
	int age;
	string name;
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
private:
	int size;
public:
	Person entries[MAX_SIZE]{};
	Entry();
	int getSize();
	void inputData(const char*, int, int);
	std::string** getResult();

	void swap(Person*, Person*);
	void SelectionSort();
	void BubbleSort();
	
	/*int main()
	{
		int AGE[10];
		Person p[10]{};
		int n;
		cout << "enter the number of person";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "enter your age" << endl;
			cin >> p[i].age;
			cout << "enter your name" << endl;
			cin >> p[i].name;
			bool taken = true;
			while (taken)
			{
				cout << "the seat number is" << endl;
				cin >> p[i].seat_no;
				taken = false;
				for (int k = 0; k < i; k++)
				{
					if (p[k].seat_no == p[i].seat_no)
					{
						cout << "seat already taken" << endl;
						taken = true;
						break;
					}
				}
			}
		}
		cout << "age " << " name " << " seatNum " << endl;
		for (int i = 0; i < n; i++)
		{
			//show_data(p[i]);
		}
	}*/
};

