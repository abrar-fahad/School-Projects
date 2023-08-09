
#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include "Contact.h"
#include <iostream>

class ContactBook
{
	private:
		Contact* contacts;
		//number of contacts
		int numContacts;
		//size of dynamic array
		int sz;
		//contact book user first name
		string first;
		//contact book user last name
		string last;
		//internal functions to get index
		int getIndex(string first, string last);
		//increase the size of the dynamic array
		Contact* grow(Contact* contacts,int& sz, int &numContacts);
		//internal functions to get user last and first
		string getLastName() const;
		string getFirstName() const;
	public:
		ContactBook();
		ContactBook(const string f,const string l);
		//Getters
		string getContactBookfName() const;
		string getContactBooklName() const;
		//setters
		void setContactBookFName(const string firstName);
		void setContactBookLName(const string lastName);
		// Create a new contact
		void newContact();
		//Search a specific contact
		void searchContact();
		//update an existing contact
		void updateContact();
		//delete an existing contact
		void deleteContact();
		//display all available contacts
		void viewContacts();
		//returns number of contacts
		int sizeList() const;
		//destructor
		~ContactBook();
		//copy constructor
		ContactBook(const ContactBook& c1);
		//assignment operator
		ContactBook & operator = (const ContactBook& c1);


};



#endif
