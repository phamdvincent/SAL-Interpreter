#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "header.h"

#include <string>
#include <sstream>

using namespace std;


vector<string> Machine::getMemory() { return memory; }
map<string, int> Machine::getVarLocation() { return varLocation; }

int Machine::getLocation(string symbol) {
	map<string,int>::iterator i = this->varLocation.find(symbol);

	return i->second;
}

long int Machine::getRegA() { return this->regA; }
long int Machine::getRegB() { return this->regB; }
int Machine::getCounter() { return this->counter; }
int Machine::getZeroResult() { return this->zeroResult; }
int Machine::getOverFlow() { return this->overflow; }
char Machine::getInput() { return this->input; }


void Machine::setMemory(string newStr, int location) {
	this->memory[location] = newStr;
}

void Machine::insertMemory(string instruction) {
	memory.push_back(instruction);
}

void Machine::insertVarLocation(string variableName, int location) {
	this->varLocation.insert(pair<string, int>(variableName, location));
}

void Machine::setRegA(long int num) {
	this->regA = num;
}
void Machine::setRegB(long int num) {
	this->regB = num;
}

void Machine::setCounter(int num) {
	this->counter = num;
}

void Machine::setZeroResult(int num) {
	this->zeroResult = num;
}

void Machine::setOverFlow(int num) {
	this->overflow = num;
}




void Machine::execute() {

	this->regA = 0;
	this->regB = 0;

	this->counter=0;
	this->zeroResult = 0;
	this->overflow = 0;

	while(1) {
		cout << "Enter command: ";
		string cmd1;
		string cmd2;
		cin >> input;

		if(input == 'i') {
			string filename = "input.sal";
			ifstream file;
			string instruction;

			file.open(filename);
			while(getline(file ,instruction)){

				this->insertMemory(instruction);
			}

			cout << "List of instructions: " << endl;
			for(int i = 0; i < this->memory.size(); i++){
				cout << this->memory[i] << endl;
			}
			file.close();
		}

		if(input == 'd') {

				istringstream ss(this->memory[counter]);
				ss >> cmd1 >> cmd2;

				if(cmd1.compare("DEC") == 0) {
					DEC* newDec = new DEC(this,"DEC", cmd2, counter);
					newDec->execute();
				}


				if(cmd1.compare("LDA") == 0) {
					LDA* newLDA = new LDA(this,"LDA", cmd2);
					newLDA->execute();

				}

				if(cmd1.compare("LDB") == 0) {
					LDB* newLDB = new LDB(this,"LDB", cmd2);
					newLDB->execute();

				}

				if(cmd1.compare("LDI") == 0) {
					LDI* newLDI = new LDI(this,"LDI", stol(cmd2));
					newLDI->execute();

				}

				if(cmd1.compare("ST") == 0) {
					ST* newST = new ST(this,"ST", cmd2);
					newST->execute();

				}

				if(cmd1.compare("XCH") == 0) {
					XCH* newXCH = new XCH(this,"XCH");
					newXCH->execute();

				}

				if(cmd1.compare("JMP") == 0) {
					JMP* newJMP = new JMP(this,"JMP", stoi(cmd2)-1);
					newJMP->execute();
				

				}

				if(cmd1.compare("JZS") == 0 && this->zeroResult == 1) {
					JZS* newJZS = new JZS(this,"JZS", stoi(cmd2)-1);
					newJZS->execute();

				}

				if(cmd1.compare("JVS") == 0 && this->overflow == 1) {
					JVS* newJVS = new JVS(this,"JVS", stoi(cmd2)-1);
					newJVS->execute();

				}

				if(cmd1.compare("ADD") == 0) {
					ADD* newADD = new ADD(this,"ADD");
					newADD->execute();

				}

				if(cmd1.compare("HLT") == 0) {
					HLT* newHLT = new HLT(this,"HLT");
					newHLT->execute();

				}

				cout << endl;

				cout << "Content of Memory: " << endl;
				for(int i = 0; i < this->memory.size(); i++) {
					cout << memory[i] << endl;
				}

				cout << endl;

				cout << "Program Counter: " << this->counter << endl;
				cout << "Register A: " << this->regA << endl;
				cout << "Register B: " << this->regB << endl;

				cout << "Zero-Result bit: " << this->zeroResult << endl;
				cout << "Overflow bit: " << this->overflow << endl << endl;
				
				counter++;

		}

		if(input == 'r'){

			while(1){

			istringstream ss(this->memory[counter]);
				ss >> cmd1 >> cmd2;

				if(cmd1.compare("DEC") == 0) {
					DEC* newDec = new DEC(this,"DEC", cmd2, counter);
					newDec->execute();
				}


				if(cmd1.compare("LDA") == 0) {
					LDA* newLDA = new LDA(this,"LDA", cmd2);
					newLDA->execute();

				}

				if(cmd1.compare("LDB") == 0) {
					LDB* newLDB = new LDB(this,"LDB", cmd2);
					newLDB->execute();

				}

				if(cmd1.compare("LDI") == 0) {
					LDI* newLDI = new LDI(this,"LDI", stol(cmd2));
					newLDI->execute();

				}

				if(cmd1.compare("ST") == 0) {
					ST* newST = new ST(this,"ST", cmd2);
					newST->execute();

				}

				if(cmd1.compare("XCH") == 0) {
					XCH* newXCH = new XCH(this,"XCH");
					newXCH->execute();

				}

				if(cmd1.compare("JMP") == 0) {
					JMP* newJMP = new JMP(this,"JMP", stoi(cmd2)-1);
					newJMP->execute();
				

				}

				if(cmd1.compare("JZS") == 0 && this->zeroResult == 1) {
					JZS* newJZS = new JZS(this,"JZS", stoi(cmd2)-1);
					newJZS->execute();

				}

				if(cmd1.compare("JVS") == 0 && this->overflow == 1) {
					JVS* newJVS = new JVS(this,"JVS", stoi(cmd2)-1);
					newJVS->execute();

				}

				if(cmd1.compare("ADD") == 0) {
					ADD* newADD = new ADD(this,"ADD");
					newADD->execute();

				}

				if(cmd1.compare("HLT") == 0) {
					cout << endl;

				cout << "Content of Memory: " << endl;
				for(int i = 0; i < this->memory.size(); i++) {
					cout << this->memory[i] << endl;
				}

				cout << endl;

				cout << "Program Counter: " << counter << endl;
				cout << "Register A: " << this->regA << endl;
				cout << "Register B: " << this->regB << endl;

				cout << "Zero-Result bit: " << this->zeroResult << endl;
				cout << "Overflow bit: " << this->overflow << endl << endl;
					HLT* newHLT = new HLT(this,"HLT");
					newHLT->execute();

				}


				if(counter > this->memory.size()){
					break;
				}

				counter++;

		}

	}


	if(input == 's') {
			cout << "Saving to File... " << endl;
			ofstream file;
			string filename = "output.txt";
			remove(filename.c_str());

			file.open(filename);

			file << "Content of Memory: " << "\n";
			for(int i = 0; i < this->memory.size(); i++) {
					file << this->memory[i] << "\n";
				}


				file << "\n";

				file << "Program Counter: " << counter << "\n";
				file << "Register A: " << this->regA << "\n";
				file << "Register B: " << this->regB << "\n";

				file << "Zero-Result bit: " << this->zeroResult << "\n";
				file << "Overflow bit: " << this->overflow << endl << "\n";

				file.close();


		}

		if(input == 'q') {
			break;
		}

		
	}
}
