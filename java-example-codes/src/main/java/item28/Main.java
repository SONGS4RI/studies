package item28;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Object[] objects = new Long[1];
        objects[0] = "타입이 달라 넣을 수 없습니다.";

        // 컴파일 에러
//        List<Object> list = new ArrayList<Long>();
//        list.add("타입이 달라 넣을 수 없습니다!");
    }
}
