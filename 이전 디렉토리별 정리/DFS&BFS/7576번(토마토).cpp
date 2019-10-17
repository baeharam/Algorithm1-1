#include <iostream>
#include <queue>
using namespace std;

struct tc{
	int cond;
	int x;
	int y;
};

tc tomato[1005][1005], t;
queue<tc> q;

int main(void)
{
	// n�� ���� ����, m�� ���� �����̹Ƿ� �ݴ�� �Է¹޴´�.
	int n, m; cin >> m >> n;

	// �� ���� �丶�� ����
	int tomatoNum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j].cond;
			// x�� ����, y�� ���� �����Ѵ�.
			// ��/��/��/��� ���ϱ� ���ؼ�!
			tomato[i][j].x = i;
			tomato[i][j].y = j;
			if (tomato[i][j].cond==0) tomatoNum++;
			else if (tomato[i][j].cond == 1) q.push(tomato[i][j]);
		}
	}

	while (!q.empty()) {
		t = q.front(); q.pop();
		// ����
		if (t.x - 1 >= 0 && tomato[t.x-1][t.y].cond == 0) {
			// t.cond+1�� �ٽ��ε� �丶�䰡 �;�� ��¥�� ���ϱⰡ ��������� ����ü�� cond�� �����ؼ�
			// ���� �丶��� �Ͽ��� �ű⼭ 1���� ��Ŵ���� ���� �� �־���.
			tomato[t.x-1][t.y].cond = t.cond+1;
			q.push(tomato[t.x-1][t.y]);
		}
		// �Ʒ���
		if (t.x + 1 <= n-1 && tomato[t.x+1][t.y].cond == 0) {
			tomato[t.x+1][t.y].cond = t.cond+1;
			q.push(tomato[t.x+1][t.y]);
		}
		// ����
		if (t.y - 1 >= 0 && tomato[t.x][t.y-1].cond == 0) {
			tomato[t.x][t.y-1].cond = t.cond+1;
			q.push(tomato[t.x][t.y-1]);
		// ������
		if (t.y + 1 <= m - 1 && tomato[t.x][t.y + 1].cond == 0) {
			tomato[t.x][t.y + 1].cond = t.cond + 1;
			q.push(tomato[t.x][t.y + 1]);
		}
	}

	// �� ���� �丶�䰡 �ִ��� �˻�
	bool tomatoComplete = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j].cond == 0) tomatoComplete = false;
		}
		if (!tomatoComplete) break;
	}

	// cond-1�ϴ� ������ ó���� cond=1�̱� �����̴�.
	if (tomatoComplete) cout << tomato[t.x][t.y].cond - 1;
	else cout << "-1";
	return 0;
}