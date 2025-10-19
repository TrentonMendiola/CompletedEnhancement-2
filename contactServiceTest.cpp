#include "pch.h"
#include "C:\Users\Teton\source\repos\CS320Project Enhancement 1\CS320Project Enhancement 1\ContactService.h"

TEST(TestContactServiceMethods, TestAddContactUsingID) {

	//create new service object for contact service class and contacts vector
	ContactService* service = new ContactService();
	std::vector<Contact> contacts;

	//variables for the contact
	std::string contactID = "testID";
	std::string firstName = "testName";
	std::string lastName = "testName";
	std::string phoneNumber = "0123456789";
	std::string address = "test address";

	//use add contact method to add new contact
	service->addContactUsingID(contactID, firstName, lastName, phoneNumber, address, contacts);

	//bool variable to determine if the contact was added to the contacts vector
	bool idPresent = false;

	//loop through the contacts vector
	for (Contact& contact : contacts)
	{
		//check if the contact ID is present in the vector
		if (contact.getContactID() == contactID)
		{
			idPresent = true;
		}
	}

	//Expect the idPresent to be true proving the contact was added to the contacts vector
	EXPECT_TRUE(idPresent);
}

TEST(TestContactServiceMethods, TestDeleteContactUsingID) {
	

	//create new service object for contact service class and contacts vector
	ContactService* service = new ContactService();
	std::vector<Contact> contacts;

	//variables for the contact
	std::string contactID = "testID";
	std::string firstName = "testName";
	std::string lastName = "testName";
	std::string phoneNumber = "0123456789";
	std::string address = "test address";

	//use add contact method to add new contact
	service->addContactUsingID(contactID, firstName, lastName, phoneNumber, address, contacts);

	//bool variable to determine if the contact is present in the vector
	bool idPresent = false;

	//use delete contact method to delete contact
	service->deleteContactUsingID(contactID, contacts);

	//loop through the contacts vector
	for (Contact& contact : contacts)
	{
		//check if the contact ID is present in the vector
		if (contact.getContactID() == contactID)
		{
			idPresent = true;
		}
	}

	//Expect the idPresent to be false proving the contact was deleted from the contacts vector
	EXPECT_FALSE(idPresent);


}

TEST(TestContactServiceMethods, TestUpdateContactUsingID) {

	//create new service object for contact service class and contacts vector
	ContactService* service = new ContactService();
	std::vector<Contact> contacts;

	//create new contact with valid variables
	Contact newContact("testID", "name", "name", "0123456789", "address");

	//insert the contact into the contacts vector
	contacts.push_back({ newContact });

	//create new information for the contact
	std::string contactID = "testID";
	std::string firstName = "newName";
	std::string lastName = "newName";
	std::string phoneNumber = "1111111111";
	std::string address = "new address";

	//update contact with new variables using update contact using ID method
	service->updateContactUsingID(contactID, firstName, lastName, phoneNumber, address, contacts);

	//loop through the contacts vector
	for (Contact& contact : contacts)
	{
		//check if the contact ID is present in the vector
		if (contact.getContactID() == contactID)
		{
			//verify new values were set
			EXPECT_EQ(contact.getContactID(), "testID");
			//verify first name
			EXPECT_EQ(contact.getFirstName(), "newName");
			//verify last name 
			EXPECT_EQ(contact.getLastName(), "newName");
			//verify phone number 
			EXPECT_EQ(contact.getPhoneNumber(), "1111111111");
			//verify address
			EXPECT_EQ(contact.getAddress(), "new address");
		}
	}
}

//Tests to ensure each contact service method works when used multiple times

TEST(TestMultipleUseServiceMethods, TestAddContactUsingIDMultipleTimes) {

	//create new service object for contact service class and contacts vector
	ContactService* service = new ContactService();
	std::vector<Contact> contacts;

	//variables for the contact
	std::string contactID = "testID";
	std::string firstName = "testName";
	std::string lastName = "testName";
	std::string phoneNumber = "0123456789";
	std::string address = "test address";

	//use add contact method to add new contact
	service->addContactUsingID(contactID, firstName, lastName, phoneNumber, address, contacts);

	//bool variable to determine if the contact was added to the contacts vector
	bool idPresent = false;

	//loop through the contacts vector
	for (Contact& contact : contacts)
	{
		//check if the contact ID is present in the vector
		if (contact.getContactID() == contactID)
		{
			idPresent = true;
		}
	}

	//Expect the idPresent to be true proving the contact was added to the contacts vector
	EXPECT_TRUE(idPresent);

	//reset bool
	idPresent = false;

	//new variables for the next contact
	contactID = "testID1";
	firstName = "testName1";
	lastName = "testName1";
	phoneNumber = "1123456789";
	address = "test address1";

	//use add contact method to add new contact
	service->addContactUsingID(contactID, firstName, lastName, phoneNumber, address, contacts);

	//loop through the contacts vector
	for (Contact& contact : contacts)
	{
		//check if the contact ID is present in the vector
		if (contact.getContactID() == contactID)
		{
			idPresent = true;
		}
	}

	//Expect the idPresent to be true proving the contact was added to the contacts vector
	EXPECT_TRUE(idPresent);

}

TEST(TestMultipleUseServiceMethods, TestDeleteContactUsingIDMultipleTimes) {

	//create new service object for contact service class and contacts vector
	ContactService* service = new ContactService();
	std::vector<Contact> contacts;

	//variables for the contact
	std::string contactID = "testID";
	std::string firstName = "testName";
	std::string lastName = "testName";
	std::string phoneNumber = "0123456789";
	std::string address = "test address";

	//use add contact method to add new contact
	service->addContactUsingID(contactID, firstName, lastName, phoneNumber, address, contacts);

	//bool variable to determine if the contact is present in the vector
	bool idPresent = false;

	//use delete contact method to delete contact
	service->deleteContactUsingID(contactID, contacts);

	//loop through the contacts vector
	for (Contact& contact : contacts)
	{
		//check if the contact ID is present in the vector
		if (contact.getContactID() == contactID)
		{
			idPresent = true;
		}
	}

	//Expect the idPresent to be false proving the contact was deleted from the contacts vector
	EXPECT_FALSE(idPresent);

	//new information for second contact
	contactID = "testID1";
	firstName = "testName";
	lastName = "testName";
	phoneNumber = "0123456789";
	address = "test address";

	//use add contact using ID method to add contact
	service->addContactUsingID(contactID, firstName, lastName, phoneNumber, address, contacts);

	//use delete contact method to delete contact
	service->deleteContactUsingID(contactID, contacts);

	//loop through the contacts vector
	for (Contact& contact : contacts)
	{
		//check if the contact ID is present in the vector
		if (contact.getContactID() == contactID)
		{
			idPresent = true;
		}
	}

	//Expect the idPresent to be false proving the contact was deleted from the contacts vector
	EXPECT_FALSE(idPresent);
}

TEST(TestMultipleUseServiceMethods, TestUpdateContactUsingIDMultipleTimes) {

	//create new service object for contact service class and contacts vector
	ContactService* service = new ContactService();
	std::vector<Contact> contacts;

	//create new contact with valid variables
	Contact newContact("testID", "name", "name", "0123456789", "address");

	//insert the contact into the contacts vector
	contacts.push_back({ newContact });

	//create new information for the contact
	std::string contactID = "testID";
	std::string firstName = "newName";
	std::string lastName = "newName";
	std::string phoneNumber = "1111111111";
	std::string address = "new address";

	//update contact with new variables using update contact using ID method
	service->updateContactUsingID(contactID, firstName, lastName, phoneNumber, address, contacts);

	//loop through the contacts vector
	for (Contact& contact : contacts)
	{
		//check if the contact ID is present in the vector
		if (contact.getContactID() == contactID)
		{
			//verify new values were set
			EXPECT_EQ(contact.getContactID(), "testID");
			//verify first name
			EXPECT_EQ(contact.getFirstName(), "newName");
			//verify last name 
			EXPECT_EQ(contact.getLastName(), "newName");
			//verify phone number 
			EXPECT_EQ(contact.getPhoneNumber(), "1111111111");
			//verify address
			EXPECT_EQ(contact.getAddress(), "new address");
		}
	}

	//create second new contact with valid variables
	Contact newContact1("testID1", "name", "name", "0123456789", "address");

	//insert the contact into the contacts vector
	contacts.push_back({ newContact1 });

	//create new information for the second contact
	contactID = "testID1";
	firstName = "newName";
	lastName = "newName";
	phoneNumber = "1111111111";
	address = "new address";

	//update contact with new variables using update contact using ID method
	service->updateContactUsingID(contactID, firstName, lastName, phoneNumber, address, contacts);

	//loop through the contacts vector
	for (Contact& contact : contacts)
	{
		//check if the contact ID is present in the vector
		if (contact.getContactID() == contactID)
		{
			//verify new values were set
			EXPECT_EQ(contact.getContactID(), "testID1");
			//verify first name
			EXPECT_EQ(contact.getFirstName(), "newName");
			//verify last name 
			EXPECT_EQ(contact.getLastName(), "newName");
			//verify phone number 
			EXPECT_EQ(contact.getPhoneNumber(), "1111111111");
			//verify address
			EXPECT_EQ(contact.getAddress(), "new address");
		}
	}
}

//Test to ensure using service methods adding ID's wont work if ID is present
TEST(TestServiceMethodWhenIDIsPresent, TestAddContactUsingIDMethodWhenIDIsPresent) {

	//create new service object for contact service class and contacts vector
	ContactService* service = new ContactService();
	std::vector<Contact> contacts;

	//variables for the contact
	std::string contactID = "testID";
	std::string firstName = "testName";
	std::string lastName = "testName";
	std::string phoneNumber = "0123456789";
	std::string address = "test address";

	//use add contact method to add new contact
	service->addContactUsingID(contactID, firstName, lastName, phoneNumber, address, contacts);

	//expect invalid argument error
	EXPECT_THROW
	(
		//using add contact using ID method again with the same contactID should result in invalid argument throw
		service->addContactUsingID(contactID, firstName, lastName, phoneNumber, address, contacts), std::invalid_argument
	);
}

//Tests to ensure service methods removing or update a contact wont work unless ID is present
TEST(TestServiceMethodWhenIDIsNotPresent, TestDeleteContactUsingIDWhenIDIsNotPresent) {

	//create new service object for contact service class and contacts vector
	ContactService* service = new ContactService();
	std::vector<Contact> contacts;

	//No contact is added to the contact vector, so it is empty

	//variables for the contact
	std::string contactID = "testID";
	std::string firstName = "testName";
	std::string lastName = "testName";
	std::string phoneNumber = "0123456789";
	std::string address = "test address";

	//expect invalid argument error
	EXPECT_THROW(
		//using delete contact using ID method when ID is not present in the vector should result in invalid argument throw
		service->deleteContactUsingID(contactID, contacts), std::invalid_argument
	);
}


TEST(TestServiceMethodWhenIDIsNotPresent, TestUpdateContactUsingIDWhenIDIsNotPresent) {

	//create new service object for contact service class and contacts vector
	ContactService* service = new ContactService();
	std::vector<Contact> contacts;

	//No contact is added to the contact vector, so it is empty

	//create new information for the contact
	std::string contactID = "testID";
	std::string firstName = "newName";
	std::string lastName = "newName";
	std::string phoneNumber = "1111111111";
	std::string address = "new address";

	//expect invalid argument error
	EXPECT_THROW(
		//using update contact using ID method when the contact ID not present in the vector should result in invalid argument throw
		service->updateContactUsingID(contactID, firstName, lastName, phoneNumber, address, contacts), std::invalid_argument
	);
}

//Test to ensure service method will not update contact ID
TEST(TestServiceMethodWillNotUpdateID, TestUpdateContactUsingIDWillNotWorkWhenTryingToUpdateContactID) {
	//create new service object for contact service class and contacts vector
	ContactService* service = new ContactService();
	std::vector<Contact> contacts;

	//create new contact with valid variables
	Contact newContact("testID", "name", "name", "0123456789", "address");

	//insert the contact into the contacts vector
	contacts.push_back({ newContact });

	//create new information for the contact
	//new ID added as well
	std::string contactID = "testID1";
	std::string firstName = "newName";
	std::string lastName = "newName";
	std::string phoneNumber = "1111111111";
	std::string address = "new address";

	//expect invalid argument error
	EXPECT_THROW(
		//using update contact using ID method with a new contact ID should result in an invalid argument throw
		service->updateContactUsingID(contactID, firstName, lastName, phoneNumber, address, contacts), std::invalid_argument
	);

}


