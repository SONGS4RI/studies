package item46;

import item34.Operation;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.stream.Stream;

import static java.util.Comparator.comparing;
import static java.util.stream.Collectors.*;

public class Freq {
    public static void main(String[] args) throws FileNotFoundException {
        File file = new File(args[0]);

        // 코드 46-1 스트림 패러다임을 이해하지 못한 채 API만 사용했다 - 따라 하지 말 것! (277쪽)
        Map<String, Long> freq1 = new HashMap<>();
        try (Stream<String> words = new Scanner(file).tokens()) {
            words.forEach(word -> {
                freq1.merge(word.toLowerCase(), 1L, Long::sum);
            });
        }

        // 코드 46-2 스트림을 제대로 활용해 빈도표를 초기화한다. (278쪽)
        Map<String, Long> freq2;
        try (Stream<String> words = new Scanner(file).tokens()) {
            freq2 = words
                    .collect(groupingBy(String::toLowerCase, counting()));
        }

        System.out.println(freq2);

        // 코드 46-3 빈도표에서 가장 흔한 단어 10개를 뽑아내는 파이프라인 (279쪽)
        List<String> topTen = freq1.keySet().stream()
                .sorted(comparing(freq1::get).reversed())
                .limit(10)
                .collect(toList());

        System.out.println(topTen);
    }

    private static final Map<String, Operation> stringToEnum =
            Stream.of(Operation.values()).collect(
                    toMap(Object::toString, e -> e)
            );
}
