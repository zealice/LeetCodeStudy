#include<iostream>
//#include<vector>
using namespace std;




//ϣ�����򣨲�����������
void xiSort(int *arr, int start, int end){
	int gap = end - start + 1;
	int i,p,temp;
	while (gap > 1){
		gap = gap / 3 + 1;//���еĲ���������ʽ���ұ�֤����һ������ֵһ����1����������һ�β�������.��Ϊ����������ǲ���Ϊ1��ϣ������
		for (i = start + gap; i <= end; i++){//һ�ζ�ÿ��Ԫ�ؽ��в�����������
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