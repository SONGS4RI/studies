# 1단계: 빌드 단계
FROM eclipse-temurin:17-jdk AS builder
WORKDIR /app

# 루트의 gradlew, gradle 설정 복사
COPY gradlew .
COPY gradle ./gradle
COPY settings.gradle .
COPY build.gradle .
COPY echo/build.gradle echo/

# Echo 소스 복사
COPY echo/src echo/src

RUN chmod +x gradlew && ./gradlew :echo:clean :echo:bootJar --no-daemon

# 2단계: 실행 단계
FROM eclipse-temurin:17-jre
WORKDIR /app

# 빌드 산출물 복사
COPY --from=builder /app/echo/build/libs/*.jar app.jar

EXPOSE 8080
ENTRYPOINT ["java", "-jar", "app.jar"]
