#include <unordered_map>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class College {
private:
    unordered_map<string, pair<string, int>> courses; // Course ID -> (Teacher ID, Num Students)
    unordered_map<string, vector<string>> teachers; // Teacher ID -> List of Course IDs
    int totalStudents;

public:
    College() {
        totalStudents = 0;
    }

    bool create_course(string course_id, string teacher_id, int num_students) {
        if (courses.find(course_id) != courses.end()) {
            return false; // Course already exists
        }

        if (teachers.find(teacher_id) == teachers.end()) {
            teachers[teacher_id] = vector<string>();
        }

        if (teachers[teacher_id].size() == 5) {
            return false; // Teacher already teaching 5 courses
        }

        courses[course_id] = make_pair(teacher_id, num_students);
        teachers[teacher_id].push_back(course_id);
        totalStudents += num_students;
        return true;
    }

    bool delete_course(string course_id) {
        if (courses.find(course_id) == courses.end()) {
            return false; // Course doesn't exist
        }

        string teacher_id = courses[course_id].first;
        int num_students = courses[course_id].second;

        courses.erase(course_id);
        
        auto& courses_taught_by_teacher = teachers[teacher_id];
        courses_taught_by_teacher.erase(remove(courses_taught_by_teacher.begin(), courses_taught_by_teacher.end(), course_id), courses_taught_by_teacher.end());

        totalStudents -= num_students;
        return true;
    }

    int student_count(string teacher_id) {
        if (teachers.find(teacher_id) == teachers.end()) {
            return 0; // Teacher doesn't teach any courses
        }

        int total_students = 0;
        for (const auto& course_id : teachers[teacher_id]) {
            total_students += courses[course_id].second;
        }
        return total_students;
    }

    int total_student_count() {
        return totalStudents;
    }
};
int main(){
College new_college;

int q; 
cin >> q

assert(1 <= q and q<=5000);

while (q--)
{
string op; cin >> op;

if(op=="CREATE_COURSE")
{
int x, y, z; assert(cin >> x >> y >> z);

assert(1 <= x && x <= (int)le9); assert(1 <=y and y <=(int)1e9);

assert(1 <=z && z <= (int)1e9);

cout << (new_college.CREATE_COURSE(x, y, z) ? "Course created successfully!":"Couldn't create course!") << endl;

}

else if (op=="DELETE COURSE")
{
int x; assert(cin >> x);

assert(1 <= x && x <= (int)1e9);

cout << (new_college.DELETE_COURSE(x) ? "Course deleted successfully!" : "Couldn't delete course!") << endl;
}
else if(op=="STUDENT COUNT")
{
int x; assert(cin >> x);

assert(1 <= x && x <= (int)1e9);

long long students= new_college.STUDENT_COUNT(x);
cout << "No of students taught by teacher with ID"<<x<< "is" << students <<endl;
}
else if(op=="TOTAL_STUDENT_COUNT")

{ long long students =new_college.TOTAL_STUDENT_COUNT();
 cout << "Total no of students is" << students << endl;

} else assert(false);

} return 0;
}