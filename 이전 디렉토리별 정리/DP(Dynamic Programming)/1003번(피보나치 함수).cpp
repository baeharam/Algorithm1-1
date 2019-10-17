#include <cstdio>

// 0~40
int memo[41][2];

void fibonacci(int n) {
	// memo�� ���� ������Ʈ ������ �׳� ����
	if (memo[n][0] != -1 && memo[n][1] != -1) return;
	// memo�� ���� ������Ʈ ���� �ʾҰ� ���� n-2, n-1�� ���� ���� ������Ʈ �Ǿ�����
	// ���� �Ǻ���ġ ���� ��������� ������Ʈ
	else if ((memo[n-2][0] != -1 && memo[n-2][1] != -1) &&
		(memo[n - 1][0] != -1 && memo[n - 1][0] != -1)) {
		memo[n][0] = memo[n - 2][0] + memo[n - 1][0];
		memo[n][1] = memo[n - 2][1] + memo[n - 1][1];
	}
	// memo[n]�� ������Ʈ �ȉ�� memo[n-2], memo[n-1]�� �ϳ��� ������Ʈ �ȵǾ����� 
	// �ٽ� �Ǻ���ġ �Լ��� �ҷ��� ������Ʈ ��Ų �Ŀ� �������� n�� ���� �ٽ� �ҷ��� �������Ѵ�.
	else {
		fibonacci(n - 1);
		fibonacci(n - 2);
		fibonacci(n);
	}
}

int main(void)
{
	int tc, n; scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		// ���� -1�� �ʱ�ȭ
		for (int i = 0; i <= 40; i++) {
			memo[i][0] = -1;
			memo[i][1] = -1;
		}
		// 0�� 1�� ���� �ʱ�ȭ
		memo[0][0] = 1, memo[1][1] = 1;
		memo[0][1] = 0, memo[1][0] = 0;
		fibonacci(n);
		printf("%d %d\n", memo[n][0], memo[n][1]);
	}
}