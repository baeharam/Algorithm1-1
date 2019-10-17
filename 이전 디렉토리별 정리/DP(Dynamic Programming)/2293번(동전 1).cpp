#include <iostream>

int dp[10000 + 1];
int cost[100 + 1];

int main(void)
{
	int n, k; std::cin >> n >> k;

	for (int i = 1; i <= n; i++) std::cin >> cost[i];

	dp[0] = 1; // �ڱ��ڽ� ��ŭ�� ��ġ�� ������ ��� �ε����� 0�� �Ǿ 1�� �̸� �ʱ�ȭ.

	for (int i = 1; i <= n; i++) {
		for (int j = cost[i]; j <= k; j++)	
			dp[j] += dp[j - cost[i]];
	}

	std::cout << dp[k];
	return 0;
}