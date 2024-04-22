# Rest_Client Utility

**Description**
Utility for querying 2 branches with lists of binary packages located at [ALT linux Repository](https://rdb.altlinux.org/api/export/branch_binary_packages/{branch}).

**Preparation**
For the correct compilation of the project, the libraries curl and nlohmann must be installed.
Switch to superuser mode by using the command (su-)
``` apt-get install nlohmann-json-devel ```
``` apt-get install curl ```
``` apt-get install libcurl ```
``` apt-get install libcurl-devel ```

 
**Installation:**

1) Clone the repository:
``` git clone git@github.com:TexA2/Rest_Client.git ```
2) Navigate to the project directory
3) Run the utility with administrator rights (su -) using the make command:
``` make ```
4) To remove object files, use the command:
 ``` make clean ```
 
**Interacting with the program:**
To start the program, run it from the project folder using the command
``` ./start``` 
The program will prompt you to choose a branch name for the query. If the desired branch is not in the list, the user can specify their own data.
After selecting the branch, the user will be asked whether they want to select an architecture for that branch. The user can skip this step if desired. If the user chooses to select an architecture, they will be asked to enter it when prompted by the application, which will show a list of possible architectures in advance.
 
After entering all the data, the program will download the data from the server.
Two json files <branch_name>.json will be created in the project folder.
 
Once the files are downloaded, the user will be prompted to choose the type of comparison between two branches:
 
1) All packages present in the 1st branch but not in the 2nd
2) All packages present in the 2nd branch but not in the 1st
3) All packages whose version-release is greater in the 1st branch than in the 2n
