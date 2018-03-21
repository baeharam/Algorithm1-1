#include <iostream>

const long long m = 1000000007LL; 
long long x = 0LL, y = 0LL;

void EGCD(long long a, long long b)
{
	
	// x,y�� �ʱⰪ�� 1�� 0
	// b�� 0�� �������� ��, �� ��Ŭ���� �˰����� ��� �������� �� ���ư���.
	if (b == 0){
		x = 1;
		y = 0;
		return;
	}

	EGCD(b, a%b); // ��Ŭ���� �˰��� ����

	long long temp = 0LL;
	temp = x;
	x = y;
	y = temp - (a / b)*y;
}

long long bino(long long n, long long k)
{
	long long nf=1LL;
	long long p=1LL;
	long long ans = 0LL;

	// n! �ϸ鼭 ��ⷯ ����
	for (long long i= n; i >= 1LL; i--){
		nf *= i;
		nf %= m;
	}
	// k! �ϸ鼭 ��ⷯ ����
	for (long long i = k; i >= 1LL; i--){
		p *= i;
		p %= m;
	}
	// (n-k)! �ϸ鼭 ��ⷯ ����
	for (long long i = n-k; i >= 1LL; i--){
		p *= i;
		p %= m;
	}
	// p�� ��ⷯ������ ����� k!(n-k)!

	// Ȯ�� ��Ŭ���� �˰����� �̿��� p�� ������ ���Ѵ�.
	EGCD(p, m);
	

	// ��ⷯ ������ �й��Ģ�� ���� �ٽ� �� �� ��ⷯ ������ ���ش�.
	ans = (nf*x) % m;
	return ans >= 0 ? ans : ans + m;
}


int main(void)
{
	long long n, k; std::cin >> n>>k;
	std::cout << bino(n, k);
	return 0;
}