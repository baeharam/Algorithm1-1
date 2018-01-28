#include <cstdio>
#include <cmath>

int main(void)
{
	int m, n; scanf("%d%d", &m, &n);
	int len = n - m + 1;
	int *eratos = new int[len];

	// ü�� �Ÿ� �� n���� Ŀ�� �� ���� ������ max�� ����
	int max = static_cast<int>(std::ceil(std::sqrt(n)));

	// m���� n������ ���� ��� �迭�� ����ֱ�
	for (int i = m, j = 0; i <= n; i++, j++){
		if (i == 1) { eratos[j] = 0; continue; }
		eratos[j] = i;
	}

	bool IsPrime = true;
	for (int i = 2; i < max; i++){
		for (int j = 2; j < i; j++){
			if (i%j == 0){ IsPrime = false; break; }
			else{ IsPrime = true; continue; }
		}
		if (IsPrime){
			for (int j = 0; j < len; j++)
				if (eratos[j] == i) continue;
				else if (eratos[j] % i == 0) eratos[j] = 0;
		}
	}

	for (int i = 0; i < len; i++)
		if (eratos[i] != 0)  printf("%d\n", eratos[i]);

	delete[] eratos;

	return 0;
}