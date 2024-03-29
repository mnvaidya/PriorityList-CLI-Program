## PriorityList CLI Program 

## Specification

1. Run the app in the console with `./task`.

2. Enter the task. Each task occupies a single line. These tasks are saved in a file. The format of the saved task :

   ```
   p task
   ```

   where `p` is the priority (positive number) and `task` is the description of the task.

   > Priority denotes how important a task is, if it is a high priority task, it should be completed earlier. Priority is denoted using an integer, the lower the number, the higher the priority.

   Example of a file that has 2 items.

   ```
   1 Buy milk
   2 Complete the project
   ```

3. Completed task are written to a Completed.txt file. Each task occupies a single line in this file. Each line in the file should be in this format :

   ```
   task
   ```

   where task is the task description.

   Example of a file that has 2 items.

   ```
   Buy milk
   Complete the project
   ```

4. Priority can be any integer _greater than_ or _equal to_ 0. 0 being the highest priority

5. If two task have the same priority, the task that was added first should be displayed first.

6. The files should always be sorted in order of the priority, ie, the task with the highest priority should be first item in the file.


## Usage

### 1. Help

Executing the command without any arguments, or with a single argument help prints the CLI usage.

```
$ ./task help
Usage :-
$ ./task add 2 hello world    # Add a new item with priority 2 and text "hello world" to the list
$ ./task ls                   # Show incomplete priority list items sorted by priority in ascending order
$ ./task del INDEX            # Delete the incomplete item with the given index
$ ./task done INDEX           # Mark the incomplete item with the given index as complete
$ ./task help                 # Show usage
$ ./task report               # Statistics
```

### 2. List all pending items

Use the ls command to see all the items that are not yet complete, in ascending order of priority.

Every item should be printed on a new line. with the following format

```
[index] [task] [priority]
```

Example:

```
$ ./task ls
1. change light bulb [2]
2. water the plants [5]
```

index starts from 1, this is used to identify a particular task to complete or delete it.

### 3. Add a new item

Use the add command. The text of the task should be enclosed within double quotes (otherwise only the first word is considered as the item text, and the remaining words are treated as different arguments).

```
$ ./task add 5 "the thing i need to do"
Added task: "the thing i need to do" with priority 5
```

### 4. Delete an item

Use the del command to remove an item by its index.

```
$ ./task del 3
Deleted item with index 3
```

Attempting to delete a non-existent item should display an error message.

```
$ ./task del 5
Error: item with index 5 does not exist. Nothing deleted.
```

### 5. Mark a task as completed

Use the done command to mark an item as completed by its index.

```
$ ./task done 1
Marked item as done.
```

Attempting to mark a non-existed item as completed will display an error message.

```
$ ./task done 5
Error: no incomplete item with index 5 exists.
```

### 6. Generate a report

Show the number of complete and incomplete items in the list. and the complete and incomplete items grouped together.

```
$ ./task report
Pending : 2
1. this is a pending task [1]
2. this is a pending task with priority [4]

Completed : 3
1. completed task
2. another completed task
3. yet another completed task
```
