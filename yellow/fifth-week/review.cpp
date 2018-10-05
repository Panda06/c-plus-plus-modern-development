#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DudeOrGirlOrWhoever {
public:
	DudeOrGirlOrWhoever(const string& name, const string& type) : name_(name), type_(type) {}

	// potentially changes state so not const
	virtual void Walk(const string& destination) {
		cout << type_ << ": " << name_ << " walks to: " << destination << endl;
	}

	string Name() const {
		return name_;
	}

	string Type() const {
		return type_;
	}

protected:
	string name_;
	string type_;
};


class Student: public DudeOrGirlOrWhoever {
public:

	Student(const string& name, const string& favouriteSong) : DudeOrGirlOrWhoever(name, "Student"), song_(favouriteSong) {}

	void Walk(const string& destination) override {
		DudeOrGirlOrWhoever::Walk(destination);
		cout << "Student: " << name_ << " sings a song: " << song_ << endl;
	}

	// potentially changes state so not const
	void Learn() {
		cout << "Student: " << name_ << " learns" << endl;
	}

	void SingSong() const {
		cout << "Student: " << name_ << " sings a song: " << song_ << endl;
	}

public:
	string song_;
};


class Teacher: public DudeOrGirlOrWhoever {
public:
	Teacher(const string& name, const string& subject) : DudeOrGirlOrWhoever(name, "Teacher"), subject_(subject) {}

	void Teach() const {
		cout << "Teacher: " << name_ << " teaches: " << subject_ << endl;
	}

public:
	string subject_;
};


class Policeman: public DudeOrGirlOrWhoever {
public:
	Policeman(const string& name) : DudeOrGirlOrWhoever(name, "Policeman") {}

	void Check(const DudeOrGirlOrWhoever& p) const {
		cout << "Policeman: " << name_ << " checks " << p.Type() << ". " << p.Type() << "'s name is: " << p.Name() << endl;
	}
};


void VisitPlaces(DudeOrGirlOrWhoever& t, const vector<string>& places) {
	for (auto p : places) {
		t.Walk(p);
	}
}

int main() {
	Teacher t("Jim", "Math");
	Student s("Ann", "We will rock you");
	Policeman p("Bob");

	VisitPlaces(t, { "Moscow", "London" });
	p.Check(s);
	VisitPlaces(s, { "Moscow", "London" });

	int c;
	cin >> c;
	return 0;
}
