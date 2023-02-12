FROM alpine:3.16.3

RUN apk update && apk upgrade && apk add --no-cache php8 \
    php8-common php8-session php8-curl php8-soap php8-mysqli \
    php8-dom php8-iconv php8-xml php8-simplexml php8-cgi \
    php8-pdo_mysql php8-pdo php8-posix php8-gettext php8-gd \
    php8-imap php8-ctype php8-ldap php8-iconv wget

WORKDIR /var/www

RUN wget https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php \
    && mv adminer-4.8.1.php adminer.php

ENTRYPOINT [ "php", "-S", "[::]:8080", "-t", "/var/www" ]