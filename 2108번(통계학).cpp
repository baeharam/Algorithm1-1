#include <iostream>
#include <algorithm>
#include <cmath>

const int max = 8000 + 1;
const int negative = 4000;

int main(void)

{
	int n, minNum = 0,sum=0, maxNum = 0;
	std::cin >> n;
	int *List = new int[n];
	int Fre[max] = { 0 }; // �󵵼� �迭
	// ���� index�� ����ϱ� ����
	// p[-4000]=Fre[0]�̰� p[4000]=Fre[8000]
	int *p = &Fre[negative];

	// ������ ���� ���� ����
	for (int i = 0; i < n; i++){
		std::cin >> List[i];
		if (minNum > List[i]) minNum = List[i];
		if (maxNum < List[i]) maxNum = List[i];
		p[List[i]]++; sum += List[i];
	}


	// �������� ����
	std::sort(List,List+n);

	// ������
	std::cout << std::floor(sum / static_cast<double>(n)+0.5) << std::endl;

	// �߾Ӱ�
	std::cout << List[n / 2] << std::endl;

	// �ֺ�
	int freMax = 0, index; bool flag = false;

	// �ֺ� �� ���� ū ���� ã��, ���������� �ƴ��� Ȯ��
	for (int i = minNum; i <= maxNum; i++){
		if (freMax < p[i]){ flag = false; freMax = p[i]; index = i; }
		else if(freMax==p[i]) flag = true;
	}

	if (flag){
		for (int i = minNum; i <= maxNum; i++){
			if (flag && freMax == p[i]) { flag = false; }
			else if (!flag && freMax == p[i])
			{
				std::cout << i << std::endl;
				break;
			}
		}
	}
	else std::cout << index << std::endl;

	// ����
	std::cout << List[n - 1] - List[0] << std::endl;

	// �޸� ����
	delete[] List;

	return 0;
	
}