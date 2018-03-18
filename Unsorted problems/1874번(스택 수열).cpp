#include <iostream>
#include <cstdio>

class Node{
private:
	int data;
	Node* prevNode;
public:
	Node(int data, Node* prevNode);
	int getData() const { return data; }
	void setPrev(Node* prev);
	Node* getPrev() const;
};

Node::Node(int num, Node* prev)
	:data(num), prevNode(prev)
{}

void Node::setPrev(Node* prev)
{
	this->prevNode = prev;
}

Node* Node::getPrev() const
{
	return prevNode;
}

class Stack{
private:
	Node* topNode;
	int size;
public:
	Stack();
	~Stack();
	void Push(const int& data);
	int Pop();
	bool IsEmpty() const;
	int Size() const;
	int Top() const;
	bool find(int data);
	
};

// ������
Stack::Stack() :topNode(NULL), size(0)
{}

// �Ҹ��� topNode~������ prevNode���� delete���ֱ�
Stack::~Stack()
{
	Node* top = this->topNode;
	while (top){
		Node* old = top;
		top = top->getPrev();
		delete old;
	}
}

// Push
void Stack::Push(const int& data)
{
	// ����ִٸ� ���ο� ��ü�� �Ҵ��Ѵ�.
	if (this->topNode == NULL)
		this->topNode = new Node(data, NULL);
	// �ƴ϶�� �����ͺ����� topNode�� ���
	// topNode�� ���ο� ��ü�� �����Ѵ�. temp�� prevNode�� ���Եȴ�.
	else{
		Node* temp = topNode;
		this->topNode = new Node(data, temp);
	}
	this->size++;
}

// ���� ���� �� ���� �� ����
int Stack::Pop()
{
	// �ƹ��͵� ������ -1 ����
	if (this->topNode == NULL) return -1;

	// �ӽú����鿡 �����Ϳ� topNode�� ��´�.
	int temp = this->topNode->getData();
	Node *old = this->topNode;

	// ���� prevNode�� NULL�̶�� topNode�� NULL�� �ʱ�ȭ���ָ� �ȴ�.
	if (this->topNode->getPrev() == NULL)
		this->topNode = NULL;
	// �ƴ϶�� topNode�� prevNode�� ��ĭ�� �����ش�.
	else{
		this->topNode = this->topNode->getPrev();
		this->topNode->setPrev(this->topNode->getPrev());
	}

	// �޸𸮿� �Ҵ�Ǿ��� topNode�� �������ְ� ���̰� �پ���.
	// �����͸� �������ش�.
	this->size--;
	delete old;
	return temp;
}

// ����ִ��� ���� ����
bool Stack::IsEmpty() const
{
	if (this->size) return false;
	else return true;
}

// � �ִ��� ����
int Stack::Size() const
{
	return this->size;
}

// ���� ���� �� �������� �ʰ� ����
int Stack::Top() const
{
	if (!IsEmpty()) return this->topNode->getData();
	else return -1;
}

// Ư�� �� ã��
bool Stack::find(int data)
{
	Node* findNode = this->topNode;
	while (findNode){
		if (data == findNode->getData()) return true;
		else findNode = findNode->getPrev();
	}
	return false;
}

int main(void)
{
	Stack s;
	int n, num; scanf("%d", &n);
	int *list = new int[n];
	int before = 0;
	char sign[200000] = { 0 };

	for (int i = 0; i < n; i++) scanf("%d", &list[i]);
	
	for(int i=0,k=0; i<n; i++){
		// ���ڰ� ���ÿ� ������ �� ���ڱ��� ���ÿ� ä����� pop
		if (!s.find(list[i])){
			// �߰��Ǿ��� �ִ񰪺��� ���ڰ� ������ NO
			if (before >= list[i]) { before = -1; break; }
			for (int j = before + 1; j <= list[i]; j++){
				sign[k++] = '+';
				s.Push(j);
			}
			sign[k++] = '-'; s.Pop(); before = list[i];
		}
		// ���ڰ� ���ÿ� ������ ���� ������ Pop
		else{
			int temp = s.Pop();
			sign[k++] = '-';
			while (temp != list[i]){ temp = s.Pop(); sign[k++] = '-'; }
		}

	}

	if (before == -1) printf("NO\n");
	else{
		for (int i = 0; i < 200000; i++){
			if (sign[i] == 0) break;
			printf("%c\n", sign[i]);
		}
	}

	

	delete[] list;

	return 0;

}
