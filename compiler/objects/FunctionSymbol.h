#ifndef FUNCTIONSYMBOL_H
#define FUNCTIONSYMBOL_H

#include <string.h>
#include <string>
#include <vector>


#include "FunctionSymbolParam.h"
#include "WireSymbol.h"

using namespace std;


class FunctionSymbol
{
public:

	FunctionSymbol();
    FunctionSymbol(string name, string projectName, string projectFolder);
	FunctionSymbol(const FunctionSymbol &In);
	~FunctionSymbol();
	FunctionSymbol& operator = (const FunctionSymbol &In);

	bool addConnectionFunctionSymbol(string name, int size, string with);
	InoutSymbol& searchinoutSymbol(string name);
	bool addFunctionSymbolParam(string name);
	bool addValueFunctionSymbolParam(string name, int value);
	FunctionSymbolParam& searchFunctionSymbolParam(string name);

	bool addWireConnection(string function_in, InoutSymbol out, InoutSymbol in);

	void createFileModule();
	void createFileModule(string base);
	void printToFile();

	// getters

	string getName();
	string getFilenameAsociated();
	string getFunction();
	string getDescription();
	string getCode();
	string getProjectName();
	string getReferences();
	string getOutputFileData();

	//setters

	void setName(string name);
	void setFunction(string function);
	void setDescription(string description);
	void setCode(string code);
	void setProjectName(string projectName);
	void setReferences(string references);

private:
	string name;
	vector<InoutSymbol> v_inoutwires;
	vector<FunctionSymbolParam> v_param;
	vector<WireSymbol> v_wire;
	string filename_asociated;
	string function;
	string description;
	string code;
	string projectName;
	string references;
	string output_file_data;
	
};



#endif