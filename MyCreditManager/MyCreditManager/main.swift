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

    func findStudent(studentName: String) -> Student? {
        guard let student: Student = self.studentGroup?[studentName] else {
            return nil
        }
        return student
    }
    
    func addStudent() -> Void {
        guard let studentName: String = input(prompt: "추가할 학생의 이름을 입력해주세요\n"), studentName != "" else {
            print("입력이 잘못되었습니다. 다시 확인해주세요.\n")
            return
        }
        if self.findStudent(studentName: studentName) != nil {
            print("\(studentName) 은 이미 존재하는 학생입니다. 추가하지 않습니다.")
            return ;
        }
        var student: Student = Student(name: studentName)
        if self.studentGroup == nil {
            self.studentGroup = [student.name : student]
        }else {
            self.studentGroup?.updateValue(student, forKey: student.name)
        }
        print(student.name, "학생을 추가했습니다.")
    }
    
    func deleteStudent() -> Void {
        guard let studentName: String = input(prompt: "삭제할 학생의 이름을 입력해주세요\n"), studentName != "" else {
            print("입력이 잘못되었습니다. 다시 확인해주세요.\n")
            return
        }
        if self.findStudent(studentName: studentName) != nil {
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

func addGrade(studentGroup: StudentGroup) -> Void {
    let nameSubjectGrade: String? = input(prompt: "성적을 추가할 학생의 이름, 과목 이름, 성적(A+, A, F 등)을 띄어쓰기로 구분하여 차례로 작성해주세요.\n입력예) Mickey Swift A+\n만약에 학생의 성적 중 해당 과목이 존재하면 기존 점수가 갱신됩니다.\n")
    guard let nameSubjectGrade: Array<String> = nameSubjectGrade?.components(separatedBy: " "), nameSubjectGrade.count == 3 else {
        print("입력이 잘못되었습니다. 다시 확인해주세요.")
        return
    }
    guard var student: Student = studentGroup.findStudent(studentName: nameSubjectGrade[0]) else {
        print("\(nameSubjectGrade[0]) 학생을 찾지 못했습니다.")
        return
    }
    guard scores[nameSubjectGrade[2]] != nil else {
        print("성적(A+, A, F 등)이 잘못 되었습니다. 다시 확인해주세요.")
        return
    }
    
    if student.findSubject(subjectName: nameSubjectGrade[1]) {
        student.subjectGrades![nameSubjectGrade[1]] = nameSubjectGrade[2]
        print("\(nameSubjectGrade[0]) 학생의 \(nameSubjectGrade[1]) 과목의 성적이 \(nameSubjectGrade[2])로 변경되었습니다.")
    }else {
        if student.subjectGrades == nil {
            student.subjectGrades = [nameSubjectGrade[1] : nameSubjectGrade[2]]
        }else {
            student.subjectGrades!.updateValue(nameSubjectGrade[2], forKey: nameSubjectGrade[1])
        }
        print("\(nameSubjectGrade[0]) 학생의 \(nameSubjectGrade[1]) 과목의 성적이 \(nameSubjectGrade[2])로 추가되었습니다.")
    }
}

func deleteGrade(studentGroup: StudentGroup) -> Void {
    let nameSubject: String? = input(prompt: "성적을 삭제할 학생의 이름, 과목 이름을 띄어쓰기로 구분하여 차례로 작성해주세요.\n입력예) Mickey Swift\n")
    guard let nameSubject: Array<String> = nameSubject?.components(separatedBy: " "), nameSubject.count == 2 else {
        print("입력이 잘못되었습니다. 다시 확인해주세요.")
        return
    }
    
    guard var student: Student = studentGroup.findStudent(studentName: nameSubject[0]) else {
        print("\(nameSubject[0]) 학생을 찾지 못했습니다.")
        return
    }
    
    if student.findSubject(subjectName: nameSubject[1]) {
        student.subjectGrades!.removeValue(forKey: nameSubject[1])
        print("\(nameSubject[0]) 학생의 \(nameSubject[1]) 과목의 성적이 삭제되었습니다.")
    }else {
        print("\(nameSubject[0]) 학생은 \(nameSubject[1]) 과목의 성적이 존재하지않습니다.")
    }
}

func showGrades(studentGroup: StudentGroup) -> Void {
    guard let studentName: String = input(prompt: "평점을 알고싶은 학생의 이름을 입력해주세요.\n"), studentName != "" else {
        print("입력이 잘못되었습니다. 다시 확인해주세요.\n")
        return
    }
    guard let student: Student = studentGroup.findStudent(studentName: studentName) else {
        print("\(studentName) 학생을 찾지 못했습니다.")
        return
    }
    
    if student.subjectGrades == nil {
        print("\(studentName) 학생은 성적이 없습니다.")
    }else {
        var totalGrade: Double = 0, subjectCnt: Int = 0
        for (key, value) in student.subjectGrades! {
            print("\(key): \(value)")
            subjectCnt += 1
            totalGrade += scores[value.uppercased()]!
        }
        totalGrade /= Double(subjectCnt)
        print("평점: \(totalGrade)")
    }
}

// 실행부
var studentGroup: StudentGroup = StudentGroup()
let scores: Dictionary <String, Double>! = ["A+":4.5, "A":4, "B+":3.5, "B":3, "C+":2.5, "C":2, "D+":1.5, "D":1, "F":0]
while(true) {
    let input_line: String? = input(prompt: "원하는 기능을 입력해주세요\n1: 학생추가, 2:학생삭제, 3:성적추가(변경), 4: 성적삭제, 5: 평점보기, X: 종료\n")
    
    if input_line == nil || input_line == "X" {
        print("프로그램을 종료합니다...")
        break ;
    }else if input_line == "1" {
        studentGroup.addStudent()
    }else if input_line == "2" {
        studentGroup.deleteStudent()
    }else if input_line == "3" {
        addGrade(studentGroup: studentGroup)
    }else if input_line == "4" {
        deleteGrade(studentGroup: studentGroup)
    }else if input_line == "5" {
        showGrades(studentGroup: studentGroup)
    }else {
        print("뭔가 입력이 잘못되었습니다. 1~5 사이의 숫자 혹은 X를 입력해주세요.")
    }
}
