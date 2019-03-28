#include<iostream>
//#include<vector>
using namespace std;



//����������ĳ���ڵ�Ϊ���ڵ����ȫ�������Ľṹ��ʹ֮����󶥶ѡ�
void adjustHeap(int * arr, int index, int length){//index�Ǵ������Ľڵ���arr�е��±꣬length��arr��Ԫ���ܸ�����
	int temp;
	int i = index;
	for (int k = 2 * i + 1; k < length;k=2*i+1){
		if (k+1 < length && arr[k] < arr[k + 1]){
			k = k + 1;//��kָ��ϴ���ӽڵ�
		}
		if (arr[k] > arr[i]){
			temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
			i = k;
		}
		else{
			break;//��Ϊ���������������Ѿ�����󶥶��������������ģ����arr[i]�������������ô���ü��������ˣ�ֱ��break��
		}
	}
}


//����������adjustHeap����һ���󶥶ѣ��ٽ������ڵ�����һ���ڵ㣬�ų����������Ѿ��ź���Ľڵ㣬�ٴε�����Ϊ�󶥶ѣ��ٽ�����ѭ����ȥ...ֱ�����нڵ��źã�
void heapSort(int * arr, int start, int end){
	int length = end - start + 1;
	//�����󶥶�
	for (int index = length / 2 - 1; index >= start; index--){//�����һ����Ҷ�ӽڵ㿪ʼ������index������һ����Ҷ�ӽڵ���±�
		adjustHeap(arr, index, length);
	}
	for (int j = end; j >= start; j--){
		//������β
		int temp = arr[start];
		arr[start] = arr[j];
		arr[j] = temp;
		//������arr[start]Ϊ�����������Ϊ����ĩβ�㣬ֻ�и�ֵ�仯�ˣ�����ڵ㶼���ϴ󶥶ѽṹҪ��
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