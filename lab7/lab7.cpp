#include <iostream>
#include "SLList.h"

using namespace std;

void printSLList(const SLList* list)
{
	while(list->hasNext()){
		cout << list->GetData() << " ";
		list = list->next();
	};
	cout << list->GetData() << endl;
}

void deleteDouble(SLList* list) {
	auto now = list;
	auto prev = list;
	auto current = prev->next();
	auto temp = list;
	bool t = false;
	while (now->hasNext())
	{
		while (current->hasNext()) {
			if (now->GetData() == current->GetData())
			{
				prev->removeNext();
				current = prev->next();
				continue;
			}
			prev = prev->next();
			current = prev->next();
		};
		if (now->GetData() == current->GetData()) {
			t = true;
		}
		temp = now;
		now = now->next();
		prev = now;
		current = prev->next();
	}
	if(t)
		temp->removeNext();
};

int foundK(SLList* list,int k) {
	auto prev = list;
	auto current = prev->next();
	int count = 2;
	while(current->hasNext()){
		prev = current;
		current = prev->next();
		count++;
	}
	prev = list;
	current = prev->next();
	for (int i = 0; i < count - 1; i++) {
		if (count - k == 0) {
			return prev->GetData();
		}
		else if (count - k == i + 1) {
			return current->GetData();
		}
		prev = current;
		current = prev->next();
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SLList* now = SLList::beginList(0);
	int count = 10;
	auto tmp = now;
	now = tmp;
	for (int i = 0; i < count - 1; i++) {
		tmp = tmp->addElement(0 + rand() % 12);
	}
	cout << "Вывод обычной последовательности" << endl;
	printSLList(now);
	cout << "Вывод определенного числа с конца последовательности" << endl;
	cout << foundK(now, 9) << endl;
	deleteDouble(now);
	cout << "Вывод последовательности без повторений" << endl;
	printSLList(now);
}