#include <iostream>
#include <vector>
using namespace std;
void swap(int* a, int* b);
void heapify(vector<int>& hT, int i);
void insert(vector<int>& hT, int newNum);
void deleteNode(vector<int>& hT, int num);
void printHeap(vector<int>& hT);
void menu(vector<int>);
void createHTree(vector<int> &root);
void removeTree(vector<int>t);