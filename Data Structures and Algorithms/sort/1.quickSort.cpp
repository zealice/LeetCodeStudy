#include<iostream>
//#include<vector>
using namespace std;

//��������

//������߷ֱ������η���
int partition(int * arr, int start, int end){//����Ԫ��Ϊ��׼Ԫ�أ����ػ�׼Ԫ�����յ�λ��
	int temp;
	while (start != end){
		while (arr[start] <= arr[end]){//���ұ��ж�
			end--;
			if (start == end)return start;//ÿ������仯�󣬶�Ҫ�ж��Ƿ�s=e
		}

		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		if (start == end)return start;
		while (arr[start] <= arr[end]){//������ж�
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

void quickSort(int *arr,int start,int end){//�ݹ�ʵ��
	if (start >= end){//ֻ��һ��Ԫ�ػ�û��Ԫ��
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