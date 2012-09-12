/** 
 	@page appendix_styleguide C++ Coding Style Guide

	@author Jamoma, Timothy Place

h2. Variables

Declare all variables on separate lines.
If a variable is assigned immediately, then give it a default value in the declaration.
Prefer explicit types, e.g. TTObjectPtr rather than TTObject*.
User tabular formatting, as mentioned in the section "Whitespace"

h2. Functions

Functions always appear:

1. With the return type on the same line as the function name
2. With the arguments on the same line as the function name, unless they dont fit.  
	In this case they follow in tabular format below the first argument name.
3. The open curly brace is on the line below the function name -- not the same line.
4. The closing curly brace is always on its own line

<pre class ="cpp>"
TTHashPtr	TTNodeDirectory::getDirectory()
{
	return this->directory;
}
</pre>

Whitespace between two functions should generally be two blank lines.
There should never be two consecutive blank lines within a function.

h2. Arguments

Prefer passing arguments as TTValueRef or const TTValueRef.

h2. Whitespace

# Multiple lines of similar function calls, similar definitions, should prefer tabular style formatting 
	(which is to say, things are lined up in columns).
	This makes it faster to see the variant information between the lines, and also to edit multiple lines 
	simultaneously using an editor such as TextMate.
	
	
	
h2. Naming Conventions

Macros -- all upper case, words divided by underscores

Variables
1. CamelCase.
2. Variable names begin with lower-case letters
3. Class Member variables begin with 'm'
4. Constants begin with a 'k'
5. Globals begin with 'g'
6. Statics begin with 's'
7. member method names begin with lower-case letters
8. Classes or Global scope functions beggin with upper-case letters.
9. Library functions begin with 'TT', non-library functions do not.

h2. Casting

1. Be wary of casting if the problem/warning can be avoided in another way.

Readability is the most important thing.  So we dont always use the crazy C++ casting stuff...

2. Prefer C++ Style int(someValue) casts to (int)someValue casts.  


h2. Constructors

1. for TTObject subclasses, use the appropriate macro (such as TT_OBJECT_CONSTRUCTOR) to implement the function signature correctly
2. prefer initializers to assigning values
3. initializers should be indented one tab

*/