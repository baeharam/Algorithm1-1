#include <iostream>
#include <algorithm>

int dp[500 + 1][500 + 1];
int novel[500 + 1];
int sum[500 + 1];

int main(void)
{
	int tc; std::cin >> tc;
	int chapter;

	while (tc--) {
		std::cin >> chapter;

		//std::cout << "original\n\n";

		// novel �迭���� ������ �� ���� ������ ũ�⸦ �ְ�
		// sum �迭���� �� ����ũ����� �������� ����ؼ� �ִ´�.
		for (int i = 1; i <= chapter; i++) {
			std::cin >> novel[i];
			sum[i] = sum[i - 1] + novel[i];
		}

		// 1��° ����� ������ ���� chapter �ٷ� �������� �ݺ��Ѵ�.
		for (int i = 1; i < chapter; i++) {
			for (int x = 1; x + i <= chapter; x++) {
				//std::cout << x << "��° ����� " << x + i << "��° ����� : ";
				int y = x + i;
				dp[x][y] = INT_MAX;

				for (int k = x; k < y; k++) {
					//std::cout << x << " ~ " << k << " , " << k+1 << " ~ " << y<< " | ";
					dp[x][y] = std::min(dp[x][y], dp[x][k] + dp[k + 1][y] + sum[y] - sum[x - 1]);
				}
				std::cout << '\n';
			}
		}
		
		std::cout << dp[1][chapter];

	}

	return 0;
}