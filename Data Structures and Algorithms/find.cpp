#include<iostream>
//#include<vector>
#include<array>
#include<string>
using namespace std;



//˳����ң�һ��һ���Աȣ����Ӷ�n
int shunxuFind(int * arr, int length, int target){
	for (int i = 0; i < length; i++){
		if (arr[i] == target){
			return i;
		}
	}
	return -1;
}

//���ֲ��ң��ݹ�)�����б���ֵ�Աȣ������ҵ���������������б���ֵ�Աȣ�С�����ұ����б���ֵ�Աȣ�ѭ���ù��̡����Ӷ�logn
//���ֲ��ҵ�ǰ�����б��������
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
//���֣�ѭ��������ѭ���ͱ�ݹ飩
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

//�������ң����б�Ԫ�طֿ飬ÿһ���Ӧһ����������ҵ�keyֵ������������ڸ��������Ӧ�Ŀ����ң������Ӷȸ���n
//���������������Ҹ��Ӷ�Ϊlogn
//��ϣ����
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