#include "Header.h"

//�������������� �����
void decodeFile(Node* root, unsigned long long countOfBytes,
                ifstream& codeFile, ostream& result)
{
    Node* tempNode = root;	//��������� ���� � �����
    short byte;	//���� ���� �������� �� �����
    bool bit;	//����������� ��� ��� ����������� ���� �� ������
    unsigned long long count = 0;	//������� ���������� ������
    while (true)
    {
        byte = codeFile.get();	//���� ���� �� ���������

        for (int whichBit = 0; whichBit < 8; whichBit++)	//������������ ����� ����
        {
            bit = byte & (1 << (7 - whichBit));	//������ ������, ������� �� ��������
                                                //���� ��� ����� 1, �� ���� �������
                                                //����� ���� ������
            if (bit == 1)
                tempNode = tempNode->right_;
            else
                tempNode = tempNode->left_;
            //���� ���������� ����, �� ��� ����� ����
            if (tempNode->left_ == nullptr && tempNode->right_ == nullptr)
            {
                result << tempNode->byte_;	//������������ ������
                tempNode = root;	//��������� ������� ����� ���� � �����
                count++;
                if (count == countOfBytes)	//����������� ���������, ���� ���� �������� ��� ����� � �����
                    return;
            }
        }
    }
}