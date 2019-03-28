#include<iostream>
#include<vector>
using namespace std;
 
    //ѡ������ÿ������Сֵ�ŵ������ǰ�档���ҵ���СԪ������λ�õ�������Ȼ�󽫸�Ԫ�����һλ�ϵ�Ԫ�ؽ��н��������Ӷ�O(n^2)��
void xuanzeSort(int *arr, int start, int end){
 int min;//��СԪ��λ��
 int temp;
 for (int i = start; i <= end; i++){
  min = i;
  for (int j = i + 1; j <= end; j++){
   if (arr[j] < arr[min]){
    min = j;
   }
  }
  temp = arr[i];
  arr[i] = arr[min];
  arr[min] = temp;
 }
}
 
    //�������򣨴�������һ��һ��Ԫ���š���֤���������������ģ����������е���һ��Ԫ�ز��뵽�������У�ֱ����β�����Ӷ�O(n^2)��
void charuSort(int *arr, int start, int end){
 int temp;
 for (int i = start+1; i <= end; i++){
  for (int p = i - 1; p >= start; p--){
   if (arr[p + 1] < arr[p]){
    temp = arr[p];
    arr[p] = arr[p + 1];
    arr[p + 1] = temp;
   }
   else{
    break;
   }
  }
 }
}
 
    //ð������ÿ�αȽ�����Ԫ�أ���С�Ļ���ǰ�棬ֱ����β��ѭ��������̣�ֱ����β�����Ӷ�O(n^2)��
void paoSort(int *arr, int start, int end){
 int temp;
 for (int i = start; i <= end; i++){
  for (int j = i + 1; j <= end; j++){
   if (arr[j] < arr[i]){
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
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
 paoSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
 return 0;
}