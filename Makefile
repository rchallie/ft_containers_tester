#      _____                         
#    (, /   )   /)       /) /) ,    
#      /__ / _ (/   _   // //     _ 
#  )  /   \_(__/ )_(_(_(/_(/__(__(/_
#  (_/   						 
#                                  42.

# TODO:
# Remove -D and add automaticaly add all start of line

#---- CONFIGURATION --------------------------------

# File with test to do.
MACRO_FILE_CONFIG = macro.config

#---------------------------------------------------


#---- Don't touch ----------------------------------

MACRO = `cat $(MACRO_FILE_CONFIG) | grep -v "\#"`

NORMAL = "\033[0;0m"
GREEN = "\033[0;32m"
RED = "\033[0;31m"

NAME		= ft_container_tester

SOURCES_DIR = ./
SOURCES 	= 	testVector.cpp \
				main.cpp

INCLUDE 	= ./test.hpp

FLAGS 		= -Wall -Wextra -Werror

OBJS_DIR 	= 	objs/
OBJ 		= 	$(SOURCES:.cpp=.o)
OBJS 		= 	$(addprefix $(OBJS_DIR), $(OBJ))
#---------------------------------------------------

$(OBJS_DIR)%.o	:	$(SOURCES_DIR)%.cpp $(INCLUDE)
	@mkdir -p $(OBJS_DIR)
	@echo $(GREEN)"Compiling : " $(NORMAL) $<
	@clang++ \
		-D VECTOR_FILE_PATH=$(VECTORS_HPP)\
		 $(MACRO) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@clang++ -g $(FLAGS) -o $(NAME) $(OBJS)
	@echo $(GREEN) "\rDONE !"$(NORMAL)

all : $(NAME)

clean :
	@echo $(RED)"Removing  :  "$(NORMAL) $(OBJS_DIR)
	@rm -rf $(OBJS_DIR)
	@echo $(RED)"Removing  :  "$(NORMAL) "vectors"
	@rm -rf ./vectors

fclean: clean
	@echo $(RED)"Removing  :  "$(NORMAL) $(NAME)
	@rm -rf $(NAME)

re : fclean all

run : all
	@./$(NAME)