#include <iostream>

int ps[2000 + 1][2000 + 1];
int score[2000 + 1];
int people[2000 + 1];
int num[2000 + 1];

int main(void)
{
	int n, t, p; std::cin >> n >> t >> p;

	// �� ����� ID�� Ǭ ������ 1�� ��Ǭ ������ 0���� �ʱ�ȭ
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= t; j++){
			std::cin >> ps[i][j];
		}
	}

	// �� �迭�� �������� ���� �ʱ�ȭ
	for (int i = 1; i <= t; i++){
		for (int j = 1; j <= n; j++){
			if (ps[j][i] == 0) score[i]++;
		}
	}

	// ������ �������� �� ����� ȹ���� �� ���� �ʱ�ȭ
	// ���ÿ� �� ����� Ǭ ���� �� �ʱ�ȭ
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= t; j++){
			if (ps[i][j] == 1){
				people[i] += score[j];
				num[i]++;
			}
		}
	}

	int rank = 1;

	// ���̵� p�� ��츦 �����ϰ� �˻�
	// ������ ���ǿ� ���� ���� ���
	for (int i = 1; i <= n; i++){
		if (i != p){
			if (people[i] > people[p]) rank++;
			else if (people[i] == people[p]){
				if (num[i] > people[p]) rank++;
				else if (num[i] == num[p] && i < p) rank++;
			}
		}
	}

	std::cout << people[p] << ' ' << rank;

	return 0;
}