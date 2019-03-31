#include<iostream>
#include<vector>//二维数组用vector申请
//#include<array>
//#include<string>
//#include<stack>
using namespace std;

//T60
//动态规划，迭代
void Spro(int n){
	if (n < 1) return;
	//int(*arr)[] = new int[6 * n + 1][n + 1];
	vector<vector<int>> arr(6*n+1,vector<int>(n+1,0));//二维数组
	for (int k = 1; k <= 6; k++){//一个骰子时
		arr[k][1] = 1;
	}
	for (int col = 2; col <= n; col++){
		for (int i = col - 1; i <= 6*(col-1); i++){
			for (int j = i + 1; j <= i + 6; j++){
				arr[j][col] += arr[i][col - 1];
			}
		}
	}
	double sum = 0;
	for (int i = 1; i <= 6 * n; i++){//对第n列求和
		sum += arr[i][n];
	}
	double check = 0;
	for (int i = n; i <= 6 * n; i++){
		cout << "P(" << i << ")=" << arr[i][n] / sum << endl;
		check += arr[i][n] / sum;
	}
	cout << check << endl;
}
//改进：6可以改为输入的变量参数，适用于不同点数的骰子




int main(){
	int n =2;
	Spro(n);
	return 0;
}