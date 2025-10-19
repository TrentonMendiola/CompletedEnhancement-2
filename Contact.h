#pragma once
#include <string>
#include <iostream>


class Contact
{
private:
	//Variables used in contact object
	std::string contactID, firstName, lastName, phoneNumber, address;


public:

	std::string data;

	Contact(const std::string& a)
		: data(a)
	{
	}

	// Overloading < operator
	bool operator<(const Contact& contact) const
	{
		return data < contact.data;
	}


	Contact(std::string contactID, std::string firstName, std::string lastName, std::string phoneNumber, std::string address) {

		//Verify contact variables are not empty and correct length
		if (contactID.empty() || contactID.length() > 10) {

			throw std::invalid_argument("Invalid ID");
		}

		if (firstName.empty() || firstName.length() > 10) {

			throw std::invalid_argument("Invalid First Name");
		}

		if (lastName.empty() || lastName.length() > 10) {

			throw std::invalid_argument("Invalid Last Name");
		}

		if (phoneNumber.empty() || phoneNumber.length() != 10) {

			throw std::invalid_argument("Invalid Phone Number");
		}

		if (address.empty() || address.length() > 30) {

			throw std::invalid_argument("Invalid Address");
		}
		
		//no issues with the variables then assign contact variables
		this->contactID = contactID;
		this->firstName = firstName;
		this->lastName = lastName;
		this->phoneNumber = phoneNumber;
		this->address = address;
		
	}

	//getters 
	std::string getContactID()
	{
		return contactID;
	}

	std::string getFirstName()
	{
		return firstName;
	}


	std::string getLastName()
	{
		return lastName;
	}


	std::string getPhoneNumber()
	{
		return phoneNumber;
	}

	std::string getAddress()
	{
		return address;
	}

	//setters
	void setFirstName(std::string newFirstName)
	{
		firstName = newFirstName;
	}

	void setLastName(std::string newLastName)
	{
		lastName = newLastName;
	}

	void setPhoneNumber(std::string newPhoneNumber)
	{
		phoneNumber = newPhoneNumber;
	}
	void setAddress(std::string newAddress)
	{
		address = newAddress;
	}



};

