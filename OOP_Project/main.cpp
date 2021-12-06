/******************************************************
 * Filename		:	main.cpp
 * Author		:	Hayrullah Uður Güvenen
 * Date			: 	06.01.2021
 * Description	:	Main codes of project
 * ***************************************************/
 
#include "Refrigerators.h"
#include "Dishwashers.h"
#include "Washmachines.h"
#include<stdio.h>
#include<string.h>
#include<vector>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

main(){
  int select; 
  int choice;
  string line;

	vector<Refrigerators> ref; // Array of Refrigerators
  	vector<Dishwashers> dish; // Array of Dishwashers
  	vector<Washmachines> wash; // Array of Washmachines
  	// Reading Refrigerators from .txt file
  	cout<<"Refrigerators:"<<endl;
  	ref[0].ReadFile(ref);
  	cout<<endl;
  	// Reading Dishwashers from .txt file
  	cout<<"Dishwashers:"<<endl;
  	dish[0].ReadFile(dish);
  	cout<<endl;
  	// Reading Washing Machine from .txt file
  	cout<<"Washing Machine:"<<endl;
  	wash[0].ReadFile(wash);
  	cout<<endl;
  	
  	cout<<endl;
  	cout<<endl;
  	// Menu for Simple Inventory Project and User Selecting Operation.
  	cout<<"******************Welcome to the Inventory Book******************"<<endl;
  	cout<<"1.If you want to ADD new product to inventory list, Enter 1."<<endl;
  	cout<<"2.If you want to CHANGE new product to inventory list, Enter 2."<<endl;
  	cout<<"3.If you want to EXIT the program, Enter 3."<<endl;
  	cin>>select;
  	
  	switch(select){
  		case 1: // Selecting Product Type to Add
  			cout<<"Choose the product you want to add;"<<endl;
  			cout<<"1.Refrigerator:"<<endl;
  			cout<<"2.Dishwasher:"<<endl;
  			cout<<"3.Washing machine:"<<endl;
  			cout<<"4.EXIT:"<<endl;
  			cin>>choice;
  			switch(choice){
  				case 1: // Adding a new Refrigerator
  					ref[0].addRefrigerator(ref);
  					break;
  				case 2: // Adding a new Dishwasher
  					dish[0].addDishwashers(dish);
  					break;
  				case 3: // Adding a new Washing Machine
  					wash[0].addWashmachines(wash);
  					break;
  				case 4:
  					exit(0);
  					break;
			  }
			  break;
			  
		case 2: // Selecting Product Type to Changing Number
			cout<<"Choose the product you want to change"<<endl;
			cout<<"1.Refrigerator:"<<endl;
  			cout<<"2.Dishwasher:"<<endl;
  			cout<<"3.Washing machine:"<<endl;
  			cout<<"4.EXIT:"<<endl;
  			cin>>choice;
			switch(choice){
				case 1: // Changing Number of Refrigerator
					ref[0].change(ref);
					break;
				case 2: // Changing Number of Dishwasher
					dish[0].change(dish);
					break;
				case 3: // Changing Number of Washing machine
					wash[0].change(wash);
					break;
				case 4:
					exit(0);
					break;
			}
			break;
			
		case 3: 
			exit(0);
			break;
	}	
 
 	return 0; 	
}
