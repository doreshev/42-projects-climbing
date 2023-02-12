all:
	@cd srcs && docker-compose up

build:
	@cd srcs && docker-compose build

stop:
	@docker-compose -f srcs/docker-compose.yml stop

down:
	@docker-compose -f srcs/docker-compose.yml down

clean: down
	@docker system prune -a --force

fclean:
	@docker stop $$(docker ps -qa)
	@docker system prune --all --force --volumes
	@docker network prune --force
	@docker volume prune --force
	@sudo rm -rf /home/doreshev/data/mysql/*
	@sudo rm -rf /home/doreshev/data/html/*

rm:
	@sudo rm -rf /home/doreshev/data/mysql/*
	@sudo rm -rf /home/doreshev/data/html/*

re: clean rm all

bonus: all

.PHONY : all clean fclean re run bonus rm stop down build