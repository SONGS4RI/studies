#!/bin/bash

sleep 10
echo "init kafka start"
# Kafka 토픽 생성
/bin/kafka-topics --bootstrap-server broker-1:19092,broker-2:19092,broker-3:19092 \
  --create --topic test-topic --partitions 1 --replication-factor 3
echo "test-topic created"

/bin/kafka-topics --bootstrap-server broker-1:19092,broker-2:19092,broker-3:19092 \
  --create --topic test-topic-dlq --partitions 3 --replication-factor 3
echo "test-topic-dlq created"

sleep 1

echo "init kafka end"

