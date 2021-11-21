#pragma once



// ������ �������� ������ �����
// � ������� byte_ - ������
// frequency_ - ��� ������� � ������
struct Node
{
	char byte_ = '\0';
	long long frequency_ = 0;
	Node* left_ = nullptr;
	Node* right_ = nullptr;

	Node() {}
	Node(Node* lChild, Node* rChild) : left_(lChild), right_(rChild)
	{
		frequency_ = lChild->frequency_ + rChild->frequency_;
	}
};



// ������������ ��� ���������� � priority_queue
// ����������: �� ���������� ������ 
struct cmpNode
{
	bool operator()(const Node* n1, const Node* n2) const {
		return n1->frequency_ > n2->frequency_;
	}
};