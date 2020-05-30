# FT_CONTAINERS_TESTER v.0.0.02
## TODO :

 - [ ] Vector
 - [ ] List
 - [ ] Map
 - [ ] Stack
 - [ ] Queue
 - [ ] Deque
 - [ ] Set
 - [ ] Multiset
 - [ ] Multimap

## Installation:
### Default installation:
Use this command:

    git clone https://github.com/rchallie/ft_containers_tester FtCTester && cd FtCTester && make run
> This command will clone, go in tester folder, and mount it and use the default configuration on the _Makefile_.

### Custom installation:
Clone this repository into your ft_containers project folder:

    git clone https://github.com/rchallie/ft_containers_tester <name>
 Go into _\<name\>_ folder :

    cd <name>
Start the tester :

    make run
> This will run the tester and use configuration in _Makefile_.

## Configuration:
### Mount configuration:
In _Makefile_ :

    #---- CONFIGURATION --------------------------------
    
    # Change this to set the configuration file to use.
    MACRO_FILE_CONFIG = macro.config
    
    #---------------------------------------------------
- `MACRO_FILE_CONFIG` : Change the configuration file.

### Configuration files:
Basically, you have a one file of configuration named _macro.config_, inside it, all tests are activated. If you set one the test to from `1` to `0` , the test will not be executed and will _not the tester will not try to compile with the necessary_ function . 
> Exemple :
	> If you haven't coded yet the function `.empty()` you can set `VECTOR_FUNC_EMPTY=` to `0`.
	The tester will not compile using `.empty()` and don't test it. 

#### > You own:
You can write your own configuration file. Think to change the file path on the _Makefile_. <br> **Pay attention :** if a line is _not_ set, like `VECTOR_FUNC_EMPTY=1`, the tester will not compile the function `.empty()`, this is the same for all function in containers.

You can add comments using `#` on a line.
## Have fun !
When you have started the tester you will see if you function do the same things the the STL.
You can find _output_ of all tests in the folder equivalent to the container name. 
