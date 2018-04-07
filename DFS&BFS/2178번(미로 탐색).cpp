#include <cstdio>
#include <queue>
#include <algorithm>

int maze[101][101];
bool visited[101][101];
char s[101];

struct Pos {
	int x;
	int y;
	int length;
};

int main(void)
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		for (int j = 0; j < m; j++) {
			maze[i][j+1] = s[j] - '0';
			visited[i][j+1] = false;
		}
	}

	// �������� �ʱ�ȭ�ؼ� ť�� �ֱ�
	Pos begin = { 1,1,1 };
	std::queue<Pos> path;
	path.push(begin);
	visited[1][1] = true;

	int x = 0, y = 0;
	int len = 1;
	int ans = 1e10;

	while (!path.empty()) {
		x = path.front().x; y = path.front().y;
		len = path.front().length;
		if (x == n && y == m) {
			ans = std::min(ans, len);
			break;
		}
		path.pop();
		

		// ����
		if (x - 1 >= 1 && maze[x-1][y]==1 && visited[x - 1][y] == false) {
			Pos up = { x - 1,y,len+1 };
			path.push(up);
			visited[x - 1][y] = true;
		}
		// �Ʒ���
		if (x + 1 <= n && maze[x+1][y] == 1 && visited[x + 1][y] == false) {
			Pos down = { x + 1,y,len + 1 };
			path.push(down);
			visited[x + 1][y] = true;
		}
		// ����
		if (y-1>=1 && maze[x][y-1] == 1 && visited[x][y - 1] == false) {
			Pos left = { x,y - 1,len + 1 };
			path.push(left);
			visited[x][y - 1] = true;
		}
		// ������
		if (y + 1 <=m && maze[x][y+1] == 1 && visited[x][y + 1] == false) {
			Pos right = { x,y+1,len + 1 };
			path.push(right);
			visited[x][y + 1] = true;
		}
	}

	printf("%d", ans);



	return 0;
}