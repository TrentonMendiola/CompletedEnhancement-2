#pragma once
#include <string>
#include <vector>
#include "Contact.h"
#include <algorithm>


class ContactService
{
public:


	//Method will add a new contact using its ID as an identifier
	void addContactUsingID(std::string contactID, std::string firstName, std::string lastName, std::string phoneNumber, std::string address, std::vector<Contact>& contacts)
	{
		//loop through the contacts vector
		for (Contact& contact : contacts) 
		{
			//check if the contact ID is already present in the vector
			if (contact.getContactID() == contactID) 
			{
				//if the ID is present display error message
				throw std::invalid_argument("ContactID is already Present!");
			}
		}

		//ContactID was not found to be present so create a new contact object using the entered valid information
		Contact newContact(contactID, firstName, lastName, phoneNumber, address);

		//insert the object into the contacts vector
		contacts.push_back({newContact});
	}



	//Method to delete contact using ID as an identifier
	void deleteContactUsingID(std::string contactID, std::vector<Contact>& contacts)
	{
	
		//using find to search through contacts vector
		auto it = find_if(contacts.begin(), contacts.end(), [&contactID](Contact& x) {
			//return if contactID is equal to what user entered
			return x.getContactID() == contactID;
			});

		//if the contact ID was found
		if (it != contacts.end()) {
			//erase that element
			contacts.erase(it);
		}

		//else contact ID was not found
		else {
			//display error message 
			throw std::invalid_argument("ContactID is not present!");
		}

	}


	
	//Method will update an existing contact using the ID as an identifier
	void updateContactUsingID(std::string contactID, std::string firstName, std::string lastName, std::string phoneNumber, std::string address, std::vector<Contact>& contacts) 
	{

		//Bool variable to identify if the entered ID is present in the contacts vector
		bool idPresent = false;

		for (Contact& contact : contacts)
		{
			//check if the contactID is already present in the vector
			if (contact.getContactID() == contactID) 
			{
				//as the id is present the bool will be set to true
				idPresent = true;
				//the information will be updated to the new information 
				contact.setFirstName(firstName);
				contact.setLastName(lastName);
				contact.setPhoneNumber(phoneNumber);
				contact.setAddress(address);
			}
		}
		//if the contact ID was not found the bool will still be false
		if (idPresent == false) 
		{
			//if the bool is false error message will be displayed
			throw std::invalid_argument("ContactID is not present!");
		}
	}



};