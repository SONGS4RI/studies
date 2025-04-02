FROM eclipse-temurin:17-jdk AS builder
WORKDIR /app

# 루트의 gradlew, gradle 설정 복사
COPY gradlew .
COPY gradle ./gradle
COPY settings.gradle .
COPY build.gradle .
COPY time/build.gradle time/

# Time 소스 복사
COPY time/src time/src

# Gradle 빌드 (time 모듈만)
RUN chmod +x gradlew && ./gradlew :time:clean :time:bootJar --no-daemon

# 2단계: 실행 단계
FROM eclipse-temurin:17-jre
WORKDIR /app

# 빌드 산출물 복사
COPY --from=builder /app/time/build/libs/*.jar app.jar

EXPOSE 8080
ENTRYPOINT ["java", "-jar", "app.jar"]
