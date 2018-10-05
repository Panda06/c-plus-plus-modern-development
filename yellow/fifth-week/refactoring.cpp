#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human {
public:
    Human(const string& _name, const string& _profession ) :
         Name(_name), Profession(_profession) {}
    string GetName() const {
        return Name;
    }
    string GetProfession() const {
        return Profession;
    }
    virtual void Walk(const string& destination) const {
        cout << GetProfession() << ": " << GetName() << " walks to: "
             << destination << endl;
    }
private:
    const string Name;
    const string Profession;

};

class Student : public Human {
public:

    Student(const string& name, const string& favouriteSong) :
           Human(name, "Student"), FavouriteSong(favouriteSong) {}

    void Learn() {
        cout << "Student: " << GetName() << " learns" << endl;
    }
    void Walk(const string& destination) const override {
        Human::Walk(destination);
        SingSong();
    }
    void SingSong() const {
        cout << GetProfession() << ": " << GetName() << " sings a song: "
             << FavouriteSong << endl;
    }

public:
    const string FavouriteSong;
};


class Teacher : public Human {
public:

    Teacher(const string& name, const string& subject) :
            Human(name, "Teacher"), Subject(subject) {}

    void Teach() {
        cout << GetProfession() << ": " << GetName() << " teaches: "
             << Subject << endl;
    }

public:
    const string Subject;
};


class Policeman : public Human {
public:
    Policeman(const string& name) : Human(name, "Policeman") {}

    void Check(const Human& h) {
        cout << GetProfession() << ": " << GetName() << " checks "
             << h.GetProfession() <<". " << h.GetProfession()
             << "'s name is: " << h.GetName() << endl;
    }
};


void VisitPlaces(Human& h, const vector<string> places) {
    for (const auto& p : places) {
        h.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
