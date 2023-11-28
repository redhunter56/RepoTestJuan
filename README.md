# Lab06

## Objective
The objective of this Lab is to create an implementation of a Binary Search Tree.

## Task 0
Follow lab standards here - https://github.com/olekaspt/LabStandards

## Task 1  Implement a Binary Search Tree

Implement the Binary Search Tree (BST) as a Template, so it can store any type.  In the requirements below this Template is referred to as <ITEM>
Utilize smart pointers (use std::shared_pointer) as I want a linked-based implementation.

Create a "Node" class that will be used in the BST that uses templates.  The "BinaryNode" from the slide deck can be used as inspiration.  This will need the methods on it return value, and get left and right child.

Create a Binary Search Tree class with the following methods.

Assumption, assume no duplicates will be added.

*  Constructor
*  Destructor
*  Insert – accepts a <ITEM> that is created outside this class.  This will find the correct place to insert the node and insert it and add a node as well.
*  Find – accepts a value, returns true of false if present.
*  Remove - Accepts a value, and returns true if able to remove.
*  Size – returns the number of elements in the tree as an integer.
*  GetAllAscending – returns an array or std::vector with each node stored in order from smallest to largest (based on the sorting value, not the other data in the node).  HINT - this is INORDER traversal
*  Clear – removes all nodes in the tree in a way to avoid memory leaks.

## Task 2

Write unit tests for the above methods (3 per method except construct/destructor).  

## Task 3
Include in your lab report what the tree looks like (you can draw it by hand) after inserting the following nodes in the following orders as well as screen shots of the results from calling GetAllAscending:
1.	“Star Wars”, “Star Trek”, “Space Balls”, “Galaxy Quest”
1.	“Cars”, “Monsters , Inc”, “The Incredibles”, “Wall-E”
1.	“Halloween”, “A Nightmare On Elm Street”, “Hocus Pocus”, “Beetlejuice”
Discuss why your tree has the structure it has and what can be done to give it a better structure (i.e. more balanced).

# Task 4 Participation Rubric


Participation rubric of teammates.  List out for your all team members how much they participated.  This will go into your Lab report.
```
	             Member1	Member2	Member3
Member1 (opinion)	33	     33	     33
Member2 (opinion)	33	     33	     33
Member3 (opinion)	33	     33	     33
```			
			
Example 			
```
	             Member1	Member2	Member3
Member1 (opinion)	33	     33	     33
Member2 (opinion)	20	     40	     40
Member3 (opinion)	20	     40	     40
```

## Lab Submission

1. Package all the files in a single tar file 
1. Lab report of requested items.

# Lab Grading
1. 50% Task1 has been correctly implemented and meets all requirements
1. 15% Task2 has been correctly implemented and meets all requirements
1. 15% Task3 has been correctly implemented and meets all requirements
3. 20% Lab Report