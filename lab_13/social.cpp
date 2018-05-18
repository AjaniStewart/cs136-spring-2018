#include <string>
#include <iostream>

using namespace std;
class Profile
{
private:
    string display_name;
    string user_name;

public:
    Profile(string usrn, string dispname)
        :user_name(usrn), display_name(dispname) { }
    Profile() {user_name = ""; display_name = "";}

    string getUsername() {return user_name;}
    string getFullName() {return display_name + " (@" + user_name + ")";}
    void setDisplayName(string dn) {display_name = dn;}
  
};


int main() {
    Profile p1("marco", "Marco");    
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");    
    cout << p2.getUsername() << endl; // tarma1
    cout << p2.getFullName() << endl; // Tarma Roving (@tarma1)
}