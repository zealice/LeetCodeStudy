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
	int * lst = new int[n+1];//����д��new int[];һ��Ҫ�����ڴ棬����delete�������Ϊ��֪������delete���ע��һ��Ҫ�ڷ���ǰdelete������
	lst[0] = 0;//û����
	lst[1] = 1;//1��������Ϊ�������=0(<=1)
	lst[2] = 2;//2��������Ϊ�������=1(<=2)
	lst[3] = 3;//3��������Ϊ�������=2(<=2)
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
	delete[] lst;//�����飬���Լ�[]
	return result;
}



int main(){
	int n =0;
	int max = cutMax(n);
	return 0;
}