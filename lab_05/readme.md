# Lab 5

## Purpose
There are several purposes to this week's lab. The first 
is to get you used to looking through a big set of code,
understand its structure, and amend it properly. The second
purpose is to implement a database class, taking advantage
of inheritance.

## Steps
[1] Skim through the code. There is a `linked_list` class
which does exactly what you would expect. You don't
need to make any edits to this class

[2] There is a base `hash_table_base` class which is designed
specifically for other classes to inherit. For example,
the `hash_table_firstname` class inherits the base class
and adds overrides for the `hash_function` and `extract_key` 
functions.

[3] Write code to complete `hash_table_lastname` and
`hash_table_id`, using `hash_table_firstname` to guide
you.

[4] Improve the hash_function by making it position sensitive, meaning
that "Smith" and "Htims" should map to different indexes.

[5] Run `test_case_1()` to make sure your solutions to
item [3] work as expected. 

[6] As you can see in `test_case_1()`, every student
has to be explicitly inserted into three different hash tables.
Its a painful process. Create a `db` class whose member variables
are the three hash tables. When a user calls `db.insert()`,
it will automatically insert the new student into all
three hash tables. Likewise, when the user calls a `lookup`
function, the `db` class should call `lookup()` on the appropriate
hash table.

[7] Check to make sure [6] works by running `test_case_2()`

## Notes

Don't forget to document your code, including with the
comment block at the top of the file.

The submit script will only submit `lab_05.py`   

## Due
Sunday 3/16/2025 at midnight

## Questions
`iobeid@temple.edu`
