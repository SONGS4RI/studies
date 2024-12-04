package com.kafka.impl;

public record Product(
        String productName,
        int productCode,
        boolean isDql
) {
    public Product(String productName, int productCode) {
        this(productName, productCode, false);
    }
}
