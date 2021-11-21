#include "Header.h"

//Раскодирование файла
void decodeFile(Node* root, unsigned long long countOfBytes,
                ifstream& codeFile, ostream& result)
{
    Node* tempNode = root;	//Обработка идет с корня
    short byte;	//Байт кода Хаффмана из файла
    bool bit;	//Считываемый бит для направления пути по дереву
    unsigned long long count = 0;	//Счетчик записанных файлов
    while (true)
    {
        byte = codeFile.get();	//Байт идет на обработку

        for (int whichBit = 0; whichBit < 8; whichBit++)	//Обрабатывает целый байт
        {
            bit = byte & (1 << (7 - whichBit));	//Каждый разряд, начиная со старшего
                                                //Если бит равен 1, то идет направо
                                                //Иначе идет налево
            if (bit == 1)
                tempNode = tempNode->right_;
            else
                tempNode = tempNode->left_;
            //Если встретился лист, то это конец кода
            if (tempNode->left_ == nullptr && tempNode->right_ == nullptr)
            {
                result << tempNode->byte_;	//Записывается символ
                tempNode = root;	//Обработка символа опять идет с корня
                count++;
                if (count == countOfBytes)	//Заканчивает обработку, если были выведены все байты в текст
                    return;
            }
        }
    }
}