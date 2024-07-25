package com.module.api.controller;

import com.module.common.utils.TestBean;
import com.module.common.utils.TestMethod;
import lombok.RequiredArgsConstructor;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/api")
@RequiredArgsConstructor
public class ApiController {
    @Autowired
    private final TestBean testBean;

    @GetMapping("/bean")
    public String bean() {
        testBean.test();
        return "bean";
    }

    @GetMapping("/method")
    public String method() {
        TestMethod testMethod = new TestMethod();
        testMethod.test();
        return "method";
    }
}
