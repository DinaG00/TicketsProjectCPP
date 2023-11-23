/*Minimum 3 classes related to the project
Classes must contain(in total, not each) at least one dynamically allocated vector of characters, one dynamically allocated numeric vector, one constant field, one static field and one method static.Members must be related to the class.
All attributes will be defined in the private area of ​​the class
All attributes will have accessor methods; setters will contain validations
Each class will contain at least 2 generic methods(other than constructors or accessors) that will be used to perform various processing
Each class will contain at least one default constructor and one with parameters.Classes with pointer members will follow the "rule of 3".
Each class will contain overloads for << and >> operators
Each class will have at least 2 overloaded operators from the following(the same operator cannot be overloaded in 2 different classes) :
	indexing operator []
	arithmetic operators(+, -, *or /)
	++ or --(both forms)
	implicitly or explicitly cast
	negation operator !
	relational operators(<.>, = < , >= , == )
	Classes will be implemented in their own header and/or cpp file
	Main function will be located in another cpp file
	This phase is considered implemented if at least 75 % of requirements are implemented*/

//Definition of at least 3 classes related to the project requirement per team member.For individual projects, at least 3 classes:
//Each class must contain at least one dynamically defined field managed by a pointer and at least one statically defined array; both character strings(char* or string * ) and vectors of numerical values must be taken into account
//at least one class defines a static field
//at least one class defines a constant field
//all attributes are defined on the private area of the class
//for each attribute, a public interface(accessory functions) is defined that allows reading and writing the value; setter methods must validate input values and throw exception if they are not valid
//each class contains at least 2 generic methods for processing / displaying the attributes
//each class contains at least 2 constructors with parameters, a copy constructor, a destructor and the overloaded form of the operator =
//>> and << must be overloaded for each class
//for each class, the following must be overloaded : indexing operator [],  at least one mathematical operator (+, -, *or /), ++ or --(with the 2 forms), the cast operator (to any type) explicitly or implicitly, the negation operator !, a conditional operator (<.>, = < , >= ), operator for testing equality between 2 objects ==
//	All classes can be defined in a single source file or in separate header files
//
//	Solution main method can be placed in another source file
//
//	Phase 1 is considered completed if at least 75 % of the requirements are implemented
//

#include <iostream>
#include <string>

using namespace std;

//---------------------------------------------------------------------------------------------------------------------
//reading the characteristics of the event location 
//(eg: maximum number of seats, number of rows , zones, number/coding of seats per row, etc.)
class Location
{

};

//---------------------------------------------------------------------------------------------------------------------
//reading the characteristics of the event
//(eg: date, time, name, etc.)
class event
{

};

//----------------------------------------------------------------------------------------------------------------------
//nominal tickets according to the desired characteristics
//(eg: VIP, lawn, tribune, boxes, etc.)

class seatType
{

};



int main()
{
	
}
