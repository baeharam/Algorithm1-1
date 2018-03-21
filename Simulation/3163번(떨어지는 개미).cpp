#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

typedef std::vector<std::pair<int, int>> vp;

vp ant;
std::deque<int> idList;
std::vector<int> fallList;

int main(void)
{
	int tc; std::cin >> tc;
	while (tc--) {
		int n, l, k, id, pos; std::cin >> n >> l >> k;
		while (n--) {
			std::cin >> pos >> id;
			// id������ ����ϱ� ���� idList�� �����Ѵ�.
			idList.push_back(id);
			// ����(���/����)�� ���� 0 Ȥ�� l�� ������ġ���� �Ÿ��� ���ؾ� �Ѵ�.
			id < 0 ? ant.push_back({ pos,id }) : ant.push_back({ l - pos,id });
		}
		// std::vector<std::pair>�� sort�� ���� ó�� ���ұ������� �Ѵ�.
		// ���� ������ �������� �ð� �������� �����Ѵ�.
		std::sort(ant.begin(), ant.end());

		for (int i = 0; i < ant.size(); i++) {
			// id�� ��,�ڸ� ���� ����س��´�.
			int frontValue = idList.front(), backValue = idList.back();

			// �������� �ð��� ���� ���
			if (i != ant.size() - 1 && ant[i].first == ant[i + 1].first) {
				// id�� �� ���� �� ���� �����Ѵ�.
				if (frontValue < backValue) {
					fallList.push_back(frontValue);
					fallList.push_back(backValue);
				}
				else {
					fallList.push_back(backValue);
					fallList.push_back(frontValue);
				}
				// 2���� ó�����־��� ������ ������ ��� pop���ְ� i�� �ѹ��� ������Ų��.
				idList.pop_back(); idList.pop_front(); i++;
			}
			// �Ϲ����� ��� id�� ��ȣ ��, ���⿡ ���� � id�� ������ ���� �����Ѵ�.
			else if (ant[i].second < 0) {
				fallList.push_back(frontValue);
				idList.pop_front();
			}
			else {
				fallList.push_back(backValue);
				idList.pop_back();
			}
		}
		std::cout << fallList[k - 1] << '\n';

		// �ʱ�ȭ
		ant.clear();
		idList.clear();
		fallList.clear();
	}
	return 0;
}