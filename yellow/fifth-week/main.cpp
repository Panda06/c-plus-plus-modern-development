#include <iostream>
#include <string>
#include <vector>

using namespace std;


// Declarations (may be in separate files)

class Person {
public:
    Person(const string& type, const string& name) : Type(type), Name(name), os(cout) {}

    virtual void Walk(const string& destination) const;
    virtual ~Person() = default;

protected:
    ostream& PrepareStream() const;

public:
    const string Type;
    const string Name;
private:
    // non-const stream holder for possibility of using streams other than 'cout'
    ostream& os;
};


class Student : public Person {
public:

    Student(const string& name, const string& favouriteSong) :
        Person("Student", name),
        FavouriteSong(favouriteSong) {}

    void Learn() const;
    void Walk(const string& destination) const override;
    void SingSong() const ;

private:
    const string FavouriteSong;
};


class Teacher : public Person {
public:

    Teacher(string name, string subject) :
        Person("Teacher", name),
        Subject(subject) {}

    void Teach() const;

private:
    const string Subject;
};


class Policeman : public Person {
public:
    Policeman(const string& name) :
        Person("Policeman", name) {}

    void Check(const Person& t) const;

};

// Implimentations
// Person
void Person::Walk(const string& destination) const {
    PrepareStream() << " walks to: " << destination << endl;
}

ostream& Person::PrepareStream() const {
    return os << Type << ": " << Name;
}

// Student
void Student::Learn() const {
    PrepareStream() << " learns" << endl;
}

void Student::Walk(const string& destination) const {
    Person::Walk(destination);
    SingSong();
}

void Student::SingSong() const {
    PrepareStream() << " sings a song: " << FavouriteSong << endl;
}

//Teacher
void Teacher::Teach() const {
    PrepareStream() << " teaches: " << Subject << endl;
}

//Policeman
void Policeman::Check(const Person& t) const {
    PrepareStream() << " checks " << t.Type << ". " << t.Type << "'s name is: " << t.Name << endl;
}


void VisitPlaces(const Person& t, const vector<string>& places) {
    for (const auto& p : places) {
        t.Walk(p);
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
