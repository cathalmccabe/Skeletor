#ifndef WIRESYMBOL_H
#define WIRESYMBOL_H

#include <string.h>
#include <string>
#include <vector>
#include "InoutSymbol.h"

using namespace std;
class WireSymbol
{
public:
	WireSymbol();
	WireSymbol(string function_out, string function_in ,int pos_out, int pos_in);
	~WireSymbol();
	WireSymbol(const WireSymbol &In);
	WireSymbol& operator = (const WireSymbol &In);

	string getFuncionOut();
	string getFuncionIn();
	int getInoutSymbolOut();
	int getInoutSymbolIn();

private:
	string function_out;
	string function_in;
	int pos_out;
	int pos_in;
	
};




#endif