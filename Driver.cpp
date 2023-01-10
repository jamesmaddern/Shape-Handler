/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for assignment 
Fall 2019

Written by Ayse Kucukyilmaz

This file is a representative test file. 
During marking, we will use the exact same notation 
as provided in the brief, so make sure
you follow that guideline. Also make sure that you don't 
change the main body provided to you here.
Otherwise, your code may not pass the test cases...

GOOD LUCK! 

------------------------------------------------------ */

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>


using namespace std;

bool isNumber(const string& s)
{
	for (char const& ch : s) {
		if (std::isdigit(ch) == 0 && ch != '.') {
			return false;
		}
	}
	return true;
}
void checkArgs(int errorCode, const vector<string>& p) {
	for (int i = 1; i < p.size(); i++) {
		if (!isNumber(p[i])) {
			throw errorCode;
		}
	}
}
int main()
{
	string userCommand;
	vector <Shape*> shapes;     // this one will hold your shapes
	vector <string> parameters; // this one will hold parameters for the commands

	
	while (userCommand.compare("exit") != 0) 
	{
		try 
		{

			std::cout << setprecision(5) << "Enter the command: ";
		
			getline(cin, userCommand);
			std::cout << endl;

			char* cstr = new char[userCommand.length() + 1];

			strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());
			// implement a string tokenizer to populate the parameters vector 
			// check function strtok_s
			const char* token = strtok_s(cstr, " ", &cstr);
			while (token) {
				parameters.push_back(token);
				token = strtok_s(NULL, " ", &cstr);
			}
			// as a result of the process, parameters[0] should hold your command, followed by your parameters 
			if (parameters.empty()) {
				throw 0;

			}
			string command = parameters[0];
			

			// in the following code, consider checking for the arguments.
			// in case of too few arguments, you may remind the user the correct format

			if (command.compare("addR") == 0) {
				// get parameters in the correct order
				// The following four lines have a type mismatch error
				// note that the the parameters vector contains ascii values
				// HINT: stoi function converts from string to int
				for (int i = 0; i < 500; i++) {

					if(parameters.size() != 5){
						throw 1;
					}
					checkArgs(1,parameters);

					int x = std::stoi(parameters[1].c_str()); // fix me! also note that x is not previously defined :(
					int y = std::stoi(parameters[2].c_str());
					int h = std::stoi(parameters[3].c_str());
					int w = std::stoi(parameters[4].c_str());


					Rectangle* r = new Rectangle(x, y, h, w);
					shapes.push_back(r);
					std::cout << *r << endl;
				}
										
			
			}
			else if (command.compare("addS") == 0) {				
				for (int i = 0; i < 200; i++) {


					if (parameters.size() != 4) {
						throw 2;
					}
					checkArgs(2, parameters);
					// get parameters
					// ...
					int x = std::stoi(parameters[1].c_str());
					int y = std::stoi(parameters[2].c_str());
					int e = std::stoi(parameters[3].c_str());
					Square* s = new Square(x, y, e);
					shapes.push_back(s);
					std::cout << *s << endl;
				}
				
			}

			else if (command.compare("addC") == 0) {
				// get parameters
				// ...
				if (parameters.size() != 4) {
					throw 3;
				}
				checkArgs(3, parameters);
				int x = std::stoi(parameters[1].c_str());
				int y = std::stoi(parameters[2].c_str());
				int r = std::stoi(parameters[3].c_str());
				Circle* c = new Circle(x, y, r);
				shapes.push_back(c);
				std::cout << *c << endl;
			
			}
			else if (command.compare("scale") == 0) {
				if (parameters.size() != 4) {
					throw 4;
				}
				if (shapes.empty()) {
					throw 7;
				}
				checkArgs(4, parameters);

				// scale object at index... the scaling needs to be isotropic in case of circle and square 
				// you may want to check if the index exists or not!
				int shapeNo = std::stoi(parameters[1].c_str()); // read from parameters
				float scaleX = std::stoi(parameters[2].c_str());
				float scaleY = std::stoi(parameters[3].c_str());
				// Multiple inhertitance is tricky! The Shape class does nto have a scale function, the Movable does!
				// As a result all your derived classes have scale functions... 
				// You may need to use type casting wisely to use polymorphic functionality!
				Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
				m->scale(scaleX, scaleY);

				std::cout << *shapes[shapeNo - 1] << endl;
			}
			else if (command.compare("move") == 0) {
				if (parameters.size() != 4) {
					throw 5;
				}
				if (shapes.empty()) {
					throw 7;
				}
				checkArgs(5, parameters);
				// move object at index 
				int shapeNo = std::stoi(parameters[1].c_str()); // read from parameters
				int x = std::stoi(parameters[2].c_str());
				int y = std::stoi(parameters[3].c_str());
				// you may want to check if the index exists or not!
			
				// Study the following code. A Shape object is not Movable, but all derived classes are...
				// you can't automatically type cast from a Shape to a Movable, but you can force a downcasting
				Movable *m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
				for (int i = 0; i < 100; i++) {
					m->move(x, y);

				}
				// scale should work similarly...

				// note that here you should see the corresponding toString output for the derived classes...
				// if toString is not a virtual function, you may see the base class functionality :(
			
				std::cout << *shapes[shapeNo - 1] << endl;
			}
			else if (command.compare("display") == 0) {
				
				if (parameters.size() > 2) {
					throw 6;
				}
				if (shapes.empty()) { throw 7; }
				checkArgs(6, parameters);
				/*Rectangle* r = new Rectangle(10, 10, 10, 10);
				cout << *r << endl;*/
				
				// this is not given in our example, but why don't you implement a display function which shows all objects stored in shapes?
				



				
				if (parameters.size() == 1) {
					transform(shapes.begin(), shapes.end(), shapes.begin(),[](Shape* s) {std::cout << *s << endl;return s;});					
				}
				else {
					if (stoi(parameters[1]) > shapes.size()) {
						throw 6;
					}
					int shapeNo = std::stoi(parameters[1].c_str());
					std::cout << shapes.at(shapeNo - 1) << endl;
				}
			}
			else if (command.compare("clear") == 0) {
				transform(shapes.begin(), shapes.end(), shapes.begin(), [](auto s) {delete s; return nullptr; });
				shapes.clear();
			}
			else if(command.compare("exit")!=0) {
				throw 0;
			}



			
			parameters.clear();
			
			
			
			cout << endl << endl;
		}
		catch(int errorCode){
			if (!parameters.empty()) {
				parameters.clear();

			}
			switch (errorCode) {
			case 0:
				std::cout << "Invalid Command:\nAvailable Commands:\n\tAdd Rectangle:\t addR xPosition yPosition Height Width" <<
					"\n\tAdd Square: \t addS xPosition yPosition Edge" <<
					"\n\tAdd Circle: \t addC xPosition yPosition Radius" <<
					"\n\tMove Shape: \t move shapeIndex newXPosition newYPosition" <<
					"\n\tScale Shape: \t scale shapeIndex scaleX scaleY" <<
					"\n\tDisplay Shapes: \tdisplay [shapeIndex]" <<
					"\n\tClear Shapes: \tclear";
				break;
			case 1:
				std::cout << "Invalid Argument List:\n\tAdd Rectangle:\t addR xPosition yPosition Height Width";
				break;
			case 2:
				std::cout << "Invalid Argument List:\n\tAdd Square:\t addS xPosition yPosition Edge";
				break;
			case 3:
				std::cout << "Invalid Argument List:\n\tAdd Circle:\t addC xPosition yPosition Radius";
				break;
			case 4:
				std::cout << "Invalid Arguement List:\n\tMove Shape:\t move shapeIndex newXPosition newYPosition";
				break;
			case 5:
				std::cout << "Invalid Argument List:\n\tScale Shape:\t scale shapeIndex scaleX scaleY";
				break;
			case 6:
				std::cout << "Invalid Argument List:\n\tDisplay Shape(s): \t display [shapeIndex]";
				break;
			case 7:
				std::cout << "Cannot Access Shapes, no shapes created.";
				break;
			}
			std::cout << endl << endl;

		}
		
	}

	std::cout << "Press any key to continue...";
	std::getchar();

	return 0;
}
