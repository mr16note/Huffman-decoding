#include "Header.h"
//�������������� ������ �����
void restoreTree(Node* root, ifstream& codeFile)
{
    Node* tempNode = root;	//��������� ������ ������� ���������� � �����
    char symbol; //����������� ������
    int codeSize; //������ ���� ������� �� ��������
    short byte; //���� ���� �������� �� �����
    bool bit;	//����������� ��� ��� ����������� ���� �� ������
    while (true)
    {
        symbol = (char)codeFile.get(); //������ ���� ������� - ������
        codeSize = codeFile.get();	//������ ���� ������� - ����� ���� �� ��������
        if (codeSize == 0)	//����� ������� (��� ����� ����� 0)
            break;
        while (codeSize != 0)	//���� �� �������� ������������ ���
        {
            byte = codeFile.get();	//����� ���� ���� (����� ����� codeSize/8 ����)
            for (int whichBit = 0; whichBit < 8 && whichBit < codeSize; whichBit++)	
                //������������ �� ��� ���, ���� �� ���������� ���� ��� ��������� ����� ����
            {
                bit = byte & (1 << (7 - whichBit));	//������� ������ ������ (�� �������� � ��������)
                //���� 1, �� �������� ���� ������
                //���� 0, �� �����
                if (bit == 1)
                {
                    if (tempNode->right_ == nullptr)	//���� ���� �� ������� ���� ��� �� ��� ������
                        tempNode->right_ = new Node;	//������� ���
                    tempNode = tempNode->right_;		//��������� �������
                }
                else
                {
                    if (tempNode->left_ == nullptr)		//���� ���� �� ������� ���� ��� �� ��� ������
                        tempNode->left_ = new Node;		//������� ���
                    tempNode = tempNode->left_;			//��������� �����
                }
            }

            if (codeSize > 8) //���� ���������� ����� �������� ������ �����
                codeSize -= 8;	//������ ����������� ��������������� ���� ����������� �� 8 (���)
            else
                codeSize = 0;	//����� ������ ������������ ������
        }
        tempNode->byte_ = symbol;	//�.�. ������ ���� �������� ������, ��� ������������� ������
        tempNode = root;	//��������� ������ ������� ���������� �����, � �����
    }
}