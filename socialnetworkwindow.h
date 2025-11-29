#ifndef SOCIALNETWORKWINDOW_H
#define SOCIALNETWORKWINDOW_H

#include <QMainWindow>
#include "network.h"
#include "user.h"
#include "post.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class SocialNetworkWindow;
}
QT_END_NAMESPACE

class SocialNetworkWindow : public QMainWindow
{
    Q_OBJECT

public:
    //pre: None
    //post: initializes network and maps widgets
    SocialNetworkWindow(QWidget *parent = nullptr);

    ~SocialNetworkWindow();

    //pre: None
    //post: Exit to profile button maps to this function
    //      which changes currUser to loggedInUser
    void exitToLogin();

    //pre: None
    //post: Checks if user entered valid name and logins in
    void loginUser();

    //pre: None
    //post: Displays profile page with friends, suggestions, and posts
    void displayProfilePage();

    //pre: None
    //post: Goes to this friend's profile if cell in friends table is clicked
    void getFriendProfile(int r, int c);

    //pre: None
    //post: Adds connection between logged in user and friend
    void addFriend();

    //pre: None
    //post: Goes to suggested friend's profile if cell in suggestions table is clicked
    void getSuggestedProfile(int r, int c);

    //pre: None
    //post: When user clicks add post button, runs this function which
    //      adds to post to currUser profile
    void addPost();

    //pre: None
    //post: edits biography and updates .txt file
    void editBio();

    //pre: None
    //post: searches for user by name if valid
    void search();

    //pre: None
    //post: allows user to change their login info
    void changeLoginInfo();

    //pre: None
    //post: saves login info if password or usernae are valid
    void saveLoginInfo();

    //pre: None
    //post: exits from changing login info screen
    void exitFromChangeLogIn();

private:
    Ui::SocialNetworkWindow *ui;
    Network mySocialNetwork;
    User* currUser;
    User* loggedInUser;

};
#endif // SOCIALNETWORKWINDOW_H
