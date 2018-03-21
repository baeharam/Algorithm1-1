#include <iostream>
#include <stack>

int h[100000];

int main(void)
{
	int n; std::cin >> n;
	while (n) {
		std::stack<int> s;
		for (int i = 0; i < n; i++) std::cin >> h[i];
		long long area = 0;

		for (int i = 0; i < n; i++) {
			// ������ ������� �ʰ� i��° ���簢���� ���̺��� ���ÿ� ����ִ� �ε����� ���̰� ū ���
			while (!s.empty() && h[s.top()] > h[i]) {
				// ���ÿ��� pop��Ű�� ���� ���� ����
				long long height = h[s.top()];
				s.pop();
				// pop���� �� ������ ��� �Ǹ� �� �ʺ�� i��° ���簢���� ������ ���ÿ� ����ִ� ���簢���� ������ �ʺ� �ȴ�.
				long long width = i;
				// pop���� �� ���ÿ� ������ �ִٸ� i~s.top()�� ���̰� �ʺ� �ȴ�.
				if (!s.empty()) width = i - s.top() - 1;
				// �� ū ���̰� ���� ����
				if (width*height > area) area = width * height;
			}
			// �׻� ���ÿ� �ε����� �ִ´�.
			s.push(i);
		}


		// ������ ������� ���� ���, ������ ������ ���� ��!
		while (!s.empty()) {
			long long height = h[s.top()];
			s.pop();
			long long width = n;
			if (!s.empty()) width = n - s.top() - 1;
			if (width*height > area) area = width * height;
		}
		std::cout << area << '\n';
		std::cin >> n;
	}
	return 0;
}