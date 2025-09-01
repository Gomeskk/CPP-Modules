# Silence all commands unless explicitly printed
MAKEFLAGS += --silent

# Color variables
RESET = \033[0m
BOLD = \033[1m
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
CYAN = \033[36m
MAGENTA = \033[35m

# Variables
CXX = c++
CXXFLAGS = -std=c++98
NAME = BraiiiiiiinnnzzzZ
OBJ_DIR = objs

SRCS = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Rules
all: $(NAME)
	@echo "$(GREEN)Build completed$(RESET)"
	@echo "$(MAGENTA) (　-_･) ︻デ═一' * (/❛o❛)/"

$(NAME): $(OBJS)
	@echo "$(CYAN)Linking objects...$(RESET)"
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "$(GREEN)Executable $@ created$(RESET)"

$(OBJ_DIR)/%.o: %.cpp
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	rm -rf $(OBJ_DIR)
	@echo "$(MAGENTA) ¯\\_(ᵕ—ᴗ—)_/¯"

fclean: clean
	@echo "$(RED)Cleaning executable...$(RESET)"
	rm -f $(NAME)
	@echo "$(MAGENTA) (╯°□°)╯︵ ┻━┻"

re: fclean all

.PHONY: all clean fclean re

