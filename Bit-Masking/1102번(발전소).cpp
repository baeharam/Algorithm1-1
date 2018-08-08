#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
int cost[17][17], dp[1 << 17], n, p, start;
string factory_state;

int fix(int state, int num)
{
	// �����Ұ� p����ŭ �����ִٸ� ���� �����̹Ƿ� 0 ����
	if (num == p) return 0;
	// �� ������ �������ϰ� ���� �����ִ� ��Ȳ�̶�� -1 ����
	if (state == 0) return -1;

	// �޸������̼�
	int &ret = dp[state];
	if (ret != -1)return ret;

	// �ּڰ��� ���� �ʱ�ȭ
	ret = INF;
	for (int i = 0; i < n; i++) {
		// ���� �ִ� ������ ã�´�.
		if (state&(1 << i)) {
			for (int j = 0; j < n; j++) {
				// ���� �����Ҹ� �ٽ�
				if (i == j) continue;
				// �����ִ� ������ ã�´�.
				if ((state&(1 << j)) == 0)
					// �����ִ� �� �� ���¸� �ѱ�� ��� ���� ������ ���
					ret = min(ret, fix(state | (1 << j), num+1) + cost[i][j]);
			}
		}
	}
	return ret;
}

int main(void)
{
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> cost[i][j];
	}
	cin >> factory_state >> p;
	
	// ���� ���� Ȯ�� �� �ʱ�ȭ, �׸��� � �����ִ��� Ȯ��
	int cnt = 0;
	for (int i = 0; i < factory_state.size(); i++) {
		if (factory_state[i] == 'Y') {
			start |= (1 << i);
			cnt++;
		}
	}

	// p�� �̻� ���� ������ ��� �ʿ����
	if (cnt >= p) puts("0");
	// p�� �̸��ε� 0�� ���������� ������ ���� �Ұ�
	else if (cnt == 0) puts("-1");
	// �ƴϸ� �ּҺ�� ���
	else printf("%d", fix(start, cnt));
		
	return 0;
}