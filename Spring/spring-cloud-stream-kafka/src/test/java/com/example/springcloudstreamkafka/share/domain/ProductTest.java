package com.example.springcloudstreamkafka.share.domain;

import com.fasterxml.jackson.databind.ObjectMapper;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ProductTest {
    @Test
    public void testDeserialization() throws Exception {
        String json = "{\"productName\":\"사탕\",\"productCode\":123456}";

        ObjectMapper objectMapper = new ObjectMapper();
        Product product = objectMapper.readValue(json, Product.class);

        assertEquals("사탕", product.productName());
        assertEquals(123456, product.productCode());
    }
}