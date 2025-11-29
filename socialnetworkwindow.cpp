#include "socialnetworkwindow.h"
#include "ui_socialnetworkwindow.h"
#include <iostream>
#include <sstream>

SocialNetworkWindow::SocialNetworkWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SocialNetworkWindow)
{
    ui->setupUi(this);

    //intialize network with .txt files
    mySocialNetwork.readUsers("users.txt");
    mySocialNetwork.readPosts("posts.txt");
    mySocialNetwork.readBiography("biography.txt");
    mySocialNetwork.readPassword("password.txt");

    //connects buttons and tables to functions
    connect(ui->loginButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::loginUser);

    connect(ui->friendsTable,
            &QTableWidget::cellClicked,
            this,
            &SocialNetworkWindow::getFriendProfile);

    connect(ui->friendSuggestions,
            &QTableWidget::cellClicked,
            this,
            &SocialNetworkWindow::getSuggestedProfile);

    connect(ui->returnButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::exitToLogin);

    connect(ui->addFriendButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::addFriend);

    connect(ui->addPostButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::addPost);

    connect(ui->editBioButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::editBio);

    connect(ui->searchButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::search);

    connect(ui->changeLoginInfoButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::changeLoginInfo);

    connect(ui->saveLoginInfoButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::saveLoginInfo);

    connect(ui->exitFromChangeButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::exitFromChangeLogIn);

    //for the login screen
    ui->loginButton->show();
    ui->namePromptLabel->show();
    ui->usernameTextEdit->show();
    ui->passwordPromptLabel->show();
    ui->passwordTextEdit->show();
    ui->profileLabel->hide();
    ui->friendsTable->hide();
    ui->recentPosts->hide();
    ui->returnButton->hide();
    ui->friendSuggestions->hide();
    ui->addFriendButton->hide();
    ui->friendsTitleLabel->hide();
    ui->friendSuggestTitleLabel->hide();
    ui->addPostButton->hide();
    ui->messagePost->hide();
    ui->bioLabel->hide();
    ui->loginBioTextEdit->hide();
    ui->editBioButton->hide();
    ui->searchBarTextEdit->hide();
    ui->searchButton->hide();
    ui->changeLoginInfoButton->hide();
    ui->exitFromChangeButton->hide();
    ui->saveLoginInfoButton->hide();

}

SocialNetworkWindow::~SocialNetworkWindow()
{
    delete ui;
}

void SocialNetworkWindow::loginUser() {

    std::string username = ui->usernameTextEdit->toPlainText().toStdString();
    std::string password = ui->passwordTextEdit->toPlainText().toStdString();
    //check if valid username
    int id = mySocialNetwork.getId(username);

    if (id != -1 && password == mySocialNetwork.getUser(id)->getPassword()) {
        ui->usernameTextEdit->hide();
        ui->loginButton->hide();
        ui->namePromptLabel->hide();
        ui->passwordPromptLabel->hide();
        ui->passwordTextEdit->hide();
        currUser = loggedInUser = mySocialNetwork.getUser(id);
        SocialNetworkWindow::displayProfilePage();

    } else {
        //set usernameTextEdit and passwordTextEdit to empty string
        ui->usernameTextEdit->clear();
        ui->passwordTextEdit->clear();
    }


}

// button that returns to my Profile page
void SocialNetworkWindow::exitToLogin() {
    ui->returnButton->hide();
    currUser = loggedInUser;
    displayProfilePage();
}


void SocialNetworkWindow::displayProfilePage() {
    if (currUser == loggedInUser) {
        ui->returnButton->hide();
        currUser = loggedInUser;
        ui->changeLoginInfoButton->show();
        ui->bioLabel->hide();
        ui->profileLabel->setText(QString::fromStdString("My Profile"));
        ui->loginBioTextEdit->setText(QString::fromStdString(currUser->getBiography()));
        ui->loginBioTextEdit->show();
        ui->editBioButton->show();
        //show friendSuggestions
        ui->friendSuggestions->setColumnCount(1);
        int loggedIn_id = currUser->getId();
        int score = -1;
        std::vector<int> suggestions = mySocialNetwork.suggestFriends(loggedIn_id, score);
        if (score != 0) {
            //fills table if there are friend suggestions
            ui->friendSuggestions->setRowCount(suggestions.size());
            ui->friendSuggestions->setColumnCount(1);
            int row = 0;
            QTableWidgetItem* n;

            for (int f : suggestions) {
                n = new QTableWidgetItem(QString::fromStdString(mySocialNetwork.getUser(f)->getName()));
                ui->friendSuggestions->setItem(row, 0, n);
                row += 1;
            }

            //show table
            ui->friendSuggestions->show();
            ui->friendSuggestTitleLabel->show();
            ui->addFriendButton->hide();
        }
    } else {
        //don't show friend suggestions if on another profile
        std::string title = currUser->getName() + "'s Profile";
        ui->profileLabel->setText(QString::fromStdString(title));
        ui->returnButton->show();
        ui->addFriendButton->show();
        ui->friendSuggestions->hide();
        ui->loginBioTextEdit->hide();
        ui->bioLabel->show();
        ui->editBioButton->hide();
        ui->friendSuggestTitleLabel->hide();
        ui->changeLoginInfoButton->hide();
    }

    ui->addPostButton->show();
    ui->messagePost->show();
    ui->searchBarTextEdit->show();
    ui->searchButton->show();


    ui->profileLabel->show();


    //display friends
    ui->friendsTitleLabel->show();
    ui->friendsTable->setColumnCount(1);
    int n = currUser->getFriends().size();
    ui->friendsTable->setRowCount(n);
    ui->bioLabel->show();
    ui->bioLabel->setText(QString::fromStdString("Bio:\n" + currUser->getBiography()));

    int row = 0;
    QTableWidgetItem* name;
    for (const int& f : currUser->getFriends()) {
        name = new QTableWidgetItem(QString::fromStdString(mySocialNetwork.getUser(f)->getName()));
        ui->friendsTable->setItem(row, 0, name);
        row += 1;
    }
    ui->friendsTable->show();

    //display posts
    int id = currUser->getId();
    std::string recent = mySocialNetwork.getPostsString(id, 5);
    ui->recentPosts->setText(QString::fromStdString(recent));
    ui->recentPosts->show();

}


void SocialNetworkWindow::getFriendProfile(int r, int c) {
    QTableWidgetItem* name = ui->friendsTable->item(r, c);
    std::string n = name->text().toStdString();
    int id = mySocialNetwork.getId(n);
    //sets currUser to this profile
    currUser = mySocialNetwork.getUser(id);
    //refresh page
    SocialNetworkWindow::displayProfilePage();
}


void SocialNetworkWindow::getSuggestedProfile(int r, int c) {
    QTableWidgetItem* name = ui->friendSuggestions->item(r, c);
    std::string n = name->text().toStdString();
    int id = mySocialNetwork.getId(n);
    //sets currUser to this profile
    currUser = mySocialNetwork.getUser(id);
    //refresh page
    SocialNetworkWindow::displayProfilePage();
}

void SocialNetworkWindow::addFriend() {
    if (currUser == loggedInUser) return;
    //add connection
    mySocialNetwork.addConnection(loggedInUser->getName(), currUser->getName());
    //write changes into users.txt
    mySocialNetwork.writeUsers("users.txt");
    //refresh page
    displayProfilePage();
}

void SocialNetworkWindow::addPost() {
    int author_id = loggedInUser->getId();
    int profile_id = currUser->getId();
    std::string message = ui->messagePost->toPlainText().toStdString();
    if (message != "") {
        //create post
        Post* p = new Post(profile_id, author_id, message, 0);
        mySocialNetwork.addPost(p);
        //write changes into posts.txt
        mySocialNetwork.writePosts("posts.txt");
    }
    ui->messagePost->clear();
    //refresh page
    displayProfilePage();
}

void SocialNetworkWindow::editBio() {
    std::string bio = ui->loginBioTextEdit->toPlainText().toStdString();
    currUser->setBiography(bio);
    mySocialNetwork.writeBiography("biography.txt");
    displayProfilePage();
}

void SocialNetworkWindow::search() {
    std::string s = ui->searchBarTextEdit->toPlainText().toStdString();
    int id = mySocialNetwork.getId(s);

    if (id != -1) {
        currUser = mySocialNetwork.getUser(id);
        ui->searchBarTextEdit->setText(QString::fromStdString("Search..."));
    } else {
        ui->searchBarTextEdit->setText(QString::fromStdString("Could not find user"));
    }

    displayProfilePage();
}

void SocialNetworkWindow::changeLoginInfo() {
    ui->profileLabel->hide();
    ui->addPostButton->hide();
    ui->messagePost->hide();
    ui->searchBarTextEdit->hide();
    ui->searchButton->hide();
    ui->friendsTable->hide();
    ui->friendsTitleLabel->hide();
    ui->friendSuggestions->hide();
    ui->friendSuggestTitleLabel->hide();
    ui->bioLabel->hide();
    ui->loginBioTextEdit->hide();
    ui->editBioButton->hide();
    ui->profileLabel->hide();
    ui->recentPosts->hide();

    //now hide the button
    ui->changeLoginInfoButton->hide();

    //reuse password and username login again
    ui->saveLoginInfoButton->show();
    ui->exitFromChangeButton->show();
    std::string name = currUser->getName();
    std::string password = currUser->getPassword();
    ui->namePromptLabel->show();
    ui->usernameTextEdit->setText(QString::fromStdString(name));
    ui->usernameTextEdit->show();
    ui->passwordPromptLabel->show();
    ui->passwordTextEdit->setText(QString::fromStdString(password));
    ui->passwordTextEdit->show();


}

void SocialNetworkWindow::saveLoginInfo() {
    std::string name = ui->usernameTextEdit->toPlainText().toStdString();
    std::string password = ui->passwordTextEdit->toPlainText().toStdString();

    //check if name is valid
    if(name.empty()) {
        ui->usernameTextEdit->setText(QString::fromStdString(currUser->getName()));
    } else {
        std::stringstream ss(name);
        std::string first;
        std::string last;
        ss >> first >> last;
        if (first.empty() || last.empty()) {
            ui->usernameTextEdit->setText(QString::fromStdString(currUser->getName()));
        } else {
            currUser->setName(name);
            mySocialNetwork.writeUsers("users.txt");
        }
    }

    //check if password is valid
    if(password.empty()) {
        ui->passwordTextEdit->setText(QString::fromStdString(currUser->getPassword()));
    } else {
        currUser->setPassword(password);
        mySocialNetwork.writePassword("password.txt");
    }

}

void SocialNetworkWindow::exitFromChangeLogIn() {
    ui->profileLabel->show();
    ui->addPostButton->show();
    ui->messagePost->show();
    ui->searchBarTextEdit->show();
    ui->searchButton->show();
    ui->friendsTable->show();
    ui->friendsTitleLabel->show();
    ui->friendSuggestions->show();
    ui->friendSuggestTitleLabel->show();
    ui->bioLabel->show();
    ui->loginBioTextEdit->show();
    ui->editBioButton->show();
    ui->profileLabel->show();
    ui->recentPosts->show();

    ui->changeLoginInfoButton->show();


    ui->saveLoginInfoButton->hide();
    ui->exitFromChangeButton->hide();
    ui->namePromptLabel->hide();
    ui->usernameTextEdit->hide();
    ui->passwordPromptLabel->hide();
    ui->passwordTextEdit->hide();

    displayProfilePage();

}



