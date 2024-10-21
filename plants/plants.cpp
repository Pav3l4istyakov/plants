#include <iostream>
#include <string>




class Base
{
public:
	Base() {
		std::cout << "Base construct\n";
	}
	virtual ~Base() {
		std::cout << "Base destroyed\n";
	}

	virtual void PrintW() const { std::cout << "Hello world\n"; }


private:

};

class Derived :public Base {
public:
	Derived() {
		std::cout << "Derived construct\n";
	}
	~Derived() {
		std::cout << "Derived destroyed\n";
	}
	void PrintW() const override { std::cout << "Hello world \n"; }


};



void F00(Base& a)
{
	a.PrintW();
}

class Plant {
public:

	Plant(const std::string& name, const std::string& size, float height)
		: name(name), size(size), height(height) {}


	virtual void info() const {
		std::cout << "name: " << name << "\n"
			<< "size: " << size << "\n"
			<< "height: " << height;
	}
protected:
	std::string name;
	std::string size;
	float height;


};


class shrub : public Plant {
public:

	shrub(const std::string& name, float height)
		: Plant(name, "low", height) {}


	void info() const override {
		Plant::info();
	}
};

class Tree : public Plant {
public:

	Tree(const std::string& name, float height)
		: Plant(name, "big", height) {}


	void info() const override {
		Plant::info();
	}
};



int main() {

	/*Base * a= new Base;
	a->PrintW();
	Base * A = new Derived;
	A->PrintW();
	F00(*a);
	F00(*A);
	delete a;
	delete A;*/
	shrub shrub("shrub", 1.2);
	Tree tree("tree", 5.5);
	std::cout << "shub heght:\n";
	shrub.info();
	std::cout << "\ntree height:\n";
	tree.info();

	return 0;
}