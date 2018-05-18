#include <string>
#include <iostream>
#include <cctype>

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

class Network
{
private:
    static const int MAX_USERS = 20;
    int numUsers;
    Profile profiles[MAX_USERS];
    int findID(string name)
    {
        for (int i = 0; i < numUsers; i++)
            if (profiles[i].getUsername() == name)
                return i;
        return -1;
    }

public:
    Network() {numUsers = 0;}
    bool addUser(string usrn, string dspn)
    {
        //check if profiles is full
        if (numUsers == MAX_USERS) return false;
        //check if the username is valid
        for (int i = 0; i < usrn.size(); ++i)
            if (!isalnum(usrn[i]))
                return false;
        //check if the name is taken
        for (int i = 0; i < numUsers; ++i)
            if (profiles[i].getUsername() == usrn)
                return false;

        Profile newProfile(usrn,dspn);
        profiles[numUsers] = newProfile;
        numUsers++;
        return true;
    }
};



int main() {

   Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)
  
  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i), 
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}