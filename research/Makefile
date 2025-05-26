# **************************************************************************** #
# DIRECTORIES
SRC_DIR := src/
INC_DIR := inc/
OBJ_DIR := obj/
LIB_DIR := lib/

# **************************************************************************** #
# PROJECT
NAME := myfirstprogram.out

# **************************************************************************** #
# FILES
SRC_FILES := myfirstprogram
INC_FILES := myfirstprogram

# GENERAL FILES
SRCS := $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_FILES)))
OBJS := $(SRCS:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)
DEPS := $(OBJS:.o=.d)
INCS := $(addprefix $(INC_DIR), $(addsuffix .hpp, $(INC_FILES)))

# **************************************************************************** #
# COMPILER
CPP := c++
CPPFLAGS := -Wall -Wextra -Werror -std=c++98
CPPFLAGS += -MMD -MP
IFLAGS := -I$(INC_DIR)

# DEBUG MODE
BUILD_MODE_FILE := .build_mode
DEBUG ?= 0
VALGRIND ?= 0
VALGRIND_FLAGS := -s --tool=memcheck --leak-check=full --show-leak-kinds=all \
--track-origins=yes --trace-children=yes --track-fds=yes

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
	@$(CPP) $(CPPFLAGS) $(IFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@printf "%b" "$(CL) -> $(BW)[$(NAME)]:\t$(BG)Compilation success\t✅$(NC)\n"
	@echo "─────────────────────────────────────────────────────$(BY)"
	@echo "   ▗▄▄      ▗▖  ▗▖                                   ";
	@echo "  ▐▌        ▐▛▚▞▜▌ ▗▄▖ ▗▄▄▄ ▗▖ ▗▖▗▖  ▗▄▄▖ ▗▄▄▖      ";
	@echo "  ▐▌   ▟▖▟▖ ▐▌  ▐▌▐▌ ▐▌▐▌  █▐▌ ▐▌▐▌  ▐▙▄  ▀▄▄        ";
	@echo "  ▝▚▄▄▖▝ ▝  ▐▌  ▐▌▝▚▄▞▘▐▙▄▄▀▝▚▄▞▘▐▙▄▖▐▙▄▖ ▄▄▄▀       ";
	@echo "                                          by ozamora-";
	@echo "$(NC)─────────────────────────────────────────────────────"
# @echo "───────────────────────────$(BY)"
# @echo "         ▖  ▖   ▌  ▜       ";
# @echo " ▛▘▟▖▟▖  ▛▖▞▌▛▌▛▌▌▌▐ █▌▛▘  ";
# @echo " ▙▖▝ ▝   ▌▝ ▌▙▌▙▌▙▌▐▖▙▖▄▌  ";
# @echo "                by ozamora-";
# @echo "$(NC)───────────────────────────"

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
# BONUS SECTION (GROUPED FOR EASY REMOVAL)
# Comment or delete this section if you don't need bonus functionality.

# BONUS DIRECTORIES
SRC_BONUS_DIR := src/bonus/
INC_BONUS_DIR := inc/bonus/
OBJ_BONUS_DIR := obj/bonus/

# BONUS FILES
BONUS_NAME := .PROJECT_NAME_bonus
SRC_BONUS_FILES := main_bonus
INC_BONUS_FILES := PROJECT_NAME_bonus

# BONUS GENERAL FILES
SRCS_BONUS := $(addprefix $(SRC_BONUS_DIR), $(addsuffix .cpp, $(SRC_BONUS_FILES)))
OBJS_BONUS := $(SRCS_BONUS:$(SRC_BONUS_DIR)%.cpp=$(OBJ_BONUS_DIR)%.o)
DEPS_BONUS := $(OBJS_BONUS:.o=.d)
INCS_BONUS := $(addprefix $(INC_BONUS_DIR), $(addsuffix .hpp, $(INC_BONUS_FILES)))

# BONUS COMPILER FLAGS
IFLAGS_BONUS:= -I$(INC_BONUS_DIR)

# BONUS RULES
bonus: $(BONUS_NAME)
$(BONUS_NAME): $(OBJS_BONUS)
	@$(CPP) $(CPPFLAGS) $(IFLAGS_BONUS) $(OBJS_BONUS) $(LDFLAGS) -o $(NAME) 
	@touch $(BONUS_NAME)
	@printf "%b" "$(CL) -> $(BW)[$(NAME)]:\t$(BG)Bonus compiled\t✅$(NC)\n"

$(OBJ_BONUS_DIR):
	@mkdir -p $(OBJ_BONUS_DIR)
$(OBJ_BONUS_DIR)%.o: $(SRC_BONUS_DIR)%.cpp | $(OBJ_BONUS_DIR)
	@mkdir -p $(dir $@)
	@printf "%b" "$(CL) -> $(BW)[$(NAME)]:\t$(NC)$<\r"
	@$(CPP) $(CPPFLAGS) $(IFLAGS_BONUS) -c $< -o $@

# **************************************************************************** #
# NORM AND DEBUG RULES

# Rule to compile with debug flags
debug:
	@if [ ! -f $(BUILD_MODE_FILE) ] || ! grep -q "DEBUG=1" $(BUILD_MODE_FILE); then \
		$(MAKE) fclean -s; \
	fi
	@echo "DEBUG=1" > $(BUILD_MODE_FILE)
	@$(MAKE) DEBUG=1 -s
	@echo " -> $(BW)[Debug]:\t$(BB)Debug mode enabled\t🟦$(NC)"
	-@if [ ! -z "$(ARGS)" ]; then ./$(NAME) $(ARGS); fi

# Rule to compile with valgrind debug flags
valgrind:
	@if [ ! -f $(BUILD_MODE_FILE) ] || ! grep -q "VALGRIND=1" $(BUILD_MODE_FILE); then \
		$(MAKE) fclean -s; \
	fi
	@echo "VALGRIND=1" > $(BUILD_MODE_FILE)
	@$(MAKE) VALGRIND=1 -s
	@echo " -> $(BW)[Valgrind]:\t$(BB)Valgrind mode enabled\t🟦$(NC)"
	-@if [ ! -z "$(ARGS)" ]; then \
		valgrind $(VALGRIND_FLAGS) ./$(NAME) $(ARGS); \
	fi

# **************************************************************************** #

.PHONY: all clean fclean re debug valgrind
.DEFAULT_GOAL := all