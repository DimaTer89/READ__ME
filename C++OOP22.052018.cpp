#include <windows.h>
#include <iostream>

using namespace std;

class P_example
 {
  int num;
  public:
   void set_num(int val)
	   {
	    num=val;
	   }
   void show_num();
 };

void P_example::show_num()
 {
  cout << num << "\n";
 }

int main()
 {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  P_example ob;  // Объявляем объект
  P_example* p;  // Объявляем указатель на объект.
  ob.set_num(1); // Получаем прямой доступ к объекту
  cout << "Вывод значения через прямой доступ" << endl;
  ob.show_num(); // Выводим на экран
  p= &ob;        // Присваиваем указателю р адрес объекта ob.
  cout << "Вывод значения через указатель" << endl;
  p->show_num(); // Получаем доступ к объекту ob с помощью указателя и выводим на экран.
  return 0;
 }
================================================
#include <windows.h>
#include <iostream>

using namespace std;

class P_example
 {
  int num;
  public:
   void set_num(int val)
	   {
	    num=val;
	   }
   void show_num();
 };

void P_example::show_num()
 {
  cout << num << "\n";
 }

int main()
 {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  P_example ob[2];
  P_example* p;
  ob[0].set_num(10); // прямой доступ к объектам 
  ob[1].set_num(20);
  cout << "Вывод значений через прямой доступ" << endl;
  ob[0].show_num(); 
  ob[1].show_num();
  p= &ob[0];         // Получаем указатель на первый элемент.
  cout << "Вывод значений через указатель" << endl;
  p->show_num();// Отображаем значение элемента ob[0] с помощью указателя.
  p++;               // Переходим к следующему объекту.
  p->show_num();// Отображаем значение элемента ob[1] с помощью указателя.
  p--;               // Возвращаемся к предыдущему объекту.
  p->show_num();     // Снова отображаем значение элемента оЬ[0].
  return 0;
 }
===============================================
#include <windows.h>
#include <iostream>

using namespace std;

class _3D
 {
  double x,y,z;
  public:
   _3D();
   _3D(double initX,double initY,double initZ);
   void Show()
	   {
     cout << x <<" " << y <<" " <<z <<"\n";
    }
 };
//конструктор класса _3D с параметрами
_3D::_3D(double initX,double initY,double initZ)
 {
  x = initX;
  y = initY;
  z = initZ;
  cout << "С аргументами!!!\n";
 }
//конструктор класса _3D без параметров
_3D::_3D()
 {
  x=y=z=0;
  cout << "Без аргументов!!!\n";
 }

void main()
{
 SetConsoleCP(1251);
 SetConsoleOutputCP(1251);
 //создается объект B, вызывается
 //конструктор без параметров
 //все члены класса инициализируются нулем
 //на экране надпись "Без аргументов!!!"
 _3D B;
 //создается указатель на объект типа
 //_3D и в этот указатель записывается
 //адрес объекта B
 _3D* pB=&B;
 //через указатель вызывается функция
 //Show()
 pB->Show();  
 //создается объект A, вызывается
 //конструктор c параметрами
 //все члены класса инициализируются
 //соответствующими переменными
 //на экране надпись "С аргументами!!!"
 _3D A(3,4,0);
 //создается указатель на объект типа
 //_3D и в этот указатель записывается
 //адрес объекта А
 _3D* pA=&A;
 //через указатель вызывается функция
 //Show()
 pA->Show();
}
===============================================
#include <windows.h>
#include <iostream>

using namespace std;

class Point
 {
  double x,y;
  public:
   Point()
	   {
     x=y=0;
     cout << "\nБез аргументов!!!\n";
    }
   void Show()
	   {
     cout << x << " " << y << "\n";
    }
 };

void main()
 {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  int i;
  //создание объекта
  Point A;
  //показ содержимого на экран
  A.Show();
  cout<<"****************************";
  //создание указателя на объект
  Point* pA;
  cout << "1" << endl;
  //Динамическое выделение памяти под один
  //объект типа Point
  pA=new Point;
  cout << "2" << endl;
  //проверка, выделилась ли память
  //и выход, если не выделилась
  if(!pA)
   exit(0);
  //через указатель вызывается функция
  //Show()
  pA->Show();
  cout<<"****************************";
  //создание указателя на объект
  Point* pB;
  cout << "3" << endl;
  //Динамическое выделение памяти под массив
  //объектов типа Point
  pB=new Point[10];
  cout << "4" << endl;
  //проверка, выделилась ли память
  //и выход, если не выделилась
  if(!pB)
   exit(0);
  //Вызов функции Show() для каждого элемента
  //массива PB
  for(i=0;i<10;i++)
   {
    pB[i].Show();
   }
  //Удаление объекта РА
  delete pA;
  //Удаление массива РB
  delete[]pB;
}
================================
#include <windows.h>
#include <iostream>
#include <string.h>

using namespace std;

class object_
 {
  char* str;
  public:
   //статическое поле класса
   static int num_obj;
   //конструктор
   object_ (const char* s)
	   {
     SetConsoleOutputCP(1251);
	    str=new char[strlen(s)+1];
     strcpy(str,s);
     cout <<"Создание " << str <<'\n';
     //Увеличиваем значение счетчика
     num_obj++;
    }
   //деструктор
   ~object_()
	   {
     cout <<"Уничтожение " << str << '\n';
     delete str;
     //уменьшаем значение счетчика
     num_obj--;
    }
 };

//Инициализация статического элемента. Об этом говорит
//ключевое слово int!
int object_::num_obj=0;

//создание глобальных объектов
object_ s1("Первый глобальный объект.");
object_ s2("Второй глобальный объект.");

//вспомогательная функция
void f(const char* str)
 {
  //Локальный объект
  object_ s(str);
  //явное обращение к статическому полю
  //без указания объекта
  cout <<"Количество объектов - " << object_::num_obj << ".\n";
  cout <<"Отработка функции f()" <<".\n";
}
void main ()
 {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  
//явное обращение к статическому полю
  cout <<"В данный момент, количество объектов-" << object_::num_obj << ".\n";
  object_ M("Объект в функции main().");
  //обращение к статическому полю через объект
  cout <<"В данный момент, количество объектов-" << M.num_obj <<".\n";
  f("Локальный объект.");
  cout <<"В данный момент, количество объектов-" << M.num_obj <<".\n";
  f("Другой локальный объект.");
  cout << "Перед завершением функции main() количество объектов - " << object_::num_obj << ".\n";
 }
==============================================
int search_NOK (int x, int y)
{
    int count=(x<y) ? x : y;
 
    for (int i=2; i<=count; i++)
        if (!(x%i) && !(y%i)) return i;
    else return 1;
}
=================================================
	#include <windows.h>
#include <iostream>

using namespace std;

class prim
{
	int numb;
	//статическое поле
	static int stat_;
public:
	//Конструктор
	prim(int i)
	{
		numb = i;
	}
	/*
	Статическая функция. Указатель this не
	определен, поэтому выбор объекта
	осуществляется по явно переданному указателю.
	Поле stat_ не требует указателя на объект,
	т.к. оно общее для всех объектов класса prim.
	*/
	static void func(int i, prim* p = 0)
	{
		//если хотя бы один объект есть
		if (p)
			p->numb = i;
		//если объектов класса нет
		else
			stat_ = i;
	}
	/*
	Если статическая функция обращается только к
	статическому члену класса, то никаких указателей
	не требуется.
	*/
	static void show()
	{
		cout << "stat_=" << stat_ << "\n\n";
	}
	//показ нестатического члена
	void show2()
	{
		cout << "numb=" << numb << "\n\n";
	}
};

//Инициализация статического члена класса.
int prim::stat_ = 8;

void main()
{
	/*
	До создания объектов типа prim возможен
	единственный способ обращения к статической
	функции-члену.
	*/
	prim::show();
	//Можно изменить значение статического члена класса.
	prim::func(10);
	/*
	После создания объекта типа prim можно обратиться
	к статической функции обычным для абстрактных
	типов способом.
	*/
	//Создается объект obj и его поле numb
	//становится равным 23.
	prim obj(23);
	obj.show2();
	//Можно изменить значение созданного объекта.
	prim::func(20, &obj); //obj.numb 20.
	obj.show2();
	obj.func(27, &obj); //obj.numb 27.
	obj.show2();
	system("pause");
}
================================================
	#include <windows.h>
#include <iostream>

using namespace std;

class temp
 {  
  static int number;
  static char name[30];
  int id;
  public:
   void setid(void);
   int getid(void);
   static char* getname(void);
 };

int temp::number=0;
char temp::name[]="Имя класса";

char* temp::getname()
 {
  return(name);
 }

void temp::setid(void)
 {
  number++;
  id=number;
 }

int temp::getid(void)
 {
  return(id);
 }

int main()
 {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  
  temp a, b;
  a.setid();
  b.setid();
  cout << "a.id = " << a.getid() << endl;
  cout << "b.id = " << b.getid() << endl;
  cout << temp::getname() << "\n";
  cin.get();
  return 0;
 }
===========================================
	#include <windows.h>
#include <iostream>

using namespace std;

class Singleton
 {
  private:
  //указатель на единственный экземпляр класса
  static Singleton* s;
  int k;
  //закрытый конструктор
  Singleton(int i)
   {
    k=i;
   }
  public:
   //функция для получения указателя на
   //единственный экземпляр класса
   static Singleton* getReference()
	   {
     return s;
    }
   //получение значения нестатического члена класса
   int getValue()
	   {
     return k;
    }
   //перезапись значения нестатического члена класса
   void setValue(int i)
	   {
     k=i;
    }
 };

// Инициализация статического члена класса.
Singleton* Singleton::s=new Singleton(3);

void main()
 {
  //получение указателя на
  //единственный экземпляр класса
  Singleton* p=Singleton::getReference();
  //работа с компонентом объекта
  cout << p->getValue() << "\n\n";
  p->setValue(p->getValue()+5);
  cout << p->getValue() << "\n\n";
}
==========================
	
