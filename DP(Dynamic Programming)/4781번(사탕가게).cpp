#include <cstdio>
#include <algorithm>
#include <cstring>

int dp[10005]; // 1��~10,000������ ���� �� ����
int candy[5005][2]; // ������ ������ �ִ� 5000�� �׸��� ������ Į�θ��� ����

int main(void)
{
	// int_m, int_p�� �Ҽ��� ������ �ٲٱ� ���� ����
	int n, c, int_m, int_p;
	double m, p;
	scanf("%d %lf", &n, &m);
	int_m = (int)(m * 100 + 0.5);

	while (n&&int_m) {
		for (int i = 1; i <= n; i++) {
			scanf("%d %lf", &c, &p);
			int_p = (int)(p * 100 + 0.5);
			candy[i][0] = c; candy[i][1] = int_p;
		}

		for (int p = 1; p <= int_m; p++) {
			for (int i = 1; i <= n; i++) {
				int ci = candy[i][0]; // ������ Į�θ�
				int pi = candy[i][1]; // ������ ����
				if (pi <= p)
					dp[p] = std::max(dp[p], ci + dp[p - pi]);
			}
		}

		printf("%d\n", dp[int_m]);
		memset(dp, 0, sizeof(dp));
		scanf("%d %lf", &n, &m);
		int_m = (int)(m * 100 +0.5);
	}

	return 0;
}