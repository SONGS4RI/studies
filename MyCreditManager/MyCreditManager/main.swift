//
//  main.swift
//  MyCreditManager
//
//  Created by aoleejohn on 2023/05/02.
//

import Swift

class Student{
    let name: String
    
    init(name: String) {
        self.name = name
    }
}

class StudentGroup{
    
    func findStudent(studentName: String) -> Bool{
        
    }
}

func input(prompt: String?) -> String?{
    if let prompt = prompt, !prompt.isEmpty {
        print(prompt, terminator:"")
    }
    return readLine()
}

func addNewStudent(studentGroup: StudentGroup) -> Void{
    let studentName: String? = input(prompt: "추가할 학생의 이름을 입력해주세요")
    
    
    
}

while(true){
    let input_line: String? = input(prompt: "원하는 기능을 입력해주세요\n1: 학생추가, 2:학생삭제, 3:성적추가(변경), 4: 성적삭제, 5: 평점보기, X: 종료\n")
    
    if input_line == nil || input_line == "X"{
        print("프로그램을 종료합니다...")
        break ;
    }else if input_line == "1"{
        let studentName = input(prompt: "추가할 학생의 이름을 입력해주세요")
    }else if input_line == "2"{
        // 학생삭제
    }else if input_line == "3"{
        // 성정추가
    }else if input_line == "4"{
        // 성적삭제
    }else if input_line == "5"{
        // 평정보기
    }else{
        print("뭔가 입력이 잘못되었습니다. 1~5 사이의 숫자 혹은 X를 입력해주세요.")
    }
}
