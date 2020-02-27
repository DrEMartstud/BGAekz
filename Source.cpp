#include <iostream>
#include <vector>
#include <iterator>
#include <ctime>

using namespace std;
void ukazateliTest() {
	int var = 123; // ������������� ���������� var ������ 123
	int* ptrvar = &var; // ��������� �� ���������� var (��������� ����� ���������� ���������)
	cout << "&var    = " << &var << endl;// ����� ���������� var ������������ � ������, ����������� ��������� ������ ������
	cout << "ptrvar  = " << ptrvar << endl;// ����� ���������� var, �������� ��������� ��������� ptrvar
	cout << "var     = " << var << endl; // �������� � ���������� var
	cout << "*ptrvar = " << *ptrvar << endl; // ����� �������� ������������� � ���������� var ����� ���������, ��������� ������������� ���������
}
void first() {
//1)������� ������ ������ ���� string.�������� ���������, ������� ���������� � ������ ����������� � ������� ���������� ������� �� �����.
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
	//2) ������� ������ ������ ���� int. �������� ���������, ������� ���������� � ������ ������ ������������� �����. 
	//��� ����� �������������� ����� ���������� ������� ����������. 
	//������� ���������� ������� �� ����� � ������� �����, ����������� �� ���������.
	cout << "-Second- \n";
	vector <int> intVector;
	int number;
	cout << "Number > 0\n";
	while ((cin >> number) && number > 0) intVector.push_back(number);
	vector<int>::iterator znachenie;
	for (znachenie = intVector.begin(); znachenie < intVector.end(); znachenie++) cout << *znachenie << endl;
}

void third() {
//3) ������� ������ ������ ���� double. 
//�������� ���������, ������� ���������� � ������ ����� �� ��� ���, ���� �� ������ ����. 
//������� �� ����� � ������� ��������� ������ ������������� �������� �������. 
	cout << "-Third- \n";
	vector <double> doubleVector;
	double number;
	cout << "Number != 0\n";
	while ((cin >> number) && number != 0) doubleVector.push_back(number);
	vector<double>::iterator znachenie;
	for (znachenie = doubleVector.begin(); znachenie < doubleVector.end(); znachenie++) if (*znachenie > 0) cout << *znachenie << endl;
}

void fourth() {
	//4)��������� �������������� ��������. ������ �������, ��� �������� � ��� ��������. 
	//��������� ������������ ����� ���� � ���� ��������. �������� �������������� ��������.
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
//5) �������� �������� ������������ ������. 
//���������� ��������� ������� �������� � ������. ������� �������� ������ �� �����. 
//�������������� ��� ������������� �������� �������, ���� ����� ���, ������� ��������������� ���������. 
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
//6) ������� �����, ���������� �������, ��� � ��� �������� � �������� ����� ������. 
//�������� � ����� �������� ������� ��� ����� ���� ������ � �������� ������� ��� ������ ������ �� ����� 
//(����������� �� ���������).
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
//7) ������� �����, ������������ �������� ���������� ��� �������� ���� float, ���������� ������� ������ ������������.
//� ������ �������: 1. �������, ������� ��������� ������� ������������ �� ������� ������;2. �������, ��������� ��������� �� �����. 	
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
//8) ������� �����, ������������ �������� ���������� �������� �����, ������� ������, ���������� ������� � ����. 
//� ������ ������� �����������, ���������� � �������, ��������� ���������� �� �����.
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
//9) ������� ������� ����� Zoo ��� ������ � ����. �������� ����� ������ Zoo � ����� ��� � ��� ��������. �������� ����� � ����������� � ������� ������ ���������� �� �����.
//����������� ������ Anim � Bird ������ ��������� �������� ����� ��� �����. 
//������������ Anim() � Bird() ������ ���������� ����������� ��������� ������ Zoo � ���������������� ����������� ����. 
//������ Anim � Bird ������ ��������� �������, ��������� �� ����� ��� ���������� � ����� �������.
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
	cout << "-Tenth-\n";
}

void eleventh() {
	cout << "-Eleventh-\n";
}

int main() {
	
	//ukazateliTest();
	//first();
	//second();
	//third();
	//fourth();
	//fifth();
	//sixth();
	//seventh();
	//eighth();
	//ningth();
	return 0;
}