#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class Machine {
private:
	vector<string> memory;
	map <string, int> varLocation;
	long int regA;
	long int regB;

	int counter;

	int zeroResult;
	int overflow;
	char input;

public:

	vector<string> getMemory();
	map<string, int> getVarLocation();
	int getLocation(string symbol);
	long int getRegA();
	long int getRegB();
	int getCounter();
	int getZeroResult();
	int getOverFlow();
	char getInput();

	void setMemory(string newStr, int location);
	void insertMemory(string instruction);
	void insertVarLocation(string variableName, int location);
	void setRegA(long int num);
	void setRegB(long int num);
	void setCounter(int num);
	void setZeroResult(int num);
	void setOverFlow(int num);
	void setInput(char input);



	void execute();
};

class SAL{

private:

public:
	string name;
	virtual void execute() = 0;

};

class DEC : public SAL{

public:
	DEC(Machine* machine,string name, string symbol, int location) {
		this->machine = machine;
		this->name = name;
		this->symbol = symbol;
		this->location = location;
	}

	void execute();



private:
	string symbol;
	int location;
	Machine* machine;
};


class LDA : public SAL{

public:
	LDA(Machine* machine, string name, string symbol) {
		this->machine = machine;
		this->name = name;
		this->symbol = symbol;
	}

	void execute();

private:
	string symbol;
	Machine* machine;

};

class LDB : public SAL{

public:
	LDB(Machine* machine, string name, string symbol) {
		this->machine = machine;
		this->name = name;
		this->symbol = symbol;
	}

	void execute();

private:
	Machine* machine;
	string symbol;

};


class LDI : public SAL{

private:
	long int value;
	Machine* machine;

public:
	LDI(Machine* machine, string name, long int value) {
		this->machine = machine;
		this->name = name;
		this->value = value;
	}

	void execute();



};

class ST : public SAL{

public:
	ST(Machine* machine, string name, string symbol) {
		this->machine = machine;
		this->name = name;
		this->symbol = symbol;
	}

	void execute();

private:
	Machine* machine;
	string symbol;

};

class XCH : public SAL{

public:
	XCH(Machine*machine, string name) {
		this->machine = machine;
		this->name = name;
	}

	void execute();

private:
	Machine* machine;

};

class JMP : public SAL{

public:
	JMP(Machine* machine, string name, int number) {
		this->machine = machine;
		this->name = name;
		this->number = number;
	}

	void execute();

private:
	Machine* machine;
	int number;

};


class JZS : public SAL{

public:
	JZS(Machine* machine, string name, int number) {
		this->machine = machine;
		this->name = name;
		this->number = number;
	}

	void execute();

private:
	Machine* machine;
	int number;

};

class JVS : public SAL{

public:
	JVS(Machine* machine, string name, int number) {
		this->machine = machine;
		this->name = name;
		this->number = number;
	}

	void execute();

private:
	Machine* machine;
	int number;

};

class ADD : public SAL{

public:
	ADD(Machine* machine, string name) {
		this->machine = machine;
		this->name = name;
	}

	void execute();

private:
	Machine* machine;

};

class HLT : public SAL{

public:
	HLT(Machine* machine,string name) {
		this->machine = machine;
		this->name = name;
	}

	void execute();

private:
	Machine* machine;

};

