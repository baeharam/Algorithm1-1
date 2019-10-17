#include <cstdio>
#include <algorithm>

// �� ȸ�Ǵ� ���۽ð��� ���ð��� ����
struct Meet {
	int begin;
	int end;
};

Meet m[100005]; // ȸ���� ���� �ִ� 10����

/*
1. ������ �ð��� ���� ȸ�Ǻ��� �߰��Ѵ�. (���� �ð��� �����ϱ�)
2. ������ �ð��� ���� ���, ���۽ð��� ���� ȸ�Ǻ��� �߰��Ѵ�.
*/
bool cmp(const Meet& m1, const Meet& m2) {
	return (m1.end == m2.end) ? (m1.begin < m2.begin) : (m1.end < m2.end);
}

int main(void)
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d %d", &m[i].begin, &m[i].end);
	std::sort(m, m + (n + 1), cmp); // ���� cmp�Լ� �������� sorting

	// ������ �ð� �������� ���ĉ����ϱ� ����ü �迭�� ù��° end�� ���� ���� ������ �ð�
	// time�� �ʱ�ȭ ��Ű�� ȸ�Ǹ� 1�� �����ϱ� num�� 1.
	int time = m[1].end;
	int num = 1;

	for (int i = 2; i <= n; i++) {
		// time�� ������ ������ ȸ���� �ð����� ���ų� ������ ȸ�Ǹ� �� �� �����Ƿ� num�����ϰ�
		// ������ �ð��� ���� ������ ȸ���� ������ �ð����� �ٽ� ����.
		if (time <= m[i].begin) {
			num++;
			time = m[i].end;
		}
	}


	printf("%d", num);
	return 0;
}