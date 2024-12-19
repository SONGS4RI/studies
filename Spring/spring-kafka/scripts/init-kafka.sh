#!/bin/bash

sleep 10

# Kafka 토픽 생성
/opt/kafka/bin/kafka-topics.sh --bootstrap-server broker-1:19092,broker-2:19092,broker-3:19092 \
  --create --topic test-topic --partitions 3 --replication-factor 3

/opt/kafka/bin/kafka-topics.sh --bootstrap-server broker-1:19092,broker-2:19092,broker-3:19092 \
  --create --topic test-topic-dlq --partitions 3 --replication-factor 3



echo "init kafka"

