FROM alpine:3.16.3

ARG DB_NAME \
    DB_USER \
    DB_PASS \
    DB_ROOT

RUN apk update && apk add --no-cache mariadb mariadb-client

COPY ./tools/maria.sh .

RUN sh maria.sh

ENTRYPOINT ["/usr/bin/mysqld", "--user=mysql", "--console"]