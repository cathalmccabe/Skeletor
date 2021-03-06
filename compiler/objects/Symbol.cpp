#include "Symbol.h"


Symbol :: Symbol(){
	this -> name = "null";
	this -> type = -1;
}
Symbol :: Symbol(const string name,const int type, const string module){
	this -> name = name;
	this -> type = type;
	this -> module = module;
}
Symbol :: Symbol(const string name,const int type, const string value, const int type_var, const string module){
	this -> name = name;
	this -> type = type;
	string value_aux = value;
	this -> typeVar = type_var;
	this -> module = module;
	// is a String
	if (type_var == 3){
		value_aux.erase(0, 1);
		value_aux.erase(value_aux.size() - 1);
		this -> value_s = value_aux;
	}
	else{
		this -> value_s = value;
	}
}
/*
Symbol :: Symbol(const string name,const int type, const int value){
	this -> name = name;
	this -> type = type;
	this -> value_i = value;
}
Symbol :: Symbol(const string name,const int type, const bool value){
	this -> name = name;
	this -> type = type;
	this -> value_b = value;
}*/
Symbol :: Symbol(const Symbol &In){
	this -> name = In.name;
	this -> type = In.type;
	this -> value_s = In.value_s;
	this -> typeVar = In.typeVar;
	this -> module = In.module;
}
Symbol :: ~Symbol(){}

Symbol& Symbol ::  operator = (const Symbol &In) {

	if(this != &In)
    {
		Symbol(In);
    	return *this;
	}
}

string Symbol :: getName() {return this -> name;}
int Symbol :: getType() {return this -> type;}
int Symbol :: getTypeVar() {return this -> typeVar;}
string Symbol :: getValue_S() {return this -> value_s;}
string Symbol :: getModule() {return this -> module;}