/*
** Exercise 03: Unnecessary violence
**
** Turn-in directory: ex03/
** Files to turn in: Makefile, main.cpp, Weapon.{h, hpp}, Weapon.cpp,
**                   HumanA.{h, hpp}, HumanA.cpp, HumanB.{h, hpp}, HumanB.cpp
** Forbidden functions: None
**
** Description:
** Implement a `Weapon` class with:
** - A private string attribute `type`.
** - `getType()` to return a constant reference to `type`.
** - `setType()` to update `type`.
**
** Create `HumanA` and `HumanB` classes with:
** - A `Weapon` and a `name`.
** - `attack()` to display "<name> attacks with their <weapon type>".
**
** Differences:
** - `HumanA` takes a `Weapon` in its constructor and is always armed.
** - `HumanB` does not take a `Weapon` in its constructor and may not always
**   have a weapon.
**
** Test the implementation with provided code and ensure proper memory management.
*/


