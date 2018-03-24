#include <cstdio>
#include <algorithm>
#include <cstring>

// dp[��][���ʳ�][�����ʳ�]
// �ٿ��� �Ͽ��� �ִ�� �ϵ��� �������
// ����� �Ͽ��� �ּҷ� �ϵ��� �������
int dp[2][1001][1001];
int card[1001];

int game(int turn, int left, int right)
{
	// ī�尡 1���� ��� �ٿ�� ������ ��� ���� �׳� �ѱ��.
	if (left == right) {
		if (turn == 0) return card[left];
		else if (turn == 1) return 0;
	}

	if (dp[turn][left][right] != -1) return dp[turn][left][right];

	// �ٿ��� ��� ���� ī�带 ������ ���� ������ ī�带 ������ ��� �� �ִ��� ��������� ����Ѵ�.
	if (turn == 0)
		dp[turn][left][right] = std::max(card[left] + game(1, left + 1, right), card[right] + game(1, left, right - 1));
	// ����� ��� �ٿ��� ������ �ּҷ� �ϴ� ���� ã�� ���� ��������� ����Ѵ�. ��, ���� ������ ���� �����Ƿ� ī�������� ������ �ʴ´�.
	else if(turn==1)
		dp[turn][left][right] = std::min(game(0, left + 1, right), game(0, left, right - 1));
	
	return dp[turn][left][right];
}

int main(void)
{
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= n; i++) scanf("%d", &card[i]);

		printf("%d\n", game(0,1,n));
	}
	return 0;
}