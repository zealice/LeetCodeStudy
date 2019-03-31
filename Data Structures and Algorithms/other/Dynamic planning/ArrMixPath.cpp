//给定一个矩阵m，从左上角开始每次只能向右走或者向下走，最后达到右下角的位置，路径中所有数字累加起来就是路径和，返回所有路径的最小路径和
//动态规划
//不可贪心算法，并不能得到最优解
int minArr(vector<vector<int>> p, int raw, int col){
	//vector<vector<int>> min(raw, vector<int>(col, 0));
	//min[0][0] = p[0][0];
	if (p.empty())return 0;
	for (int i = 1; i < raw; i++){
		p[i][0] = p[i - 1][0] + p[i][0];
	}
	for (int j = 1; j < col; j++){
		p[0][j] = p[0][j - 1] + p[0][j];
	}
	int min;
	for (int j = 1; j < col; j++){
		for (int i = 1; i < raw; i++){
			min = (p[i - 1][j] < p[i][j - 1]) ? p[i - 1][j] : p[i][j - 1];
			p[i][j] = p[i][j] + min;
		}
	}
	return p[raw - 1][col - 1];
}