class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int student_count = students.size(), circular_stu=0, square_stu=0;
        for(int i=0; i<students.size(); i++){
            if(students[i] == 0){circular_stu++;}
            else{square_stu++;}
        }
        for(int i=0; i<sandwiches.size(); i++){
            if(sandwiches[i] == 0){
                if(circular_stu > 0){
                    student_count--;  // because he'll take it and leave the line.
                    circular_stu--;    // circular student is also gone.
                }
                else{return student_count;}
            }
            else{
                if(square_stu > 0){
                    student_count--;
                    square_stu--;
                }
                else{return student_count;}
            }
        }
        return student_count;
    }
};