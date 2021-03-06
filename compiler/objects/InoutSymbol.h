#ifndef INOUTSYMBOL_H
#define INOUTSYMBOL_H


#include <string.h>
#include <string>
#include <vector>
using namespace std;

const int IN=1;
const int OUT=2;
const int INOUT=3;

class InoutSymbol
{
public:
	InoutSymbol();
	InoutSymbol(const string name,const int typeconnection,const string width);
	InoutSymbol(const InoutSymbol &In);
	~InoutSymbol();
	InoutSymbol& operator = (const InoutSymbol &In);
	// getters
	string getName();
	string getNameVerilog();
	int getType();
	string getWidth();
	string getValue();
	void setName(string name);
	string getPadding(string name);
	void setType(int type);
	void setWidth(int width);
	void setValue(string value);


private:
	/* Value definitions*/
	string name;
	string name_verilog;
	int typeconnection;
	string width; // TODO CHECK
	string value;
};


#endif
