//
//  main.swift
//  MyCreditManager
//
//  Created by aoleejohn on 2023/05/02.
//

import Swift

class MyCreditManager {
    var studentGroup: StudentGroup = StudentGroup()
    let scores: Dictionary <String, Double>? = ["A+":4.5, "A":4, "B+":3.5, "B":3, "C+":2.5, "C":2, "D+":1.5, "D":1, "F":0]
    
    func run() {
        while(true) {
            let input_line: String? = input(prompt: "원하는 기능을 입력해주세요.\n1: 학생추가, 2:학생삭제, 3:성적추가(변경), 4: 성적삭제, 5: 평점보기, X: 종료\n")
            if input_line == nil || input_line == "X" {
                print("프로그램을 종료합니다...")
                break ;
            }else if input_line == "1" {
                do { try studentGroup.addStudent() } catch {
                    print(error)
                }
            }else if input_line == "2" {
                do { try studentGroup.deleteStudent() } catch {
                    print(error)
                }
            }else if input_line == "3" {
                do { try studentGroup.addGrade() } catch {
                    print(error)
                }
            }else if input_line == "4" {
                do { try studentGroup.deleteGrade() } catch {
                    print(error)
                }
            }else if input_line == "5" {
                do { try studentGroup.showGrades() } catch {
                    print(error)
                }
            }else {
                print("뭔가 입력이 잘못되었습니다. 1~5 사이의 숫자 혹은 X를 입력해주세요.")
            }
        }
    }
}

MyCreditManager().run()
