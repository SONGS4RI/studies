//
//  util.swift
//  MyCreditManager
//
//  Created by aoleejohn on 2023/05/03.
//

import Foundation

func input(prompt: String?) -> String? {
    if let prompt = prompt, !prompt.isEmpty {
        print(prompt, terminator:"")
    }
    return readLine()
}
