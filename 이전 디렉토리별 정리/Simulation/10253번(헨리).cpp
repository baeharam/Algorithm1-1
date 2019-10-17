#include <iostream>

long long inputFraction[2];
long long unitFraction[2];

long long GCD(long long a, long long b)
{
	if (a < b) std::swap(a, b);
	while (b) {
		long long temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}

long long LCM(long long a, long long b)
{
	return a * (b / GCD(a, b));
}

long long henryRepresentation()
{
	long long unitN = unitFraction[0], unitD = unitFraction[1]; // �����м��� ����,�и�
	long long inputN = inputFraction[0], inputD = inputFraction[1]; // �Էºм��� ����,�и�
	long long ans;

	while (true) {
		unitFraction[1]=inputFraction[1]=LCM(unitD, inputD); // �и� �ּҰ������ ���

		// ����� �Ϳ� ���� ���ڵ� �����ش�.0
		unitFraction[0] = unitN * unitFraction[1] / unitD;
		inputFraction[0] = inputN * inputFraction[1] / inputD;

		if (unitFraction[0] == inputFraction[0]) {
			ans = inputFraction[1] / GCD(inputFraction[0], inputFraction[1]);
			break;
		}

		// �����м��� ���ڰ� �Էºм��� ���ں��� �۰ų� ������ ���ְ� �ٽ� ó������ ����
		if (unitFraction[0] <= inputFraction[0]) {
			inputFraction[0] -= unitFraction[0];
			inputN = inputFraction[0]; inputD = inputFraction[1];

			if (inputN) unitD = inputD / inputN;
			else unitD++;
		}
		// �ƴϸ� �и� ��� ������Ų��.
		else unitD++;
		// �����м��� ���ڴ� �׻� 1�̱� ������ �ʱ�ȭ
		unitN = 1;
	}
	return ans;
}

int main(void)
{
	long long tc; std::cin >> tc;

	while (tc--) {
		unitFraction[0] = 1; // �����м��� ���ڴ� 1
		unitFraction[1] = 2; // �����м��� �и������ 2
		std::cin >> inputFraction[0] >> inputFraction[1];
		std::cout << henryRepresentation() << '\n';
	}
	return 0;
}