//
//  ViewController.swift
//  UpDownGame
//
//  Created by aoleejohn on 2023/05/27.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var slider : UISlider!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    @IBAction func sliderValueChanged(_ sender : UISlider) {
        slider = sender
    }
    
    @IBAction func touchUpHitButton(_ sender : UIButton) {
        print(slider.value)
    }
    
    @IBAction func touchUpResetButton(_ sender : UIButton) {
        print("touchUpResetButton")
    }
}

