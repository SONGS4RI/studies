package com.example.demo;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/echo")
public class Controller {
    @Value("${app.version}")
    private String version = "not set";

    @GetMapping
    public String echo(@RequestParam String message) {
        return version + ":" + message;
    }
}
