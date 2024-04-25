# Rest_Client Utility

**Description**
Utility for querying 2 branches with lists of binary packages (export/branch_binary_packages/{branch}) located at [ALT linux Repository](https://rdb.altlinux.org/api/).

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
3) Run the utility  using the make command:
``` make ```

 
**Interacting with the program:**
To start the program, run it from the project folder using the command
``` ./start``` 

the program asks to chooose the operating mode:
1) The user writes a full Get request to the server and the received response is written to a file res.json
2) The user works with the method (export/branch_binary_packages/{branch}) 
and writes the full request to this method.
The user is required to form 2 requests. 
When the requests are sent, the response is saved to files.
 
Once the files are downloaded, the user will be prompted to choose the type of comparison between two branches:
 
1) All packages present in the 1st branch but not in the 2nd
2) All packages present in the 2nd branch but not in the 1st
3) All packages whose version-release is greater in the 1st branch than in the 2n
