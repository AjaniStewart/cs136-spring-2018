#include <string>
#include <iostream>
#include <cctype>

using namespace std;

struct Post
{
    string username;
    string messages;
};

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
    static const int MAX_POSTS = 100;
    int numPosts;
    Post posts[MAX_POSTS];
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

    bool userFollows(int uID1,int uID2)
    {
        return following[uID1][uID2];
    }

    bool writePost(string usrn, string msg)
    {
        if (!(userInNetwork(usrn)) || numPosts == MAX_POSTS) return false;
        Post newPost = {usrn, msg};
        posts[numPosts] = newPost;
        numPosts++;
        return true;
    }

    bool printTimeline(string usrn)
    {
        if (!(userInNetwork(usrn))) return false;
        int uID = findID(usrn);
        for (int i = numPosts - 1; i >= 0; --i)
        {
            if (userFollows(uID,findID(posts[i].username)) || posts[i].username == usrn)
            {
                cout << profiles[findID(posts[i].username)].getFullName() << ": ";
                cout << posts[i].messages << "\n";
            }
        }
        return true;
    }
};


int main() {
  Network nw;
  // add three users
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");
   
  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}
