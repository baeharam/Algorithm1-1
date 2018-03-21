#include <iostream>

int dp[500 + 1][500 + 1];
int novel[500 + 1];
int C[500 + 1];
int A[500 + 1][500 + 1];

int main(void)
{
	int tc; std::cin >> tc;
	int last_chapter;

	while (tc--) {
		std::cin >> last_chapter;

		std::cout << "knuth optimization\n\n";

		// novel �迭���� ������ �� ���� ������ ũ�⸦ �ְ�
		// C �迭���� �� ����ũ����� �������� ����ؼ� �ִ´�.
		for (int i = 1; i <= last_chapter; i++) {
			std::cin >> novel[i];
			C[i] = C[i - 1] + novel[i];
		}
		for (int i = 1; i <= last_chapter; i++)
			A[i - 1][i] = i;

		// 1��° ����� ������ ���� last_chapter �ٷ� �������� �ݺ��Ѵ�.
		for (int i = 2; i <= last_chapter; i++) {
			for (int x = 0; x + i <= last_chapter; x++) {
				std::cout << x + 1 << "��° ����� " << x + i << "��° ����� : ";
				int y = x + i;
				dp[x][y] = INT_MAX;

				for (int k = A[x][y-1]; k <=A[x+1][y]; k++) {
					std::cout << x+1 << " ~ " << k << " , " << k << " ~ " << y << " | ";
					int min = dp[x][k] + dp[k][y] + C[y] - C[x];
					if (dp[x][y] > min) {
						dp[x][y] = min;
						A[x][y] = k;
					}
				}
				std::cout << '\n';
			}
		}

		std::cout << dp[0][last_chapter];

	}

	return 0;
}