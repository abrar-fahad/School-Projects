
#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include "Address.h"

class Contact
{

	private:
		std::string firstName;
		std::string lastName;
		std::string phone;
		std::string email;
		Address address;
		bool isValidEmail(const string& email);
	public:
		//Define the constructor for all parameters and one for empty
		//Setting values for all parameters
		Contact(const std::string fn, const std::string ln, const std::string ph,const std::string em, Address add);
		//default constructor
		Contact();
		// Accessors made as per requirement
		std::string getFName() const;
		std::string getLName() const;
		std::string getPhone() const;
		std::string	getEmail() const;

		//void input();
		//void output() const;
		//used in operator overloading
		// Mutators made as per requirement
		void setFName();
		void setLName();
		void setPhone();
		void setEmail();
		void setAddress();
		//operator overloaded as per requirement
		bool operator == (const Contact &c);
		bool operator != (const Contact &c);
		bool operator > (const Contact &c);
		bool operator < (const Contact &c);
		bool operator >= (const Contact &c);
		bool operator <= (const Contact &c);

		friend std::ostream& operator <<(std::ostream& outputStream, const Contact &c);
		friend std::istream& operator >>(std::istream & inputStream,Contact &c);


};

#endif
