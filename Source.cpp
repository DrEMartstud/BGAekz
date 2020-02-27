#include <iostream>
#include <vector>
#include <iterator>
#include <ctime>
#include <stdlib.h>

using namespace std;
void ukazateliTest() {
	int var = 123; // инициализация переменной var числом 123
	int* ptrvar = &var; // указатель на переменную var (присвоили адрес переменной указателю)
	cout << "&var    = " << &var << endl;// адрес переменной var содержащийся в памяти, извлечённый операцией взятия адреса
	cout << "ptrvar  = " << ptrvar << endl;// адрес переменной var, является значением указателя ptrvar
	cout << "var     = " << var << endl; // значение в переменной var
	cout << "*ptrvar = " << *ptrvar << endl; // вывод значения содержащегося в переменной var через указатель, операцией разименования указателя
}
void first() {
//1)Создать пустой вектор типа string.Написать программу, которая записывает в вектор предложения и вывести содержимое вектора на экран.
	cout << "-First- \n";
	vector <string> ourVector;
	string s;
	for (int i = 0; i < 5; i++) {
		cout << i << ": ";
		cin >> s;
		ourVector.push_back(s);
	}
	vector<string>::iterator ukaz;
	for (ukaz = ourVector.begin(); ukaz != ourVector.end(); ukaz++) cout << *ukaz << endl;
}

void second() {
	//2) Создать пустой вектор типа int. Написать программу, которая записывает в вектор только положительные числа. 
	//При вводе отрицательного числа заполнение вектора прекратить. 
	//Вывести содержимое вектора на экран с помощью цикла, основанного на диапазоне.
	cout << "-Second- \n";
	vector <int> intVector;
	int number;
	cout << "Number > 0\n";
	while ((cin >> number) && number > 0) intVector.push_back(number);
	vector<int>::iterator znachenie;
	for (znachenie = intVector.begin(); znachenie < intVector.end(); znachenie++) cout << *znachenie << endl;
}

void third() {
//3) Создать пустой вектор типа double. 
//Написать программу, которая записывает в вектор числа до тех пор, пока не введен ноль. 
//Вывести на экран с помощью итератора только положительные элементы вектора. 
	cout << "-Third- \n";
	vector <double> doubleVector;
	double number;
	cout << "Number != 0\n";
	while ((cin >> number) && number != 0) doubleVector.push_back(number);
	vector<double>::iterator znachenie;
	for (znachenie = doubleVector.begin(); znachenie < doubleVector.end(); znachenie++) if (*znachenie > 0) cout << *znachenie << endl;
}

void fourth() {
	//4)Обработка исключительных ситуаций. Ввести фамилию, год рождения и пол студента. 
	//Проверить правильность ввода пола и года рождения. Обратить исключительные ситуации.
	cout << "-Fourth-\n";
	class family {
	private:
		string familia;
		float yearOfBirth;
		string pol;
	public:
		void input() {
			string f;
			float y;
			string p;

			cout << "Familia: \n";
			cin >> f;
			cout << "Year: \n";
			cin >> y;
			try {
				if (y < 1900 || y > 2020) throw 0.0;
			}
			catch (double) {
				cout << "Err. Y: \n";
				y = 0;
			}
			cout << "Pol: \n";
			cin >> p;
			try {
				if (p != "W" && p != "w" && p != "M" && p != "m") throw 0;
			}
			catch (int) {
				cout << "Err. P: \n";
				p = "?";
			}
			familia = f;
			pol = p;
			yearOfBirth = y;
		}
		void output() {
			cout << familia << " " << yearOfBirth << " " << pol << endl;
		}
	};
	family Person;
	Person.input();
	Person.output();
}

void fifth() {
//5) Объявить числовой динамический массив. 
//Количество элементов массива получить с экрана. Вывести исходный массив на экран. 
//Просуммировать все положительные элементы массива, если таких нет, вывести соответствующее сообщения. 
	cout << "-Fifth- \n";
	int kol = 0, sum = 0;
	cout << "Kol: \n";
	cin >> kol;
	int* dynamicArray = new int[kol];
	srand(time(NULL));
	for (int i = 0; i < kol; i++) {
		dynamicArray[i] = rand() % 100 - 50;
		cout << i << ": " << dynamicArray[i] << endl;
		if (dynamicArray[i] > 0) sum += dynamicArray[i];
	}
	if (sum > 0) cout << "Sum: " << sum << endl;
	else cout << "Net >0 \n";
	delete[] dynamicArray;
}

void sixth() {
//6) Создать класс, содержащий фамилию, пол и год рождения в закрытой части класса. 
//Включите в класс открытую функцию для ввода этих данных и открытую функцию для вывода данных на экран 
//(конструктор не создавать).
cout << "-Sixth- \n";
	
class family {

private:
	string sn = "Unknown";
	int y = 404;
	char s = '?';
public:
	void init(string surname, int year, char sex) {
		sn = surname;
		if (year >= 1900 && year <= 2020) y = year; else cout << "Vveden nepravilniy god. \n";
		if (sex == 'm' || sex == 'M' || sex == 'w' || sex == 'W') s = sex; else cout << "Vveden nepravilniy pol. \n";
	}
	void info() {cout << "Surname: " << sn<< " sex: " << s << " year: " << y << endl;}
};
family guy;
guy.init("Peter", 1999, 'm');
guy.info();
}

void seventh() {
//7) Создать класс, конструктору которого передаются три значения типа float, являющиеся длинами сторон треугольника.
//В классе создать: 1. Функцию, которая вычисляет площадь треугольника по формуле Герона;2. Функцию, выводящий результат на экран. 	
	cout << "-Seventh-\n";
	class triangle {
	public:
		float a, b, c, p, s;
		triangle(float katet1, float katet2, float katet3) {
			a = katet1;
			b = katet2;
			c = katet3;
		}
		void geronsArea() {
			if ((a + b) > c && (a + c) > b && (b + c) > a) {
				p = (a + b + c) / 2;
				s = sqrt(p * (p - a) * (p - b) * (p - c));
			}
			else { cout << "Treugolnika s takimi storonami ne suschestvuet\n"; }
		}
		void showArea() { cout << "Sg: " << s << endl; }
	};
	triangle t(2.2, 2.4, 2.3);
	t.geronsArea();
	t.showArea();
}

void eighth() {
//8) Создать класс, конструктору которого передаются заглавие книги, фамилия автора, количество страниц и цена. 
//В классе создать конструктор, деструктор и функцию, выводящих информацию на экран.
	cout << "-Eighth- \n";
	class books {
	public:
		string bookName, authorsSurname;
		int pagesCount, price;
		books() {
			bookName = "";
			authorsSurname = "";
			pagesCount = 0;
			price = 0;
			cout << "Constructed book\n";
		}
		void init(string nameOfTheBook, string surnameOfTheAuthor, int countOfPages, int priceOfTheBook) {
			bookName = nameOfTheBook;
			authorsSurname = surnameOfTheAuthor;
			pagesCount = countOfPages;
			price = priceOfTheBook;
		}
		void show() {
			cout << "N: " << bookName << " Au: " << authorsSurname << " C: " << pagesCount << " P: " << price << "$\n";
		}
		~books() { cout << "Destructed\n"; }
	};
	books Gatsby;
	Gatsby.init("Man", "Gatsby", 356, 10);
	Gatsby.show();
}

void ningth() {
//9) Создать базовый класс Zoo для зверей и птиц. Закрытые члены класса Zoo – число ног и год рождения. Открытые члены – конструктор и функция вывода информации на экран.
//Производные классы Anim и Bird должны содержать название зверя или птицы. 
//Конструкторы Anim() и Bird() должны передавать необходимые аргументы классу Zoo и инициализировать собственные поля. 
//Классы Anim и Bird должны содержать функцию, выводящие на экран всю информацию о своем объекте.
	cout << "-Ninth-\n";
	class Zoo {
	public:
		Zoo(int legsCount, int yearOfBirth) {
			legs = legsCount;
			year = yearOfBirth;
		}
		void show() {
			cout << "Legs: " << legs << "  Born: " << year << endl;
		}
	protected:
		int legs, year;
	};
	
	class Anim : public Zoo {
	public:
		Anim(int legsCount, int yearOfBirth, string nameOfTheAnim) : Zoo(legsCount, yearOfBirth) {
			animalsName = nameOfTheAnim;
		}
		void show() {
			cout << "Legs: " << legs << "  Born: " << year << " Name: " << animalsName << endl;
		}
	protected:
		string animalsName;
	};
	class Bird: public Anim {
	public:
		Bird(int legsCount, int yearOfBirth, string nameOfTheBird, bool canFly) : Anim(legsCount, yearOfBirth, nameOfTheBird){
			flies = canFly;
		}
		void show() {
			cout << "Legs: " << legs << "  Born: " << year << " Name: " << animalsName << " Flies: " << flies << endl;
		}
	protected:
		bool flies;
	};
	Zoo Animal(2, 2000);
	Animal.show();
	Anim horse(4, 2005, "Loshad");
	horse.show();
	Bird parrot(2, 2018, "Lesha", true);
	parrot.show();
}

void tenth() {
//10) Создать базовый класс, открытые члены которого – основание и высота геометрической фигуры. 
//Создать производные классы, которые вычисляют площадь треугольника и площадь параллелограмма и выводят полученные значения на экран.
	cout << "-Tenth-\n";
	class Shape {
	public:
		float a, h;
		Shape(float osnovanie, float visota) { a = osnovanie, h = visota; }
	};
	class Parall : public Shape {
	public:
		float sParall;
		Parall(float osnovanieP, float visotaP) : Shape(osnovanieP, visotaP) {
			sParall = a * h;
			cout << "Sp: " << sParall << endl;
		}
	};
	class Triangle : public Shape {
	public:
		float sTriangle;
		Triangle(float osnovanieT, float visotaT) : Shape(osnovanieT, visotaT) {
			sTriangle = (a * h) / 2;
			cout << "St: " << sTriangle << endl;
		}
	};
	Parall Sp(2.2, 4.5);
	Triangle St(2.0, 1.0);
}

void eleventh() {
//11) Создать базовый класс для хранения числа этажей и комнат в здании, а также общую площадь комнат. 
//Создать производный класс, который хранит число лекционных аудиторий и компьютерных классов и еще один произвольный класс, 
//который хранит число штатных единиц заведующих компьютерным классом и число огнетушителей. 
	cout << "-Eleventh-\n";
	class House {
	public:
		int floors, rooms, commonArea;
		House(int numberOfFloors, int numberOfRooms, int wholeCommonArea) { floors = numberOfFloors; rooms = numberOfRooms; commonArea = wholeCommonArea; } 
	};
	class University : public House {
	public:
		int computerClasses;
		University(int numberOfFloors, int numberOfLectoriums, int amountOfComputerClasses, int wholeCommonArea) : House(numberOfFloors, numberOfLectoriums, wholeCommonArea) {
			computerClasses = amountOfComputerClasses;
		}
	};
	class Responsible : public University {
	public:
		int responsible, fireExtngsh;
		Responsible(int numberOfFloors, int numberOfLectoriums, int amountOfComputerClasses, int wholeCommonArea, int amountOfResponsibleForComputerClasses, int amountOfForeExtnguishers) : University(numberOfFloors, numberOfLectoriums, amountOfComputerClasses ,wholeCommonArea) {
			responsible = amountOfResponsibleForComputerClasses;
			fireExtngsh = amountOfForeExtnguishers;
		}
	};
	Responsible resp(2, 10, 4, 200, 2, 20);
	cout << "Fext: " << resp.fireExtngsh << endl;
	cout << "ComAr: " << resp.commonArea<< endl;
	cout << "CompCl: "<< resp.computerClasses << endl;
}

void twelvth() {
//12) Множественное наследование. Создать производный класс familia, содержащий закрытый член класс для хранения фамилии. 
//Наследование косвенное: классу familia предшествующий shtat, который содержит должность и зарплату, а классу shtat предшествует класс sotrudnik, 
//содержащий год рождения и пол. Все три класса содержат конструкторы. Классы familia содержит метод, выводящий поля всех классов на экран.
	cout << "-Twelvth-\n";
	class Familia {
	public:
		Familia(string familia) { surname = familia; }
		virtual void show() { cout << "Sur: " << surname << endl; }
	protected:
		string surname;
	};
	class Shtat: public Familia {
	public:
		Shtat(string familia, string position, float amountOfPayedMoney) : Familia(familia) {
			job = position; 
			sallary = amountOfPayedMoney;
		}
		virtual void show() { cout << "Sur: " << surname << " Pos: " << job << " $: " << sallary << endl; }
	protected:
		string job;
		float sallary;
	};
	class Sotrudnik: public Shtat {
	public:
		Sotrudnik(string familia, string position, float amountOfPayedMoney, int born, char sexType) : Shtat(familia, position, amountOfPayedMoney) {
			year = born;
			sex = sexType;
		}
		virtual void show() { cout << "Sur: " << surname << " Pos: " << job << " $: " << sallary << " Y: " << year << " Sex: " << sex << endl; }
	protected:
		int year;
		char sex;
	};
	Familia a("Osel");
	a.show();
	Shtat b("Phiona", "Pincess", 0);
	b.show();
	Sotrudnik c("Shrek", "Ogre", 0, 1999, 'm');
	c.show();
}

void thirteenth() {
//13) Множественное наследование. То же, что и в задаче 12, только наследование прямое.
	cout << "-Thirteenth-\n";

}

void fourteenth() {
//14) Виртуальные базовый классы. У главы семьи есть внук – наследник отца и дяди, которые в свою очередь является наследниками своего отца. 
//Имущество: дед владеет домом; отец владеет квартирой; дядя –автовладелец; внук имеет долги; Сможет ли наследство покрыть долги внука? 
	cout << "-Fourteenth-\n";

}

void fifteenth() {
//15) Создать базовый класс dimen, в котором хранятся длина и ширина геометрической фигуры. В классе dimen также объявляется объявляется виртуальная функция  pl(), 
//которая, при ее подмене в производном классе train возвращает площадь треугольника, 
//а при ее подмене в производном классе par возвращает площадь параллелограмма. Во всех трех классах создать конструкторы! К виртуальной функции обратиться через указатель. 
	cout << "-Fifteenth-\n";
}

void sixteenth() {
//16) Чистые виртуальные функции. То же, что и в задаче 15, только pl() – чистая виртуальная функция. 
	cout << "-Sixteenth-\n";
}

void seventeenth() {
//17) Дружественный функции. Создать классы tryan и rectan; оба класса содержат закрытые переменные: rectan – длину и ширину прямоугольника, 
//tryan –  катеты прямоугольного треугольника. Оба класса имеют конструктор и функцию, которая вычисляет периметр прямоугольника в классе rectan и периметр треугольника в классе tryan. 
//Функция per_greater дружественна для обоих классов. Эта функция вычисляет кратность периметров друг другу (оператор % работает с целочисленными переменными!).
	cout << "-Seventeenth-\n";
}

void eighteenth() {
//18) Родовые функции – работа с массивами. Найти min, max. Вывести элементы между min и max. Просуммировать все положительные элементы. 
	cout << "-Eighteenth-\n";
}
void clearScreen() {
	system("cls");
}
void selectTask() {
	int number;
	bool itIsTrue = true;
	while (itIsTrue) {
	cout << "Number of task: \n";
	cin >> number;
	switch (number)
	{
	case 0:
		ukazateliTest();
		break;
	case 1:
		first();
		break;
	case 2:
		second();
		break;
	case 3:
		third();
		break;
	case 4:
		fourth();
		break;
	case 5:
		fifth();
		break;
	case 6:
		sixth();
		break;
	case 7:
		seventh();
		break;
	case 8:
		eighth();
		break;
	case 9:
		ningth();
		break;
	case 10:
		tenth();
		break;
	case 11:
		eleventh();
		break;
	case 12:
		twelvth();
		break;
	case 13:
		thirteenth();
		break;
	case 14:
		fourteenth();
		break;
	case 15:
		fifteenth();
		break;
	case 16:
		sixteenth();
		break;
	case 17:
		seventeenth();
		break;
	case 18:
		eighteenth();
		break;
	case 404:
		clearScreen();
		break;
	default:
		itIsTrue = false;
	}
}
 }
int main() {
	selectTask(); 
	return 0;
}