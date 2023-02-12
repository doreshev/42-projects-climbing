FROM alpine:3.16.3

RUN apk update && apk upgrade && apk add --no-cache nginx

COPY ./conf/default.conf /etc/nginx/http.d/
COPY ./tools/* www/html/

EXPOSE 80

ENTRYPOINT ["nginx", "-g", "daemon off;"]