FROM alpine:3.16.3

ARG FTP_USER \
    FTP_PASS

RUN apk update && apk upgrade && \
    apk add --no-cache vsftpd

RUN adduser -h /var/www -s /bin/false -D $FTP_USER && \
    echo "$FTP_USER:$FTP_PASS" | /usr/sbin/chpasswd && \
    adduser $FTP_USER root

COPY ./tools/vsftpd.conf /etc/vsftpd

ENTRYPOINT ["/usr/sbin/vsftpd", "/etc/vsftpd/vsftpd.conf"]