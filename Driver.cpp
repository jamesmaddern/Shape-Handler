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
/// <summary>
/// Checks whether a given string is numeric
/// </summary>
/// <param name="s"> - string to be checked</param>
/// <returns>true if numeric, false if contains letters</returns>
bool isNumber(const std::string& s)
{
	for (char const& ch : s) {
		if (std::isdigit(ch) == 0) {
			return false;
		}
	}
	return true;
}
/// <summary>
/// checks each argument to ensure it is a number
/// </summary>
/// <param name="errorCode">the error code that will be thrown for that particular check</param>
/// <param name="p">vector of parameters</param>
void checkArgs(int errorCode, const std::vector<std::string>& p) 
{
	for (int i = 1; i < p.size(); i++) {
		if (!isNumber(p[i])) {
			throw errorCode;
		}
	}
}
/// <summary>
/// Main function
/// </summary>
/// <returns></returns>
int main()
{
	std::string userCommand;
	std::vector <Shape*> shapes;     // this one will hold your shapes
	std::vector <std::string> parameters; // this one will hold parameters for the commands

	
	while (userCommand.compare("exit") != 0)
	{
		try 
		{
			//get user input
			std::cout << std::setprecision(5) << "Enter the command: ";		
			getline(std::cin, userCommand);
			std::cout << std::endl;

			//create c string to hold user input then copy user input into the cstring
			char* cstr = new char[userCommand.length() + 1];			
			strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());

			//string tokenizer to populate the parameters vector 
			const char* token = strtok_s(cstr, " ", &cstr);
			while (token) {
				parameters.push_back(token);
				token = strtok_s(NULL, " ", &cstr);
			}			

			if (parameters.empty()) throw 0;	//raise exception if user has not entered any data
			std::string command = parameters[0];

			if (command.compare("addR") == 0) {

				//handling invalid inputs
				if(parameters.size() != 5)throw 1;	
				checkArgs(1,parameters);

				//populating shape attributes
				int x = std::stoi(parameters[1].c_str()); 
				int y = std::stoi(parameters[2].c_str());
				int h = std::stoi(parameters[3].c_str());
				int w = std::stoi(parameters[4].c_str());

				//create, add, then display rectangle
				Rectangle* r = new Rectangle(x, y, h, w);
				shapes.push_back(r);
				std::cout << *r << std::endl;
			}
			else if (command.compare("addS") == 0) {
				
				//handling invalid inputs
				if (parameters.size() != 4)throw 2;	
				checkArgs(2, parameters);
				
				//populating shape attributes
				int x = std::stoi(parameters[1].c_str());
				int y = std::stoi(parameters[2].c_str());
				int e = std::stoi(parameters[3].c_str());

				//create add then display square
				Square* s = new Square(x, y, e);
				shapes.push_back(s);
				std::cout << *s << std::endl;
				
			}
			else if (command.compare("addC") == 0) {
				
				//handling invalid inputs
				if (parameters.size() != 4) throw 3;
				checkArgs(3, parameters);

				//populating shape attributes
				int x = std::stoi(parameters[1].c_str());
				int y = std::stoi(parameters[2].c_str());
				int r = std::stoi(parameters[3].c_str());

				//create add then display circle
				Circle* c = new Circle(x, y, r);
				shapes.push_back(c);
				std::cout << *c << std::endl;
			
			}
			else if (command.compare("scale") == 0) {

				//handling invalid inputs
				if (parameters.size() != 4)throw 4;
				checkArgs(4, parameters);
				//makes sure there are shapes to be scaled(prevents index out of bounds error)
				if (shapes.empty())throw 7;				

				int shapeNo = std::stoi(parameters[1].c_str()); 
				if (0 >= shapeNo || shapeNo > shapes.size())throw 8;	//check index is in range
				float scaleX = std::stoi(parameters[2].c_str());
				float scaleY = std::stoi(parameters[3].c_str());
				
				//case shape to a movable object, scale then print
				Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
				m->scale(scaleX, scaleY);
				std::cout << *shapes[shapeNo - 1] << std::endl;
			}
			else if (command.compare("move") == 0) {

				//handling invalid inputs
				if (parameters.size() != 4)throw 5;
				if (shapes.empty())throw 7;
				checkArgs(5, parameters);
			
				int shapeNo = std::stoi(parameters[1].c_str()); // read from parameters
				if (0 >= shapeNo || shapeNo > shapes.size())throw 8;
				int x = std::stoi(parameters[2].c_str());
				int y = std::stoi(parameters[3].c_str());			
			
				//case shape to a movable object, move then print
				Movable *m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);			
				m->move(x, y);			
				std::cout << *shapes[shapeNo - 1] << std::endl;
			}
			else if (command.compare("display") == 0) {
				
				//handling invalid inputs
				if (parameters.size() > 2)throw 6;
				if (shapes.empty())throw 7;
				checkArgs(6, parameters);

				
				if (parameters.size() == 1) {	//displays all the shapes
					transform(shapes.begin(), shapes.end(), shapes.begin(),[](Shape* s) {std::cout << *s << std::endl;return s;});					
				}
				else {
					if (stoi(parameters[1]) > shapes.size() || stoi(parameters[1]) <= 0)throw 6; //error checking					
					int shapeNo = std::stoi(parameters[1].c_str());
					std::cout << *shapes.at(shapeNo - 1) << std::endl; //print specified shape
				}
			}
			else if (command.compare("clear") == 0) {
				//deletes all shape pointers using lambda function inside a map function.
				transform(shapes.begin(), shapes.end(), shapes.begin(), [](auto s) {delete s; return nullptr; });
				shapes.clear();	//clears the shapes vector
			}
			else if(command.compare("exit")!=0)throw 0; //throw exception if any other input is entered

			parameters.clear();	//emptys parameters ready for next loop		
			std::cout << std::endl << std::endl;
		}
		catch(int errorCode){
			if (!parameters.empty()) parameters.clear();
			switch (errorCode) {	//selects relevant error message for given error code
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
			case 8:
				std::cout << "Shape index does not exit, try again.";
				break;
			}
			std::cout << std::endl << std::endl;

		}
		
	}

	std::cout << "Press any key to continue...";
	std::getchar();
	//exit program
	return 0;
}
