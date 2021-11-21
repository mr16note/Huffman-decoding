#include "Header.h"

int main()
{
    ifstream codeFile(CODE_F, ios::binary); //Бинарный файл, который будет раскодироваться

    unsigned long long countOfBytes = 0; //Счетчик байтов с текстом в файле

    for (int i = 0; i < 8; i++)	//Заполнение счетчика (в файле занимает первые 8 байт)
    {
        countOfBytes <<= 8;
        countOfBytes += codeFile.get();
    }

    cout << "Size: " << dec << countOfBytes << endl; //Выводит размер

    Node* root = new Node; //Корень дерево (не несет за собой символов)

    restoreTree(root, codeFile); //Составление дерева и таблицы

    ofstream result(RESULT_TEXT, ios::binary); //Текстовый файл, в который записывается раскодированный текст

    decodeFile(root, countOfBytes, codeFile, result);	//Заполнение текстового файла

    system("pause");
    return 0;
}