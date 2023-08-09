// Abrar Fahad
// Project ContactBook using c++

#include <iostream>
#include "ContactBook.h"

void userOption(ContactBook book);
int main()
{
	//single contactbook created
	ContactBook bob;
	bob.setContactBookFName("Sponge");
	bob.setContactBookLName("Bob");
	userOption(bob);

	return 0;


}
//Creates a menu for the user in which the user can type an option
void userOption(ContactBook user0)
{
	char option;
	do
	{
		cout<<"Menu"<<endl;
		cout<<"********************************************"<<endl;
		cout<<"--------------------------------------------"<<endl;
		cout<<"a. Add new Contact"<<endl;
	    cout<<"b. Search for a contact"<<endl;
	    cout<<"c. Display all contacts"<<endl;
	    cout<<"d. Update a contact"<<endl;
	    cout<<"e. Delete a contact"<<endl;
	    cout<<"f. Exit."<<endl;
	    cout<<"--------------------------------------------"<<endl;
	    cout<<"********************************************"<<endl;
	    cout<<"OPTION: ";
	    cin >> option;
	    //allows the user to create a new contact in the contact book
	    if (option=='a')
	   	{
	    	user0.newContact();
	   	}
	    //allows the user to search for a contact based on first name and last name.
	    else if(option=='b')
	    {
	    	user0.searchContact();
	    }
	    //allows the user to see all the contacts stored in the system
	    else if(option=='c')
	    {
	    	user0.viewContacts();

	    }
	    //updates a specific contact
	    else if(option=='d')
	    {
	    	user0.updateContact();
	    }
	    //deletes a specific contact
	    else if(option=='e')
	    {
	    	user0.deleteContact();
	    }
	    cout<<endl;
	    //use f to exit the code
	} while (option!='f');


}
