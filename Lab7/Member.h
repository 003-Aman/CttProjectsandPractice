#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>
using namespace std;

class Member {
private:
    string name;
    string contact;
    string memberID;

public:
    Member();
    Member(string name, string contact, string memberID);

    string getName() const;
    string getContact() const;
    string getMemberID() const;
    void setName(string name);
    void setContact(string contact);
    void setMemberID(string memberID);
    void displayMember() const;
};

#endif
