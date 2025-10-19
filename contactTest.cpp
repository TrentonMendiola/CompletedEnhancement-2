#include "pch.h"
#include "C:\Users\Teton\source\repos\CS320Project Enhancement 1\CS320Project Enhancement 1\Contact.h"

TEST(TestContactVariablesInitializeCorrectly, TestContact) {

	//create contact object with test variables
	Contact* contact = new Contact("TestID", "TestName", "TestName", "0123456789", "Test Address");

	//use expect equal to verify that get commands used on the contact object return the correct variables
	//verify ID
	EXPECT_EQ(contact->getContactID(), "TestID");
	//verify first name
	EXPECT_EQ(contact->getFirstName(), "TestName");
	//verify last name 
	EXPECT_EQ(contact->getLastName(), "TestName");
	//verify phone number 
	EXPECT_EQ(contact->getPhoneNumber(), "0123456789");
	//verify address
	EXPECT_EQ(contact->getAddress(), "Test Address");

}

//Tests to ensure entering variables that are too long will throw error
TEST(TestFailureWhenVariablesTooLong, TestContactIDTooLong) {
	//Expect invalid_argument throw
	EXPECT_THROW
		(
		//create contact object with test variables
		//contact ID is more than 10 characters long
		Contact * contact = new Contact("TestID11111", "TestName", "TestName", "0123456789", "Test Address"), std::invalid_argument
		);
}

TEST(TestFailureWhenVariablesTooLong, TestFirstNameTooLong) {
	//Expect invalid_argument throw
	EXPECT_THROW
	(
		//create contact object with test variables
		//first name is more than 10 characters long
		Contact * contact = new Contact("TestID", "TestName123", "TestName", "0123456789", "Test Address"), std::invalid_argument
	);
}

TEST(TestFailureWhenVariablesTooLong, TestLastNameTooLong) {
	//Expect invalid_argument throw
	EXPECT_THROW
	(
		//create contact object with test variables
		//last name is more than 10 characters long
		Contact * contact = new Contact("TestID", "TestName", "TestName123", "0123456789", "Test Address"), std::invalid_argument
	);
}

TEST(TestFailureWhenVariablesTooLong, TestPhoneNumberTooLong) {
	//Expect invalid_argument throw
	EXPECT_THROW
	(
		//create contact object with test variables
		//phone number is more than 10 characters long
		Contact * contact = new Contact("TestID", "TestName", "TestName", "01234567891", "Test Address"), std::invalid_argument
	);
}

TEST(TestFailureWhenVariablesTooLong, TestAddressTooLong) {
	//Expect invalid_argument throw
	EXPECT_THROW
	(
		//create contact object with test variables
		//address is more than 30 characters long
		Contact * contact = new Contact("TestID", "TestName", "TestName", "0123456789", "Test AddressTest AddressTest Ad"), std::invalid_argument
	);
}

//Tests to ensure entering variables with empty values will throw error
TEST(TestFailureWhenVariablesAreEmpty, TestContactIDEmpty) {
	//Expect invalid_argument throw
	EXPECT_THROW
	(
		//create contact object with test variables
		//contact ID is empty
		Contact * contact = new Contact("", "TestName", "TestName", "0123456789", "Test Address"), std::invalid_argument
	);
}

TEST(TestFailureWhenVariablesAreEmpty, TestFirstNameEmpty) {
	//Expect invalid_argument throw
	EXPECT_THROW
	(
		//create contact object with test variables
		//first name is empty
		Contact * contact = new Contact("TestID", "", "TestName", "0123456789", "Test Address"), std::invalid_argument
	);
}

TEST(TestFailureWhenVariablesAreEmpty, TestLastNameEmpty) {
	//Expect invalid_argument throw
	EXPECT_THROW
	(
		//create contact object with test variables
		//last name is empty
		Contact * contact = new Contact("TestID", "TestName", "", "0123456789", "Test Address"), std::invalid_argument
	);
}

TEST(TestFailureWhenVariablesAreEmpty, TestPhoneNumberEmpty) {
	//Expect invalid_argument throw
	EXPECT_THROW
	(
		//create contact object with test variables
		//phone number is empty
		Contact * contact = new Contact("TestID", "TestName", "TestName", "", "Test Address"), std::invalid_argument
	);
}

TEST(TestFailureWhenVariablesAreEmpty, TestAddressEmpty) {
	//Expect invalid_argument throw
	EXPECT_THROW
	(
		//create contact object with test variables
		//address is empty
		Contact * contact = new Contact("TestID", "TestName", "TestName", "0123456789", ""), std::invalid_argument
	);
}

//Tests to ensure setters are working properly

TEST(TestSetters, TestSettingFirstName) {

	//create contact object with valid test variables
	Contact* contact = new Contact("TestID", "TestName", "TestName", "0123456789", "Test Address");

	//use expect equal to verify that get commands used on the contact object return the correct variables
	//verify first name
	EXPECT_EQ(contact->getFirstName(), "TestName");

	//set first name to a new name
	contact->setFirstName("NewName");

	//verify new name
	EXPECT_EQ(contact->getFirstName(), "NewName");

}

TEST(TestSetters, TestSettingLastName) {

	//create contact object with valid test variables
	Contact* contact = new Contact("TestID", "TestName", "TestName", "0123456789", "Test Address");

	//use expect equal to verify that get commands used on the contact object return the correct variables
	//verify last name
	EXPECT_EQ(contact->getLastName(), "TestName");

	//set last name to a new name
	contact->setLastName("NewName");

	//verify new name
	EXPECT_EQ(contact->getLastName(), "NewName");

}

TEST(TestSetters, TestSettingPhoneNumber) {

	//create contact object with valid test variables
	Contact* contact = new Contact("TestID", "TestName", "TestName", "0123456789", "Test Address");

	//use expect equal to verify that get commands used on the contact object return the correct variables
	//verify phone number
	EXPECT_EQ(contact->getPhoneNumber(), "0123456789");

	//set phone number to a new number
	contact->setPhoneNumber("1111111111");

	//verify new number
	EXPECT_EQ(contact->getPhoneNumber(), "1111111111");

}

TEST(TestSetters, TestSettingAddress) {

	//create contact object with valid test variables
	Contact* contact = new Contact("TestID", "TestName", "TestName", "0123456789", "Test Address");

	//use expect equal to verify that get commands used on the contact object return the correct variables
	//verify address
	EXPECT_EQ(contact->getAddress(), "Test Address");

	//set first name to a new name
	contact->setAddress("New Address");

	//verify new address
	EXPECT_EQ(contact->getAddress(), "New Address");

}

//Tests to ensure entering the maximum length for the variables does not throw any errors
TEST(TestMaxVariables, TestMaxContactID) {

	EXPECT_NO_THROW
	({
		//create contact object with valid test variables
		//contact ID is 10 characters long
		Contact * contact = new Contact("TestID1234", "TestName", "TestName", "0123456789", "Test Address");

	});
}

TEST(TestMaxVariables, TestMaxFirstName) {

	EXPECT_NO_THROW
	({
		//create contact object with valid test variables
		//first name is 10 characters long
		Contact * contact = new Contact("TestID", "TestName12", "TestName", "0123456789", "Test Address");

		});
}

TEST(TestMaxVariables, TestMaxLastName) {

	EXPECT_NO_THROW
	({
		//create contact object with valid test variables
		//last name is 10 characters long
		Contact * contact = new Contact("TestID", "TestName", "TestName12", "0123456789", "Test Address");

		});
}

TEST(TestMaxVariables, TestMaxPhoneNumber) {

	EXPECT_NO_THROW
	({
		//create contact object with valid test variables
		//phone number is 10 characters long
		Contact * contact = new Contact("TestID", "TestName", "TestName", "0123456789", "Test Address");

		});
}

TEST(TestMaxVariables, TestMaxAddress) {

	EXPECT_NO_THROW
	({
		//create contact object with valid test variables
		//address is 30 characters long
		Contact * contact = new Contact("TestID", "TestName", "TestName", "0123456789", "012345678901234567890123456789");

		});
}

//Tests to ensure entering the minimum length for the variables does not throw any errors
TEST(TestMinVariables, TestMinContactID) {

	EXPECT_NO_THROW
	({
		//create contact object with valid test variables
		//contact ID is 1 character long
		Contact * contact = new Contact("1", "TestName", "TestName", "0123456789", "Test Address");

		});
}

TEST(TestMinVariables, TestMinFirstName) {

	EXPECT_NO_THROW
	({
		//create contact object with valid test variables
		//first name is 1 characters long
		Contact * contact = new Contact("TestID", "1", "TestName", "0123456789", "Test Address");

		});
}

TEST(TestMinVariables, TestMinLastName) {

	EXPECT_NO_THROW
	({
		//create contact object with valid test variables
		//last name is 1 character long
		Contact * contact = new Contact("TestID", "TestName", "1", "0123456789", "Test Address");

		});
}

TEST(TestMinVariables, TestMinPhoneNumber) {

	EXPECT_NO_THROW
	({
		//create contact object with valid test variables
		//phone number is 10 characters long
		Contact * contact = new Contact("TestID", "TestName", "TestName", "0123456789", "Test Address");

		});
}

TEST(TestMinVariables, TestMinAddress) {

	EXPECT_NO_THROW
	({
		//create contact object with valid test variables
		//address is 1 character long
		Contact * contact = new Contact("TestID", "TestName", "TestName", "0123456789", "1");

		});
}
