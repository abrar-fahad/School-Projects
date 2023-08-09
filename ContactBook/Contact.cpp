#include "Contact.h"
#include <iostream>
#include <algorithm>
#include <limits>
#include <string>
#include <regex>

//Constructor that saves all values
Contact::Contact(std::string fn, std::string ln, std::string ph,std::string em, Address add)
{
	firstName=fn;
	lastName=ln;
	phone=ph;
	email=em;
	address=add;
}
//default constructor
Contact::Contact()
{
	firstName="N/A";
	lastName="N/A";
	phone="N/A";
	email="N/A";
}

/*
 * commented out due to use in operator overloading
void Contact::input()
{
	setFName();
	setLName();
	setPhone();
	setEmail();

	//calls the address from the address.cpp file to input the address
	cin>>address;
}
*/
//Prints out all the parameters
/*
 * commented out due to use in operator overloading
void Contact::output() const
{
	std::cout<<"Contact:"<<std::endl;
	std::cout<<"First Name: "<<firstName<<std::endl;
	std::cout<<"Last Name: "<<lastName<<std::endl;
	std::cout<<"Phone Number: "<<phone<<std::endl;
	std::cout<<"Email Address: "<<email<<std::endl;
	std::cout<<"Home Address: "<<address<<endl;
}
*/
//Accessors made as per requirement
std::string Contact::getFName() const
{
	return firstName;
}
std::string Contact::getLName() const
{
	return lastName;
}

std::string Contact::getPhone() const
{
	return phone;
}
std::string	Contact::getEmail() const
{
	return email;
}

//Mutators made as per requirement
//mutators internally check if the input is valid
void Contact::setFName()
{
	//checks the first name for digits and if no digits exists saves the name
	do
	{
		std::cout<<"Enter First Name: ";
		std::cin>>firstName;

		if(std::any_of(firstName.begin(),firstName.end(),::isdigit))
		{
			std::cout<<"Invalid First Name"<<std::endl;
		}
		else
		{
			break;
		}
	}while(true);
}
void Contact::setLName()
{
	//check the last name for digits and if no digits exists saves the name
	do{
		std::cout<<"Enter Last Name: ";
		std::cin>>lastName;

		if(std::any_of(lastName.begin(),lastName.end(),::isdigit))
		{
			std::cout<<"Invalid Last Name"<<std::endl;
		}
		else
		{
			break;
		}
	}while(true);
}

void Contact::setPhone()
{
	//Checks the phone number if its exactly 10 digit and that it does not contain anything other than numbers
	do
	{
		std::cout<<"Enter Phone Number: ";
		std::cin>>phone;
		if((phone.length())>10 || phone.length()<10 || ((std::any_of(phone.begin(),phone.end(),::isdigit))== false))
		{
			std::cout<<"Invalid phone number"<<std::endl;
		}
		else
		{
			break;
		}
	}while(true);
}
//uses regex to match a given email with a regular expression
bool Contact::isValidEmail(const string& email)
{
    const regex pattern(
        "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}
//Validate the email address with regular expression
void Contact::setEmail()
{
	do
	{
		std::cout<<"Enter Email Address: ";
		std::cin>>email;
		if (isValidEmail(email)==true){
			break;
		}
		else
		{
			std::cout<<"Invalid Email Address"<<std::endl;
		}

	}while(true);
}
//sets the address
void Contact::setAddress()
{
	std::cin>>address;
}

//Operators overloaded as per requirement
//<<operator overloaded
std::ostream& operator <<(std::ostream& out, const Contact &c)
{
	out<<"Contact:"<<std::endl;
	out<<"First Name: "<<c.firstName<<std::endl;
	out<<"Last Name: "<<c.lastName<<std::endl;
	out<<"Phone Number: "<<c.phone<<std::endl;
	out<<"Email Address: "<<c.email<<std::endl;
	out<<"Home Address: "<<c.address<<endl;

	return out;
}
//>> operator overloaded
std::istream& operator >>(std::istream & inputStream, Contact &c)
{
	c.setFName();
	c.setLName();
	c.setPhone();
	c.setEmail();
	//calls the address from the address.cpp file to input the address
	inputStream>>c.address;


	return inputStream;
}
//compares two string to see if its equal to one another
bool Contact::operator == (const Contact &c)
{
	return (lastName.compare(c.lastName)==0 && firstName.compare(c.firstName)==0);

}
//compares two string to see if its not equal to one another
bool Contact::operator != (const Contact &c)
{
	return (lastName.compare(c.lastName)!=0 && firstName.compare(c.firstName)!=0);

}
//compares two string to see if its greater than one another
bool Contact::operator > (const Contact &c)
{
	return(lastName.compare(c.lastName)>0 && firstName.compare(c.firstName)>0);

}
//compares two string to see if its less than one another
bool Contact::operator < (const Contact &c)
{
	return (lastName.compare(c.lastName)<0 && firstName.compare(c.firstName)<0);

}
//compares two string to see if its greater than or equal to each other
bool Contact::operator >= (const Contact &c)
{
	return (lastName.compare(c.lastName)>=0 && firstName.compare(c.firstName)>=0);

}
//compares two string to see if its less than or equal to each other
bool Contact::operator <= (const Contact &c)
{
	return (lastName.compare(c.lastName)<=0 && firstName.compare(c.firstName)<=0);

}


