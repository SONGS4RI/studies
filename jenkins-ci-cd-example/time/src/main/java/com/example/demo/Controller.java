package com.example.demo;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.time.LocalDateTime;

@RestController
@RequestMapping("/time")
public class Controller {
    @Value("${app.version}")
    private String version = "not set";

    @GetMapping
    public String time() {
        return version + ":" + LocalDateTime.now();
    }
}
