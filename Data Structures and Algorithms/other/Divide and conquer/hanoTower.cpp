// ��ŵ��
//���ε�˼�룬�����⻯С���⣬�ݹ�
void hanoTower(int n, char A, char B, char C){
	if (n == 1){
		cout << A << "->" << B << endl;
		return;
	}
	hanoTower(n - 1, A, C, B);
	hanoTower(1, A, B, C);
	hanoTower(n - 1, C, B, A);
}