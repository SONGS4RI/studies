//
//  classOfStudents.swift
//  MyCreditManager
//
//  Created by aoleejohn on 2023/05/03.
//

import Swift
import Foundation

class StudentGroup{
    var studentGroup: Dictionary<String, Student> = [:]

    func findStudent(studentName: String) -> Student? {
        guard let student: Student = self.studentGroup[studentName] else {
            return nil
        }
        return student
    }
    
    func addStudent() throws {
        guard let studentName: String = input(prompt: PromptMessage.addStudent.rawValue), studentName != "" else {
            throw ErrorMessage.wrongInput
        }
        if self.findStudent(studentName: studentName) != nil {
            throw ErrorMessage.duplicatedStudent(name: studentName)
        }
        let student: Student = Student(name: studentName)
        self.studentGroup.updateValue(student, forKey: student.name)
        print("\(studentName) 학생을 추가했습니다.")
    }
    
    func deleteStudent() throws {
        guard let studentName: String = input(prompt: PromptMessage.deleteStudent.rawValue), studentName != "" else {
            throw ErrorMessage.wrongInput
        }
        if self.findStudent(studentName: studentName) == nil {
            throw ErrorMessage.canNotFoundStudent(name: studentName)
        }
        self.studentGroup.removeValue(forKey: studentName)
        print("\(studentName) 학생을 삭제하였습니다.")
    }
    
    func addGrade() throws {
        let nameSubjectGrade: String? = input(prompt: PromptMessage.addGrade.rawValue)
        guard var nameSubjectGrade: Array<String> = nameSubjectGrade?.components(separatedBy: " "), nameSubjectGrade.count == 3 else {
            throw ErrorMessage.wrongInput
        }
        guard let student: Student = self.findStudent(studentName: nameSubjectGrade[0]) else {
            throw ErrorMessage.canNotFoundStudent(name: nameSubjectGrade[0])
        }
        nameSubjectGrade[2] = nameSubjectGrade[2].uppercased()
        guard MyCreditManager().scores?[nameSubjectGrade[2]] != nil else {
            throw ErrorMessage.wrongGrade
        }
        if student.findSubject(subjectName: nameSubjectGrade[1]) {
            student.subjectGrades[nameSubjectGrade[1]] = nameSubjectGrade[2]
            print("\(nameSubjectGrade[0]) 학생의 \(nameSubjectGrade[1]) 과목의 성적이 \(nameSubjectGrade[2])로 변경되었습니다.")
        } else {
            student.subjectGrades.updateValue(nameSubjectGrade[2], forKey: nameSubjectGrade[1])
            print("\(nameSubjectGrade[0]) 학생의 \(nameSubjectGrade[1]) 과목의 성적이 \(nameSubjectGrade[2])로 추가되었습니다.")
        }
    }
    
    func deleteGrade() throws {
        let nameSubject: String? = input(prompt: PromptMessage.deleteGrade.rawValue)
        guard let nameSubject: Array<String> = nameSubject?.components(separatedBy: " "), nameSubject.count == 2 else {
            throw ErrorMessage.wrongInput
        }
        guard let student: Student = self.findStudent(studentName: nameSubject[0]) else {
            throw ErrorMessage.canNotFoundStudent(name: nameSubject[0])
        }
        if student.findSubject(subjectName: nameSubject[1]) == false {
            throw ErrorMessage.canNotFoundGrade(name: nameSubject[0], subject: nameSubject[1])
        }
        student.subjectGrades.removeValue(forKey: nameSubject[1])
        print("\(nameSubject[0]) 학생의 \(nameSubject[1]) 과목의 성적이 삭제되었습니다.")
    }
    
    func showGrades() throws {
        guard let studentName: String = input(prompt: "평점을 알고싶은 학생의 이름을 입력해주세요.\n"), studentName != "" else {
            throw ErrorMessage.wrongInput
        }
        guard let student: Student = self.findStudent(studentName: studentName) else {
            throw ErrorMessage.canNotFoundStudent(name: studentName)
        }
        
        if student.subjectGrades.isEmpty {
            print("\(studentName) 학생은 성적이 없습니다.")
            throw ErrorMessage.emptyGrade(name: studentName)
        }
        var totalGrade: Double = 0
        for (key, value) in student.subjectGrades {
            print("\(key): \(value)")
            if let score: Double = MyCreditManager().scores?[value] {
                totalGrade += score
            }
        }
        totalGrade /= Double(student.subjectGrades.count)
        print("평점: \(totalGrade)")
    }
}
