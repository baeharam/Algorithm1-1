#include <iostream>
#include <queue>

int main(void)
{
	int n, m; std::cin >> n; std::cin >> m;

	std::queue<int> josepus;
	std::queue<int> answer;
	// 1���� n���� ť�� �ִ´�.
	for (int i = 1; i <= n; i++) josepus.push(i);

	// �� ��° ����� �������� ����
	int idx = 1;

	// ť���� ���� ���� ������ �ӽú���
	int temp = 0;

	// ť�� ����� ������ �ݺ�
	while (!josepus.empty()){
		// m��° ����� �ƴ϶�� ť���� �� ���� �ڿ� ����ֱ�
		if (idx != m){
			temp = josepus.front();
			josepus.pop();
			josepus.push(temp);
			idx++;
		}
		// m��° ����̶�� ���� answer ť�� ����ֱ�
		else{
			answer.push(josepus.front());
			josepus.pop();
			idx = 1;
		}
	}
	
	// ������ ����
	int size = answer.size();

	for (int i = 0; i < size; i++){
		if (i == 0) {
			if (size == 1) std::cout << '<' << answer.front() << '>';
			else std::cout << '<' << answer.front() << ", ";
		}
		else if (i == size - 1) std::cout << answer.front() << '>';
		else std::cout << answer.front() << ", ";
		answer.pop();
	}

	return 0;
}