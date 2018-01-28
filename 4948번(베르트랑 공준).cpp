#include <iostream>

// while(true)�� ���� �ʱ� ����
const int flag = 123457;

// �ִ� ����
const int max = 2 * 123456;

int main(void)
{
	// C�� stream�� sync�� ������ �ʾƼ� �ӵ� ��!
	std::ios_base::sync_with_stdio(false);

	int n = flag;

	while (n){
		std::cin >> n; if (!n) break;
		int num = 0; // �Ҽ��� ����

		// �����佺�׳׽��� ü�� �̿��ϱ� ���� bool �迭
		// ���� �״�θ� index�� ���
		bool eratos[max + 1] = { false };
		for (int i = 2; i <= 2 * n; i++){
			if (!eratos[i]){
				if(i>n) num++;
				for (int j = i + i; j <= 2 * n; j += i) eratos[j] = true;
			}
		}
		std::cout << num << '\n';
	}

	return 0;
}