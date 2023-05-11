//
//  classOfStudents.swift
//  MyCreditManager
//
//  Created by aoleejohn on 2023/05/03.
//

import Swift
import Foundation

enum ErrorMessage : Error {
    case wrongInput
    case duplicatedStudent(name: String)
    case canNotFoundStudent(name: String)
    case wrongGrade
    case canNotFoundGrade(name: String, subject: String)
    case emptyGrade(name: String)

    var debugDescription: String {
        switch self {
        case .wrongInput: return "입력이 잘못되었습니다. 다시 확인해주세요.\n"
        case .duplicatedStudent(let name): return "\(name) 은 이미 존재하는 학생입니다. 추가하지 않습니다."
        case .canNotFoundStudent(let name): return "\(name) 학생을 찾지 못했습니다."
        case .wrongGrade: return "성적(A+, A, F 등)이 잘못 되었습니다. 다시 확인해주세요."
        case .canNotFoundGrade(let name, let subject): return "\(name) 학생은 \(subject) 과목의 성적이 존재하지않습니다."
        case .emptyGrade(let name): return "\(name) 학생은 성적이 없습니다."
        }
    }
}

enum Message {
    case addStudent
    case addStudentDone(name: String)
    case deleteStudent
    case deleteStudentDone(name: String)
    case addGrade
    case addGradeDone(name: String, subjectName: String, grade: String)
    case changedGrade(name: String, subjectName: String, grade: String)
    case deleteGrade
    case deleteGradeDone(name: String, subjectName: String)
    case showGrades
    case showGradesDone(totalGrade: Double)
    
    var printMessage: String {
        switch self {
        case .addStudent: return "추가할 학생의 이름을 입력해주세요\n"
        case .addStudentDone(let name): return "\(name) 학생을 추가했습니다."
        case .deleteStudent: return "삭제할 학생의 이름을 입력해주세요\n"
        case .deleteStudentDone(let name): return "\(name) 학생을 삭제하였습니다."
        case .addGrade: return "성적을 추가할 학생의 이름, 과목 이름, 성적(A+, A, F 등)을 띄어쓰기로 구분하여 차례로 작성해주세요.\n입력예) Mickey Swift A+\n만약에 학생의 성적 중 해당 과목이 존재하면 기존 점수가 갱신됩니다.\n"
        case .addGradeDone(let name, let subjectName, let grade): return "\(name) 학생의 \(subjectName) 과목의 성적이 \(grade)로 추가되었습니다."
        case .changedGrade(let name, let subjectName, let grade): return "\(name) 학생의 \(subjectName) 과목의 성적이 \(grade)로 변경되었습니다."
        case .deleteGrade: return "성적을 삭제할 학생의 이름, 과목 이름을 띄어쓰기로 구분하여 차례로 작성해주세요.\n입력예) Mickey Swift\n"
        case .deleteGradeDone(let name, let subjectName): return "\(name) 학생의 \(subjectName) 과목의 성적이 삭제되었습니다."
        case .showGrades: return "평점을 알고싶은 학생의 이름을 입력해주세요.\n"
        case .showGradesDone(let totalGrade): return "평점: \(totalGrade)"
    }
}

class StudentGroup{
    var studentGroup: Dictionary<String, Student> = [:]

    func findStudent(studentName: String) -> Student? {
        guard let student: Student = self.studentGroup[studentName] else {
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
        let student: Student = Student(name: studentName)
        self.studentGroup.updateValue(student, forKey: student.name)
        print(student.name, "학생을 추가했습니다.")
    }
    
    func deleteStudent() -> Void {
        guard let studentName: String = input(prompt: "삭제할 학생의 이름을 입력해주세요\n"), studentName != "" else {
            print("입력이 잘못되었습니다. 다시 확인해주세요.\n")
            return
        }
        if self.findStudent(studentName: studentName) != nil {
            self.studentGroup.removeValue(forKey: studentName)
            print(studentName, "학생을 삭제하였습니다.")
        } else {
            print(studentName, "학생을 찾지 못했습니다.")
        }
    }
    
    func addGrade() -> Void {
        let nameSubjectGrade: String? = input(prompt: "성적을 추가할 학생의 이름, 과목 이름, 성적(A+, A, F 등)을 띄어쓰기로 구분하여 차례로 작성해주세요.\n입력예) Mickey Swift A+\n만약에 학생의 성적 중 해당 과목이 존재하면 기존 점수가 갱신됩니다.\n")
        guard var nameSubjectGrade: Array<String> = nameSubjectGrade?.components(separatedBy: " "), nameSubjectGrade.count == 3 else {
            print("입력이 잘못되었습니다. 다시 확인해주세요.")
            return
        }
        guard let student: Student = self.findStudent(studentName: nameSubjectGrade[0]) else {
            print("\(nameSubjectGrade[0]) 학생을 찾지 못했습니다.")
            return
        }
        nameSubjectGrade[2] = nameSubjectGrade[2].uppercased()
        guard scores?[nameSubjectGrade[2]] != nil else {
            print("성적(A+, A, F 등)이 잘못 되었습니다. 다시 확인해주세요.")
            return
        }
        if student.findSubject(subjectName: nameSubjectGrade[1]) {
            student.subjectGrades[nameSubjectGrade[1]] = nameSubjectGrade[2]
            print("\(nameSubjectGrade[0]) 학생의 \(nameSubjectGrade[1]) 과목의 성적이 \(nameSubjectGrade[2])로 변경되었습니다.")
        } else {
            student.subjectGrades.updateValue(nameSubjectGrade[2], forKey: nameSubjectGrade[1])
            print("\(nameSubjectGrade[0]) 학생의 \(nameSubjectGrade[1]) 과목의 성적이 \(nameSubjectGrade[2])로 추가되었습니다.")
        }
    }
    
    func deleteGrade() -> Void {
        let nameSubject: String? = input(prompt: "성적을 삭제할 학생의 이름, 과목 이름을 띄어쓰기로 구분하여 차례로 작성해주세요.\n입력예) Mickey Swift\n")
        guard let nameSubject: Array<String> = nameSubject?.components(separatedBy: " "), nameSubject.count == 2 else {
            print("입력이 잘못되었습니다. 다시 확인해주세요.")
            return
        }
        guard let student: Student = self.findStudent(studentName: nameSubject[0]) else {
            print("\(nameSubject[0]) 학생을 찾지 못했습니다.")
            return
        }
        
        if student.findSubject(subjectName: nameSubject[1]) {
            student.subjectGrades.removeValue(forKey: nameSubject[1])
            print("\(nameSubject[0]) 학생의 \(nameSubject[1]) 과목의 성적이 삭제되었습니다.")
        } else {
            print("\(nameSubject[0]) 학생은 \(nameSubject[1]) 과목의 성적이 존재하지않습니다.")
        }
    }
    
    func showGrades() -> Void {
        guard let studentName: String = input(prompt: "평점을 알고싶은 학생의 이름을 입력해주세요.\n"), studentName != "" else {
            print("입력이 잘못되었습니다. 다시 확인해주세요.\n")
            return
        }
        guard let student: Student = self.findStudent(studentName: studentName) else {
            print("\(studentName) 학생을 찾지 못했습니다.")
            return
        }
        
        if student.subjectGrades.isEmpty {
            print("\(studentName) 학생은 성적이 없습니다.")
        }else {
            var totalGrade: Double = 0
            for (key, value) in student.subjectGrades {
                print("\(key): \(value)")
                
                if let score: Double = scores?[value] {
                    totalGrade += score
                }
            }
            totalGrade /= Double(student.subjectGrades.count)
            print("평점: \(totalGrade)")
        }
    }
}
