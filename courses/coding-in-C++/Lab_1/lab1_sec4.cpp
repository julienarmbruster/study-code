#include <iostream>
#include <limits>

void readStudentData(std::string& name,
                    unsigned int& homework, 
                    unsigned int& midterm, 
                    unsigned int& finalExam)
{
    std::cout<<"Name:"<<std::endl;
    std::getline(std::cin, name);
    std::cout<<"Homework"<<std::endl;
    std::cin>>homework;
    std::cout<<"Midterm:"<<std::endl;
    std::cin>>midterm;
    std::cout<<"Final Exam:"<<std::endl;
    std::cin>>finalExam;

};

void calculateGrade(unsigned int& homework, 
                    unsigned int& midterm, 
                    unsigned int& finalExam,
                    double& finalGrade,
                    std::string& letterGrade)
{
    double homeworkWeight = 0.4;
    double midtermWeight = 0.25;
    double finalExamWeight = 0.35;
    const int F_ascii = 70;
    
    finalGrade = homework*homeworkWeight+midterm*midtermWeight+finalExam*finalExamWeight;
    letterGrade = F_ascii-finalGrade*0.05;
    std::cout<<finalGrade<<letterGrade;
}

int main(){
    std::string name;
    unsigned int homework=0;
    unsigned int midterm=0;
    unsigned int finalExam=0;
    double finalGrade=0;
    std::string letterGrade;
    readStudentData(name,homework,midterm,finalExam);
    calculateGrade(homework, midterm, finalExam, finalGrade, letterGrade);


}