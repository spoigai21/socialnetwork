/********************************************************************************
** Form generated from reading UI file 'socialnetworkwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOCIALNETWORKWINDOW_H
#define UI_SOCIALNETWORKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SocialNetworkWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *usernameTextEdit;
    QLabel *namePromptLabel;
    QPushButton *loginButton;
    QLabel *profileLabel;
    QTableWidget *friendsTable;
    QLabel *recentPosts;
    QPushButton *returnButton;
    QTableWidget *friendSuggestions;
    QPushButton *addFriendButton;
    QLabel *friendsTitleLabel;
    QLabel *friendSuggestTitleLabel;
    QPushButton *addPostButton;
    QTextEdit *messagePost;
    QLabel *bioLabel;
    QTextEdit *loginBioTextEdit;
    QPushButton *editBioButton;
    QTextEdit *searchBarTextEdit;
    QPushButton *searchButton;
    QLabel *passwordPromptLabel;
    QTextEdit *passwordTextEdit;
    QPushButton *changeLoginInfoButton;
    QPushButton *saveLoginInfoButton;
    QPushButton *exitFromChangeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SocialNetworkWindow)
    {
        if (SocialNetworkWindow->objectName().isEmpty())
            SocialNetworkWindow->setObjectName("SocialNetworkWindow");
        SocialNetworkWindow->resize(975, 649);
        centralwidget = new QWidget(SocialNetworkWindow);
        centralwidget->setObjectName("centralwidget");
        usernameTextEdit = new QTextEdit(centralwidget);
        usernameTextEdit->setObjectName("usernameTextEdit");
        usernameTextEdit->setGeometry(QRect(240, 180, 291, 41));
        namePromptLabel = new QLabel(centralwidget);
        namePromptLabel->setObjectName("namePromptLabel");
        namePromptLabel->setGeometry(QRect(330, 140, 141, 41));
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(330, 310, 100, 32));
        profileLabel = new QLabel(centralwidget);
        profileLabel->setObjectName("profileLabel");
        profileLabel->setGeometry(QRect(350, 0, 221, 16));
        friendsTable = new QTableWidget(centralwidget);
        friendsTable->setObjectName("friendsTable");
        friendsTable->setGeometry(QRect(290, 150, 191, 192));
        recentPosts = new QLabel(centralwidget);
        recentPosts->setObjectName("recentPosts");
        recentPosts->setGeometry(QRect(10, 340, 901, 231));
        returnButton = new QPushButton(centralwidget);
        returnButton->setObjectName("returnButton");
        returnButton->setGeometry(QRect(690, 10, 100, 32));
        friendSuggestions = new QTableWidget(centralwidget);
        friendSuggestions->setObjectName("friendSuggestions");
        friendSuggestions->setGeometry(QRect(20, 50, 171, 281));
        addFriendButton = new QPushButton(centralwidget);
        addFriendButton->setObjectName("addFriendButton");
        addFriendButton->setGeometry(QRect(690, 50, 100, 32));
        friendsTitleLabel = new QLabel(centralwidget);
        friendsTitleLabel->setObjectName("friendsTitleLabel");
        friendsTitleLabel->setGeometry(QRect(350, 120, 58, 16));
        friendSuggestTitleLabel = new QLabel(centralwidget);
        friendSuggestTitleLabel->setObjectName("friendSuggestTitleLabel");
        friendSuggestTitleLabel->setGeometry(QRect(50, 20, 131, 16));
        addPostButton = new QPushButton(centralwidget);
        addPostButton->setObjectName("addPostButton");
        addPostButton->setGeometry(QRect(570, 130, 100, 32));
        messagePost = new QTextEdit(centralwidget);
        messagePost->setObjectName("messagePost");
        messagePost->setGeometry(QRect(520, 180, 191, 101));
        bioLabel = new QLabel(centralwidget);
        bioLabel->setObjectName("bioLabel");
        bioLabel->setGeometry(QRect(350, 30, 251, 51));
        loginBioTextEdit = new QTextEdit(centralwidget);
        loginBioTextEdit->setObjectName("loginBioTextEdit");
        loginBioTextEdit->setGeometry(QRect(260, 20, 281, 71));
        editBioButton = new QPushButton(centralwidget);
        editBioButton->setObjectName("editBioButton");
        editBioButton->setGeometry(QRect(550, 30, 100, 32));
        searchBarTextEdit = new QTextEdit(centralwidget);
        searchBarTextEdit->setObjectName("searchBarTextEdit");
        searchBarTextEdit->setGeometry(QRect(210, 550, 311, 31));
        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(530, 550, 100, 32));
        passwordPromptLabel = new QLabel(centralwidget);
        passwordPromptLabel->setObjectName("passwordPromptLabel");
        passwordPromptLabel->setGeometry(QRect(330, 230, 161, 16));
        passwordTextEdit = new QTextEdit(centralwidget);
        passwordTextEdit->setObjectName("passwordTextEdit");
        passwordTextEdit->setGeometry(QRect(240, 260, 291, 41));
        changeLoginInfoButton = new QPushButton(centralwidget);
        changeLoginInfoButton->setObjectName("changeLoginInfoButton");
        changeLoginInfoButton->setGeometry(QRect(760, 160, 151, 71));
        saveLoginInfoButton = new QPushButton(centralwidget);
        saveLoginInfoButton->setObjectName("saveLoginInfoButton");
        saveLoginInfoButton->setGeometry(QRect(580, 180, 100, 32));
        exitFromChangeButton = new QPushButton(centralwidget);
        exitFromChangeButton->setObjectName("exitFromChangeButton");
        exitFromChangeButton->setGeometry(QRect(580, 230, 100, 32));
        SocialNetworkWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SocialNetworkWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 975, 24));
        SocialNetworkWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SocialNetworkWindow);
        statusbar->setObjectName("statusbar");
        SocialNetworkWindow->setStatusBar(statusbar);

        retranslateUi(SocialNetworkWindow);

        QMetaObject::connectSlotsByName(SocialNetworkWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SocialNetworkWindow)
    {
        SocialNetworkWindow->setWindowTitle(QCoreApplication::translate("SocialNetworkWindow", "SocialNetworkWindow", nullptr));
        usernameTextEdit->setHtml(QCoreApplication::translate("SocialNetworkWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        namePromptLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "Enter Your Name:", nullptr));
        loginButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Login", nullptr));
        profileLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "My Profile", nullptr));
        recentPosts->setText(QString());
        returnButton->setText(QCoreApplication::translate("SocialNetworkWindow", "MyProfile", nullptr));
        addFriendButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Add Friend", nullptr));
        friendsTitleLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "Friends", nullptr));
        friendSuggestTitleLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "Friend Suggestions", nullptr));
        addPostButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Add Post", nullptr));
        bioLabel->setText(QString());
        editBioButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Save Bio", nullptr));
        searchBarTextEdit->setHtml(QCoreApplication::translate("SocialNetworkWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Search...</p></body></html>", nullptr));
        searchButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Find", nullptr));
        passwordPromptLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "Enter Your Password:", nullptr));
        changeLoginInfoButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Change Login Info", nullptr));
        saveLoginInfoButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Save", nullptr));
        exitFromChangeButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SocialNetworkWindow: public Ui_SocialNetworkWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCIALNETWORKWINDOW_H
