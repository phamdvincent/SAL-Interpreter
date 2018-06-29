#include "header.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <map>


void DEC::execute() {
	machine->insertVarLocation(symbol, location);
}

void LDA::execute() {
	int location = machine->getLocation(symbol);
	string value = machine->getMemory()[location];

	machine->setRegA(stol(value));
}


void LDB::execute() {
	int location = machine->getLocation(symbol);
	string value = machine->getMemory()[location];
	
	machine->setRegB(stol(value));
}


void LDI::execute(){

	if(value > 2147483647 || value < -2147483647)
	{
		cout << "ERROR: number is not 32 bit" << endl;
	}
	else
	machine->setRegA(value);
}

void ST::execute() {
	int location = machine->getLocation(symbol);

	machine->setMemory(to_string(machine->getRegA()),location);
}


void XCH::execute() {
	long int newRegA = machine->getRegA();
	long int newRegB = machine->getRegB();
	long int temp;

	temp = newRegA;

	newRegA= newRegB;

	newRegB = temp;

	machine->setRegA(newRegA);
	machine->setRegB(newRegB);
}

void JMP::execute() {
	machine->setCounter(number);
}

void JZS::execute(){
	machine->setCounter(number);
}

void JVS::execute(){
	machine->setCounter(number);
}

void ADD::execute() {
long int A = machine->getRegA();
long int B = machine->getRegB();
long int sum = A + B;


if(sum > 2147483647 || sum < -2147483647)
	machine->setOverFlow(1);
else
	machine->setOverFlow(0);

if(sum == 0)
	machine->setZeroResult(1);
else
	machine->setZeroResult(0);

machine->setRegA(sum);

}

void HLT::execute(){
	int end = machine->getMemory().size();
	machine->setCounter(end);
	cout << "HLT: End of Program Execution. Exiting..." << endl;
	exit(0);
}

