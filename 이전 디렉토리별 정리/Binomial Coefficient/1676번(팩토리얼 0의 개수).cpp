#include <iostream>

int main(void)
{
	int n; std::cin >> n;
	int zero = 0, temp;
	
	for (int i = n; i >= 1; i--){
		// 5�� �����ϰ� ������ 0�� ���� ����
		if (i % 5 == 0){
			temp = i;
			zero++;
			// 5�� ���� �� 5�� �������ٴ� ����
			// 5�� �� �����Ѵٴ� ����̹Ƿ� 0�� ���� �ٽ� ����
			while ((temp / 5) % 5==0){
				zero++;
				temp /= 5;
			}
		}
	}

	std::cout << zero;

	return 0;
}