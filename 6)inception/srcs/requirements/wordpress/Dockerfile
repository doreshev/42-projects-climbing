FROM alpine:3.16.3

ENV EVAL_PASS \
    WP_ADMIN \
    DB_HOST \
    DB_NAME \
    DB_USER \
    DB_PASS \
    WP_PASS \
    DOMAIN \
    EMAIL \
    TITLE

RUN apk update && apk upgrade && apk add --no-cache \
    php8 \
    php8-fpm \
    php8-mysqli \
    php8-json \
    php8-curl \
    php8-dom \
    php8-exif \
    php8-fileinfo \
    php8-mbstring \
    php8-openssl \
    php8-xml \
    php8-zip \
    php8-redis \
    php8-cli \
    php8-phar \
    mariadb-client \
    wget \
    unzip

WORKDIR /var/www/

COPY ./tools/wp.sh .

RUN chmod +x wp.sh

ENTRYPOINT ["sh", "wp.sh"]