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
    bool following[MAX_USERS][MAX_USERS];
    int findID(string name)
    {
        for (int i = 0; i < numUsers; i++)
            if (profiles[i].getUsername() == name)
                return i;
        return -1;
    }

public:
    Network() 
    {
        //initalize network
        numUsers = 0;
        for (int i = 0; i < MAX_USERS; ++i)
            for (int j = 0; j < MAX_USERS; ++j)
                following[i][j] = false;
    }
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
    bool userInNetwork(string user)
    {
        for (int i = 0; i < numUsers; ++i)
            if (profiles[i].getUsername() == user)
                return true;
        return false;
    }
    bool follow(string usr1, string usr2)
    {
        if (!(userInNetwork(usr1) && userInNetwork(usr2))) return false;
        int u1 = findID(usr1);
        int u2 = findID(usr2);
        following[u1][u2] = true;
        return true;
    }

    void printDot()
    {
        cout << "digraph {\n";
        for (int i = 0; i < numUsers; ++i)
        {
            cout << "\"@" << profiles[i].getUsername() << "\"\n";
        }
        for (int i = 0; i < MAX_USERS; ++i)
            for (int j = 0; j < MAX_USERS; ++j)
            {
                if (following[i][j])
                {
                    cout << "\"@" << profiles[i].getUsername() << "\" ";
                    cout << "-> ";
                    cout << "\"@" << profiles[j].getUsername() << "\"\n";
                }
            }
        cout << "}\n";
    }
};


int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}