package p2;

import p1.School;

public class LawrenceSchool extends School {
    void property() {
        School s = new School();
//        s.schoolName = "Lawrence";      // Error: schoolName has protected access in p1.School
       schoolName= "kvdl";       // But we can use like this
    }
}
