#include<iostream>
//#include<vector>
using namespace std;



//调整以任意某个节点为根节点的完全二叉树的结构，使之满足大顶堆。
void adjustHeap(int * arr, int index, int length){//index是待调整的节点在arr中的下标，length是arr的元素总个数。
	int temp;
	int i = index;
	for (int k = 2 * i + 1; k < length;k=2*i+1){
		if (k+1 < length && arr[k] < arr[k + 1]){
			k = k + 1;//将k指向较大的子节点
		}
		if (arr[k] > arr[i]){
			temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
			i = k;
		}
		else{
			break;//因为是在左右子树都已经满足大顶堆条件下来调整的，如果arr[i]就是最大数，那么不用继续调整了，直接break。
		}
	}
}


//堆排序（先用adjustHeap构建一个大顶堆，再交换根节点和最后一个节点，排除掉最后这个已经排好序的节点，再次调整树为大顶堆，再交换，循环下去...直到所有节点排好）
void heapSort(int * arr, int start, int end){
	int length = end - start + 1;
	//构建大顶堆
	for (int index = length / 2 - 1; index >= start; index--){//从最后一个非叶子节点开始调整，index获得最后一个非叶子节点的下标
		adjustHeap(arr, index, length);
	}
	for (int j = end; j >= start; j--){
		//交换首尾
		int temp = arr[start];
		arr[start] = arr[j];
		arr[j] = temp;
		//调整以arr[start]为顶点的树，因为除开末尾点，只有该值变化了，其余节点都符合大顶堆结构要求
		adjustHeap(arr, 0, j-1-start+1);
	}
}

int main(){
	int arr[] = { 4, 3, 2, 4, 5, 8, 0};
	//quickSort(arr, 0, sizeof(arr) / sizeof(int)-1);
	//guibingSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	//xuanzeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	//charuSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	//paoSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	heapSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	return 0;
}