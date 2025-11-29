#ifndef USER_H
#define USER_H

#include <string>
#include <set>

class User {
public:
	//pre: None
	//post: creates default user
	User();

	//pre: None
	//post: creates new user with values initialized
    User(int id, std::string name, int year, int zip, std::set<int> friends);

	//pre: None
	//post: returns User's ID
	int getId();

	//pre: None
	//post: returns User's name
	std::string getName();

	//pre: None
	//post: returns User's birth year 
	int getYear();

	//pre: None
	//post: returns User's zip code
	int getZip();

    //pre: None
    //post: returns User's biography
    std::string getBiography();

    //pre: None
    //post: sets User's biography
    void setBiography(std::string b);

    //pre: None
    //post: returns User's password
    std::string getPassword();

    //pre: None
    //post: set User's password
    void setPassword(std::string p);

    //pre: None
    //post: set User's name
    void setName(std::string u);

	//pre: None
	//post: returns User's friends in set of ids
	std::set<int>& getFriends();

	//pre: None
	//post: if valid id, then delete id from friends
	void deleteFriend(int id);

	//pre: valid user id
	//post: adds id to user's friends
	void addFriend(int id);
private:
	int id_;
	std::string name_;
	int year_;
	int zip_;
	std::set<int> friends;
    std::string biography_;
    std::string password_;

};


#endif
