#include<iostream>
#include<vector>
using namespace std;
 
    //选择排序（每次找最小值放到数组的前面。先找到最小元素所在位置的索引，然后将该元素与第一位上的元素进行交换。复杂度O(n^2)）
void xuanzeSort(int *arr, int start, int end){
 int min;//最小元素位置
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
 
    //插入排序（从左往右一个一个元素排。保证左边序列是已排序的，将有序序列的下一个元素插入到该序列中，直到结尾。复杂度O(n^2)）
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
 
    //冒泡排序（每次比较两个元素，较小的换到前面，直到结尾。循环这个过程，直到结尾。复杂度O(n^2)）
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