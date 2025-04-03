#include "Member.h"

Member::Member() {
    name = "";
    contact = "";
    memberID = "";
}

Member::Member(string name, string contact, string memberID) {
    this->name = name;
    this->contact = contact;
    this->memberID = memberID;
}

string Member::getName() const {
    return name;
}

string Member::getContact() const {
    return contact;
}

string Member::getMemberID() const {
    return memberID;
}

void Member::setName(string name) {
    this->name = name;
}

void Member::setContact(string contact) {
    this->contact = contact;
}

void Member::setMemberID(string memberID) {
    this->memberID = memberID;
}

void Member::displayMember() const {
    cout << "Name: " << name << ", Contact: " << contact << ", Member ID: " << memberID << endl;
}
