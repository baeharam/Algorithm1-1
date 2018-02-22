#include <iostream>
#include <string>
#include <cmath>

// �������� 0~9������ ���� ���峵���� üũ�ϴ� �����迭
bool remote[10];

// ��ȣ�� ������ �̵��� �� �ִ� ä������ Ȯ���ϴ� �Լ�
bool checkChannel(int channel)
{
	std::string channelString = std::to_string(channel);
	bool check = true;
	for (int i = 0; i < channelString.size(); i++) {
		if (remote[channelString[i]-'0'] == false) {
			check = false;
			break;
		}
	}
	return check;
}

int main(void)
{
	while (true) {
		// ���� �������� ��� ��ư�� �����Ѵٰ� ����
		for (int i = 0; i < 10; i++) remote[i] = true;
		int n, m, input; std::cin >> n >> m;
		// �Է¹��� ��ȣ���� ���峭 ��(false)���� ����
		while (m--) {
			std::cin >> input;
			remote[input] = false;
		}

		// buttonNum = �������� ��ư�� ���� Ƚ��
		// channel_up, channel_down = Ÿ��ä�ο��� ��/�Ʒ��� ���� 2���� ���
		int buttonNum = 0, channel_up = n, channel_down = n;

		// buttonPlus, buttonMinus = +,-��ư, buttonBegin = ����ä�ο��� +,-��ư���� �̵��ؼ� �� �� �������� Ƚ�� (����)
		int buttonPlus = 0, buttonBegin = std::abs(n - 100);

		// 0�� ������ ��� ���ڹ�ư�� ���峵���� Ȯ���ϴ� ����, ��� ��ư�� ���峪�� +,-�� ����� �� �ֱ� �����̴�.
		bool isAllbroken = true;
		for (int i = 1; i < 10; i++) {
			// 1~9�� ��ư �� �ϳ��� �۵��ϸ� �ٷ� �������´�.
			if (remote[i] == true) {
				isAllbroken = false;
				break;
			}
		}

		// 0�� ������ ���ڵ� �� ���峪�� ���� ��ư�� �ϳ��� ���� ���
		if (!isAllbroken) {
			// Ÿ�� ä�ο� �ִ��� ������ ���� �̵�
			while (!checkChannel(channel_up)) {
				channel_up++;
				buttonPlus++;
			}
			// ��ȣ�� �̵��� ��ŭ �����ش�.
			std::cout << channel_up << "���� �̵��� �Ŀ� " << buttonPlus << "��ŭ �����´�.\n";
			buttonPlus += std::to_string(channel_up).size();
			// ���� ä�ο��� �̵��ϴ� �Ͱ� ������ ����� �� �� �� �������� buttonNum���� �ʱ�ȭ
			buttonNum = buttonPlus > buttonBegin ? buttonBegin : buttonPlus;

			// Ÿ�� ä���� 0�̸� �Ʒ��� ������ �� ���� ������ �� ��츸 ����
			if (channel_down != 0) {
				int buttonMinus = 0;
				// Ÿ�� ä�ο� �ִ��� ������ �Ʒ��� �̵� (�ּ� 0������ �̵�����)
				while (!checkChannel(channel_down) && channel_down != 0) {
					channel_down--;
					buttonMinus++;
				}
				// ���� while���� ���� �� �ִ� ��찡 channel_down==0�� ��쵵 �����Ƿ�
				// �װ� �̵��� �� �ִ� ä������ Ȯ��.
				if (checkChannel(channel_down)) {
					std::cout << channel_down << "���� �̵��� �Ŀ� " << buttonMinus << "��ŭ �ö󰣴�.\n";
					// ��ȣ�� �̵��� ��ŭ �����ش�.
					buttonMinus += std::to_string(channel_down).size();

					// ������ �� ���� ���� ���ؼ� buttonNum�� ���� ����
					buttonNum = buttonNum > buttonMinus ? buttonMinus : buttonNum;
				}
			}
		}
		// 0�� ���峪�� �ʾҴٸ� 0���� Ÿ��ä�η� ���� �Ͱ� 100���� Ÿ��ä�η� ���� �� �� �� ����Ƚ���� ����
		else if (remote[0] == true) buttonNum = buttonBegin > n + 1 ? n + 1 : buttonBegin;
		// 0�� ���峵�ٸ� ����ä���� 100���� +,-������ �� �� �ִ� Ƚ�� ����� ���� ���� �ȴ�.	
		else buttonNum = buttonBegin;



		std::cout << buttonNum << '\n';
	}
	

	return 0;
}