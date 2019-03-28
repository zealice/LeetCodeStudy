#include<iostream>
#include<vector>
using namespace std;


//归并排序

//合并两个已排序的序列
void hebing(int* arr, int start, int end){
	if (start == end){
		return;
	}
	int start1 = start;
	int end1 = (end + start) / 2;
	int start2 = end1 + 1;
	int end2 = end;
	int p1 = start1;
	int p2 = start2;
	int p = 0;
	vector<int> tempArr(end - start + 1, 0);
	while (p1 <= end1&&p2 <= end2){
		tempArr[p] = (arr[p1] < arr[p2]) ? arr[p1] : arr[p2];
		p++;
		if (arr[p1] < arr[p2]){
			p1++;
		}
		else{
			p2++;
		}
	}
	while (p1 <= end1){
		tempArr[p] = arr[p1];
		p++;
		p1++;
	}
	while (p2 <= end2){
		tempArr[p] = arr[p2];
		p++;
		p2++;
	}
	p = 0;
	while (p <= end-start){
		arr[start + p] = tempArr[p];
		p++;
	}
}

//递归调用
void guibingSort(int* arr, int start, int end){
	if (start == end){\\出口
		return;
	}
	int mid = (end + start) / 2;
	guibingSort(arr, start, mid);
	guibingSort(arr, mid + 1, end);
	hebing(arr, start, end);
}


int main(){
	int arr[] = { 4 };//, 3, 2, 4, 5, 8, 0};
	//quickSort(arr, 0, sizeof(arr) / sizeof(int)-1);
	guibingSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	return 0;
}