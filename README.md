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
4)Start the program with the command 
```  ./start ``` 

 
**Interacting with the program:**

During operation, the user will have the ability to work in different modes:
1) The user can send any GET request. The execution result of the request will be saved in the file "res.json",
and the contents can be viewed using the command:
``` cat res.json ```
2) The user will be able to compare the results of the requests made to the endpoint "export/branch_binary_packages/{branch}". 
Initially, a request will need to be sent for the first branch, 
followed by a request for the second branch, and then the user can select the comparison type.
after the request is completed, 2 files will be saved first.json , second.json
 
Once the files are downloaded, the user will be prompted to choose the type of comparison between two branches:
 
1) All packages present in the 1st branch but not in the 2nd
2) All packages present in the 2nd branch but not in the 1st
3) All packages whose version-release is greater in the 1st branch than in the 2n
