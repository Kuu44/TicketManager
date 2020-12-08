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
	void MergeSort();
	void merge(Person arr[], int, int, int);
	void mergeSort(Person arr[], int, int);
};

