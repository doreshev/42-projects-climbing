#!bin/sh

sed -i "s|listen = 127.0.0.1:9000|listen = 9000|g" \
      /etc/php8/php-fpm.d/www.conf
sed -i "s|;listen.owner = nobody|listen.owner = nobody|g" \
      /etc/php8/php-fpm.d/www.conf
sed -i "s|;listen.group = nobody|listen.group = nobody|g" \
      /etc/php8/php-fpm.d/www.conf

wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

if [ ! -f "/var/www/wp-config.php" ]; then
      wp core download --path=. --allow-root
      wp config create --dbhost=$DB_HOST --dbname=$DB_NAME \
            --dbuser=$DB_USER --dbpass=$DB_PASS --allow-root

      wp core install --url=$DOMAIN --title=$TITLE --admin_user=$WP_ADMIN \
            --admin_password=$WP_PASS --admin_email=$EMAIL --allow-root

      wp user create evaluator evaluator@evaluator.com --role=author --user_pass=$EVAL_PASS --allow-root
fi

exec /usr/sbin/php-fpm8 -F