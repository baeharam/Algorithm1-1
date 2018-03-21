// ���� ��� ���� �˰���
// ���������� ���� ���� Ƚ���� �޶��� �� �ִ�.
// ���� �� ���� ������ dp�� �̿��� ���ϴ� ������� ������İ��� �˰����̴�.
// m[i,j] = 0 (i=j)
// m[i,j] = min{m[i,k]+m[k+1,j]+p(i-1)p(k)p(j)} (i<j)

#include <cstdio>

int m[501][501]; // ��� ������ ���� minimum cost i~j����
int p[501]; // ����� ���� ũ�⸦ ��� ���� �迭
int k_position[501][501]; // ��ȣ�� �и��Ǵ� ��ġ�� ����ϱ� ���� �迭.

int main(void)
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) m[i][i] = 0; // i~i������ ������ �ʱ� ������ cost�� 0�̴�.
	int r, s; // r x s ���
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &r, &s);
		p[i] = s;
		if (!p[0]) p[0] = r;
	}
	
	for (int chain = 2; chain <= n; chain++) {
		for (int i = 1; i <= n - chain + 1; i++) {
			int j = i + chain - 1;
			m[i][j] = 2100000000; // minimum cost�� ã�� ���ؼ� �ſ� ū������ �ʱ�ȭ
			for (int k = i; k <= j - 1; k++) {
				//printf("%d���� %d����, %d���� %d������ �ּҺ��\n", i, k, k + 1, j);
				//printf("p[i-1] : %d, p[k] : %d, p[j] : %d\n", p[i-1], p[k], p[j]);
				int temp_min = m[i][k] + m[k + 1][j] + p[i-1] * p[k] * p[j];
				if (temp_min < m[i][j]) {
					m[i][j] = temp_min;
					k_position[i][j] = k;
				}
			}
		}
	}
	printf("%d", m[1][n]);
	return 0;
}