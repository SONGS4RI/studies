package com.kafka.impl;

import lombok.RequiredArgsConstructor;
import org.springframework.http.ResponseEntity;
import org.springframework.kafka.core.KafkaTemplate;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.HashMap;
import java.util.Map;

@RestController
@RequestMapping("/")
@RequiredArgsConstructor
public class MessageController {
    private final KafkaTemplate<String, Object> kafkaTemplate;

    @GetMapping("/send")
    public ResponseEntity<?> msg(@RequestParam String msg) {
        kafkaTemplate.send("topic", msg);

        Map<String, String> response = new HashMap<>();
        response.put("message", "[" + msg + "] sent to topic");

        return ResponseEntity.ok(response);
    }
}
