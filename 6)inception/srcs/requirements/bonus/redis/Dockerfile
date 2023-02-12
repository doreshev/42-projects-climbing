FROM alpine:3.16.3

RUN apk update && apk upgrade && \
    apk add --no-cache redis

ENTRYPOINT [ "redis-server" , "/etc/redis.conf" ]