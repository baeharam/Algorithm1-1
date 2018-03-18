#include <iostream>

int main(void)
{

	int N, L; std::cin >> N >> L;
	int beginNum = -1, iter = -1;

	// L�� ������ 100�����ϱ� 100������ ���Ѵ�.
	for (int i = L; i <= 100; i++) {
		// L�� Ȧ���̰� N�� L�� ������ �������� ���
		if (i % 2 != 0 && N%i == 0) beginNum = N / i - i / 2;
		// L�� ¦���̰� N�� L�� �������� ���� �������� L�� 2�� ���� ���� ���
		else if (i % 2 == 0 && N%i == i / 2) beginNum = N / i - (i / 2 - 1);
		// ���ۼ��ڰ� ���Ǿ����� �ݺ�Ƚ���� �����ϰ� ���´�.	
		if (beginNum != -1) {
			iter = i;
			break;
		}
	}

	// �ݺ�Ƚ���� ������� �ʾҰų� ���ۼ��ڰ� ������ -1�� ����Ѵ�.
	if (iter == -1 || beginNum < 0) std::cout << -1;

	// �ƴϸ� ���ۼ��ں��� �ݺ�Ƚ����ŭ ���ӵ� ���ڵ��� ����Ѵ�.
	else {
		for (int i = 0; i < iter; i++)
			std::cout << beginNum + i << ' ';
	}

	return 0;
}