#include<iostream>
//#include<vector>
//#include<array>
//#include<string>
//#include<stack>
using namespace std;

//�в�����Ŀ����ֵ�ֱ�Ϊ1,5,10,25�ֵ�Ӳ�ң�Ȼ����õ�n�֣��м��ַ�����
//���϶��µݹ飨����̫���ظ����Ҳ��ȶ������䵱n�ܴ�ʱ��

int func2(int n){//��1��5���n
	if (n <= 4 && n >= 0){
		return 1;
	}
	if (n < 0){
		return 0;
	}
	return 1 + func2(n - 5);
}
int func3(int n){//��1��5��10���n
	if (n <= 4 && n >= 0){ 
		return 1; 
	}
	if (n < 0){
		return 0;
	}
	return 1 + func2(n - 5) + func3(n - 10);
}

int func(int n){//��1��5��10��25���n
	if (n <= 4 && n >= 0){
		return 1;
	}
	if (n < 0){
		return 0;
	}
	return 1 + func2(n - 5) + func3(n - 10) + func(n - 25);//ȫ1������5��ֻ��1��5������10��ֻ��1��5��10������25��
}


//���¶���
//int funcn(int n){
//	int * lst = new int[n + 1];
//	for (int i=0; i <= n; i++){
//		if (i <= 4){
//			lst[i] = 1;
//		}
//		else if(i >= 5&&i <= 9){
//			lst[i] = 1 + lst[i - 5];// +func3(i - 10) + lst[i - 25];
//		}
//		else if (i >= 10 && i <= 24){
//			lst[i] = 1 + lst[i - 5]+ lst[i - 10];
//			for (int j = i - 15; j >= 10; j = j - 10){
//				lst[i] -= lst[]
//			}
//		}
//	}
//	
//}


//���϶���
//���ȿ���ֻ��1����ôÿ����n��ֻ��1�֡�
//������1��5�����Ǹ���ÿ��n�ķ�������1-4����ֵ=��ֵ=1��5���ϣ���ֵ=��ֵ+��ֵ[n-5]������ֵ[n-5]��������ѡ��һ��5��ʣ�µ�Ҳ��1��5��ѡ��
//��������
int countWays(int n) {
	int coins[4] = { 1, 5, 10, 25 };
	int dp[100001] = { 0 };
	dp[0] = 1;
	for (int i = 0; i<4; i++)
		for (int j = coins[i]; j <= n; j++)
			dp[j] = (dp[j] + dp[j - coins[i]]) % 1000000007;//�������þ�ֵ�õ���ֵ������
	return dp[n];
}




int main(){
	int n =20;
	int sum = countWays(n);
	return 0;
}