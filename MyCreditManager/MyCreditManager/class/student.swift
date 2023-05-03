//
//  student.swift
//  MyCreditManager
//
//  Created by aoleejohn on 2023/05/03.
//

import Swift

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
