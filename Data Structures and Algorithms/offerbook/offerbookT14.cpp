#include<iostream>
//#include<vector>
//#include<array>
//#include<string>
//#include<stack>
using namespace std;

int cutMax(int n){
	if (n <= 1){
		return 0;
	}
	if (n == 2){
		return 1;
	}
	if (n == 3){
		return 2;
	}
	int * lst = new int[n+1];//不可写成new int[];一定要分配内存，否则delete会出错，因为不知道到底delete多大！注意一定要在返回前delete！！！
	lst[0] = 0;//没有用
	lst[1] = 1;//1不剪，因为剪了最大=0(<=1)
	lst[2] = 2;//2不剪，因为剪了最大=1(<=2)
	lst[3] = 3;//3不剪，因为剪了最大=2(<=2)
	int max = 0;
	for (int j = 4; j <= n; j++){
		for (int i = 1; i <= j / 2; i++){
			if ((lst[i] * lst[j - i]) > max){
				max = lst[i] * lst[j - i];
			}
		}
		lst[j] = max;
	}
	int result = lst[n];
	delete[] lst;//是数组，所以加[]
	return result;
}



int main(){
	int n =0;
	int max = cutMax(n);
	return 0;
}