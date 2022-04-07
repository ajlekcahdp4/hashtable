# <p align = "center">Hash table</p>

This is my realisation of hash table data structure.

## Table of contents:
- [About](#about-the-project)
- [How to clone](#how-to-clone)
- [Dependencies](#dependencies)
- [Usage](#usage)

## About the project
This project has an aim to implement hash table data structer in the problem of finding the number of appearances of each word in the given text.

You give the program a text file and a word, the number of occurencies of  which you need to find. And the program will tell how many times this word appeared in the text.

## How to clone
To clone this repository run:
```
git clone https://github.com/ajlekcahdp4/hashtable.git
cd hashtable
```
## Dependencies
### For using graphic dump of the hash table, you need [graphviz](https://graphviz.org).
You can install graphviz using apt or apt-get:
```
sudo apt install graphviz
```
Or by using pacman (on arch and manjaro linux):
```
sudo pacman -S graphviz
```
## Usage
To compile this program run:
```
make
```
And then to run the program use *:
```
./HWH.out path_and_file_name.txt
```
Then the program will ask you, what word are you intrested in:
<p align="center">
<img src="https://github.com/ajlekcahdp4/hashtable/blob/main/examples/entry.png">
</p>
After naming your word the program will tell you, how many times your word appeares in the text and ask you again. If you want to escape use 'q':
<p align="center">
<img src="https://github.com/ajlekcahdp4/Akinator/blob/main/examples/run.png">
</p>

*(The program will take text file name from `argv`)


