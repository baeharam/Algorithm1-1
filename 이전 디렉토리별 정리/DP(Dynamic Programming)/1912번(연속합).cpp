#include <iostream>

// dp[i][0] = ���� ��
// dp[i][1] = ���� ��
// dp[i][2] = ���� ���� �ִ�
int dp[100000 + 1][3];

int main(void)
{
	int n; std::cin >> n;

	for (int i = 1; i <= n; i++) std::cin >> dp[i][0];
	dp[1][1] = dp[1][2] = dp[1][0];

	// �������� ����� ���� ���� ���� �������߿� �� ū������ �ʱ�ȭ��Ų��.
	for (int i = 2; i <= n; i++) {
		int temp = dp[i][0] + dp[i - 1][1];
		if (dp[i][0] > temp) dp[i][1] = dp[i][0];
		else dp[i][1] = temp;
	}

	// �����հ� ������ �������� �ִ��� ���ؼ� �� ū ���� �������� �ִ����� �����Ѵ�.
	for (int i = 2; i <= n; i++) {
		if (dp[i][1] > dp[i - 1][2]) dp[i][2] = dp[i][1];
		else dp[i][2] = dp[i - 1][2];
	}

	std::cout << dp[n][2];

	return 0;
}