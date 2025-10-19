//
// CS320Project Enhancement 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Trenton Mendiola
// Last Updated: 9/28/25
// This application allows users to store and interact with a list of contacts, users may add, update, delete contacts as well as display them in different ways

#include <iostream>
#include "Contact.h"
#include <string>
#include "ContactService.h"

//Method for displaying menu choices
static void printMainMenu() {
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "Enter the corresponding number for your selected menu option as listed below" << std::endl;
	std::cout << "Option 1 - Add Contact" << std::endl;
	std::cout << "Option 2 - Update Contact" << std::endl;
	std::cout << "Option 3 - Remove Contact" << std::endl;
	std::cout << "Option 4 - Search For Contact" << std::endl;
	std::cout << "Option 5 - Display Contacts" << std::endl;
	std::cout << "Option 6 - Exit Program" << std::endl;
}

//Method for displaying sorting options menu
static void printSortingOptionsMenu() {
	std::cout << "How would you like the Contacts to be sorted?" << std::endl;
	std::cout << "Enter the corresponding number for your selected menu option as listed below" << std::endl;
	std::cout << "Option 1 - Ascending Alphabetical Order, (Contacts Last Name)" << std::endl;
	std::cout << "Option 2 - Descending Alphabetical Order, (Contacts Last Name)" << std::endl;
	std::cout << "Option 3 - Ascending Numeric Order, (Contacts ID)" << std::endl;
	std::cout << "Option 4 - Descending Numeric Order, (Contacts ID)" << std::endl;
}


//Method for sorting contacts in ascending alphabetical order
static void sortContactAscAlphabetical(std::vector<Contact>& contacts) {

	//Use sort to sort the contacts method alphabetically based on the contacts last name
	std::sort(contacts.begin(), contacts.end(), [](Contact& x,Contact& y) {
		//return which element would be next in ascending alphabetical order
		return x.getLastName() < y.getLastName();
		});

	//loop through the contacts vector
	for (auto& contact : contacts) {
		//Output each contact element
		std::cout << contact.getContactID()<< " " << contact.getLastName() << " " << contact.getFirstName() << " " << contact.getPhoneNumber() << " " << contact.getAddress() << std::endl;
	}
}

//Method for sorting contacts in descending alphabetical order
static void sortContactDescAlphabetical(std::vector<Contact>& contacts) {

	//Use sort to sort the contacts method alphabetically based on the contacts last name
	std::sort(contacts.begin(), contacts.end(), [](Contact& x, Contact& y) {
		//return which element would be next in descending alphabetical order
		return x.getLastName() > y.getLastName();
		});

	//loop through the contacts vector
	for (auto& contact : contacts) {
		//Output each contact element
		std::cout << contact.getContactID() << " " << contact.getLastName() << " " << contact.getFirstName() << " " << contact.getPhoneNumber() << " " << contact.getAddress() << std::endl;
	}
}

//Method for sorting contacts in ascending numeric order based on the contact ID
static void sortContactAscNumeric(std::vector<Contact>& contacts) {

	//Use sort to sort the contacts method alphabetically based on the contacts last name
	std::sort(contacts.begin(), contacts.end(), [](Contact& x, Contact& y) {
		//return which element would be next in ascending numeric order
		return x.getContactID() < y.getContactID();
		});

	//loop through the contacts vector
	for (auto& contact : contacts) {
		//Output each contact element
		std::cout << contact.getContactID() << " " << contact.getLastName() << " " << contact.getFirstName() << " " << contact.getPhoneNumber() << " " << contact.getAddress() << std::endl;
	}
}

//Method for sorting contacts in descending numeric order based on the contact ID
static void sortContactDescNumeric(std::vector<Contact>& contacts) {

	//Use sort to sort the contacts method alphabetically based on the contacts last name
	std::sort(contacts.begin(), contacts.end(), [](Contact& x, Contact& y) {
		//return which element would be next in descending numeric order
		return x.getContactID() > y.getContactID();
		});

	//loop through the contacts vector
	for (auto& contact : contacts) {
		//Output each contact element
		std::cout << contact.getContactID() << " " << contact.getLastName() << " " << contact.getFirstName() << " " << contact.getPhoneNumber() << " " << contact.getAddress() << std::endl;
	}
}

//Method for finding a contact with a matching contactID user entered
static void searchForContact(std::string contactID, std::vector<Contact>& contacts) {

	//using find to search through contacts vector
	auto it = find_if(contacts.begin(), contacts.end(), [&contactID](Contact& x) {
		//return if contactID is equal to what user entered
		return x.getContactID() == contactID;
		});
	//if the contact ID was found
	if (it != contacts.end()) {
		//output its information
		std::cout << it->getContactID() << " " << it->getLastName() << " " << it->getFirstName() << " " << it->getPhoneNumber() << " " << it->getAddress() << std::endl;
	}
	//else contact ID was not found
	else {
		//display error message
		std::cout << "Contact ID is not present!" << std::endl;
	}
}





//Main application
int main()
{
	//Create contact service object
	ContactService* service = new ContactService();
	//Create contact vector to store the contacts
	std::vector<Contact> contacts;


	//Loading the vector with three contacts to be used when testing
	service->addContactUsingID("1", "afirstName", "alastName", "0123456789", "address", contacts);
	service->addContactUsingID("2", "bfirstName", "blastName", "0123456789", "address", contacts);
	service->addContactUsingID("3", "cfirstName", "clastName", "0123456789", "address", contacts);


	//Variable to hold the users input for menu choices
	int choice;
	//bool to determine if the user has chosen to exit the application
	bool exit = false;

	//display menu
	printMainMenu();


	//Get user input for main menu
	//check for invalid input variable (not int) and check that the input is between 1 and 6
	while (!(std::cin >> choice) || choice > 6 || choice < 1) {
		//output error 
		std::cout << "Invalid Input Enter One Of The Menu Choices 1-6!" << std::endl;
		//clear cin
		std::cin.clear();
		//ignore all of the input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}


	//menu loop
	while (exit != true) 
	{
		
		//if option 1 was selected (user entered 1)
		if (choice == 1) 
		{
			//Variables for new contact being added to the contacts vector
			std::string contactID, firstName, lastName, phoneNumber, address;

			//Ask user for their new contacts information, get and validate input
			std::cout << "enter your contacts information as requested" << std::endl;

			//Get user input for contact ID checking that input is not empty
			do {
				//clear input
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "enter your contacts ID" << std::endl;
				std::getline(std::cin, contactID);
			} while (contactID.empty());

			//Get user input for first name checking that input is not empty
			do {
				std::cout << "enter your contacts first name" << std::endl;
				std::getline(std::cin, firstName);
			} while (firstName.empty());

			//Get user input for last name checking that input is not empty
			do {
				std::cout << "enter your contacts last name" << std::endl;
				std::getline(std::cin, lastName);
			} while (lastName.empty());

			//Get user input for phoneNumber checking that input is not empty
			do {
				std::cout << "enter your contacts phoneNumber" << std::endl;
				std::getline(std::cin, phoneNumber);
			} while (phoneNumber.empty());

			//Get user input for address checking that input is not empty
			do {
				std::cout << "enter your contacts address" << std::endl;
				std::getline(std::cin, address);
			} while (address.empty());

			//try use add contactContactUsingID method
			try {
				service->addContactUsingID(contactID, firstName, lastName, phoneNumber, address, contacts);
			}

			//catch invalid argument throw
			catch (std::invalid_argument) {
				//display error message
				std::cout << "Contact ID could not be added" << std::endl;
			}

			//display main menu again and get users input
			printMainMenu();

			//Get user input for main menu
			//check for invalid input variable (not int) and check that the input is between 1 and 6
			while (!(std::cin >> choice) || choice > 6 || choice < 1) {
				//output error 
				std::cout << "Invalid Input!" << std::endl;
				//clear cin
				std::cin.clear();
				//ignore all of the input
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
	
		}
		//if option 2 was selected (user entered 2)
		else if (choice == 2) 
		{
			//Variables to be used for update an existing contact
			std::string contactID, firstName, lastName, phoneNumber, address;

			//ask user for the information to be used to update the contact and get input (validate input as well)
			//Get user input for contact ID checking that input is not empty
			do {
				//clear input
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "enter the contacts ID for the contact you wish to update" << std::endl;
				std::getline(std::cin, contactID);
			} while (contactID.empty());

			//ask user for information to update contact with
			std::cout << "enter your contacts new information as requested" << std::endl;

			//Get user input for first name checking that input is not empty
			do {
				std::cout << "enter your contacts first name" << std::endl;
				std::getline(std::cin, firstName);
			} while (firstName.empty());

			//Get user input for last name checking that input is not empty
			do {
				std::cout << "enter your contacts last name" << std::endl;
				std::getline(std::cin, lastName);
			} while (lastName.empty());

			//Get user input for phoneNumber checking that input is not empty
			do {
				std::cout << "enter your contacts phoneNumber" << std::endl;
				std::getline(std::cin, phoneNumber);
			} while (phoneNumber.empty());

			//Get user input for address checking that input is not empty
			do {
				std::cout << "enter your contacts address" << std::endl;
				std::getline(std::cin, address);
			} while (address.empty());

			//try to use updateContactUsingID method
			try {
				service->updateContactUsingID(contactID, firstName, lastName, phoneNumber, address, contacts);
			}
			catch (std::invalid_argument) {
				std::cout << "Contact could not be updated" << std::endl;
			}
			//display main menu again and get users input
			printMainMenu();

			//Get user input for main menu
			//check for invalid input variable (not int) and check that the input is between 1 and 6
			while (!(std::cin >> choice) || choice > 6 || choice < 1) {
				//output error 
				std::cout << "Invalid Input!" << std::endl;
				//clear cin
				std::cin.clear();
				//ignore all of the input
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		//if option 3 was selected (user entered 3)
		else if (choice == 3)
		{
			//variable to be used as contact ID for contact to be deleted
			std::string contactID;

			//ask user for contact ID of the contact they wish to delete
			//Get user input for contact ID checking that input is not empty
			do {
				//clear input
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Enter the contactID of the contact you wish to delete" << std::endl;
				std::getline(std::cin, contactID);
			} while (contactID.empty());

			//try to use delete contact using ID method with user input contactID
			try {
				service->deleteContactUsingID(contactID, contacts);
			}
			catch (std::invalid_argument) {
				std::cout << "Contact could not be deleted" << std::endl;
			}

			//display main menu
			printMainMenu();

			//Get user input for main menu
			//check for invalid input variable (not int) and check that the input is between 1 and 6
			while (!(std::cin >> choice) || choice > 6 || choice < 1) {
				//output error 
				std::cout << "Invalid Input!" << std::endl;
				//clear cin
				std::cin.clear();
				//ignore all of the input
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		//if option 4 was selected (user entered 4)
		else if (choice == 4)
		{
			std::string contactID;
			
			//Ask user for contact ID of the contact they wish to view
			//Get user input for contact ID checking that input is not empty
			do {
				//clear input
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Enter the contact ID for the contact you wish to see" << std::endl;
				std::getline(std::cin, contactID);
			} while (contactID.empty());

			//use searchForContact method using user inputed contactID
			searchForContact(contactID, contacts);

			//display main menu
			printMainMenu();

			//Get user input for main menu
			//check for invalid input variable (not int) and check that the input is between 1 and 6
			while (!(std::cin >> choice) || choice > 6 || choice < 1) {
				//output error 
				std::cout << "Invalid Input!" << std::endl;
				//clear cin
				std::cin.clear();
				//ignore all of the input
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		//if option 5 was selected (user entered 5)
		else if (choice == 5)
		{
			//Display sorting options menu
			printSortingOptionsMenu();
			
			//variable to hold the users sorting choice
			int sortingMethod;


			//Get user input for sorting options
			//check for invalid input variable (not int) and check that the input is between 1 and 4
			while (!(std::cin >> sortingMethod) || sortingMethod > 4 || sortingMethod < 1) {
				//output error 
				std::cout << "Invalid Input!" << std::endl;
				//clear cin
				std::cin.clear();
				//ignore all of the input
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

			//if user entered 1 
			if (sortingMethod == 1) {

				//use sortContactAscAlphabetical method
				sortContactAscAlphabetical(contacts);
				
			}

			//if user entered choice 2
			if (sortingMethod == 2) {

				//use sortContactDescAlphabetical method
				sortContactDescAlphabetical(contacts);
				
			}

			//if user entered choice 3
			if (sortingMethod == 3) {

				//use sort contactAscNumeric method
				sortContactAscNumeric(contacts);
				
			}

			//if user entered choice 4
			if (sortingMethod == 4) {

				//use sort contactDescNumeric method
				sortContactDescNumeric(contacts);
				
			}

			//display the main menu again and get the users input
			printMainMenu();
			
			//Get user input for main menu
			//check for invalid input variable (not int) and check that the input is between 1 and 6
			while (!(std::cin >> choice) || choice > 6 || choice < 1) {
				//output error 
				std::cout << "Invalid Input!" << std::endl;
				//clear cin
				std::cin.clear();
				//ignore all of the input
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		//if option 6 was selected (user entered 6)
		else if (choice == 6)
		{
			//end menu loop
			exit = true;
		}
	}
	
	return 0;
}


