//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <cstring>
//#include <stdio.h>
//#include <stdlib.h>
//using namespace std;
//
//
//
////сча зададим список!
//
//class NODE {
//private:
//	NODE* next, * prev;
//	static NODE* head;
//	char info[40];                      // дл€ дз это можно сделать динамическим. ѕосмотреть конструктор и деструктор
//public:
//	void Add_Inform(const char* ptr);
//	void Add_NODE();
//	void Display_All();
//
//};
//
//
//NODE* NODE::head = NULL; //инициализаци€ глобальных переменных
//
//void NODE::Add_Inform(const char* ptr) {
//	strcpy(info, ptr);
//	next = prev = 0; //NULL
//}
//
//void NODE::Add_NODE() {
//	if (head == NULL) {
//		head = this;
//		next = 0;
//		prev = 0;
//	}
//	else {
//		next = head;
//		head = this;
//		next->prev = this;
//		prev = 0;
//	}
//}
//void NODE::Display_All() {
//	NODE* cur = head;
//	while (cur != this) {
//		cout << cur->info << endl;
//		cur = cur->next;
//	}
//	cout << cur->info << endl;
//}
//
//#define var auto
//int main() {
//	int n = 4;
//	cout << "How many element would u like to input?" << endl;
//	cin >> n;
//	char buff[40];
//	//    //printf("%d\n", n);
//	int i = 0;
//	var t = new NODE();
//	NODE* h = t;
//	do {
//
//		//scanf("%s", buff);
//		cin >> buff;
//		//printf("ENT: %s", buff);
//
//		t->Add_Inform(buff);
//		t->Add_NODE();
//		t = new NODE();
//		i++;
//
//	} while (i < n);
//	delete t;
//	//NODE* a = new NODE();
//	//auto b = new NODE();
//	//auto c = new NODE();
//	//auto d = new NODE();
//	//
//	//a->Add_Inform("Ann");
//	//b->Add_Inform("Bob");
//	//c->Add_Inform("Cathy");
//	//d->Add_Inform("Dorothy");
//
//	cout << "Entered:" << endl;
//	/* a->Add_NODE();
//	 b->Add_NODE();
//	 c->Add_NODE();
//	 d->Add_NODE();*/
//	 //var s = new NODE();
//	h->Display_All();
//
//	//HEAD->Display_All();
//	return 0;
//
//}
//
//
//
//
//
//
//// дз: передаелать программу, чтобы можно было добавл€ть неограниченное количество функций
//
//
