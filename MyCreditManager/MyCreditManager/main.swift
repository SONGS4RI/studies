//
//  main.swift
//  MyCreditManager
//
//  Created by aoleejohn on 2023/05/02.
//

import Swift
import Foundation

class Student{
    let name: String
    var subjectGrades: Dictionary <String, String>?
    
    func findSubject(subjectName: String) -> Bool {
        if self.subjectGrades?[subjectName] == nil {
            return false
        }
        return true
    }
    
    init(name: String) {
        self.name = name
    }
}

class StudentGroup{
    var studentGroup: Dictionary<String, Student>?

    func findStudent(studentName: String) -> Bool {
        if self.studentGroup?[studentName] == nil {
            return false
        }
        return true
    }
    
    func addStudent(student: Student) -> Void {
        if self.findStudent(studentName: student.name) {
            print(student.name, "은 이미 존재하는 학생입니다. 추가하지 않습니다.")
            return ;
        }
        if self.studentGroup == nil {
            self.studentGroup = [student.name : student]
        }else {
            self.studentGroup?.updateValue(student, forKey: student.name)
        }
        print(student.name, "학생을 추가했습니다.")
    }
    
    func deleteStudent(studentName: String) -> Void {
        if self.findStudent(studentName: studentName) {
            self.studentGroup?.removeValue(forKey: studentName)
            print(studentName, "학생을 삭제하였습니다.")
        }else {
            print(studentName, "학생을 찾지 못햇습니다.")
        }
    }
}

func input(prompt: String?) -> String? {
    if let prompt = prompt, !prompt.isEmpty {
        print(prompt, terminator:"")
    }
    return readLine()
}

func addNewStudent(studentGroup: StudentGroup) -> Void {
    guard let studentName: String = input(prompt: "추가할 학생의 이름을 입력해주세요\n") else {
        print("입력이 잘못되었습니다. 다시 확인해주세요.\n")
        return
    }
    
    var student: Student = Student(name: studentName)
    studentGroup.addStudent(student: student)
}

func deleteStudent(studentGroup: StudentGroup) -> Void {
    guard let studentName: String = input(prompt: "삭제할 학생의 이름을 입력해주세요\n") else {
        print("입력이 잘못되었습니다. 다시 확인해주세요.\n")
        return
    }
    studentGroup.deleteStudent(studentName: studentName)
}

func addGrade(studentGroup: StudentGroup) -> Void {
    let nameSubjectGrade: String? = input(prompt: "성적을 추가할 학생의 이름, 과목 이름, 성적(A+, A, F 등)을 띄어쓰기로 구분하여 차례로 작성해주세요.\n")
    guard let subjectInfo: Array<String> = nameSubjectGrade?.components(separatedBy: " "), subjectInfo.count == 3 else {
        print("입력이 잘못되었습니다. 다시 확인해주세요.")
        return
    }
    
    var student: Student? = studentGroup.studentGroup?[subjectInfo[0]]
    if student != nil
    {
        if student!.findSubject(subjectName: subjectInfo[1]) {
            // 점수 수정
        }else {
            //추가
        }
    }
}

func deleteGrade(studentGroup: StudentGroup) -> Void {
    
}

// 실행부
var studentGroup: StudentGroup = StudentGroup()
while(true) {
    let input_line: String? = input(prompt: "원하는 기능을 입력해주세요\n1: 학생추가, 2:학생삭제, 3:성적추가(변경), 4: 성적삭제, 5: 평점보기, X: 종료\n")
    
    if input_line == nil || input_line == "X" {
        print("프로그램을 종료합니다...")
        break ;
    }else if input_line == "1" {
        addNewStudent(studentGroup: studentGroup)
    }else if input_line == "2" {
        deleteStudent(studentGroup: studentGroup)
    }else if input_line == "3" {
        addGrade(studentGroup: studentGroup)
    }else if input_line == "4" {
        deleteGrade(studentGroup: studentGroup)
    }else if input_line == "5" {
        // 평점보기
    }else {
        print("뭔가 입력이 잘못되었습니다. 1~5 사이의 숫자 혹은 X를 입력해주세요.")
    }
}
