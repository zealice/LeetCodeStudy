#include<iostream>
//#include<vector>
using namespace std;




//希尔排序（步长插入排序）
void xiSort(int *arr, int start, int end){
	int gap = end - start + 1;
	int i,p,temp;
	while (gap > 1){
		gap = gap / 3 + 1;//库中的步长调整方式。且保证最后的一个步长值一定是1（即最后进行一次插入排序.因为插入排序就是步长为1的希尔排序）
		for (i = start + gap; i <= end; i++){//一次对每个元素进行步长插入排序
			for (p = i - gap; p >= start; p -= gap){
				if (arr[p + gap] < arr[p]){
					temp = arr[p];
					arr[p] = arr[p + gap];
					arr[p + gap] = temp;
				}
				else{
					break;
				}
			}
		}
	}

}

int main(){
	int arr[] = { 4, 3, 2, 4, 5, 8, 0};
	//quickSort(arr, 0, sizeof(arr) / sizeof(int)-1);
	//guibingSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	//xuanzeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	//charuSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	//paoSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	xiSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	return 0;
}