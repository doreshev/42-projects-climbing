FROM alpine:3.16.3

RUN apk update && apk upgrade && apk add --no-cache nginx

EXPOSE 443

COPY ./conf/default.conf /etc/nginx/http.d/
COPY ./tools/* /etc/nginx/ssl/

ENTRYPOINT ["nginx", "-g", "daemon off;"]