#!/bin/sh

# Install redis-cli
apk add --no-cache redis

echo "Waiting for Redis nodes to start..."
sleep 10

echo "Creating Redis cluster with masters..."
yes yes | redis-cli --cluster create \
  redis-master-1:6379 \
  redis-master-2:6379 \
  redis-master-3:6379 \
  --cluster-replicas 0 \
  -a ${REDIS_PASSWORD}

echo "Adding slaves to the cluster..."
redis-cli --cluster add-node redis-slave-1:6379 redis-master-1:6379 --cluster-slave -a ${REDIS_PASSWORD}
redis-cli --cluster add-node redis-slave-2:6379 redis-master-2:6379 --cluster-slave -a ${REDIS_PASSWORD}
redis-cli --cluster add-node redis-slave-3:6379 redis-master-3:6379 --cluster-slave -a ${REDIS_PASSWORD}