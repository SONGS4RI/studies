import Swift

func pow(a: Int, b: Int) -> Int {
    var tmp: Int = 1
    while (true){
        if (b <= 0) break;
        b -= 1
        tmp *= a
    }
}

print(pow(a:2, b:4))
