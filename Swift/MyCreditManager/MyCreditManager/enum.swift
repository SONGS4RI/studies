//
//  enum.swift
//  MyCreditManager
//
//  Created by aoleejohn on 2023/05/11.
//

import Foundation

enum ErrorMessage: Error, CustomDebugStringConvertible {
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
        case .canNotFoundGrade(let name, let subject): return "\(name) 학생은 \(subject) 과목의 성적이 존재하지 않습니다."
        case .emptyGrade(let name): return "\(name) 학생은 성적이 없습니다."
        }
    }
}

enum PromptMessage: String {
    case addStudent = "추가할 학생의 이름을 입력해주세요.\n"
    case deleteStudent = "삭제할 학생의 이름을 입력해주세요.\n"
    case addGrade = "성적을 추가할 학생의 이름, 과목 이름, 성적(A+, A, F 등)을 띄어쓰기로 구분하여 차례로 작성해주세요.\n입력예) Mickey Swift A+\n만약에 학생의 성적 중 해당 과목이 존재하면 기존 점수가 갱신됩니다.\n"
    case deleteGrade = "성적을 삭제할 학생의 이름, 과목 이름을 띄어쓰기로 구분하여 차례로 작성해주세요.\n입력예) Mickey Swift\n"
    case showGrades = "평점을 알고싶은 학생의 이름을 입력해주세요.\n"
}
