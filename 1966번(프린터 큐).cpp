#include <iostream>
#include <queue>

// �ñ��� ������ ��ŷ�ϱ� ���� ���
const int ans = 100;

int main(void)
{
	int tc; std::cin >> tc;
	int n, m; // n=�����ǰ���(<=100) m=��ġ(0<=n<n)

	int doc,max; // �Էµ� ������ ���� ū �� 

	// �߿䵵�� �� ť
	std::queue<int> printer;
	// �ִ��� ã�� ���� ť
	std::priority_queue<int> maxFinder;
	// ���� �迭�� �� ť
	std::queue<int> answer;

	while (tc--){
		std::cin >> n; std::cin >> m;

		// ť�� �߿䵵 ���ڵ��� ������� ����ְ�
		// ���� ū ���� üũ�صд�.
		for (int i = 0; i < n; i++){
			std::cin >> doc;
			maxFinder.push(doc);
			// m��° ���� ����ϱ� ���� ��ŷ��� 100�� �����ش�.
			if (i == m) doc += ans;
			printer.push(doc);
		}

		// max���� maxFinder���� ���� �ִ´�.
		max = maxFinder.top(); maxFinder.pop();

		// ����� ������ �Լ��� ȣ������ �ʱ� ����
		// �ӽú��� temp�� ��Ƶд�.
		int temp = printer.front();

		// ���� ���� ���� ū�� �˷��ִ� ����
		bool isMax = false;

		// ť�� ����� ������ �ݺ�
		while (!printer.empty()){
			// ���ϴ� ���� 100���� ū ��찡 �ֱ� ������ üũ
			if (temp > ans)
				max > temp - ans ? isMax = false : isMax = true;
			else
				max > temp ? isMax = false : isMax = true;

			// �� ���� �ִ��� �ƴ϶�� ���� �ڷ� ������
			// temp ������Ʈ
			if (!isMax && !printer.empty()){
				printer.pop();
				printer.push(temp);
				temp = printer.front();
			}
			// �� ���� �ִ��̶�� max ������Ʈ
			// maxFinder�� ���(�켱���� ť)
			// printer�� ���� �տ� ���� answer�� ����ִ´�.
			else if (isMax){
				if (!maxFinder.empty())
				{max = maxFinder.top(); maxFinder.pop();}
				answer.push(printer.front()); printer.pop();
				if(!printer.empty()) temp = printer.front();
			}
			
		}

		// answer�� ũ�Ⱑ ��� ���ϱ� ������ ����
		int size = answer.size();
		for (int i = 0; i<size; i++){
			if (answer.front() > ans) std::cout << i + 1 << '\n';
			answer.pop();
		}
	}

	return 0;
}