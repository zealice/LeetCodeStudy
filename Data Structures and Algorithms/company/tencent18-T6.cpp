#include<iostream>
#include<vector>
using namespace std;

void eraseY(vector<vector<char>> & paint, int n, int m, int i, int j){
	paint[i][j] = 'X';
	int temp1 = 1;
	int temp2 = 1;
	while (!((i - temp1 < 0 || j - temp1 < 0 || paint[i - temp1][j - temp1] == 'X' || paint[i - temp1][j - temp1] == 'B') && (i + temp2 >= n || j + temp2 >= m || paint[i + temp2][j + temp2] == 'X' || paint[i + temp2][j + temp2] == 'B'))){
		if (i - temp1 >= 0 && j - temp1 >= 0){
			if (paint[i - temp1][j - temp1] == 'Y'){
				paint[i - temp1][j - temp1] = 'X';
			}
			else if (paint[i - temp1][j - temp1] == 'G'){
				paint[i - temp1][j - temp1] = 'B';
			}
			temp1 += 1;
		}
		if (i + temp2 < n && j + temp2 < m){
			if (paint[i + temp2][j + temp2] == 'Y'){
				paint[i + temp2][j + temp2] = 'X';
			}
			else if (paint[i + temp2][j + temp2] == 'G'){
				paint[i + temp2][j + temp2] = 'B';
			}
			temp2 += 1;
		}
	}
}

void eraseB(vector<vector<char>> & paint, int n, int m, int i, int j){
	paint[i][j] = 'X';
	int temp1 = 1;
	int temp2 = 1;
	while (!((i - temp1 < 0 || j + temp1 >= m || paint[i - temp1][j + temp1] == 'X' || paint[i - temp1][j + temp1] == 'Y') && (i + temp2 >= n || j - temp2 < 0 || paint[i + temp2][j - temp2] == 'X' || paint[i + temp2][j - temp2] == 'Y'))){
		if (i - temp1 >= 0 && j + temp1 < m){
			if (paint[i - temp1][j + temp1] == 'B'){
				paint[i - temp1][j + temp1] = 'X';
				temp1 += 1;
			}
			else if (paint[i - temp1][j + temp1] == 'G'){
				paint[i - temp1][j + temp1] = 'Y';
				temp1 += 1;
			}
		}
		if (i + temp2 < n && j - temp2 >= 0){
			if (paint[i + temp2][j - temp2] == 'B'){
				paint[i + temp2][j - temp2] = 'X';
				temp2 += 1;
			}
			else if (paint[i + temp2][j - temp2] == 'G'){
				paint[i + temp2][j - temp2] = 'Y';
				temp2 += 1;
			}
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<char>> paint(n,vector<char>(m,'X'));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> paint[i][j];
		}
	}
	int sum=0;//×Ü±Ê»­Êý
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (paint[i][j] == 'X')continue;
			if (paint[i][j] == 'Y'){
				eraseY(paint, n, m, i, j);
				sum++;
				continue;
			}
			if (paint[i][j] == 'B'){
				eraseB(paint, n, m, i, j);
				sum++;
				continue;
			}
			if (paint[i][j] == 'G'){
				eraseY(paint, n, m, i, j);
				eraseB(paint, n, m, i, j);
				sum += 2;
				continue;
			}
		}
	}
	cout << sum << endl;
	return 0;
}