#include "ContactBook.h"
#include <iostream>

//default constructor
ContactBook::ContactBook()
{
	contacts=NULL;
	numContacts=0;
	sz=0;
	first="N/A";
	last="N/A";
}
//2 parameter constructor set
ContactBook::ContactBook(const string f,const string l)
{
	contacts=NULL;
	first=f;
	last=l;
	numContacts=0;
	sz=0;
}

Contact* ContactBook::grow(Contact* contacts,int& sz, int &numContacts)
{
	if(sz==numContacts)
	{
		Contact* tempContact=new Contact[numContacts+1];
		for(int i=0;i<numContacts;i++)
		{
			tempContact[i]=contacts[i];
		}
		delete []contacts;
		return tempContact;
	}
	return contacts;
}

//accessor functions made as per requirement
string ContactBook::getContactBookfName() const
{
	return first;
}

string ContactBook::getContactBooklName() const
{
	return last;
}
//Mutators made as per requirement
void ContactBook::setContactBookFName(const string firstName)
{
	first=firstName;
}
void ContactBook::setContactBookLName(const string lastName)
{
	last=lastName;
}

//creates new contact in the contact book
void ContactBook::newContact()
{
	Contact contact;
	cin>>contact;
	contacts = grow(contacts,sz,numContacts);
	contacts[numContacts++]=contact;
	sz++;
}
//gets the first name of a contact from console
string ContactBook::getFirstName() const
{
	string first;
	cout<<"Enter Contact First Name:";
	cin>>first;
	return first;
}
//gets the last name of a contact from console
string ContactBook::getLastName() const
{
	string last;
	cout<<"Enter Contact Last Name:";
	cin>>last;
	return last;
}

//The function prints all the available contacts
void ContactBook::viewContacts()
{
	cout<<"All Contacts are listed Below"<<endl;
	cout<<"********************************************"<<endl;
	cout<<"--------------------------------------------"<<endl;
	for(int i=0;i<numContacts;i++)
	{
		cout<<contacts[i];
		cout<<"--------------------------------------------"<<endl;
		cout<<"********************************************"<<endl;
	}
}
//returns index of a contact
//used internally to find contacts based on first and last name
int ContactBook::getIndex(string first, string last)
{
	int index=-1;
	for(int i=0;i<numContacts; i++)
	{
		if(contacts[i].getFName()==first && contacts[i].getLName()==last)
		index=i;
	}
	return index;
}
//delete function deletes a certain contact
//the function is case sensitive and based on first and last name
void ContactBook::deleteContact()
{
	string first=getFirstName();
	string last=getLastName();
	int contactIndex = getIndex(first, last);
	if (contactIndex !=-1)
	{
		Contact tempContacts[10];
		int temp=0;

		for(int i=0;i<numContacts;i++)
		{
			if(i!=contactIndex)
			{
				tempContacts[temp]=contacts[i];
				temp++;
			}

		}
		numContacts--;
		for(int i=0;i<temp;i++)
		{
			contacts[i]=tempContacts[i];
		}
		cout<<"Contact named "<<first<<" "<<last<< " Deleted!"<<endl;

	}
	else
	{
		cout<<"Contact named "<<first<<" "<<last<< " does not exist. Please try Again!"<<endl;
	}

}
//updates a specific contact and allows update as long as the user wishes
void ContactBook::updateContact()
{
	string first=getFirstName();
	string last=getLastName();
	int contactIndex = getIndex(first, last);
	if (contactIndex !=-1)
	{
		char option;
		do
		{
			cout<<"Select the option you want to modify:"<<endl;
			cout<<"********************************************"<<endl;
			cout<<"--------------------------------------------"<<endl;
			cout<<"a. First Name"<<endl;
		    cout<<"b. Last Name"<<endl;
		    cout<<"c. Phone Number"<<endl;
		    cout<<"d. Email Address"<<endl;
		    cout<<"e. Home Address"<<endl;
		    cout<<"f. Stop Updating!"<<endl;
		    cout<<"--------------------------------------------"<<endl;
		    cout<<"********************************************"<<endl;
		    cout<<"OPTION: ";
		    cin >> option;
		    //note: all the inputs are again validated by using setters
		    //allows the user to change the first name
		    if (option=='a')
		   	{
		    	cout<<"New ";
		    	contacts[contactIndex].setFName();
		   	}
		    //allows the user to change last name.
		    else if(option=='b')
		    {
		    	cout<<"New ";
		    	contacts[contactIndex].setLName();
		    }
		    //allows the user to change the phone number
		    else if(option=='c')
		    {
		    	cout<<"New ";
		    	contacts[contactIndex].setPhone();

		    }
		    //allows the user to change the email address
		    else if(option=='d')
		    {
		    	cout<<"New ";
		    	contacts[contactIndex].setEmail();
		    }
		    //allows the user to change the address
		    else if(option=='e')
		    {
		    	cout<<"Enter New Address: ";
		    	contacts[contactIndex].setAddress();
		    }

		    cout<<endl;
		    //use f to exit the code
		} while (option!='f');
	}
	else
	{
		cout<<"Contact named "<<first<<" "<<last<< " does not exist. Please try Again!"<<endl;
	}
}


//The function searches a contact based on first name and last name from the console
void ContactBook::searchContact()
{
	string targetFirst=getFirstName();
	string targetLast= getLastName();

	int index = getIndex(targetFirst, targetLast);
	if(index != -1)
	{
		cout<<"--------------------------------------------"<<endl;
		cout<<contacts[index];
		cout<<"--------------------------------------------"<<endl;
	}
	else
	{
		cout<<"Contact named "<<targetFirst<<" "<<targetLast<< " does not exist."<<endl;
	}

}
//Created as per requirement to return the size of the list
int ContactBook::sizeList() const
{
	return numContacts;
}

ContactBook::~ContactBook()
{
	if(contacts!=NULL)
	{
		delete []contacts;
		contacts=NULL;
	}
}
ContactBook::ContactBook(const ContactBook& c1)
{
	this->numContacts =c1.numContacts;
	sz=numContacts;
	this->contacts =new Contact[c1.numContacts];
	for(int i=0;i<numContacts;i++)
	{
		contacts[i]=c1.contacts[i];
	}
}
//assignment operator
ContactBook& ContactBook::operator = (const ContactBook& c1)
{
	if(this != &c1)
	{
		if(contacts != NULL)
		{
			delete []contacts;
		}
		numContacts=c1.numContacts;
		contacts = new Contact[numContacts];

		for(int i=0;i<numContacts;i++)
		{
			contacts[i]= c1.contacts[i];
		}
	}
	return *this;
}



















