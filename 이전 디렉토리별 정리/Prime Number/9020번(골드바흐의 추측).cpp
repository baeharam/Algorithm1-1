#include <iostream>

const int max = 10000 + 1;

int main(void)
{
	std::ios_base::sync_with_stdio(false);

	int tc,n; std::cin >> tc;

	while (tc--){
		std::cin >> n;
		int min = n-2, prime=0;
		// �����佺�׳׽��� ü
		bool eratos[max] = { false }; eratos[0] = true; eratos[1] = true;

		// �Ҽ��ΰͰ� �ƴѰ��� �ɷ�����
		for (int i = 2; i <= n; i++){
			if (eratos[i] == false)
				for (int j = i + i; j <= n; j += i) eratos[j] = true;
		}

		// 2���� �Ҽ��� �͵鸸 ��� n���� ���̵� �Ҽ��ΰ��� ����.
		// �� �߿� �� ���̰� ���� ���� ù��° �Ҽ��� prime�� ��´�.
		for (int i = 2; i <= n; i++){
			if (!eratos[i] && !eratos[n - i]){
				if (n-i-i>=0 && min > n - i - i) {
					min = n - i - i;
					prime = i;
				}
			}
		}

		std::cout << prime << " " << n - prime << std::endl;
	}

	return 0;
}