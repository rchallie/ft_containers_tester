# FT_CONTAINERS_TESTER v.0.0.03
### ⚠️ This is WIP, if you find a bug, have a suggestion, or add a test, you can create an issue, send me a mp on slack or by mail, or do a pull request ! ⚠️
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

## Have fun !
When you have started the tester you will see if your function do the same things the the STL.
You can find _output_ of all tests in the folder equivalent to the container name. 

## Output files:
The tester will output perfomed test in terms of the container tested. The output form can change in function of tests.
You can find this in tests output :
> Here an output test of `.insert()` (fill) function using pushback to have a filled vector container: _An attribute output_

    ══════════════════════════════════════════════════════════════
    Vectors attributes : After test : Insert (fill) from pushbacked
    STL :
    Empty       : false
    Size        : 19
    Max size    : 4611686018427387903
    Capacity    : 30
    Content     : [42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 1, 1, 1, 1, 42, 42, 42]
	 
	FT :
	Empty    [ø]: Can't be compared (Need VECTOR_FUNC_EMPTY).
	Size     [✔]: 19
	Max size [✔]: 4611686018427387903
	Capacity [✘]: 32
	Content  [ø]: Can't be compared (WIP)
	══════════════════════════════════════════════════════════════
- The first part is the output of the STL containers.
- The secound part is FT containers.
		- `[ø]` : Can't be performed.
		- `[✔]` :  In agreement with the STL container.
		- `[✘]` :  Improper.
> ⚠️ Some fonctionnality can be in developpement (WIP).

    Code executed:
    ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
    ft::vector<int> ft_fill_insert_pushback;
    for (int n = 0; n < 15; n++)
	    ft_fill_insert_pushback.push_back(42);
	ft::vector<int>::iterator ft_fill_insert_pushback_it = ft_fill_insert_pushback.begin();
	ft_fill_insert_pushback_it += 12;
	ft_fill_insert_pushback.insert(ft_fill_insert_pushback_it, 4, 1);

You have the details about how the code is tested.

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

#### > The macros:
Here the macros to defined which test used:
**Generally the tester need iterators to check value inside of containers.** _think about that_.

 - `VECTOR_DEFAULT_CONSTRUCTOR` : It's the default constructor of vector. If this is not defined to `1` no test works on vectors, because not negligible amount of tests will use it. Next macros _Allow tester to **use/test**_ (if a description is added, that not mean the tester will not compile, that will just does'nt test the tests function that use it. _To check if a test need a particular macro, please check : **macro.config**_):
		 <br>-  `VECTOR_FUNC_AT` :  `.at()`. 
		 <br>- `VECTOR_FUNC_BEGIN` :  `.begin()`, a lot of test that uses iterators will need it.
		 <br>- `VECTOR_FUNC_EMPTY` :  `.empty()`.
		 <br>- `VECTOR_FUNC_SIZE` :  `.size()`.
		 <br>- `VECTOR_FUNC_MAX_SIZE` :  `.max_size()`.
		 <br>- `VECTOR_FUNC_CAPACITY` : `.capacity()`.
		 <br>- `VECTOR_FUNC_PUSHBACK` : `.push_back()`, if the macro`VECTOR_FILL_CONSTRUCTOR` is set to `0`, a lot of test will use this to avec a filled vector.
		 <br>- `VECTOR_CONSTRUCTOR_ALL` :  if is set to `0`, the tester will not test constructors.
		 <br>- `VECTOR_FILL_CONSTRUCTOR` : the fill constructor.
		 <br>- `VECTOR_INSERT_ALL` : will not test differents insert functions.
		 <br>- `VECTOR_FILL_INSERT_FUNC`: `.insert()` fill version.
		 <br>- `VECTOR_DESTRUCTOR` : the destructor.
		 <br>- `VECTOR_ITERATOR_ALL` : if is set to `0` , the tester will not use iterator. (_A lot of test use them, that can be really usefull to code them fastly._)
		<br>- `VECTOR_ITERATOR_ASSIGN_CONSTRUCTOR` : the assignable-constructor of vectors.
		<br>- `VECTOR_ITERATOR_OPE_PLUS_EQUAL` : `operator+=()`.
		<br>- `VECTOR_ITERATOR_INCREMENTATION_RIGHT` : `operator++(int)`
