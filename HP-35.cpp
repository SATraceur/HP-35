//==========================================================//
// HP-35 Calculator Emulator - Version 2.0 (12/04/2016)     //
// Author: Joshua Francis - FRAN0464 - 2147511              //
//==========================================================//

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <stdlib.h>

const double PI = 3.14159;

using namespace std;

class HPStack { // HPStack Class.

public:
	HPStack(){  // Defualt Constructor initilises stack and memory variables to 0.
		x_ = 0;
		y_ = 0;
		z_ = 0;
		t_ = 0;
		X_ = 0;
	}

	void push(double x);
	double pop();
	double peek();
	void CHS();
	void RECIP();
	void POW();
	void SQUAREROOT();
	void Exponent();
	void NLOG();
	void LOG();
	void SIN();
	void COS();
	void TAN();
	void ASIN();
	void ACOS();
	void ATAN();
	void STO();
	void RCL();
	void CLR();
	void CLX();
	void SWAP();
	void ROLL();
	void ENTER();

private:	
	double x_; // Stack Variable 1.
	double y_; // Stack Variable 2.
	double z_; // Stack Variable 3.
	double t_; // Stack Variable 4.
	double X_; // Memory Variable.
};

void HPStack::push(double x) { // Pushes user input into x_ and remaining variables up the stack.
	t_ = z_;
	z_ = y_;
	y_ = x_;
	x_ = x;
}

double HPStack::pop() { // Pops x_ off the stack and pushes remaining variables down the stack.
	double temp = x_;
	x_ = y_;
	y_ = z_;
	z_ = t_;
	return(temp);
}

double HPStack::peek() { // Returns x_.
	return (x_);
}

void HPStack::CHS() { // Changes sign of x_, stores in x_ variable.
	x_ = x_ * -1;
}

void HPStack::RECIP() { // Calculates recipriocal of x_, stores in x_ variable.
	x_ = 1 / x_;
}

void HPStack::POW() { // Calculates x_ to the power of y_, stores in x_ variable.
	x_ = pow(x_, y_);
}

void HPStack::SQUAREROOT() { // Calculates the squareroot of x_, stores in x_ variable.
	x_ = sqrt(x_);
}

void HPStack::Exponent() { // Calculates e to the power of x_, stores in x_ variable.
	x_ = exp(x_);
}

void HPStack::NLOG() { // Calculates the natural log of x_, stores in x_ variable.
	x_ = log(x_); 
}

void HPStack::LOG() { // Calculates log base 10 of x_, stores in x_ variable.
	x_ = log10(x_);
}

void HPStack::SIN() { // Calculates sine of x_, stores in x_ variable.
	x_ = sin(x_); 
}

void HPStack::COS() { // Calculates cosine of x_ stores in x_ variable.
	x_ = cos(x_); 
}

void HPStack::TAN() { // Calculates tangent of x_, stores in x_ variable.
	x_ = tan(x_);
}

void HPStack::ASIN() { // Calculates inverse sine of x_, stores in x_ variable.
	x_ = asin(x_); 
}

void HPStack::ACOS() { // Calculates inverse cosine of x_ stores in x_ variable.
	x_ = acos(x_); 
}

void HPStack::ATAN() { // Calculates inverse tangent of x_, stores in x_ variable.
	x_ = atan(x_);
}

void HPStack::STO() { // Stores x_ into memory variable X_.
	X_ = x_;
}

void HPStack::RCL() { // Moves value from memory variable to x_ and pushes remaining variables up the stack.
	t_ = z_;
	z_ = y_;
	y_ = x_;
	x_ = X_;
}

void HPStack::CLR() { // Clears all variables, sets to 0.
	t_ = 0;
	z_ = 0;
	y_ = 0;
	x_ = 0;
	X_ = 0;
}

void HPStack::CLX() { // Clears stack variable x_ and pushes remaining variables down the stack.
	x_ = y_;
	y_ = z_;
	z_ = t_;
	t_ = 0;
}

void HPStack::SWAP() { // Swaps stack variables x_ and y_.
	double temp = x_;
	x_ = y_;
	y_ = temp;
}

void HPStack::ROLL() { // Pushes variables up the stack with rollover.
	double temp = x_;
	x_ = y_;
	y_ = z_;
	z_ = t_;
	t_ = temp;
}

void HPStack::ENTER() { // Pushes variables up the stack copying x_.
	t_ = z_;
	z_ = y_;
	y_ = x_;
}

int main() {

	HPStack stack; // Variable decleration of type HPStack.
	string line;   // String decleration.

	while (getline(cin, line)) {

		stringstream expression(line);
		string token;
	

		while (expression >> token) {

			for (int i = 0; i < token.size(); i++) { // Converts token to uppercase.
				token.at(i) = toupper(token.at(i));
			}

			if (isdigit(token[0])) {
				stack.push(atof(token.data())); // Token gets pushed to stack if it's a number.
			}
			else if (token == "+") { 
				double x = stack.pop();
				double y = stack.pop();
				stack.push(x + y); // Pushes x + y to stack variable x_.
			}
			else if (token == "-") {
				double x = stack.pop();
				double y = stack.pop();
				stack.push(y - x); // Pushes x - y to stack variable x_.
			}
			else if (token == "*") {
				double x = stack.pop();
				double y = stack.pop();
				stack.push(y * x); // Pushes x * y to stack variable x_.
			}
			else if (token == "/") {
				double x = stack.pop();
				double y = stack.pop();
				stack.push(y / x); // Pushes x / y to stack variable x_.
			}
			else if (token == "CHS") {
				stack.CHS(); 
			}
			else if (token == "RECIP") {
				stack.RECIP();
			}
			else if (token == "POW") {
				stack.POW();
			}
			else if (token == "SQRT") {
				stack.SQUAREROOT();
			}
			else if (token == "EXP") {
				stack.Exponent();
			}
			else if (token == "LN") {
				stack.NLOG();
			}
			else if (token == "LOG") {
				stack.LOG();
			}
			else if (token == "SIN") {
				stack.SIN();
			}
			else if (token == "COS") {
				stack.COS();
			}
			else if (token == "TAN") {
				stack.TAN();
			}
			else if (token == "ARCSIN") {
				stack.ASIN();
			}
			else if (token == "ARCCOS") {
				stack.ACOS();
			}
			else if (token == "ARCTAN") {
				stack.ATAN();
			}
			else if (token == "PI") {
				stack.push(PI);
			}
			else if (token == "STO") {
				stack.STO();
			}
			else if (token == "RCL") {
				stack.RCL(); 
			}
			else if (token == "CLR") {
				stack.CLR();
			}
			else if (token == "CLX") {
				stack.CLX();
			}
			else if (token == "SWAP") {
				stack.SWAP();
			}
			else if (token == "ROLL") {
				stack.ROLL();
			}
			else if (token == "ENTER") {
				stack.ENTER();
			}
		}
		cout << stack.peek() << endl; // Outpus stack variable x_.
	}

	// system("pause");
	return(0);
}