#include "Header.h"

int main()
{
    ifstream codeFile(CODE_F, ios::binary); //�������� ����, ������� ����� ���������������

    unsigned long long countOfBytes = 0; //������� ������ � ������� � �����

    for (int i = 0; i < 8; i++)	//���������� �������� (� ����� �������� ������ 8 ����)
    {
        countOfBytes <<= 8;
        countOfBytes += codeFile.get();
    }

    cout << "Size: " << dec << countOfBytes << endl; //������� ������

    Node* root = new Node; //������ ������ (�� ����� �� ����� ��������)

    restoreTree(root, codeFile); //����������� ������ � �������

    ofstream result(RESULT_TEXT, ios::binary); //��������� ����, � ������� ������������ ��������������� �����

    decodeFile(root, countOfBytes, codeFile, result);	//���������� ���������� �����

    system("pause");
    return 0;
}