# **************************************************************************** #
# PROJECT
NAME := Bureaucrat

# **************************************************************************** #
# COMPILER
CPP := c++
CPPFLAGS := -Wall -Wextra -Werror -std=c++98
CPPFLAGS += -MMD -MP
LDFLAGS :=

# BUILD MODES
DEBUG ?= 0
VALGRIND ?= 0
VALGRIND_FLAGS := -s --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes \
				--trace-children=yes

ifeq ($(DEBUG),1)
	OBJ_DIR := obj/debug/
	CPPFLAGS += -g3 -fsanitize=address -DDEBUG
	LDFLAGS += -fsanitize=address
else ifeq ($(VALGRIND),1)
	OBJ_DIR := obj/valgrind/
	CPPFLAGS += -g3 -DDEBUG
else
	OBJ_DIR := obj/regular/
endif

# **************************************************************************** #
# FILES
SRC_FILES := main Bureaucrat AForm \
	ShrubberyCreationForm RobotomyRequestForm PresidentialPardonForm

# GENERAL FILES
SRCS := $(addsuffix .cpp, $(SRC_FILES))
OBJS := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS := $(OBJS:.o=.d)

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
	@$(CPP) $(CPPFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)
	@printf "%b" "$(CL) -> $(BW)[$(NAME)]:\t$(BG)Compilation success\t✅$(NC)\n"

# Rule to compile object files from source files
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@printf "%b" "$(CL) -> $(BW)[$(NAME)]:\t$(NC)$<\r"
	@$(CPP) $(CPPFLAGS) -c $< -o $@

# Rule to clean generated files
clean:
	@rm -rf obj/
	@printf "%b" "$(CL) -> $(BW)[$(NAME)]:\t$(BG)Object files cleaned\t❎$(NC)\n"

# Rule to clean generated files and the executable
fclean:
	@$(MAKE) clean > /dev/null
	@rm -rf $(NAME)
	@printf "%b" "$(CL) -> $(BW)[$(NAME)]:\t$(BG)Exe and objects cleaned\t❎$(NC)\n"

# Rule to recompile from zero
re: fclean all

# **************************************************************************** #
# DEBUG AND RULES

DEFAULT_ARGS :=
ARGS := $(DEFAULT_ARGS)

# Rule to compile and run with debug flags
debug: fclean
	@$(MAKE) DEBUG=1 $(NAME) -s
	@echo " -> $(BW)[Debug]:\t$(BB)Debug mode enabled\t🟦$(NC)"
	-./$(NAME) $(ARGS)

# Rule to run with Valgrind
valgrind: fclean
	@$(MAKE) VALGRIND=1 $(NAME) -s
	@echo " -> $(BW)[Valgrind]:\t$(BB)Valgrind mode enabled\t🟦$(NC)"
	-valgrind $(VALGRIND_FLAGS) ./$(NAME) $(ARGS)

# Rule to run the program with arguments
run: all
	-./$(NAME) $(ARGS)

# **************************************************************************** #

.PHONY: all clean fclean re debug valgrind run
.DEFAULT_GOAL := all