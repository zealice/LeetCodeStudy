#include<iostream>
//#include<vector>
#include<array>
#include<string>
using namespace std;



//顺序查找，一个一个对比，复杂度n
int shunxuFind(int * arr, int length, int target){
	for (int i = 0; i < length; i++){
		if (arr[i] == target){
			return i;
		}
	}
	return -1;
}

//二分查找（递归)，与列表中值对比，等则找到，大则与左边子列表中值对比，小则与右边子列表中值对比，循环该过程。复杂度logn
//二分查找的前提是列表是有序表！
int erfenFind(int * arr, int start, int end, int target){
	if (start > end){
		return -1;
	}
	int mid = (end + start) / 2;
	if (arr[mid] == target){
		return mid;
	}
	else if (arr[mid] < target){
		return erfenFind(arr, mid + 1, end,target);
	}
	else if (arr[mid] > target){
		return erfenFind(arr, start, mid - 1,target);
	}
}
//二分，循环（能用循环就别递归）
int erfenFind1(int * arr, int length, int target){
	int mid = (length-1) / 2;	
	while (mid >= 0 && mid < length){
		if (arr[mid] == target){
			return mid;
		}
		else if (arr[mid] < target){
			mid = (mid + length) / 2;
		}
		else if (arr[mid] > target){
			mid = (mid - 1) / 2;
		}
	}
	return -1;
}

//索引查找（将列表元素分块，每一块对应一个索引项。先找到key值所在索引项，再在该索引项对应的块中找）。复杂度根号n
//二叉排序树。查找复杂度为logn
//哈希查找
int main(){
	//int arr[] = { 4, 3, 2, 4, 5, 8, 0};
	//quickSort(arr, 0, sizeof(arr) / sizeof(int)-1);
	//guibingSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	//xuanzeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	//charuSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	//paoSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	//heapSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	//array.sort(arr);
	int* p;
	int *a = nullptr;
	string c;
	c = "123";
	c[1] = '4';
	int arr[] = { 1, 2, 3 };
	char arr1[] = "123";

	char* ps="123";
	//*ps = "123";
	int *a1 = new int;
	int (*a2)[5] = new int[2][5];//
	int *a3 = new int[5];
	cout << arr << endl;
	cout << arr1 << endl;
	cout << *ps << endl<<ps[1]<<endl<<&(ps);
	return 0;
}