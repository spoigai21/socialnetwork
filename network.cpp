#include "network.h"

#include <sstream>
#include <fstream>
#include <iostream>
#include <queue>
#include <map>

Network::Network() { 
    users_ = {}; 
    posts_ = {};
}


User* Network::getUser(int id) {
    for (User *user : users_)
        if (user->getId() == id) return user;
    return nullptr;
}

void Network::addUser(User* user) {
    // add if user is not nullptr
    if (user == nullptr) return;
    users_.push_back(user);
    posts_.push_back({});
}

int Network::addConnection(std::string s1, std::string s2) {
    // check if users exist
    User* friendOne = nullptr; 
    User* friendTwo = nullptr;

    // loop to find users based on name
    for (auto user : users_) {
        if (user->getName() == s1) {
            friendOne = user;
        } else if (user->getName() == s2) {
            friendTwo = user;
        }
    }

    // add friend connection if they exist
    if (friendOne != nullptr && friendTwo != nullptr) {
        friendOne->addFriend(friendTwo->getId());
        friendTwo->addFriend(friendOne->getId());
        return 0;
    }

    // -1 is returned if one or both of users do not exist in network
    return -1;
}


int Network::deleteConnection(std::string s1, std::string s2) {
    // check if users exist
    User* friendOne = nullptr; 
    User* friendTwo = nullptr;

    // loop to find users based on name
    for (auto user : users_) {
        if (user->getName() == s1) {
            friendOne = user;
        } else if (user->getName() == s2) {
            friendTwo = user;
        }
    }

    // delete friend connection if they exist
    if (friendOne != nullptr && friendTwo != nullptr) {
        friendOne->deleteFriend(friendTwo->getId());
        friendTwo->deleteFriend(friendOne->getId());
        return 0;
    }
    
    return -1;
}


int Network::getId(std::string name) {
    for (auto user : users_)
        if (user->getName() == name) return user->getId();
    return -1;
}

int Network::numUsers() { return users_.size(); }

void Network::readUsers(const char* fname) {
    std::ifstream input(fname);

    //check if file is open; return if invalid
    if (!input.is_open()) {
        std::cerr << "Error: cannot open file" << std::endl; 
        return;
    }

    // for storing each line in file
    std::string line = "";
    // first line has number of users in file
    getline(input, line);
    // use stoi to convert string to int
    int n = std::stoi(line);
    //create temp variable holders for user's data
    int id, year, zip;
    std::string name;
    std::set<int> friends;
    // stringstream object which is used to read lines
    std::stringstream ss;

    //iterate through rest of file
    for(int counter = 0; counter < n; ++counter) {
        //first line contains id
        getline(input, line);
        id = std::stoi(line);

        //second line contains name
        getline(input, line);
        // do substr(1) to skip over tab
        name = line.substr(1);

        //third line contains year
        getline(input, line);
        ss.str(line);
        ss>>year;
        ss.clear();

        //fourth line contains zip
        getline(input, line);
        ss.str(line);
        ss>>zip;
        ss.clear();

        //fifth line contains friends ids
        getline(input, line);
        ss.str(line);
        int val = 0;
        while(ss >> val) {
            friends.insert(val);
        }
        // after getting data, insert User into users_
        addUser(new User(id, name, year, zip, friends));
        friends.clear();
    }

    ss.clear();
    // close file
    input.close();
}

void Network::writeUsers(const char* fname) {
    std::ofstream output(fname);

    //check if file is open; return if invalid
    if (!output.is_open()) {
        std::cerr << "Error: cannot open file" << std::endl; 
        return;
    }

    output << numUsers() << "\n";
    for (User *u : users_) {
        output << u->getId() << "\n";
        //for remaining put tab after data
        output << "\t" << u->getName() << "\n";
        output << "\t" << u->getYear() << "\n";
        output << "\t" << u->getZip() << "\n";
        output << "\t";

        for (const int& id : u->getFriends()) {
            output << id << " ";
        }
        output << "\n";
    }

    // close file
    output.close();

    //write into biography.txt
    writeBiography("biography.txt");
}

void Network::readBiography(const char *fname) {
    std::ifstream input(fname);

    if (!input.is_open()) {
        std::cerr << "Error: cannot open file" << std::endl;
        return;
    }
    std::string line;
    getline(input, line);
    int num = std::stoi(line);

    int id = 0;
    std::string bio;

    for (int counter = 0; counter < num; counter++) {
        //store id
        getline(input, line);
        if(line.empty()) break;

        id = std::stoi(line);
        //get bio
        getline(input, line);
        //skip over tab
        if (line.empty()) {
            bio = "";
        } else {
            bio = line.substr(1);
        }
        getUser(id)->setBiography(bio);

        //ignore next
        input.ignore();

    }

    input.close();

}



void Network::writeBiography(const char* fname) {
    std::ofstream output(fname);

    //check if file is open; return if invalid
    if (!output.is_open()) {
        std::cerr << "Error: cannot open file" << std::endl;
        return;
    }

    output << numUsers() << "\n";

    for (User *u : users_) {
        output << u->getId() << "\n";
        //for remaining put tab after data
        output << "\t" << u->getBiography() << "\n";
        output << "\n";
    }

    output.close();

}

void Network::readPassword(const char *fname) {
    std::ifstream input(fname);

    if (!input.is_open()) {
        std::cerr << "Error: cannot open file" << std::endl;
        return;
    }

    std::string line;
    getline(input, line);
    int num = std::stoi(line);

    int id = 0;
    std::string password;

    for (int counter = 0; counter < num; counter++) {
        //store id
        getline(input, line);
        if(line.empty()) break;

        id = std::stoi(line);
        //input >> id;

        getline(input, line);
        //skip over tab
        if (line.empty()) {
            //invalid password since it is empty
            password="password" + std::to_string(id);
        } else {
            password = line.substr(1);
        }
        getUser(id)->setPassword(password);

        //ignore next
        input.ignore();

    }

    input.close();

}

void Network::writePassword(const char *fname) {
    std::ofstream output(fname);

    //check if file is open; return if invalid
    if (!output.is_open()) {
        std::cerr << "Error: cannot open file" << std::endl;
        return;
    }

    output << numUsers() << "\n";

    for (User *u : users_) {
        output << u->getId() << "\n";
        //for remaining put tab after data
        output << "\t" << u->getPassword() << "\n";
        output << "\n";
    }

    output.close();

}


std::vector<int> Network::shortestPath(int from, int to) {

    //if invalid ids, return empty vector
    if (getUser(from) == nullptr || getUser(to) == nullptr) { return {}; }

    std::queue<int> nextUserIDs;
    std::vector<bool> visited(numUsers(), false);
    //list of previous vectors 
    std::vector<int> prev(numUsers(), -1);

    nextUserIDs.push(from);
    visited[from] = true;

    while(!nextUserIDs.empty()) {
        int userID = nextUserIDs.front();
        nextUserIDs.pop();
 
        const std::set<int>& f = getUser(userID)->getFriends();
        if (f.empty()) continue;
        
        for (const auto& i : f) {
            if(!visited[i]) {
                visited[i] = true;
                prev[i] = userID;
                nextUserIDs.push(i);
            }
        }
    }
        //if final position not visited, return empty vector
        if (!visited[to]) return {};

        std::vector<int> path;
        int curr = to;

        //trace back to curr from to, storing path in vector
        while (curr != -1) {
            path.push_back(curr);
            curr = prev[curr];
        }
        //reverse path to get "from" to "to" order
        reverse(path.begin(), path.end());
        return path;
}


std::vector<int> Network::distanceUser(int from, int& to, int distance) {
    if(getUser(from) == nullptr) {
        to = -1;
        return {};
    }

    std::queue<int> nextUserIDs;
    std::vector<bool> visited(numUsers(), false);
    std::vector<int> prev(numUsers(), -1);
    //to store distances
    std::vector<int> dist(numUsers(), -1);
    
    nextUserIDs.push(from);
    visited[from] = true;
    dist[from] = 0;

    while(!nextUserIDs.empty()) {
        //get current id and remove from queue
        int userID = nextUserIDs.front();

        //if id that meets distance is found, terminate loop
        if(dist[userID] == distance) break;
        nextUserIDs.pop();
 
        const std::set<int>& f = getUser(userID)->getFriends();
        if (f.empty()) continue;
        
        for (const auto& i : f) {
            if(!visited[i]) {
                //if unvisited mark as visited and store ids and distances in vectors
                visited[i] = true;
                prev[i] = userID;
                dist[i] = 1 + dist[userID];
                nextUserIDs.push(i);
            }
        }
    }
        to = -1;

        for (int i = 0; i < numUsers(); i++) {
            //check for distance and set "to" if possible
            if (dist[i] == distance) {
                to = i;
                break;
            }
        }

        if(to == -1) return {};
        
        //trace back to find path
        int curr = to;
        std::vector<int> path;

        while (curr != -1) {
            path.push_back(curr);
            curr = prev[curr];
        }

        reverse(path.begin(), path.end());
        return path;
}


//helper function for suggestFriends()
bool Network::checkFriend(int id, int other_id) {
    //return true if other id is a friend with id, otherwise false
    User* u = getUser(id);
    if (u == nullptr) return false;

    const std::set<int>& f = u->getFriends();
    return f.count(other_id) > 0;
}

std::vector<int> Network::suggestFriends(int who, int& score) {
    User* person = getUser(who);
    if(person == nullptr) {
        score = 0;
        return {};
    }

    //ids->frequency (num of mutual friends)
    std::map<int, int> mutual_friends;
    for (User* u : users_) {
        if (u == person) { continue; }

        if (!checkFriend(who, u->getId())) {
            // check if mutuals and add to map/raise score if true
            const std::set<int>& f = u->getFriends();
            //frequency
            int s = 0;
            for (const auto& i : f) {
                if(checkFriend(i, who)) s += 1;
            }
            if (s > 0) mutual_friends.insert(std::make_pair(u->getId(), s));
        }


    }

    if (mutual_friends.empty()) { 
        score = 0;
        return {};
    }

    int max_score = 0;

    for (const auto& p : mutual_friends) {
        if(p.second > max_score) {
            max_score = p.second;
        }
    }

    score = max_score;

    std::vector<int> suggested_friends;

    for (const auto& p : mutual_friends) {
        if(p.second == max_score) {
            suggested_friends.push_back(p.first);
        }
    }
    return suggested_friends;
        
}

//helper function for groups()
void Network::dfs(std::vector<int>& user_ids, std::vector<bool>& visited, const int& start_id) {
    if(visited[start_id]) return;

    //set visited to true and add to group
    visited[start_id] = true;
    user_ids.push_back(start_id);

    const std::set<int>& f = getUser(start_id) -> getFriends();
    //call dfs on friends
    for (const auto& i : f) dfs(user_ids, visited, i);
    
}

std::vector<std::vector<int>> Network::groups() {
    std::vector<std::vector<int>> all_groups;
    std::vector<int> group;
    std::vector<bool> visited(numUsers(), false);

    for (User* u : users_ ) {
        int id = u->getId();

        if (!visited[id]) {
            //run dfs starting from unvisited id
            dfs(group, visited, id);
            // if subgroup is not empty, add to all_groups
            if (!group.empty()) {
                all_groups.push_back(group);
                group.clear();
            }
        }   
    }
    return all_groups;
}


void Network::addPost(Post* post) {
    if(post == nullptr) return;
    //check if user Id is valid
    int user_id = post->getProfileId();
    if (getUser(user_id) == nullptr) return;    
    
    //next message id is the number of posts
    int next_message_id = 0;

    for (auto list : posts_) {
        next_message_id += list.size();
    }

    //set post and push to vector
    post->setMessageId(next_message_id);
    posts_[user_id].push_back(post);
}

std::vector<Post*> Network::getPosts(int id) {
    //check if id is valid
    if (getUser(id) == nullptr) return {};
    return posts_[id];
}

std::string Network::postDisplayString(Post* post) {
    if (post == nullptr) return "";

    //get author's name
    User* u = getUser(post->getAuthorId());

    if(u == nullptr) return "";

    //return in specified format
    return u->getName() + " wrote: " + post->toString();
}

std::string Network::getPostsString(int profileId, int howMany) {
    if (howMany <= 0) return "";
    if(getUser(profileId) == nullptr) return "";
    if(posts_[profileId].empty()) return "";

    std::string res = "";
    int count = 0;
    Post* p;

    for (int i = posts_[profileId].size() - 1; i >= 0; --i) {
        //store post
        p = posts_[profileId][i];
        //store string into res
        res += postDisplayString(p);
        count += 1;
        //if reached howMany or no more posts left return
        if(count >= howMany || i == 0) return res;
        //separate posts
        res += "\n\n";
    }

    p = nullptr;
    // if profile id has no posts
    return "";
}

int Network::readPosts(char* fname) {
    //return -1 if unable to open file
    std::ifstream input(fname);
    if(!input.is_open()) return -1;
    
   std::string line = "";
    // first line has number of users in file
    getline(input, line);
    // use stoi to convert string to int
    int n = std::stoi(line);
    //create temp variable holders for user's data
    int message_id, profile_id, author_id, likes;
    std::string message_text;
    std::string url;
    std::stringstream ss;

    Post* p;

    //iterate through rest of file
    for(int counter = 0; counter < n; ++counter) {
        //first line contains message id
        input >> message_id;
        input.ignore();

        //second line contains message text
        getline(input, line);
        // do substr(1) to skip over tab
        if(!line.empty() && line[0] == '\t') {
            message_text = line.substr(1);
        } else {
            message_text = line;
        }

        //third line contains profile id
        getline(input, line);
        ss.str(line);
        ss>>profile_id;
        ss.clear();

        //fourth line contains authorid
        getline(input, line);
        ss.str(line);
        ss>>author_id;
        ss.clear();

        //fifth line contains likes
        getline(input, line);
        ss.str(line);
        ss>>likes;
        ss.clear();

        //sixth line contains friends url
        getline(input, line);
        url = line;

        //if url empty, then create Post, else LinkPost
        if (url.empty()) {
            p = new Post(profile_id, author_id, message_text, likes);
        } else {
            url = url.substr(1);
            p = new LinkPost(profile_id, author_id, message_text, likes, url);
        }

        //set message id since no field in constructor for it
        p->setMessageId(message_id);
        posts_[profile_id].push_back(p);
    }

    // close file
    input.close();
    return n;
}

//helper function for writePosts()
bool comparison(Post* left, Post* right) { return left->getMessageId() < right->getMessageId(); }

int Network::writePosts(char* fname) {
    //return -1 if unable to open file
    std::ofstream output(fname);
    if(!output.is_open()) return -1;

    //create single vector for all posts
    std::vector<Post*> all_posts;

    for(auto& list : posts_) {
        for (Post* p : list) {
            all_posts.push_back(p);
        }
    }

    //sort in increasing order of message ids 
    sort(all_posts.begin(), all_posts.end(), comparison);
    
    int n = all_posts.size();
    output << n << "\n";


    for (int count = 0; count < n; count++) {
        Post* p = all_posts[count];
        output << p->getMessageId() << "\n";
        output << "\t" << p->getMessage() << "\n";
        output << "\t" << p->getProfileId() << "\n";
        output << "\t" << p->getAuthorId() << "\n";
        output << "\t" << p->getLikes() << "\n";
        if (p->getURL() != "") {
            output << "\t" << p->getURL() << "\n";
        } else {
            output << "\n";
        }
    }

    output.close();
    return n;
}
