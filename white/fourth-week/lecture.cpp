struct Specialization {
    string specialization;
    explicit Specialization(string _specialization) {
        specialization = _specialization;
    }
};
struct Course {
    string course;
    explicit Course(string _course) {
        course = _course;
    }
};
struct Week {
    string week;
    explicit Week(string _week) {
        week = _week;
    }
};
struct LectureTitle {
  string specialization;
  string course;
  string week;
  LectureTitle(Specialization _specialization, Course _course, Week _week) {
      specialization = _specialization.specialization;
      course = _course.course;
      week = _week.week;
  }
};
