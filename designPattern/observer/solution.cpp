#include <iostream>
#include <list>
using namespace std;
class Isubscriber
{
public:
    virtual void notify(string msg) = 0;
};

class User : public Isubscriber
{
private:
    int userId;

public:
    User(int userId)
    {
        this->userId = userId;
    }
    void notify(string msg)
    {
        cout << "user" << userId << "recieved msg" << msg << endl;
    }
};

class Group
{
private:
    list<Isubscriber *> users;

public:
    void subscribe(Isubscriber *user)
    {
        users.push_back(user);
    }
    void unSubscribe(Isubscriber *user)
    {
        users.remove(user);
    }
    void notify(string msg)
    {
        for (auto user : users)
        {
            user->notify(msg);
        }
    }
};

int main()
{
    Group *group = new Group;

    User *user1 = new User(1);
    User *user2 = new User(2);
    User *user3 = new User(3);

    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);

    group->notify("new msg");

    group->unSubscribe(user1);

    group->notify("helloo");

    return 0;
}