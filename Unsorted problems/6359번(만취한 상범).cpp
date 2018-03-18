#include <iostream>

int main(void)
{
	int tc,n; std::cin >> tc;
	bool room[100 + 1]; // 5����~100����

	for (int i = 1; i <= 100; i++) room[i] = true;

	// �������� : true (ó���� ����̰� �� �����ٰ� ����)
	// �� ���� ���� ù��°�̹Ƿ� 2������� �˻�
	// �������� : false 

	while (tc--){
		std::cin >> n;
		for (int i = 2; i <= n; i++){
			for (int j = i; j <= n; j++){
				// i�� ����� �游 �˻��Ѵ�.
				// ���������� �ݰ� ���������� ����.
				if (j%i == 0)
					room[j] ? room[j] = false : room[j] = true;
			}
		}
		int whoCanRun = 0;
		for (int i = 1; i <= n; i++){
			// �����ִ� �游 ������ �� �ִ�.
			if (room[i]) whoCanRun++;
			// ��� ���� �ٽ� ���� (�ʱ�ȭ)
			room[i] = true;
		}
		std::cout << whoCanRun << '\n';
	}

	return 0;
}