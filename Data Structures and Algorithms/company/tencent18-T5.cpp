#include<iostream>
#include<vector>
using namespace std;



int main(){
	int n, m;
	cin >> n >> m;
	if (n < 1 || m > 100000)return -1;
	vector<vector<int>> arrn(n,vector<int>(2,0));
	vector<vector<int>> arrm(m, vector<int>(2, 0));
	int temp;
	for (int i = 0; i < n; i++){
		cin >> temp;
		if (temp <= 0 || temp >= 1000)return -1;
		arrn[i][0] = temp;
		cin >> temp;
		if (temp < 0 || temp > 100)return -1;
		arrn[i][1] = temp;
	}
	for (int i = 0; i < m; i++){
		cin >> temp;
		if (temp <= 0 || temp >= 1000)return -1;
		arrm[i][0] = temp;
		cin >> temp;
		if (temp < 0 || temp > 100)return -1;
		arrm[i][1] = temp;
	}
	vector<vector<int>> arr(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (arrn[i][0] >= arrm[j][0] && arrn[i][1] >= arrm[j][1]){
				arr[i][j] = 200 * arrm[j][0] + 3 * arrm[j][1];
			}
		}
	}
	vector<int> arrs(m, 0);
	int flag = 1;
	temp = 0;
	for (int i = 0; i < m; i++)//适用于n<=m
	{
		for (int j = 0; j < n; j++){
			if (arr[j][i] == -1){
				flag = 0;
				break;
			}
			temp += arr[j][i];
		}
		arrs[i] = flag*temp;
		flag = 1;
		temp = 0;
	}
	for (int i = 0; i < m; i++){
		if (arrs[i]>temp){
			temp = arrs[i];
		}
	}
	cout<<n <<endl<<temp<< endl;//最大收益
}