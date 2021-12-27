Given a postfix expression.Your task is to complete the method constructTree().The output of the program will print the infix expression of the given postfix expression.

Input:
The constructTree() function takes a single argument as input,character array containg the given postfix expression.
Output:
Infix expression should be printed for each given postfix expression.
Constraints:
1<=T<=50
1<=length_of_expression<=20
Example:
Input:
2
ab+ef*g*-
wlrb+-*
Output:
a + b - e * f * g
w * l - r + b
Note:The Input/Ouput format and Example given are used for system's internal purpose, 
and should be used by a user for Expected Output only. As it is a function problem, 
hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
  
  // code
  
  /*struct et
{
	char value;
	et* left, *right;
};*/

//function to construct expression tree
et* help(char postfix[], int &curr){
    if(curr < 0) return NULL;
    et* root = new et(postfix[curr]);
    curr--;
    if(isalpha(root->value)) return root;
    else{
        root->right = help(postfix,curr);
        root->left = help(postfix,curr);
    }
    return root;
}
et* constructTree(char postfix[])
{
    int curr = strlen(postfix)-1;
    return help(postfix,curr);
//code here
}
