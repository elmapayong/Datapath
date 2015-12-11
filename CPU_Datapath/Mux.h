#ifndef Mux_H
#define Mux_H

class Mux
{
private:
	int a, b, result;
	bool chooseA;
	 
public:
	Mux();
	void setChoiceA(bool);
	int getResult();
};

#endif Mux_H