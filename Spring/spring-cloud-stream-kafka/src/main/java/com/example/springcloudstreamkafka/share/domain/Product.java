package com.example.springcloudstreamkafka.share.domain;

public record Product(
        String productName,
        int productCode,
        boolean isDql
) {
    public Product(String productName, int productCode) {
        this(productName, productCode, false);
    }
}
