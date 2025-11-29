#ifndef POST_H
#define POST_H

#include <string>

class Post {
    public:
        //pre: None
        //post: default constructor for Post
        Post();

        //pre: valid ids
        //post: initializes private feels with given parameters
        Post(int profileId, int authorId, std::string message, int likes);
        
        //pre: None
        //post: returns message id
        int getMessageId();

        //pre: None
        //post: sets message id to given id
        void setMessageId(int id);

        //pre: None
        //post: returns profile id
        int getProfileId();

        //pre: None
        //post: returns author id
        int getAuthorId();

        //pre: None
        //post: returns message 
        std::string getMessage();

        //pre: None
        //post: returns likes
        int getLikes();

        //pre: None
        //post: base class returns empty string
        virtual std::string getURL();

        //pre: None
        //post: returns message with number of likes as a string
        virtual std::string toString();
        
    private:
        int messageId_;
        int profileId_;
        int authorId_;
        std::string message_;
        int likes_;
};

class LinkPost : public Post {
    public:
    //pre: None
    //post: intializes values to default
    LinkPost();

    //pre: valid ids and url
    //post: initializes values to given values
    LinkPost(int profileId, int authorId, std::string message, int likes, std::string url);

    //pre: None
    //post: returns valid Id
    std::string getURL();

    //pre: None
    //post: returns message with url and number of likes as a string
    std::string toString();

    private:
    std::string url_;
};


#endif