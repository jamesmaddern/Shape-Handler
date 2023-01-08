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
using namespace std;

int main()
{
	string userCommand;
	vector <Shape*> shapes;     // this one will hold your shapes
	vector <string> parameters; // this one will hold parameters for the commands


	while (userCommand.compare("exit") != 0) 
	{
		try 
		{

			cout << "Enter the command: ";
		
			getline(cin, userCommand);
			cout << endl;

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
				if(parameters.size() != 5){
					throw 1;
				}
				int x = std::stoi(parameters[1].c_str()); // fix me! also note that x is not previously defined :(
				int y = std::stoi(parameters[2].c_str());
				int h = std::stoi(parameters[3].c_str());
				int w = std::stoi(parameters[4].c_str());


				Rectangle* r = new Rectangle(x, y, h, w);
				shapes.push_back(r);
				cout << r->toString();/* instead of this, you may implement operator overloadig and 
										use cout << r which will give you additional points */
			
			}
			else if (command.compare("addS") == 0) {
				for (int i = 0; i < 200; i++) {

					if (parameters.size() != 4) {
						throw 2;
					}
					// get parameters
					// ...
					int x = std::stoi(parameters[1].c_str());
					int y = std::stoi(parameters[2].c_str());
					int e = std::stoi(parameters[3].c_str());
					Square* s = new Square(x, y, e);
					shapes.push_back(s);
					cout << s->toString();
				}
			}

			else if (command.compare("addC") == 0) {
				// get parameters
				// ...
				if (parameters.size() != 4) {
					throw 3;
				}
				int x = std::stoi(parameters[1].c_str());
				int y = std::stoi(parameters[2].c_str());
				int r = std::stoi(parameters[3].c_str());
				Circle* c = new Circle(x, y, r);
				shapes.push_back(c);
				cout << c->toString();
			
			}
			else if (command.compare("scale") == 0) {
				if (parameters.size() != 4) {
					throw 4;
				}
				if (shapes.empty()) {
					throw 7;
				}
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

				cout << shapes[shapeNo - 1]->toString();
			}
			else if (command.compare("move") == 0) {
				if (parameters.size() != 4) {
					throw 5;
				}
				if (shapes.empty()) {
					throw 7;
				}
				// move object at index 
				int shapeNo = std::stoi(parameters[1].c_str()); // read from parameters
				int x = std::stoi(parameters[2].c_str());
				int y = std::stoi(parameters[3].c_str());
				// you may want to check if the index exists or not!
			
				// Study the following code. A Shape object is not Movable, but all derived classes are...
				// you can't automatically type cast from a Shape to a Movable, but you can force a downcasting
				Movable *m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
				m->move(x, y);
				// scale should work similarly...

				// note that here you should see the corresponding toString output for the derived classes...
				// if toString is not a virtual function, you may see the base class functionality :(
			
				cout << shapes[shapeNo - 1]->toString();
			}
			else if (command.compare("display") == 0) {
				
				if (parameters.size() > 2) {
					throw 6;
				}
				if (shapes.empty()) { throw 7; }
				// this is not given in our example, but why don't you implement a display function which shows all objects stored in shapes?
				if (parameters.size() == 1) {
					for (int i = 0; i < shapes.size(); i++) {
						cout << setprecision(1) <<shapes.at(i)->toString();
					}
				}
				else {
					if (stoi(parameters[1]) > shapes.size()) {
						throw 6;
					}
					int shapeNo = std::stoi(parameters[1].c_str());
					cout << shapes.at(shapeNo-1)->toString();
				}
				


			}
			else if (command.compare("clear") == 0) {
				//clear shapes
				for (int i = 0; i < shapes.size(); i++) {
					
					delete shapes[i];
				
				}
				shapes.clear();
			}
			else if(command.compare("exit")!=0) {
				throw 0;
			}
			parameters.clear();
			// do any necessary postprocessing at the end of each loop...
			// yes, there is some necessary postprocessing...
			cout << endl << endl;
		}
		catch(int errorCode){
			if (!parameters.empty()) {
				parameters.clear();

			}
			switch (errorCode) {
			case 0:
				cout << "Invalid Command:\nAvailable Commands:\n\tAdd Rectangle:\t addR xPosition yPosition Height Width" <<
					"\n\tAdd Square: \t addS xPosition yPosition Edge" <<
					"\n\tAdd Circle: \t addC xPosition yPosition Radius" <<
					"\n\tMove Shape: \t move shapeIndex newXPosition newYPosition" <<
					"\n\tScale Shape: \t scale shapeIndex scaleX scaleY" <<
					"\n\tDisplay Shapes: \tdisplay [shapeIndex]";
				break;
			case 1:
				cout << "Invalid Argument List:\n\tAdd Rectangle:\t addR xPosition yPosition Height Width";
				break;
			case 2:
				cout << "Invalid Argument List:\n\tAdd Square:\t addS xPosition yPosition Edge";
				break;
			case 3:
				cout << "Invalid Argument List:\n\tAdd Circle:\t addC xPosition yPosition Radius";
				break;
			case 4:
				cout << "Invalid Arguement List:\n\tMove Shape:\t move shapeIndex newXPosition newYPosition";
				break;
			case 5:
				cout << "Invalid Argument List:\n\tScale Shape:\t scale shapeIndex scaleX scaleY";
				break;
			case 6:
				cout << "Invalid Argument List:\n\tDisplay Shape(s): \t display [shapeIndex]";
				break;
			case 7:
				cout << "Cannot Access Shapes, no shapes created.";
				break;
			}
			cout << endl << endl;

		}
		
	}

	cout << "Press any key to continue...";
	std::getchar();

	return 0;
}
