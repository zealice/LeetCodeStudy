#include<iostream>
#include<vector>
using namespace std;

unsigned long FindMax(vector<unsigned long>& arr, unsigned long n){//找到最大值下标
	unsigned long max = 0;
	for (unsigned long i = 0; i<n; i++){
		if (arr[i] > arr[max]){
			max = i;
		}
	}
	return max;
}

int main(){
	unsigned long n;
	cin >> n;
	vector<unsigned long> arr(n, 0);
	if (n<1 || n>100000)return -1;
	unsigned long number;
	for (unsigned long i = 0; i<n; i++){
		cin >> number;
		if (number<1 || number>1000000000)return -1;
		arr[i] = number;
	}
	unsigned long sum1 = 0;
	unsigned long sum2 = 0;
	for (unsigned long i = 0; i<n; i++){
		if (i % 2 == 0){
			number = FindMax(arr, n);
			sum1 += arr[number];
			arr[number] = 0;
		}
		else{
			number = FindMax(arr, n);
			sum2 += arr[number];
			arr[number] = 0;
		}
	}
	number = sum1 - sum2;
	cout << number << endl;
	return 0;
}