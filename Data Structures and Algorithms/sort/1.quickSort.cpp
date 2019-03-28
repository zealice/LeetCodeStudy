#include<iostream>
//#include<vector>
using namespace std;

//快速排序法

//拆成两边分别处理（分治法）
int partition(int * arr, int start, int end){//以首元素为基准元素，返回基准元素最终的位置
	int temp;
	while (start != end){
		while (arr[start] <= arr[end]){//从右边判断
			end--;
			if (start == end)return start;//每次坐标变化后，都要判断是否s=e
		}

		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		if (start == end)return start;
		while (arr[start] <= arr[end]){//从左边判断
			start++;
			if (start == end)return start;
		}
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		end--;
	}
	return start;
}

void quickSort(int *arr,int start,int end){//递归实现
	if (start >= end){//只有一个元素或没有元素
		return;
	}
	int index = partition(arr, start, end);
	quickSort(arr, start, index - 1);
	quickSort(arr, index + 1, end);
}




int main(){
	int arr[] = { 4 , 3, 2, 4, 5, 8, 0};
	quickSort(arr, 0, sizeof(arr) / sizeof(int)-1);
	return 0;
}