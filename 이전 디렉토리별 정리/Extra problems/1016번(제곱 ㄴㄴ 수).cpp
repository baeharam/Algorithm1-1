#include <cstdio>
#include <cmath>
#include <vector>

typedef long long ll;
const ll primeMax = 1000000;
int prime[primeMax + 1];
ll prime_square[primeMax];
bool isDivide[primeMax + 1];

/*
1~n������ ���� �� �����佺�׳׽��� ü�� �Ἥ �Ҽ��� �ɷ��� ��
n������ ����� �ƴ� ��Ʈn������ ����� �ص� �Ǵ� ������?
n=ab��� ���� ��, a,b ��ΰ� ��Ʈn���� ũ�ٸ� ab�� n���� Ŀ���� �ǹǷ� �ݵ��
��� 1���� ��Ʈn���� �۴�. ���� ��Ʈn������ Ȯ���ص� 1~n������ ��� �Ҽ��� �ɷ�����.
*/

void Eratos()
{
	// 1���� �ִ������� ��Ʈ1���� 100�������� �ɷ����� ��.
	// 2���� 100������ prime�迭�� �ʱ�ȭ
	for (int i = 2; i <= primeMax; i++) prime[i] = i;

	// �����佺�׳׽��� ü, 2���� �����ؼ� 100�������� ����� -1�� �ʱ�ȭ
	// ��, 2~100�� ������ �Ҽ��� �ɷ����� �۾�
	for (int i = 2; i <= primeMax; i++) {
		for (int j = 2; j <= primeMax / i; j++)
			prime[i*j] = -1;
	}

	// �ɷ��� �Ҽ��� �����Ͽ� prime_square �迭�� ����
	for (int i = 2, j = 0; i <= primeMax; i++) {
		if (prime[i] != -1)
			prime_square[j++] = (ll)prime[i] * prime[i];
	}
}

int main(void)
{
	ll min, max; scanf("%lld %lld", &min, &max);
	Eratos();
	// 0���� max���� isDivide�迭�� ���� false�� �ʱ�ȭ
	for (ll i = min; i <= max; i++) isDivide[i - min] = false;

	int ans = 0, i = 0;


	while (prime_square[i] && prime_square[i]<=max) {
		ll j = ((min + prime_square[i] - 1) / prime_square[i]) *prime_square[i];
		while (j <= max) {
			isDivide[j - min] = true;
			j += prime_square[i];
		}
		i++;
	}

	for (ll i = min; i <= max; i++) if (isDivide[i-min]) ans++;

	printf("%lld", (max-min+1)-ans);
	return 0;
}