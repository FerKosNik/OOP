#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	
	Person(std::string name, int age, string gender, int weight);
	
	int age, weight;
	string name, gender;
	
	void changeName(string nameNew) {
		this->name = nameNew;
	};

	void changeAge(int ageNew) {
		this->age = ageNew;
	}

	void changeWeight(int weightNew) {
		this->weight = weightNew;
	}

	void show() {
		cout << this->name << " " << this->age << " eyars old " << this->weight << " kg " << endl;
	}
};

Person::Person(std::string name, int age, string gender, int weight)
	:name(name), age(age), gender(gender), weight(weight)
{};
	

class Student : public Person {
public:
	int static counter;
	int course{};
	
	Student(string name, int age, string gender, int weight, int course) 
		: Person(name, age, gender, weight), course(course)
	{
		++counter;
	};

	void changeCourse(int courseNew) {
		this->course = course;
	}

	void show() {
		cout << this->name << " " << this->age << " eyars old " << this->weight 
			<< " kg study in " <<this->course << " course " << endl;
	}
};

int Student::counter = 0;

//================================//

class Fruit {
public:
	string name{};
	string color{};
	string getName() {
		return name;
	}
	string getColor() {
		return color;
	}
};

class Apple : public Fruit {
public:
	Apple(string color = " red ") {
		this->name = " apple ";
		this->color = color;
	};
};

class Banana : public Fruit {
public:
	Banana(string name = " banana ", string color = " yellowe ") {
		this->name = name;
		this->color = color;
	}
};

class GrannySmith : public Apple {
public:
	GrannySmith(string name = " Granny Smith apple", string color = " green ") {
		this->name = name;
		this->color = color;
	}

};

int main() {
	Student Ivan("Ivan", 23, "m", 85, 5);
	Ivan.changeName("Vasya");
	Ivan.changeWeight(74);
	Ivan.show();
	Student P("Petya", 18, "m", 76, 2);
	Student D("Dima", 21, "m", 68, 1);
	P.show();
	D.show();
	cout << " count student " << Student::counter << endl;
	
	//================================//

	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";



	return 0;
}