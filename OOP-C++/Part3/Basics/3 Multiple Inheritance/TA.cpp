class TA : public Teacher, public Student {

  public:
    void print() {
        cout << "TA " << endl;
    }
};

/*
   If we create TA's object then Teacher's constructor will call as it is written first
   then Student's constructor will call.
 */
