#include <iostream>

int dp[1000000+1];


int main(void)
{
	int n; std::cin >> n;

	while(n>1){
		// 1) ������ �ִ� ���� ������Ʈ �� �� �߿� �� �������� �����Ѵ�.
		// 2) ���� 0�� ��� �ƹ��͵� ������� �ʾұ� ������ ������ ������Ʈ ��Ų��.
		if (dp[n - 1] > dp[n]+1 || dp[n-1]==0) dp[n - 1] = dp[n] + 1;
		if (n % 2 == 0 && (dp[n / 2]>dp[n] + 1 || dp[n/2]==0)) dp[n / 2] = dp[n] + 1;
		if (n % 3 == 0 && (dp[n / 3]>dp[n] + 1 || dp[n/3]==0)) dp[n / 3] = dp[n] + 1;
		n--;
	}

	std::cout << dp[1];

	return 0;

}