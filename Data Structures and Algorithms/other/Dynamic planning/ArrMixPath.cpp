//����һ������m�������Ͻǿ�ʼÿ��ֻ�������߻��������ߣ����ﵽ���½ǵ�λ�ã�·�������������ۼ���������·���ͣ���������·������С·����
//��̬�滮
//����̰���㷨�������ܵõ����Ž�
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