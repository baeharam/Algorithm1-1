#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> p, m;

int num[10001], n, ans;

// ������ ����� ���� �����ؼ� ������ ���� �ͺ���, ����� ū �ͺ��� ������
// ������ ���� ��� 1. ������ 0�� ���ϴ� ���� �̵�
// ������ ���� ��� 2. ����� ��� ���ϱⰡ ���ϱ⺸�� ū ��찡 ���� �� ����


int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		num[i] <= 0 ? m.push_back(num[i]) : p.push_back(num[i]);
	}

	sort(m.begin(), m.end());
	sort(p.begin(), p.end());
	
	int i = 0;
	while(i<m.size()) {
		if (i + 1 < m.size()) {
			ans += (m[i] * m[i + 1]);
			i += 2;
		}
		else {
			ans += m[i];
			i++;
		}
	}

	i = p.size() - 1;
	while (i >= 0) {
		if (i - 1 >= 0 && (p[i]*p[i-1] > p[i]+p[i-1])) {
			ans += (p[i] * p[i - 1]);
			i -= 2;
		}
		else {
			ans += p[i];
			i--;
		}
	}

	printf("%d\n", ans);
	return 0;
}