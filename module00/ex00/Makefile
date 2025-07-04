# **************************************************************************** #
# PROJECT
NAME := megaphone

# **************************************************************************** #
# DIRECTORIES
OBJ_DIR := obj/

# **************************************************************************** #
# FILES
SRC_FILES := megaphone

# GENERAL FILES
SRCS := $(addsuffix .cpp, $(SRC_FILES))
OBJS := $(SRCS:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)
DEPS := $(OBJS:.o=.d)

# **************************************************************************** #
# COMPILER
CPP := c++
CPPFLAGS := -Wall -Wextra -Werror -std=c++98
CPPFLAGS += -MMD -MP

# DEBUG MODE
BUILD_MODE_FILE := .build_mode
DEBUG ?= 0
VALGRIND ?= 0
VALGRIND_FLAGS := -s --tool=memcheck --leak-check=full --show-leak-kinds=all \
--track-origins=yes --trace-children=yes

ifeq ($(DEBUG),1)
	CPPFLAGS += -g3 -fsanitize=address
	LDFLAGS += -fsanitize=address
endif

ifeq ($(VALGRIND),1)
	CPPFLAGS += -g3
endif

# **************************************************************************** #
# COLOURS: BOLD RGBYW
BR = \033[1;31m
BG = \033[1;32m
BB = \033[1;34m
BY = \033[1;33m
BW = \033[1;37m

# NO COLOR and CLEAR LINE
NC = \033[0;39m
CL = \033[2K

# **************************************************************************** #
# ESSENTIAL RULES
-include $(DEPS)

# Default rule to create the program
all: $(NAME)

# Rule to create the program
$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $(OBJS)  -o $(NAME)
	@printf "%b" "$(CL) -> $(BW)[$(NAME)]:\t$(BG)Compilation success\t✅$(NC)\n"

# Rule to compile object files from source files
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@printf "%b" "$(CL) -> $(BW)[$(NAME)]:\t$(NC)$<\r"
	@$(CPP) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

# Rule to clean generated files
clean:
	@rm -rf $(OBJ_DIR) $(BUILD_MODE_FILE)
	@printf "%b" "$(CL) -> $(BW)[$(NAME)]:\t$(BG)Object files cleaned\t❎$(NC)\n"

# Rule to clean generated files and the executable
fclean:
	@$(MAKE) clean > /dev/null
	@rm -rf $(NAME) $(BONUS_NAME)
	@printf "%b" "$(CL) -> $(BW)[$(NAME)]:\t$(BG)Exe and objects cleaned\t❎$(NC)\n"

# Rule to recompile from zero
re: fclean all

# **************************************************************************** #
# NORM AND DEBUG RULES

ARGS := Damnit " ! " "Sorry students, I thought this thing was off."

# Rule to compile with debug flags
debug: fclean
	@$(MAKE) DEBUG=1 $(NAME) -s
	@echo " -> $(BW)[Debug]:\t$(BB)Debug mode enabled\t🟦$(NC)"
	./$(NAME) $(ARGS)

# Rule to compile with valgrind debug flags
valgrind: fclean
	@$(MAKE) VALGRIND=1 $(NAME) -s	
	@echo " -> $(BW)[Valgrind]:\t$(BB)Valgrind mode enabled\t🟦$(NC)"
	valgrind $(VALGRIND_FLAGS) ./$(NAME) $(ARGS)

# Rule to run the program with arguments
run: all
	./$(NAME) $(ARGS)

# **************************************************************************** #

.PHONY: all clean fclean re debug valgrind
.DEFAULT_GOAL := all