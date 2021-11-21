#include "Header.h"
//Восстановление дерева кодов
void restoreTree(Node* root, ifstream& codeFile)
{
    Node* tempNode = root;	//Обработка нового символа начинается с корня
    char symbol; //Считываемый символ
    int codeSize; //Размер кода символа по Хаффману
    short byte; //Байт кода Хаффмана из файла
    bool bit;	//Считываемый бит для направления пути по дереву
    while (true)
    {
        symbol = (char)codeFile.get(); //Первый байт таблицы - символ
        codeSize = codeFile.get();	//Второй байт таблицы - длина кода по Хаффману
        if (codeSize == 0)	//Конец таблицы (два байта равны 0)
            break;
        while (codeSize != 0)	//Пока не закончил обрабатывать код
        {
            byte = codeFile.get();	//Берет байт кода (будет брать codeSize/8 байт)
            for (int whichBit = 0; whichBit < 8 && whichBit < codeSize; whichBit++)	
                //Обрабатывает до тех пор, пока не обработает байт или оствшуюся часть кода
            {
                bit = byte & (1 << (7 - whichBit));	//Заносит каждый разряд (от старщего к младщему)
                //Если 1, то движение идет вправо
                //Если 0, то влево
                if (bit == 1)
                {
                    if (tempNode->right_ == nullptr)	//Если узел по данному пути еще не был создан
                        tempNode->right_ = new Node;	//Создает его
                    tempNode = tempNode->right_;		//Переходит направо
                }
                else
                {
                    if (tempNode->left_ == nullptr)		//Если узел по данному пути еще не был создан
                        tempNode->left_ = new Node;		//Создает его
                    tempNode = tempNode->left_;			//Переходит влево
                }
            }

            if (codeSize > 8) //Если оставшаяся длина занимает больше байта
                codeSize -= 8;	//Размер оставшегося необработанного кода уменьшается на 8 (бит)
            else
                codeSize = 0;	//Иначе больше обрабатывать нечего
        }
        tempNode->byte_ = symbol;	//Т.к. данный узел является листом, ему присваивается символ
        tempNode = root;	//Обработка нового символа начинается также, с корня
    }
}