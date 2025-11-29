#include "user.h"

User::User() {
    id_ = -1;
    name_ = "";
    year_ = 0;
    zip_ = 0;
    biography_ = "";
    friends = {};
}

User::User(int id, std::string name, int year, int zip, std::set<int> friends) {
    id_=id;
    name_ = name;
    year_ = year;
    zip_ = zip;
    biography_ = "Hi, I am " + name;
    password_ = "password" + std::to_string(id);

    for (const auto& i : friends ) {
        this->friends.insert(i);
    }
}

int User::getId() { return id_; }

std::string User::getName() { return name_; }

int User::getYear() { return year_; }

int User::getZip() { return zip_; }

std::string User::getBiography() { return biography_; }

void User::setBiography(std::string b) { biography_ = b; }

std::string User::getPassword() { return password_; }

void User::setPassword(std::string p) { password_ = p;}

void User::setName(std::string u) {name_ = u; }

std::set<int>& User::getFriends() { return friends; }


void User::deleteFriend(int id) {
    if(friends.find(id) != friends.end()) friends.erase(id);
}

void User::addFriend(int id) { friends.insert(id); }

