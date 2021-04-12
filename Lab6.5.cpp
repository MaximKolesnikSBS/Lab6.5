/*
	Автор: Максим Колесник
	Группа: СБС-001-О-01
	Задание№: 6: 5)
	Цель: Написать программу для создания триарного дерева.
*/

#include <iostream>
using namespace std;

int tabs = 0; //Для создания отступов
//Кол-во отступов высчитывается по кол-ву рекурсивного вхождения при выводе в фукцию print

//Структура ветки
struct Branch
{
	char Data; //Поле данных
	Branch* LeftBranch; //УКАЗАТЕЛИ на соседние веточки
	Branch* MiddleBranch;
	Branch* RightBranch;
};


//Функция внесения данных
void Add(char aData, Branch*& aBranch)
{
	//Если ветки не существует
	if (!aBranch)
	{ //создадим ее и зададим в нее данные
		aBranch = new Branch;
		aBranch->Data = aData;
		aBranch->LeftBranch = 0;
		aBranch->MiddleBranch = 0;
		aBranch->RightBranch = 0;
		return;
	}
	else //Иначе сверим вносимое
		if (aBranch->Data > aData)
		{ //Если оно меньше того, что в этой ветке - добавим влево
			Add(aData, aBranch->LeftBranch);
		}
		if (aBranch->Data == aData)
		{ //Если оно равно тому, что в этой ветке - добавим по середине
			Add(aData, aBranch->MiddleBranch);
		}
		if (aBranch->Data < aData)
		{ //Если оно больше того, что в этой ветке - добавим вправо
			Add(aData, aBranch->RightBranch);
		}
}

//Функция вывода дерева
void print(Branch* aBranch)
{
	if (!aBranch) return; //Если ветки не существует - выходим. Выводить нечего
	tabs++; //Иначе увеличим счетчик рекурсивно вызванных процедур
	//Который будет считать нам отступы для красивого вывода

	print(aBranch->LeftBranch); //Выведем ветку и ее подветки 

	for (int i = 0; i < tabs; i++) cout << " "; //Потом отступы
	cout << aBranch->Data << endl; //Данные этой ветки

	print(aBranch->MiddleBranch); //Выведем ветку и ее подветки 

	for (int i = 0; i < tabs; i++) cout << " "; //Потом отступы
	cout << aBranch->Data << endl; //Данные этой ветки

	print(aBranch->RightBranch); //Выведем ветку и ее подветки 

	for (int i = 0; i < tabs; i++) cout << " "; //Потом отступы
	cout << aBranch->Data << endl; //Данные этой ветки

	tabs--; //После уменьшим кол-во отступов
	return;
}

void FreeTree(Branch* aBranch)
{
	if (!aBranch) return;
	FreeTree(aBranch->LeftBranch);
	FreeTree(aBranch->MiddleBranch);
	FreeTree(aBranch->RightBranch);
	delete aBranch;
	return;
}


int main()
{
	Branch* Root = 0;
	char s[] = "234514";

	for (int i = 0; s[i]; i++)
	{
		Add(s[i], Root);
	}

	print(Root);
	FreeTree(Root);

	cin.get();
	return 0;
}
