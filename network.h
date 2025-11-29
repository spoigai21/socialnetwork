#ifndef NETWORK_H
#define NETWORK_H

#include "user.h"
#include "post.h"

#include <vector>

class Network {
    public:
    //pre: None
    //post: initializes empty Network
    Network();

    //pre: None
    //post: returns user if id is valid, else return nullptr
    User* getUser(int id);
    //pre: None
    //post: adds user to network if not nullptr
    void addUser(User* user);
    
    //pre: None
    //post: adds both names to each other's friend lists if they exist
    int addConnection(std::string s1, std::string s2);

    //pre: None
    //post: deletes connection if names exist
    int deleteConnection(std::string s1, std::string s2);

    //pre: None
    //post: returns id of given user's name if it exists
    int getId(std::string name);
    
    //pre: None
    //post: returns number of users in network
    int numUsers();
    
    //pre: fname should be in special format
    //post: if c string is a valid .txt file, function will initialize users_ based on file's data
    void readUsers(const char* fname);
    
    //pre: None
    //post: writes network's data into file in a specific format
    void writeUsers(const char* fname);

    //pre: None
    //post: reads biography's data
    void readBiography(const char* fname);

    //pre: None
    //post: reads biography's data
    void writeBiography(const char* fname);

    //pre: None
    //post: reads biography's data
    void readPassword(const char* fname);

    //pre: None
    //post: writes all passwords of each user into file
    void writePassword(const char* fname);
    
    //pre: valid ids
    //post: returns vector containing shortest path between ids
    std::vector<int> shortestPath(int from, int to);
    
    //pre: valid id
    //post: if possible, returns shortest path of given distance and sets "to" to destination id;
    //      else sets "to" to -1 and reutrns empty vector
    std::vector<int> distanceUser(int from, int& to, int distance);
    
    //pre: valid ids
    //post: return true if friends, false otherwise
    std::vector<int> suggestFriends(int who, int& score);
    
    //pre: valid id
    //post: returns vector of ids of mutual friends with highest number of friends shared with user "who"
    std::vector<std::vector<int> > groups();

    //pre: valid post and valid user id
    //post: adds post to posts_
    void addPost(Post* post);

    //pre: valid id
    //post: returns all posts profile id has as vector
    std::vector<Post*> getPosts(int id);

    //pre: valid post
    //post: returns author name and message with number of likes as a string
    std::string postDisplayString(Post* post);

    //pre: valid id
    //post: returns howMany recent posts as a string 
    std::string getPostsString(int profileId, int howMany);

    //pre: none
    //post: stores posts into posts_ based on file input
    int readPosts(char* fname);

    //pre: none
    //post: writes all posts_ based on order of message_id into given file
    int writePosts(char* fname);

    private:
    //pre: None
    //post: returns true if given ids are friends, false otherwise
    bool checkFriend(int id, int other_id);

    //pre: None
    //post: recursively traverses stores subgroup of users in network through dfs
    void dfs(std::vector<int>& user_ids, std::vector<bool>& visited, const int& start_id);

    std::vector<User*> users_;
    std::vector<std::vector<Post*>> posts_;
};



#endif
