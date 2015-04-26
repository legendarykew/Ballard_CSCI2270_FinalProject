# Ballard_CSCI2270_FinalProject
Final project for CSCI 2270

Project: Dynamic Structure Generator

Project Summary
  The concept of this project is to provide a solution to the problem that not every application requires a "vanilla" data structure: perhaps a single queue, or a BST, isn't enough to satisfy what one's trying to do. Of course, with every issue in CS, a solution can be made in the project -- but a general means of quickly creating and initializing more complex and interwoven data structures would make matters easier. So, that's what Dynamic Structure Generator (DSG) aims to do: provide a simple means of creating, initializing and interacting with more complex data structures, like binary trees of queues, or a stack of hash tables. The user, when using the provided driver file, is presented with a menu, with options to initalize a data structure, to add data, to get data, and to quit. Initializing a data structure means asking the user what structures they'd like, and in what order. For instance, initializing a data structure presents the user with another menu of data structures DSG supports. They choose what data structures they want from the top-down (i.e., if they choose hash table, then queue, then it will be a hash table of queues), then the program generates an empty data structure of what they asked for. Adding data simply asks the user for an integer, then, depending on the data structure, where in the structure they want it. Some structures figure this out themselves, some may not necessarily. Getting data is simply a means of browsing the data structure.
  
How To Run

Dependencies

System Requirements
  The project is developed for Linux, and should run on any modern distro.
  
Group Members
  Robert Ballard
  
Contributors

Open issues/bugs

