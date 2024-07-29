FROM mariadb:latest

# 설정 파일 복사
# COPY ./config/docker.cnf /etc/mysql/conf.d/docker.cnf
# MariaDB 클라이언트 설치
RUN apt-get update && apt-get install -y mariadb-client
# 포트 노출
EXPOSE 3306
