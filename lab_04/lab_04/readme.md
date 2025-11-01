# Lab 4

## Purpose
One way of determining if a tree is well balanced is to count how many of the nodes
have zero children, one child, or two children. Well-balanced trees will have very few
nodes with just one child. A degenerate tree will have all nodes with one child, except the
very last node which will have zero children.

The purpose of Lab 4 is to write a binary search tree function that counts the number of nodes 
with zero, one, or two valid children. I have supplied you with `lab_04.py` which contains a `bst` 
class as well as all the testcases you'll need. You should only edit the `count()` method of the
`bst` class.

## Steps
[1] Use the rsync command (or equivalent) to copy the code to your directory: `rsync -rv $SHARE/lab_04 .`

[2] Complete the `count()` function. This function will
save the node counts in the three corresponding class
variables. Recursion is recommended.You may only edit the count() function. No other edits are permissable.

[3] Answer the questions (see Notes) in a code block at the top of your `lab_04.py` file.

[4] Submit your assignment using the `submit.py` 
command.

## Notes
There are three test cases. The first two are simple enough that you can manually validate
your results. The third cases reads 1000 randomly generated ints out of a file and puts them
in the tree. My results are:
- Nodes with 0 children: 345
- Nodes with 1 children: 311
- Nodes with 2 children: 344

Your code should return the same. Is this a well-balanced tree? If the tree was _perfectly_ balanced,
what would the node counts be? Answer those questions in a comment block at the top of your `lab_04.py`
file.

Document your code. Add a block at the top with
your name, date, and contact info, and instructions to 
run the code. Comment methods implementations as well.
Use self documenting code and meaningful variable 
names.

## Due
Sunday 2/23/2025 at midnight

## Questions
`iobeid@temple.edu`
