#include <cstdio>
#include <cmath>

int main(void)
{
	int n, k = 1; scanf("%d", &n);
	bool prime = true;
	int root_n = (int)sqrt(n);

	// �Ҽ��� �Ǻ��� ���� �����ٱ����� �������� �� ���ִ�.
	// ��? n�� �Ҽ��� �ƴ϶�� �ϸ� n=a*b�ε� a,b �� �������� �ִ��� ��Ʈn�̱� ������.
	for (int i = 2; i <= root_n; i++) {
		if (n%i == 0) {
			k = i;
			prime = false;
			break;
		}
	}

	if (prime) printf("%d", n - 1);
	else printf("%d", n - n / k);


	return 0;
}