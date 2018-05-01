// ���� ��� ���� �˰���
// ���������� ���� ���� Ƚ���� �޶��� �� �ִ�.
// ���� �� ���� ������ dp�� �̿��� ���ϴ� ������� ������İ��� �˰����̴�.
// m[i,j] = 0 (i=j)
// m[i,j] = min{m[i,k]+m[k+1,j]+p(i-1)p(k)p(j)} (i<j)

#include <cstdio>
#include <Windows.h>
#include <cstdlib>

int m[501][501]; // ��� ������ ���� minimum cost i~j����
int p[501]; // ����� ���� ũ�⸦ ��� ���� �迭
int k_position[501][501]; // ��ȣ�� �и��Ǵ� ��ġ�� ����ϱ� ���� �迭.

void PrintOptimalParen(int s[][501], int i, int j)
{
	if (i == j) printf("A%d", i);
	else {
		printf("(");
		PrintOptimalParen(s, i, s[i][j]);
		PrintOptimalParen(s, s[i][j] + 1, j);
		printf(")");
	}
}

int main(void)
{
	printf("����� ���� �Է� : ");
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) m[i][i] = 0; // i~i������ ������ �ʱ� ������ cost�� 0�̴�.
	int r, s; // r x s ���
	// ó���� ������ ��� �������� ���� column�̴�.
	printf("�� ����� ��� �� �Է�\n");
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &r, &s);
		p[i] = s;
		// ó���� row�� �������ش�.
		if (!p[0]) p[0] = r;
	}
	printf("\n");
	
	// 1. n���� ����� ���Ѵٰ� �ϸ� �� �ȿ��� [1,k]�� [k+1,n]�� ������ ������ ���� �� �ְ�.
	// ����� ���ϴ� ������ 2������ n���� ���ϴ� ��찡 �ִ�.
	for (int chain = 2; chain <= n; chain++) {
		// 2. ��� ����� ���ϳĿ� ���� ������ ���� ���� �� �ִ�.
		// EX) 2���� ����� ���Ѵٰ� �ϸ� (1,2),(2,3),(3,4)....(n-1,n) �̷� ����� ������ ���´�.
		// ���� i�� 1���� n-chain+1�� ������ ���⿡ �ִ�. ��� ����� ���ϳĿ� ���� ��������� �ϱ� ����!!
		for (int i = 1; i <= n - chain + 1; i++) {
			// 3. ������ i�� ���� chain���� ��ŭ ���ؾ� �ϹǷ� j�� �� ������ �Ѵ�. chain���� ��ŭ �����ִ� ���̴�.
			int j = i + chain - 1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("���ϴ� ����� ���� : %d, ������? : %d ~ %d\n-----------------------------------\n", chain,i, j);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			// ó���� �ּ� ����� ���� ������ �ּҺ���� ã�� ���ؼ� ū������ �ʱ�ȭ ���־�� �Ѵ�.
			m[i][j] = 2100000000;

			// i���� j���� chain ���̸�ŭ ���ϴµ� �� ���ϴµ��� k�� �������� �������� �� �ִ�.
			// EX) 1���� 3���� ���ϴ� ���� (1,1),(2,3)�� (1,2),(3,3)���� ������.
			// ���� k�� ������ i���� j-1�� �Ǵ� ���̴�. k+1�� ���ؼ� ����� ���� �ֱ� ������ j-1����..
			for (int k = i; k <= j - 1; k++) {
				printf("%d���� %d����, %d���� %d������ �ּҺ��\n\n", i, k, k + 1, j);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				if (i == k) printf("A%d = %d X %d | ", i, p[i - 1], p[k]);
				else {
					for (int l = i; l <= k; l++) {
						printf("A%d", l);
					}
					printf(" = %d X %d | ", p[i - 1], p[k]);
				}
				if (k + 1 == j) printf("A%d = %d X %d, ", k + 1, p[k], p[j]);
				else {
					for (int l = k + 1; l <= j; l++) {
						printf("A%d", l);
					}
					printf(" = %d X %d", p[k], p[j]);
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

				//printf("p[i-1] : %d, p[k] : %d, p[j] : %d", p[i-1], p[k], p[j]);
				int temp_min = m[i][k] + m[k + 1][j] + p[i-1] * p[k] * p[j];
				printf(", �ּҺ�� : %d + %d + %d = %d\n",m[i][k],m[k+1][j],p[i-1]*p[k]*p[j], temp_min);
				printf("-------------------------------------------\n");
				if (temp_min < m[i][j]) {
					m[i][j] = temp_min;
					k_position[i][j] = k; // ������ �ּҺ���� ���� split�ϴ� ��ġ
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			printf("%d~%d�� ���� �ּҺ�� : %d\n", i, j, m[i][j]);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("-------------------------------------------\n");
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	printf("\n�ּ� ���� Ƚ�� : %d\n", m[1][n]);
	printf("��� ���ؾ� �ϴ°�? : ");
	PrintOptimalParen(k_position, 1, n);
	system("pause");
	return 0;
}