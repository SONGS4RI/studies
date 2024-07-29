package main.kotlin

import java.util.Scanner
import kotlin.random.Random

fun main() {
    val username: String = "Kildong"// 불변
    var changeName = "A"// 가변

    println("$username && ${changeName}!!")

    var test: Int? = null

    test?.let {
        println("${it}출력 안됨!!!!!")
    }
    var num1 = 10
    var num2 = 20
    println(kotlin.math.max(num1, num2))

    // 랜덤
    val rand = Random.nextInt(0, 100)// 0 ~ 99
    println(rand)

    // 입력
//    val reader = Scanner(System.`in`)
//    val num = reader.nextInt()
//    println(num)

    //조건
    var result = if (num1 > 10) {
        "num1 > 10"
    } else {
        "num1 <= 10"
    }
    println(result)

    when {// switch 문과 유사
        num1 > 10 -> {
            println("num1 > 10")
        }
        else -> {
            println("num1 <= 10")
        }
    }

    val items = listOf(1, 2, 3, 4, 5)

    // for 문
    for (item in items) {
        println(item)
    }
    items.forEach{
        item -> println(item)
    }
    for (i in 0..(items.size - 1)) {
        println(items[i])
    }

    // 리스트
    var changableItems = mutableListOf(1, 2, 3, 4, 5)
    changableItems.add(5)
    changableItems.removeAt(0)

    // 배열 -> 잘사용안함
    val arrays = arrayOf(1, 2, 3)
    arrays[0] = 10

    try {
        val res = items[5]
    } catch (e: Exception) {
        println(e.message)
    }

    // nullable
    var nameNull: String? = null
    nameNull = "notNull"

    nameNull.let {
        println(nameNull)
    }

    val john = Person("John", 20)
    println(john)
    println(john.hobby)

    val mike = DataPerson("mike", 22)
    println(mike)

    // 타입 체크
    val dog : Animal = Dog()
    val cat = Cat()

    if (dog is Dog) {
        println("왈왈")
    }
    if (dog is Animal) {
        println("@#$%^")
    }

    myFunc(){
        println("함수 호출")
    }
}

fun sum(a: Int,  b: Int, c: Int = 0) : Int {// c는 사용안해도 됨, 디폴트값 지정
    return a + b + c
}

fun minus(a: Int, b: Int) = a + b

class Person(val  name: String, var age: Int) {
    var hobby = "축구"
        private set
        get() =  "취미 : $field"

}

data class DataPerson(val  name: String, var age: Int) {

    init {
        println("init")
    }
}
// 상속
abstract class Animal {
    open fun move() {// open 키워드가 있어야 자식에서 상속을 하던 overide를 하던 함
        println("이동")
    }
}

class Dog : Animal(), Drawable {
    override fun move() {
        println("껑충")
    }

    override fun draw() {
        TODO("Not yet implemented")
    }

}

class Cat : Animal(), Drawable {
    override fun move() {
        println("깡총")
    }

    override fun draw() {
        TODO("Not yet implemented")
    }

}

// 인터페이스

interface Drawable {
    fun draw()
}

// 제네릭
class Box<T>(val value: T) {

}

// 콜백함수
fun myFunc(callBack : () -> Unit) {
    println("함수 시작!!")
    callBack()
    println("함수 끝!!")

}

suspend fun Fun1() {}