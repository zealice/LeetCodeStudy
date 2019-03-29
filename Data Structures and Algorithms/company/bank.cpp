#include<iostream>
//#include<vector>
//#include<array>
//#include<string>
//#include<stack>
using namespace std;

//有不限数目的面值分别为1,5,10,25分的硬币，然后想得到n分，有几种方法？
//自上而下递归（计算太多重复，且不稳定，尤其当n很大时）

int func2(int n){//用1、5组成n
	if (n <= 4 && n >= 0){
		return 1;
	}
	if (n < 0){
		return 0;
	}
	return 1 + func2(n - 5);
}
int func3(int n){//用1、5、10组成n
	if (n <= 4 && n >= 0){ 
		return 1; 
	}
	if (n < 0){
		return 0;
	}
	return 1 + func2(n - 5) + func3(n - 10);
}

int func(int n){//用1、5、10、25组成n
	if (n <= 4 && n >= 0){
		return 1;
	}
	if (n < 0){
		return 0;
	}
	return 1 + func2(n - 5) + func3(n - 10) + func(n - 25);//全1；含有5且只有1、5；含有10且只有1、5、10；含有25。
}


//自下而上
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


//自上而下
//首先考虑只有1，那么每任意n都只有1种。
//考虑有1和5，于是更新每个n的方法数，1-4：新值=旧值=1；5以上：新值=旧值+新值[n-5]。（新值[n-5]代表首先选了一个5，剩下的也在1和5里选）
//其它类似
int countWays(int n) {
	int coins[4] = { 1, 5, 10, 25 };
	int dp[100001] = { 0 };
	dp[0] = 1;
	for (int i = 0; i<4; i++)
		for (int j = coins[i]; j <= n; j++)
			dp[j] = (dp[j] + dp[j - coins[i]]) % 1000000007;//迭代（用旧值得到新值）方法
	return dp[n];
}




int main(){
	int n =20;
	int sum = countWays(n);
	return 0;
}