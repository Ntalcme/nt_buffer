NAME				= libntbuffer.a
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror -I./include -pedantic -I./src
AR					= ar
ARFLAGS				= rcs
RM					= rm -rf

BUILD_DIR			= build
OBJ_DIR				= $(BUILD_DIR)/obj
LIB_DIR				= $(BUILD_DIR)/lib

SRCS				= $(wildcard src/*.c)
OBJS				= $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS				= $(OBJS:.o=.d)

INSTALL_DIR         = /usr/local
INSTALL_LIB_DIR     = $(INSTALL_DIR)/lib
INSTALL_INC_DIR     = $(INSTALL_DIR)/include/$(NAME:.a=)

all:				$(LIB_DIR)/$(NAME)


install: 			all
					@echo "Installation of the $(NAME) library..."
					@mkdir -p $(INSTALL_LIB_DIR)
					@cp $(LIB_DIR)/$(NAME) $(INSTALL_LIB_DIR)
					@mkdir -p $(INSTALL_INC_DIR)
					@cp -r include/nt_library/* $(INSTALL_INC_DIR)/
					@echo "$(NAME) has been installed in $(INSTALL_LIB_DIR) and its headers in $(INSTALL_INC_DIR) !"
					@echo "Cleaning up local build files..."
					$(RM) $(BUILD_DIR)
					@echo "Local clean-up completed."

uninstall:
					@echo "Uninstalling the $(NAME) library..."
					$(RM) $(INSTALL_LIB_DIR)/$(NAME)
					$(RM) $(INSTALL_INC_DIR)
					@echo "$(NAME) has been uninstalled."

$(LIB_DIR)/$(NAME): $(OBJS) | $(LIB_DIR)
					@$(AR) $(ARFLAGS) $@ $(OBJS)
					@echo "Compilation completed."

$(OBJ_DIR)/%.o:		src/%.c | $(OBJ_DIR)
					@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@
					@echo "Compiled $< into $@"

$(OBJ_DIR):
					@mkdir -p $@

$(LIB_DIR):
					@mkdir -p $@

$(BUILD_DIR):
					@mkdir -p $@

clean:
					@echo "Cleaning up object files and dependencies..."
					$(RM) $(OBJ_DIR)

fclean: 
					@echo "Cleaning up the $(NAME) library..."
					$(RM) $(BUILD_DIR)
					@echo "Local clean-up completed."

re: 				fclean all

-include 			$(DEPS)

.PHONY: 			all clean fclean re install uninstall