// 汉诺塔
//分治的思想，大问题化小问题，递归
void hanoTower(int n, char A, char B, char C){
	if (n == 1){
		cout << A << "->" << B << endl;
		return;
	}
	hanoTower(n - 1, A, C, B);
	hanoTower(1, A, B, C);
	hanoTower(n - 1, C, B, A);
}