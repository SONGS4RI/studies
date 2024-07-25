package com.module.api.config;


import com.module.common.utils.TestBean;
import com.module.common.utils.TestMethod;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Import;

@Configuration(proxyBeanMethods = false)
@Import({
        TestBean.class,
        TestMethod.class
})
public class apiConfig {
}
