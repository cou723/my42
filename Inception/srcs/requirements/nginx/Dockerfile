FROM debian:buster
RUN apt-get -y update && apt-get -y install nginx openssl
COPY conf/nginx.conf /etc/nginx/nginx.conf
EXPOSE 443
ENV TZ Asia/Tokyo
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/ssl/username.42.fr.pem -keyout /etc/ssl/username.42.fr.key -subj "/C=FR/ST=Paris/L=Paris/O=42 School/OU=username/CN=username.42.fr"
CMD ["nginx", "-g", "daemon off;"]
