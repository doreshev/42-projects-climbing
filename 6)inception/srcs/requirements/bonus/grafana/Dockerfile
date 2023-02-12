FROM alpine:3.16.3

ENV GF_SECURITY_ADMIN_USER \
    GF_SECURITY_ADMIN_PASSWORD \
    GF_DATABASE_TYPE \
    GF_DATABASE_NAME \
    GF_DATABASE_USER \
    GF_DATABASE_PASSWORD

RUN apk update && apk upgrade && apk add --no-cache \
    grafana

COPY ./tools/* /etc/grafana/

ENTRYPOINT ["grafana-server", "-homepath", "/usr/share/grafana", "-config", "/etc/grafana/grafana.ini", "run"]