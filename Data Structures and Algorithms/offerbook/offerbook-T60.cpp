#include<iostream>
#include<vector>//��ά������vector����
//#include<array>
//#include<string>
//#include<stack>
using namespace std;

//T60
//��̬�滮������
void Spro(int n){
	if (n < 1) return;
	//int(*arr)[] = new int[6 * n + 1][n + 1];
	vector<vector<int>> arr(6*n+1,vector<int>(n+1,0));//��ά����
	for (int k = 1; k <= 6; k++){//һ������ʱ
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
	for (int i = 1; i <= 6 * n; i++){//�Ե�n�����
		sum += arr[i][n];
	}
	double check = 0;
	for (int i = n; i <= 6 * n; i++){
		cout << "P(" << i << ")=" << arr[i][n] / sum << endl;
		check += arr[i][n] / sum;
	}
	cout << check << endl;
}
//�Ľ���6���Ը�Ϊ����ı��������������ڲ�ͬ����������




int main(){
	int n =2;
	Spro(n);
	return 0;
}