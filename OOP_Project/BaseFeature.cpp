/******************************************************
 * Filename		:	BaseFeature.cpp
 * Author		:	Hayrullah Uður Güvenen
 * Date			: 	06.01.2021
 * Description	:	BaseFeature Class Implementation
 * ***************************************************/

#include "BaseFeature.h"
#include <vector>
#include <cstring>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>

using namespace std;

/// Constructor initializes parameters
BaseFeature::BaseFeature()
{
	
}
/// set Id
void BaseFeature::setId(string token)
{
	if(token[0] == 'r' || token[0]=='R'){ token[0] = 'R'; }
	else if(token[0] == 'd' || token[0]=='D'){ token[0] = 'D'; }
	else if(token[0] == 'w' || token[0]=='W'){ token[0] = 'W'; }
	else throw invalid_argument("Wrong entry!");
	
	if(token[0] =='R'|| token[0] =='D' ||token[0] =='W' ){ id=token; }
	else throw invalid_argument("Wrong entry!");
	
}
/// get Id
string BaseFeature::getId()
{
	return id;
}
/// set Height - Returns absolute value even though a negative value is entered
void BaseFeature::setHeight(string token)
{
	int temp;
	stringstream(token)>>temp;
	height=abs(temp);
}
/// get Height
string BaseFeature::getHeight()
{ 
	ostringstream temp;
    temp<<height;
 	string temp2=temp.str();
    
	return temp2;
}
/// set Lenght -Returns absolute value even though a negative value is entered
void BaseFeature::setLength(string token)
{
	int temp;
	stringstream(token)>>temp;
	length=abs(temp);
}
/// get Length
string BaseFeature::getLength()
{
	ostringstream temp;
    temp<<length;
 	string temp2=temp.str();
    
	return temp2;
}
/// set Width - Returns absolute value even though a negative value is entered
void BaseFeature::setWidth(string token)
{
	int temp;
	stringstream(token)>>temp;
	width=abs(temp);
}
/// get Width
string BaseFeature::getWidth()
{
	ostringstream temp;
    temp<<width;
 	string temp2=temp.str();
	
	return temp2;
}
/// set Energy Consumption
void BaseFeature::setEnergyCons(string token)
{
	energyCons=token;
}
/// get Energy Consumption 
string BaseFeature::getEnergyCons()
{
	return energyCons;
}
/// set Engine Power - Returns absolute value even though a negative value is entered
void BaseFeature::setEnginePower(string token)
{
	double temp;
	stringstream(token)>>temp;
	enginePower=abs(temp);
}
/// get Engine Power
string BaseFeature::getEnginePower()
{
	ostringstream temp;
    temp<<enginePower;
 	string temp2=temp.str();
    
	return temp2;
}
/// set Engine Rotation - Returns absolute value even though a negative value is entered
void BaseFeature::setEngineRotation(string token)
{
	int temp;
	stringstream(token)>>temp;
	engineRotation=abs(temp);
}

/// get Engine Rotation
string BaseFeature::getEngineRotation()
{
	ostringstream temp;
    temp<<engineRotation;
 	string temp2=temp.str();
    
	return temp2;
}
